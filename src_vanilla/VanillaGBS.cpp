// Giants Vanilla-Native Recomp — GBS model parser. See VanillaGBS.h.
#include "VanillaGBS.h"
#include "VanillaVFS.h"
#include <cstdio>
#include <cstring>

extern FILE* g_vTrace;

namespace VanillaGBS {

static uint32_t rdU32(const uint8_t* p) {
    return uint32_t(p[0]) | (uint32_t(p[1])<<8) | (uint32_t(p[2])<<16) | (uint32_t(p[3])<<24);
}

Model Parse(const uint8_t* data, size_t len) {
    Model m{};
    if (len < 12) return m;
    m.magic = rdU32(data);
    if (m.magic != 0xAA0100BEu) return m;
    m.options = rdU32(data + 4);
    m.numVertices = rdU32(data + 8);
    m.hasNormals = (m.options & 0x1) != 0;
    m.hasUVs     = (m.options & 0x2) != 0;
    m.hasRGBs    = (m.options & 0x4) != 0;
    if (m.numVertices > 100000) return m;

    size_t pos = 12;
    // vertices
    m.vertices.resize((size_t)m.numVertices * 3);
    if (pos + m.vertices.size() * 4 > len) return m;
    for (size_t i = 0; i < m.vertices.size(); i++) {
        memcpy(&m.vertices[i], data + pos, 4); pos += 4;
    }
    // normals
    if (m.hasNormals) {
        if (pos + 8 > len) return m;
        uint32_t nndefs = rdU32(data + pos); pos += 4;
        uint32_t numNormals = rdU32(data + pos); pos += 4;
        pos += (size_t)numNormals * 2;   // u16 each
    }
    // nverts + indexed_vertices
    if (pos + 4 > len) return m;
    m.nverts = rdU32(data + pos); pos += 4;
    if (m.nverts > 200000) return m;
    m.indexedVertices.resize(m.nverts);
    for (uint32_t i = 0; i < m.nverts; i++) {
        m.indexedVertices[i] = uint16_t(data[pos]) | (uint16_t(data[pos+1])<<8); pos += 2;
    }
    if (m.hasNormals) pos += (size_t)m.nverts * 2; // indexed_normals
    if (m.hasUVs)     pos += (size_t)m.nverts * 8; // vertuv f32[2]
    if (m.hasRGBs)    pos += (size_t)m.nverts * 3; // vertrgb u8[3]

    // MaxObjs
    if (pos + 4 > len) { m.ok = true; return m; }
    uint32_t nmobjs = rdU32(data + pos); pos += 4;
    pos += (size_t)nmobjs * 20;
    // SubObjects
    if (pos + 4 > len) { m.ok = true; return m; }
    m.numSubObjects = rdU32(data + pos); pos += 4;
    for (uint32_t i = 0; i < m.numSubObjects && pos < len; i++) {
        SubObj so;
        char objname[33] = {0}; memcpy(objname, data + pos, 32); pos += 32;
        so.name = objname;
        m.subObjectNames.push_back(objname);
        if (pos + 20 > len) break;
        pos += 4;                                   // maxobjindex
        so.totaltris = rdU32(data + pos); pos += 4; // totaltris
        uint32_t ntris = rdU32(data + pos); pos += 4; // ntris (tridata u16 count)
        // tridata: ntris u16, RLE-encoded as [count:u16][count×3 idx:u16]. Decode into
        // a flat triangle-vertex-index list (each idx indexes indexedVertices). Spec order:
        // tridata comes BEFORE verticeref_start/count.
        const uint8_t* tristart = data + pos;
        size_t triAvail = (len - pos) / 2;
        size_t ti = 0;
        uint32_t guard = 0;
        while (ti + 1 <= triAvail && so.tris.size() / 3 < so.totaltris && guard++ < 1000000) {
            uint16_t count = uint16_t(tristart[ti*2]) | (uint16_t(tristart[ti*2+1])<<8); ti++;
            if (count == 0) break;
            for (uint16_t c = 0; c < count && ti + 3 <= triAvail; c++) {
                for (int k = 0; k < 3; k++) {
                    so.tris.push_back(uint16_t(tristart[ti*2]) | (uint16_t(tristart[ti*2+1])<<8));
                    ti++;
                }
            }
        }
        pos += (size_t)ntris * 2;   // skip the WHOLE tridata block (ntris = u16 count)
        so.verticeref_start = (int32_t)rdU32(data + pos); pos += 4;  // verticeref_start
        so.verticeref_count = (int32_t)rdU32(data + pos); pos += 4;  // verticeref_count
        // material: [if UVs] texname[32]+bumpname[32], falloff; [if RGBs] blend; flags;
        //           emissive,ambient,diffuse,specular (packed BBGGRR); power.
        if (m.hasUVs) {
            char tex[33]={0}, bump[33]={0};
            if (pos+64<=len){ memcpy(tex,data+pos,32); memcpy(bump,data+pos+32,32); m.texNames.push_back(tex); }
            pos += 64; pos += 4;        // texname+bumpname + falloff
        } else { pos += 4; }            // falloff
        if (m.hasRGBs) pos += 4;        // blend
        pos += 4;                       // flags
        pos += 4;                       // emissive
        pos += 4;                       // ambient
        so.diffuse = rdU32(data + pos); pos += 4;   // diffuse (BBGGRR)
        pos += 4;                       // specular
        pos += 4;                       // power
        m.subObjs.push_back(std::move(so));
    }
    m.ok = true;
    return m;
}

std::vector<float> Model::buildPositionTris() const {
    std::vector<float> out;
    for (const auto& so : subObjs) {
        for (size_t t = 0; t + 2 < so.tris.size(); t += 3) {
            for (int k = 0; k < 3; k++) {
                uint16_t idx = so.tris[t + k];
                size_t poolIdx = (size_t)so.verticeref_start + idx;
                if (poolIdx >= indexedVertices.size()) { out.push_back(0); out.push_back(0); out.push_back(0); continue; }
                uint16_t base = indexedVertices[poolIdx];
                if ((size_t)base * 3 + 2 >= vertices.size()) { out.push_back(0); out.push_back(0); out.push_back(0); continue; }
                out.push_back(vertices[(size_t)base * 3 + 0]);
                out.push_back(vertices[(size_t)base * 3 + 1]);
                out.push_back(vertices[(size_t)base * 3 + 2]);
            }
        }
    }
    return out;
}

bool SelfTest() {
    auto data = VanillaVFS::GzpReadFile("Bin\\xx_intro.gzp", "intro_1.gbs");
    if (data.empty()) {
        if (g_vTrace) { fprintf(g_vTrace, "[VGBS] intro_1.gbs not found\n"); fflush(g_vTrace); }
        return false;
    }
    Model m = Parse(data.data(), data.size());
    if (!m.ok) {
        if (g_vTrace) { fprintf(g_vTrace, "[VGBS] parse FAILED (magic=%08x)\n", m.magic); fflush(g_vTrace); }
        return false;
    }
    if (g_vTrace) {
        fprintf(g_vTrace, "[VGBS] intro_1.gbs: magic=%08x opts=%08x (N%d U%d R%d) verts=%u nverts=%u subobjs=%u\n",
                m.magic, m.options, m.hasNormals, m.hasUVs, m.hasRGBs, m.numVertices, m.nverts, m.numSubObjects);
        for (size_t i = 0; i < m.subObjectNames.size() && i < 5; i++)
            fprintf(g_vTrace, "   subobj[%zu] '%s' tex='%s'\n", i, m.subObjectNames[i].c_str(),
                    i < m.texNames.size() ? m.texNames[i].c_str() : "");
        fflush(g_vTrace);
    }
    return true;
}

} // namespace VanillaGBS
