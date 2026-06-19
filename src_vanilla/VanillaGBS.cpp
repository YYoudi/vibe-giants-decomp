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
    // bbox of base vertex pool (for camera framing).
    if (m.numVertices) {
        m.bboxMin[0]=m.bboxMax[0]=m.vertices[0];
        m.bboxMin[1]=m.bboxMax[1]=m.vertices[1];
        m.bboxMin[2]=m.bboxMax[2]=m.vertices[2];
        for (uint32_t i = 1; i < m.numVertices; i++) {
            float x=m.vertices[i*3], y=m.vertices[i*3+1], z=m.vertices[i*3+2];
            if (x<m.bboxMin[0])m.bboxMin[0]=x; if (x>m.bboxMax[0])m.bboxMax[0]=x;
            if (y<m.bboxMin[1])m.bboxMin[1]=y; if (y>m.bboxMax[1])m.bboxMax[1]=y;
            if (z<m.bboxMin[2])m.bboxMin[2]=z; if (z>m.bboxMax[2])m.bboxMax[2]=z;
        }
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
    if (m.hasUVs) {                                // vertuv f32[2] — KEEP (v flipped, per canonical)
        m.vertuv.resize((size_t)m.nverts * 2);
        if (pos + m.vertuv.size() * 4 > len) return m;
        for (uint32_t i = 0; i < m.nverts; i++) {
            float u, v;
            memcpy(&u, data + pos, 4); pos += 4;
            memcpy(&v, data + pos, 4); pos += 4;
            m.vertuv[i*2+0] = u;
            m.vertuv[i*2+1] = -v;  // canonical reader flips V
        }
    }
    if (m.hasRGBs) {                               // vertrgb u8[3] — KEEP
        m.verrgb.resize((size_t)m.nverts * 3);
        if (pos + m.verrgb.size() > len) return m;
        memcpy(m.verrgb.data(), data + pos, m.verrgb.size()); pos += m.verrgb.size();
    }

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

// Interleaved XYZ(3) + DIFFUSE(1) + UV(2) = 6 floats per vertex, 3 verts per triangle.
// FVF 0x142 (XYZ|DIFFUSE|TEX1). diff = per-subobj material diffuse; UV from vertuv (if present).
std::vector<float> Model::buildTexturedTris(size_t* outVertCount) const {
    std::vector<float> out;
    size_t vc = 0;
    for (const auto& so : subObjs) {
        // diffuse packed BBGGRR -> ARGB (0xFF alpha)
        uint32_t b = (so.diffuse) & 0xFF, g = (so.diffuse >> 8) & 0xFF, r = (so.diffuse >> 16) & 0xFF;
        uint32_t diff = 0xFF000000u | (r << 16) | (g << 8) | b;
        float df; memcpy(&df, &diff, 4);
        for (size_t t = 0; t + 2 < so.tris.size(); t += 3) {
            for (int k = 0; k < 3; k++) {
                uint16_t idx = so.tris[t + k];
                size_t poolIdx = (size_t)so.verticeref_start + idx;
                float x=0, y=0, z=0, u=0, v=0;
                if (poolIdx < indexedVertices.size()) {
                    uint16_t base = indexedVertices[poolIdx];
                    if ((size_t)base * 3 + 2 < vertices.size()) {
                        x = vertices[(size_t)base * 3 + 0];
                        y = vertices[(size_t)base * 3 + 1];
                        z = vertices[(size_t)base * 3 + 2];
                    }
                    if (hasUVs && poolIdx * 2 + 1 < vertuv.size()) {
                        u = vertuv[poolIdx * 2 + 0];
                        v = vertuv[poolIdx * 2 + 1];
                    }
                }
                out.push_back(x); out.push_back(y); out.push_back(z);
                out.push_back(df);
                out.push_back(u); out.push_back(v);
                vc++;
            }
        }
    }
    if (outVertCount) *outVertCount = vc;
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

// Parse the menu 3D logo model (Giants_logo_3D.gbs from xx_giants_logo_3d.gzp) and log its
// structure + verify the textured-tri builder. Confirms the parser handles the real logo asset.
bool LogoSelfTest() {
    auto data = VanillaVFS::GzpReadFile("Bin\\xx_giants_logo_3d.gzp", "Giants_logo_3D.gbs");
    if (data.empty()) {
        if (g_vTrace) { fprintf(g_vTrace, "[VGBS] logo: Giants_logo_3D.gbs not found\n"); fflush(g_vTrace); }
        return false;
    }
    Model m = Parse(data.data(), data.size());
    if (!m.ok) {
        if (g_vTrace) { fprintf(g_vTrace, "[VGBS] logo: parse FAILED (magic=%08x)\n", m.magic); fflush(g_vTrace); }
        return false;
    }
    size_t vc = 0;
    auto tris = m.buildTexturedTris(&vc);
    if (g_vTrace) {
        fprintf(g_vTrace, "[VGBS] logo OK: magic=%08x verts=%u nverts=%u subobjs=%u bbox=(%.1f..%.1f, %.1f..%.1f, %.1f..%.1f)\n",
                m.magic, m.numVertices, m.nverts, m.numSubObjects,
                m.bboxMin[0], m.bboxMax[0], m.bboxMin[1], m.bboxMax[1], m.bboxMin[2], m.bboxMax[2]);
        for (size_t i = 0; i < m.subObjectNames.size() && i < 6; i++)
            fprintf(g_vTrace, "   subobj[%zu] '%s' tex='%s' tris=%u\n", i,
                    i < m.subObjectNames.size() ? m.subObjectNames[i].c_str() : "",
                    i < m.texNames.size() ? m.texNames[i].c_str() : "",
                    i < m.subObjs.size() ? m.subObjs[i].totaltris : 0);
        fprintf(g_vTrace, "[VGBS] logo buildTexturedTris: %zu verts (%zu floats), expected %u verts\n",
                vc, tris.size() / 6, m.numVertices);
        fflush(g_vTrace);
    }
    return vc > 0;
}

} // namespace VanillaGBS
