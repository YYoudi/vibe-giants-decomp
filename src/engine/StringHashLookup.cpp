// Giants Engine - String Hash Lookup Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringHashLookup.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
// Packed string table: null-terminated string, then uint32_t value,
// repeated N times. Base pointer and count at global addresses.
static char**    g_stringTableBase = reinterpret_cast<char**>(0x00747d3c);  // DAT_00747d3c
static int*      g_stringTableCount = reinterpret_cast<int*>(0x00747d38);   // DAT_00747d38

// ═══════════════════════════════════════════════════════════════════
// StringHashLookup (FUN_004e9ab0) — 26 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Walks a packed string table comparing each entry (case-insensitive)
// with param_1. On match, returns the uint32_t immediately following
// the string. Returns 0xFFFFFFFF if not found.

uint32_t StringHashLookup(const char* name)
{
    int count = *g_stringTableCount;
    if (count <= 0)
        return 0xFFFFFFFF;

    char* ptr = *g_stringTableBase;
    char* entryStart = ptr;

    int idx = 0;
    do
    {
        // Skip past null terminator
        do
        {
            char c = *ptr;
            ptr++;
        } while (*(ptr - 1) != '\0');

        // Read the 4-byte value after the string
        uint32_t value = *reinterpret_cast<uint32_t*>(ptr);

        // Compare case-insensitively
        if (_stricmp(entryStart, name) == 0)
        {
            return value;
        }

        idx++;
        ptr += 4;
        entryStart = ptr;
    } while (idx < count);

    return 0xFFFFFFFF;
}

} // namespace Giants
