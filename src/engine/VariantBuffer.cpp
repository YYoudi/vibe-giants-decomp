// Giants Engine - Variant Buffer Operations Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VariantBuffer.h"
#include <cstdlib>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// CleanupVariantBuffer (FUN_004d3a50) — 44 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Cleans up a variant buffer based on its type field at offset +4.
//
// VariantBuffer layout:
//   +0x04  type (0, 2, or 3)
//   +0x0c  flags (bit 0 = ownership)
//   +0x28  data pointer 1 (linked-list head for type 3, buffer for type 0)
//   +0x2c  data pointer 2 (alternate buffer for type 2)
//
// type 3: Walks linked list, frees each node
// type 0: Frees single buffer if ownership flag set
// type 2: Frees alternate buffer if ownership flag set

void CleanupVariantBuffer(uint32_t /*param_1*/, int* param_2)
{
    int type = param_2[1];  // offset +0x04

    if (type == 3)
    {
        // Linked-list cleanup: walk and free each node
        int* current = reinterpret_cast<int*>(param_2[10]);  // +0x28
        if (current != nullptr)
        {
            int* next;
            do
            {
                next = reinterpret_cast<int*>(*current);
                free(current);
                current = next;
            } while (next != nullptr);
        }
    }
    else if (type == 0)
    {
        // Single allocation cleanup with ownership flag
        if ((reinterpret_cast<uint8_t*>(param_2)[12] & 1) != 0)  // +0x0c bit 0
        {
            free(reinterpret_cast<void*>(param_2[10]));  // +0x28
        }
    }
    else if (type == 2)
    {
        // Alternate buffer cleanup with ownership flag
        if ((reinterpret_cast<uint8_t*>(param_2)[12] & 1) != 0)  // +0x0c bit 0
        {
            free(reinterpret_cast<void*>(param_2[11]));  // +0x2c
        }
    }
}

} // namespace Giants
