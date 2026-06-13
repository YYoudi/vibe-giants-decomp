// Giants Engine - Present Frame (render pipeline)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── PresentFrame (FUN_00541860) ── PASS ──
// Full render present pipeline: TLS init, BeginScene, SetRenderTargets,
// ExecuteDeferred, FlushCommandQueue, EndFrame, vtable Begin/End,
// PrePresent, PostPresent. Handles first-time init vs per-frame paths.
// 21 callers, ~12 callees.
void PresentFrame();  // FUN_00541860

} // namespace Giants
