// Giants Engine - Set Sprite Attribute
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SetSpriteAttribute (FUN_00451460) ── PASS ──
// Sets an attribute value on a sprite entry. Looks up sprite by ID
// in a table manager (index = (id >> 13) & 0x7f, sub = id & 0x1fff).
// Validates entry != 0xfffff, then writes value at attributeIndex * 8.
// 17 callers, 1 callee (FUN_00451620).
void SetSpriteAttribute(uint32_t* spriteIdPtr, uint32_t value, int attributeIndex);  // FUN_00451460

} // namespace Giants
