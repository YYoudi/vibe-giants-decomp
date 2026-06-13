// Giants Engine - String Pool Lookup Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringPool.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static uint32_t* g_StringPoolHashTable = nullptr;  // DAT_0074b820
static uint32_t* g_StringPoolChainHead = nullptr;  // DAT_0074b824

extern uint32_t HashString(const char* str);  // FUN_00632790

// ═══════════════════════════════════════════════════════════════════
// StringPoolLookup (FUN_005e99d0) — 32 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Hash-table-based string interning pool. Looks up string by hash;
// if not found, allocates entry with header (0x34 bytes) + string data.

void* StringPoolLookup(const char* str)
{
    if (str == nullptr)
        return nullptr;

    uint32_t hashVal = HashString(str);

    // Walk primary chain
    uint32_t* primary = g_StringPoolHashTable;
    while (true)
    {
        uint32_t* chain = g_StringPoolChainHead;

        if (primary == nullptr)
        {
            // Search chain by hash
            while (chain != nullptr)
            {
                if (chain[10] == hashVal)
                    return chain + 1;  // Return string data pointer

                chain = reinterpret_cast<uint32_t*>(*chain);
            }

            // Not found — allocate new entry
            const char* end = str;
            char c;
            do { c = *end; end++; } while (c != '\0');

            size_t strLen = end - str;
            size_t allocSize = strLen + 0x37;  // 0x38 header - 1 for null overlap
            uint32_t* entry = static_cast<uint32_t*>(malloc(allocSize));
            memset(entry, 0, allocSize);

            // Link into chain
            entry[0] = reinterpret_cast<uint32_t>(g_StringPoolChainHead);
            entry[1] = reinterpret_cast<uint32_t>(entry + 0xD);  // String data at +0x34
            g_StringPoolChainHead = entry;

            // Copy string into entry at offset [13] (0x34 bytes from start)
            memcpy(reinterpret_cast<char*>(entry + 0xD), str, strLen);

            // Set flag and hash
            entry[9] |= 0x1000;
            entry[10] = HashString(reinterpret_cast<const char*>(entry[1]));

            return entry + 1;
        }

        // Search collision chain within primary entry
        uint32_t count = primary[10];
        uint32_t idx = 0;

        if (count != 0)
        {
            int* entries = reinterpret_cast<int*>(primary + 0x14);
            do
            {
                if (*entries == static_cast<int>(hashVal))
                    return primary + idx * 0xC + 0xB;

                idx++;
                entries += 0xC;
            } while (idx < count);
        }

        if (idx < count)
            break;

        primary = reinterpret_cast<uint32_t*>(*primary);
    }

    return primary;
}

} // namespace Giants
