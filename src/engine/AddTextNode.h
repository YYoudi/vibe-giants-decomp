// Giants Engine - Add Text Node (UI text list builder)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── AddTextNode (FUN_004d4710) ── PASS ──
// Appends a text node to a linked list. Allocates 0x30 byte node, optionally
// copies string (flag bit 0), resolves hash (flag bit 25), computes text
// width via font scale.
// 12 callers, ~3 callees.
struct TextNode { TextNode* next; uint32_t type; uint32_t id; uint32_t flags; float x, y, width; float f1C, f20, f24, f28; char* text; };
void AddTextNode(TextNode** head, uint32_t id, uint32_t flags, char* text, float x, float y);  // FUN_004d4710

} // namespace Giants
