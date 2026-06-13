// Giants Engine - Display Mode & Font Initialization
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062b9c0 — GDI-based font/text system initialization
// FUN_005de6b0 — Bounding box computation for display objects

#pragma once

#include <cstdint>

namespace Giants {

// ─── InitDisplayMode (FUN_0062b9c0) — FAIL (usable ~50%) ───────
// Initializes GDI text rendering: creates DC, DIB section (128x64 monochrome),
// LOGFONT, and glyph bitmap buffer (64KB). 10 callers, 14 callees.
void InitDisplayMode();     // FUN_0062b9c0

// ─── ComputeBoundingBox (FUN_005de6b0) — FAIL (usable ~55%) ────
// Computes axis-aligned bounding box from linked list of display objects.
// Iterates mesh vertex data to find min/max extents.
// 2 callers, 2 callees.
void ComputeBoundingBox(int* params);   // FUN_005de6b0

} // namespace Giants
