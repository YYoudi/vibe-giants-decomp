// Giants Vanilla-Native Recomp — VFS data layer (GZP reader). See VanillaVFS.h.
#include "VanillaVFS.h"
#include <cctype>
#include <algorithm>

extern FILE* g_vTrace;   // global trace (defined in WinMain_vanilla.cpp)

namespace VanillaVFS {

static uint32_t rdU32(FILE* f) {
    uint8_t b[4];
    if (fread(b, 1, 4, f) != 4) return 0xFFFFFFFFu;
    return uint32_t(b[0]) | (uint32_t(b[1]) << 8) | (uint32_t(b[2]) << 16) | (uint32_t(b[3]) << 24);
}

bool LzDecompress(const uint8_t* src, size_t srcLen, uint8_t* out, size_t originalSize) {
    // Faithful port of gck-map-extract-objects/lib/fileutils.py:decompress.
    if (originalSize == 0) return true;
    size_t i = 0, j = 0;
    uint8_t decByte = 0;
    int decBits = 8;
    const uint32_t buffStart = 0xFEE;
    while (j < originalSize) {
        if (decBits == 8) {
            if (i >= srcLen) return false;
            decByte = src[i++];
            decBits = 0;
        }
        if (((decByte >> decBits) & 1) == 0) {
            // backref
            if (i + 1 >= srcLen) return false;
            uint8_t b0 = src[i];
            uint8_t b1 = src[i + 1];
            long decPos = (((b0 + ((b1 & 0xF0) << 4) - (long)buffStart - (long)j) & 0xFFF) - 0x1000 + (long)j);
            int decLen = (b1 & 0xF) + 3;
            i += 2;
            while (decLen > 0) {
                if (decPos >= 0) out[j] = out[decPos];
                else out[j] = 0x20;   // space (window underflow)
                j++; decPos++; decLen--;
                if (j >= originalSize) break;
            }
        } else {
            // literal
            if (i >= srcLen) return false;
            out[j++] = src[i++];
        }
        decBits++;
    }
    return true;
}

static std::string lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return (char)tolower(c); });
    return s;
}

bool GzpOpen(const char* path, std::vector<GzpEntry>& outEntries) {
    FILE* f = fopen(path, "rb");
    if (!f) return false;
    uint32_t magic = rdU32(f);
    if (magic != 0x6608F101u) { fclose(f); return false; }
    uint32_t metaOff = rdU32(f);
    if (fseek(f, metaOff, SEEK_SET) != 0) { fclose(f); return false; }
    rdU32(f);                  // unk
    uint32_t count = rdU32(f);
    outEntries.clear();
    outEntries.reserve(count);
    for (uint32_t e = 0; e < count; e++) {
        GzpEntry en;
        en.compSize  = rdU32(f);
        en.uncmpSize = rdU32(f);
        en.date      = rdU32(f);
        en.start     = rdU32(f);
        uint8_t hdr[2];
        if (fread(hdr, 1, 2, f) != 2) { fclose(f); return false; }
        en.compr = hdr[0];
        uint8_t nameLen = hdr[1];
        char nameBuf[256] = {0};
        if (nameLen) fread(nameBuf, 1, nameLen, f);   // nameLen bytes (no path, w/ ext)
        // The reference reads until null; entries are nameLen bytes possibly + null.
        en.name = std::string(nameBuf, nameLen);
        // strip a trailing null if present
        if (!en.name.empty() && en.name.back() == '\0') en.name.pop_back();
        outEntries.push_back(en);
    }
    fclose(f);
    return true;
}

std::vector<uint8_t> GzpReadFile(const char* archivePath, const char* fileName) {
    std::vector<GzpEntry> entries;
    if (!GzpOpen(archivePath, entries)) return {};
    std::string want = lower(fileName);
    for (const auto& en : entries) {
        if (lower(en.name) == want) {
            FILE* f = fopen(archivePath, "rb");
            if (!f) return {};
            // content at start+16 (16-byte per-file sub-header skipped).
            if (fseek(f, (long)en.start + 16, SEEK_SET) != 0) { fclose(f); return {}; }
            std::vector<uint8_t> comp(en.compSize);
            if (en.compSize && fread(comp.data(), 1, en.compSize, f) != en.compSize) { fclose(f); return {}; }
            fclose(f);
            std::vector<uint8_t> out(en.uncmpSize);
            if (en.compr == 0 || en.compr == 2) {
                // stored raw (compr 0 and 2 = uncompressed; 1 = LZ). compr=2 files have
                // compSize = uncmpSize + 16 (a 16-byte trailer/prefix) — copy uncmpSize.
                if (en.uncmpSize <= en.compSize) memcpy(out.data(), comp.data(), en.uncmpSize);
                else return {};
            } else {
                if (!LzDecompress(comp.data(), comp.size(), out.data(), en.uncmpSize)) return {};
            }
            return out;
        }
    }
    return {};
}

int SelfTest(const char* archivePath) {
    std::vector<GzpEntry> entries;
    if (!GzpOpen(archivePath, entries)) {
        if (g_vTrace) { fprintf(g_vTrace, "[VVFS] GZP open FAILED: %s\n", archivePath); fflush(g_vTrace); }
        return 0;
    }
    if (g_vTrace) {
        fprintf(g_vTrace, "[VVFS] GZP %s: %u entries\n", archivePath, (unsigned)entries.size());
        for (size_t i = 0; i < entries.size() && i < 8; i++) {
            fprintf(g_vTrace, "   [%u] %-28s comp=%u unc=%u start=%u compr=%u\n",
                    (unsigned)i, entries[i].name.c_str(), entries[i].compSize, entries[i].uncmpSize,
                    entries[i].start, entries[i].compr);
        }
        fflush(g_vTrace);
    }
    // Decompress the first compressed entry to validate the LZ codec end-to-end.
    for (const auto& en : entries) {
        if (en.compr != 0 && en.uncmpSize > 0 && en.uncmpSize < 4 * 1024 * 1024) {
            auto data = GzpReadFile(archivePath, en.name.c_str());
            if (!data.empty()) {
                if (g_vTrace) {
                    fprintf(g_vTrace, "[VVFS] decompressed '%s': %zu bytes OK (first16: %02x%02x%02x%02x %02x%02x%02x%02x)\n",
                            en.name.c_str(), data.size(),
                            data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
                    fflush(g_vTrace);
                }
            } else {
                if (g_vTrace) { fprintf(g_vTrace, "[VVFS] decompress FAILED: %s\n", en.name.c_str()); fflush(g_vTrace); }
            }
            break;
        }
    }
    return (int)entries.size();
}

} // namespace VanillaVFS
