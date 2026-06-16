// Giants Vanilla-Native Recomp — localized-text lookup. See VanillaText.h.
#include "VanillaText.h"
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <windows.h>

extern FILE* g_vTrace;

namespace VanillaText {

static std::vector<uint8_t> g_buf;       // the whole file in memory
static uint32_t g_count = 0;
static uint32_t g_keyBase = 0;           // offset of key region
static uint32_t g_valBase = 0;           // offset of value region
static bool g_loaded = false;

static uint32_t rdU32(const uint8_t* p) {
    return uint32_t(p[0]) | (uint32_t(p[1])<<8) | (uint32_t(p[2])<<16) | (uint32_t(p[3])<<24);
}

bool Load(const char* lang) {
    g_loaded = false;
    g_buf.clear();
    // GText<Lang>.bin is a loose file in Bin\.
    char path[64];
    snprintf(path, sizeof(path), "Bin\\GText%s.bin", lang);
    HANDLE fh = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
    if (fh == INVALID_HANDLE_VALUE) { if (g_vTrace) { fprintf(g_vTrace, "[VTEXT] %s not found\n", path); fflush(g_vTrace); } return false; }
    LARGE_INTEGER sz; GetFileSizeEx(fh, &sz);
    g_buf.resize((size_t)sz.QuadPart);
    DWORD got = 0; ReadFile(fh, g_buf.data(), (DWORD)g_buf.size(), &got, nullptr);
    CloseHandle(fh);
    if (got < 12) return false;
    g_count   = rdU32(g_buf.data() + 0);
    uint32_t keySize = rdU32(g_buf.data() + 4);
    g_keyBase = 12 + g_count * 8;
    g_valBase = g_keyBase + keySize;
    g_loaded = true;
    if (g_vTrace) {
        fprintf(g_vTrace, "[VTEXT] loaded %s: %u entries, keyBase=%u valBase=%u\n",
                path, g_count, g_keyBase, g_valBase);
        fflush(g_vTrace);
    }
    return true;
}

static const char* regionStr(uint32_t regionBase, uint32_t off) {
    if (!g_loaded || regionBase + off >= g_buf.size()) return "";
    return (const char*)(g_buf.data() + regionBase + off);   // null-terminated within region
}

const char* Lookup(const char* key) {
    if (!g_loaded || !key) return "";
    for (uint32_t i = 0; i < g_count; i++) {
        uint32_t ko = rdU32(g_buf.data() + 12 + i * 8);
        const char* k = regionStr(g_keyBase, ko);
        if (strcmp(k, key) == 0) {
            uint32_t vo = rdU32(g_buf.data() + 12 + i * 8 + 4);
            return regionStr(g_valBase, vo);
        }
    }
    return "";
}

} // namespace VanillaText
