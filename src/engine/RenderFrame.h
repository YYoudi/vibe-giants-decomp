// Giants Engine - Main Render Frame
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RenderFrame (FUN_00541860) ── PASS ──
// Main render frame function. Handles TLS init, active rendering path
// (camera update, scene render, post-processing), and first-frame
// initialization. Dispatches to renderer based on present/render mode.
// 21 callers, 12 callees.
void RenderFrame();  // FUN_00541860

} // namespace Giants
