// Giants Engine - UI/Console Linked List Operations
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── UI list node (0x38 = 56 bytes) ───────────────────────────
struct UIListNode {
    UIListNode* next;     // +0x00
    uint32_t field_04;    // +0x04
    uint32_t id;          // +0x08
    uint32_t flags;       // +0x0C
    float x;              // +0x10
    float y;              // +0x14
    uint32_t field_18;    // +0x18
    uint32_t field_1C;    // +0x1C
    uint32_t field_20;    // +0x20
    uint32_t field_24;    // +0x24
    char* text;           // +0x28
    uint32_t field_2C;    // +0x2C
    uint32_t type;        // +0x30
    uint32_t field_34;    // +0x34
};

// ─── AppendUIListNode (FUN_004d3bf0) ──────────────────────────
// Appends a new node to a UI/console linked list.
// Handles text copy (flag 0x1 = strdup, otherwise pointer assign),
// string ID lookup (flag 0x2000000), type selection (flag 0x1000000).
// 54 callers — UI/console text list management.
//
// @param head   Pointer to list head (nullptr-safe)
// @param id     Node ID
// @param flags  Bit flags controlling text handling and type
// @param text   Text string (or string ID if flag 0x2000000 set)
// @param x      X position
// @param y      Y position
void AppendUIListNode(UIListNode** head, uint32_t id, uint32_t flags,
                       char* text, float x, float y);  // FUN_004d3bf0

} // namespace Giants
