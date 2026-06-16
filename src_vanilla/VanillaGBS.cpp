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
    pos += (size_t)m.nverts * 2;          // indexed_vertices u16
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
        char objname[33] = {0}; memcpy(objname, data + pos, 32); pos += 32;
        m.subObjectNames.push_back(objname);
        if (pos + 16 > len) break;
        pos += 4;                       // maxobjindex
        uint32_t totaltris = rdU32(data + pos); pos += 4;
        uint32_t ntris = rdU32(data + pos); pos += 4;
        pos += 8;                       // verticeref_start, verticeref_count
        // tridata RLE: [count:u16][count*3 u16]
        // ntris here = number of u16 "triples"? Walk conservatively.
        // (Full RLE decode deferred — just skip the tridata block.)
        pos += (size_t)ntris * 2;
        if (m.hasUVs) {
            char tex[33]={0}, bump[33]={0};
            if (pos+64<=len){ memcpy(tex,data+pos,32); memcpy(bump,data+pos+32,32); m.texNames.push_back(tex); }
            pos += 64; pos += 4;        // texname+bumpname + falloff
        } else { pos += 4; }            // falloff
        if (m.hasRGBs) pos += 4;        // blend
        pos += 4;                       // flags
        pos += 16;                      // emissive/ambient/diffuse/specular
        pos += 4;                       // power
    }
    m.ok = true;
    return m;
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
