// Giants Vanilla-Native Recomp — FUN_00476d40 (makewrld.c) world/terrain builder.
//
// Faithful 1:1 port of vanilla Giants.exe's FUN_00476d40 (3216 bytes), the
// post-load world/terrain builder ("C:\Giants\Source\main\makewrld.c").
//
// SOURCED ENTIRELY FROM: vanilla_decompiled/00476d40.json (Ghidra body).
//   - Every world_state (DAT_006316ec) field write is preserved.
//   - The version switch (magic -0x6b69afff / -ffe / -ffd) is preserved.
//   - The bounding-box copy loop (count @ +0x204, array @ +0x208, stride 0x38)
//     is preserved.
//   - The terrain dims/origin/color-bit writes (+0x1cc..0x1e4, +0x48, +0x1c)
//     and the _DAT_005522c0 = 1.0f float math are preserved.
//   - The texture (FUN_0050e3c0) and bump-texture clone paths are preserved.
//   - The terrain-cell decode (RLE run/byte cases) is preserved.
//   - The cell-render-flag switch (cases 1..7) and the per-cell "alpha bit"
//     stencil scan at the tail are preserved.
//
// CONVENTIONS:
//   - extern "C" / __cdecl everywhere (matches VanillaSceneLists/SceneLoad).
//   - Unported callees are declared extern "C" and called verbatim with a
//     `// FIXME(unverified): callee <addr>` tag.
//   - DAT_/string globals are extern-declared at their vanilla addresses so
//     they link back to a single definition (see VanillaStubs.cpp).
#pragma once
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// FUN_00476d40 — void FUN_00476d40(const char* levelName)
// ============================================================================
// Post-load world/terrain builder ("makewrld"). Called from the scene-load
// path after the .gti + world_data buffers are on disk:
//   - allocates the 0x200-byte scratch buffer at DAT_0059cc40;
//   - loads world_data via FUN_0053a3e0(levelName, &streamPtr, &ok);
//   - validates the version magic and dispatches (0x49500 / 0x49501 / 0x49502);
//   - reads N bounding boxes (world_state+0x204 count, +0x208 array, stride 0x38);
//   - writes terrain dims/origin/color bits to world_state+0x1cc..0x1e4, +0x48,
//     +0x1c, applies the _DAT_005522c0 (=1.0f) stretch/origin float math;
//   - resolves/installs three textures (+0x4ec4/+0x4ec8/+0x4ecc), optionally
//     clones each from its bump counterpart into +0x4ed0/+0x4ed4/+0x4ed8;
//   - decodes the heightfield grid into the World (DAT_006316ec)+0x0c array,
//     populates row pointers (+0x10), first/last non-empty column arrays
//     (+0x14/+0x18), then runs the per-cell render-flag switch;
//   - finally runs the small "alpha bit" stencil scan that marks +0x0e bytes.
void FUN_00476d40(const char* levelName);

#ifdef __cplusplus
} // extern "C"
#endif
