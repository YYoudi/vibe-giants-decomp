// Giants Engine - Wide String Copy Constructor & Free Buffer
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── WideStringCopyConstruct (FUN_00443070) ── PASS ──
// MSVC std::wstring copy constructor. SSO-aware: copies inline
// for size < 8 wchars, allocates heap otherwise. 31 callers.
void WideStringCopyConstruct(void* dst, const void* src);  // FUN_00443070

// ─── FreeBufferAndDecrement (FUN_00480d00) ── PASS ──
// Frees a buffer at (param_1+8) if non-null, decrements counter
// at DAT_00701a3c+0x370. Trivial 6-line function. 31 callers.
void FreeBufferAndDecrement(int param_1);  // FUN_00480d00

// ─── ProcessString (FUN_0042fed0) ── PASS ──
// String processing with state machine: initializes buffer on first
// call (state 0->1), processes string on state 1, throws on others.
// 30 callers, 11 callees.
void ProcessString(char* stateObj, char* input);  // FUN_0042fed0

// ─── RenderSprite (FUN_005d79a0) ── PASS ──
// Renders a sprite with scale, rotation, and viewport projection.
// Handles depth scaling, aspect ratio correction, and vertex transforms.
// 30 callers, 2 callees.
void RenderSprite(int spriteData, int renderEntry, uint32_t flags,
                  float width, float posY, float height);  // FUN_005d79a0

} // namespace Giants
