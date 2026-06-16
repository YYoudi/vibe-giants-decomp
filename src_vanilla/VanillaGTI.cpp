// Giants Vanilla-Native Recomp — GTI terrain parser. See VanillaGTI.h.
#include "VanillaGTI.h"
#include "VanillaVFS.h"
#include <cstdio>
#include <cstring>
#include <algorithm>

extern FILE* g_vTrace;

namespace VanillaGTI {

static float rdF32(const uint8_t* p) {
    float f; memcpy(&f, p, 4); return f;
}
static uint32_t rdU32(const uint8_t* p) {
    return uint32_t(p[0]) | (uint32_t(p[1])<<8) | (uint32_t(p[2])<<16) | (uint32_t(p[3])<<24);
}

Terrain Parse(const uint8_t* data, size_t len) {
    Terrain t;
    if (len < 96) return t;
    t.sig     = rdU32(data + 0);
    if (t.sig != 0x94965003u) return t;
    t.xOff    = rdF32(data + 8);
    t.yOff    = rdF32(data + 12);
    t.minH    = rdF32(data + 16);
    t.maxH    = rdF32(data + 20);
    t.width   = rdU32(data + 24);
    t.height  = rdU32(data + 28);
    t.stretch = rdF32(data + 32);
    uint16_t ver; memcpy(&ver, data + 56, 2); t.version = ver;
    memcpy(t.texname, data + 68, 32); t.texname[32] = 0;

    if (t.width == 0 || t.height == 0 || t.width > 4096 || t.height > 4096) return t;
    size_t total = (size_t)t.width * t.height;
    t.cells.resize(total);

    // RLE decode from offset 96. Default cell = (minH, 0, 0,0,0).
    Cell defCell{ t.minH, 0, 0, 0, 0 };
    size_t pos = 96;
    for (size_t i = 0; i < total; ) {
        if (pos >= len) break;
        uint8_t b = data[pos++];
        if (b >= 0x80) {
            size_t skip = 256 - b;
            for (size_t k = 0; k < skip && i < total; k++) t.cells[i++] = defCell;
        } else {
            size_t n = b + 1;
            for (size_t k = 0; k < n && i < total; k++) {
                if (pos + 8 > len) { t.cells[i++] = defCell; continue; }
                Cell c;
                memcpy(&c.height, data + pos, 4); pos += 4;
                c.triFlag = data[pos++]; c.r = data[pos++]; c.g = data[pos++]; c.b = data[pos++];
                t.cells[i++] = c;
            }
        }
    }
    t.ok = true;
    return t;
}

bool SelfTest() {
    auto data = VanillaVFS::GzpReadFile("Bin\\w_intro_island.gzp", "intro_island.gti");
    if (data.empty()) {
        // try via file API path / direct
        if (g_vTrace) { fprintf(g_vTrace, "[VGTI] intro_island.gti not found\n"); fflush(g_vTrace); }
        return false;
    }
    Terrain t = Parse(data.data(), data.size());
    if (!t.ok) {
        if (g_vTrace) { fprintf(g_vTrace, "[VGTI] parse FAILED (sig=%08x)\n", t.sig); fflush(g_vTrace); }
        return false;
    }
    float lo = 1e30f, hi = -1e30f;
    for (auto& c : t.cells) { lo = std::min(lo, c.height); hi = std::max(hi, c.height); }
    if (g_vTrace) {
        fprintf(g_vTrace, "[VGTI] intro_island.gti: %ux%u stretch=%.2f minH=%.2f maxH=%.2f ver=%u tex='%s' cells=%zu hrange=[%.2f..%.2f]\n",
                t.width, t.height, t.stretch, t.minH, t.maxH, t.version, t.texname, t.cells.size(), lo, hi);
        // sample center cell
        size_t mid = (size_t)(t.height / 2) * t.width + (t.width / 2);
        fprintf(g_vTrace, "   center cell h=%.2f triFlag=%u rgb=%u,%u,%u\n",
                t.cells[mid].height, t.cells[mid].triFlag, t.cells[mid].r, t.cells[mid].g, t.cells[mid].b);
        fflush(g_vTrace);
    }
    return true;
}

} // namespace VanillaGTI
