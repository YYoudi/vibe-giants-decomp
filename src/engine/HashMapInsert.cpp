// Giants Engine - HashMap Insert Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "HashMapInsert.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// HashMapInsert (FUN_004d5150) — 22 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Inserts a new key-value entry into a linked-list hashmap.
// Node layout (20 + strlen+1 bytes):
//   [+0]  next node pointer (initially NULL)
//   [+4]  value (param_4)
//   [+8]  flags (initially 0)
//   [+12] string key data (strcpy from param_3)
// Entry layout:
//   [+0]  next entry pointer (linked list)
//   [+8]  key (int param_2)
//   [+10] tail pointer to node list
//   [+24] flags (bit 9 = has nodes)

void HashMapInsert(int* root, int key, const char* strValue, uint32_t value)
{
    int* entry = reinterpret_cast<int*>(*root);
    if (entry == nullptr) {
        return;
    }

    // Walk linked list to find matching key
    while (entry[2] != key) {
        entry = reinterpret_cast<int*>(*entry);
        if (entry == nullptr) {
            return;
        }
    }

    // Find tail of node list at entry[10]
    int* tail = reinterpret_cast<int*>(entry[10]);
    int** tailPtr = reinterpret_cast<int**>(&entry[10]);
    while (tail != nullptr) {
        tailPtr = reinterpret_cast<int**>(tail);
        tail = reinterpret_cast<int*>(*tail);
    }

    // Measure string length
    const char* scan = strValue;
    char c;
    do { c = *scan; scan++; } while (c != '\0');

    // Allocate node: 4 uint32_t fields + string data
    size_t strLen = static_cast<size_t>(scan - strValue - 1);
    size_t allocSize = 16 + strLen + 1;
    uint32_t* node = static_cast<uint32_t*>(malloc(allocSize));

    // Initialize node
    *node = 0;                  // next = NULL
    node[3] = reinterpret_cast<uint32_t>(node + 4);  // self-ref to string area
    node[1] = value;            // store value
    node[2] = 0;                // flags = 0

    // Copy string into node
    char* dst = reinterpret_cast<char*>(node + 4);
    const char* src = strValue;
    do {
        c = *src;
        src++;
        dst[src - strValue - 1] = c;
    } while (c != '\0');

    // Link node to tail
    *reinterpret_cast<int*>(tailPtr) = reinterpret_cast<int>(node);

    // Set flag on entry
    entry[3] = entry[3] | 0x200;
}

} // namespace Giants
