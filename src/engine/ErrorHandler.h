// Giants Engine - Error Dialog Handler
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062edc0 — Error display system with in-game text rendering
// and MessageBoxA fallback.

#pragma once

#include <cstdint>

namespace Giants {

// ─── ShowErrorDialog (FUN_0062edc0) — FAIL (usable ~75%) ───────
// Displays an error screen using the game's text rendering pipeline.
// If renderer is unavailable, falls back to MessageBoxA.
// Renders: "Giants: Citizen Kabuto", error message, "Enter to Continue",
// "Escape to Exit Game". Loops polling input until user responds.
// Includes RenderDoc F12 capture support.
//
// @param param_1  Context pointer (this or object ref)
// @param param_2  Error message string (encoded)
void ShowErrorDialog(uint32_t param_1, uint32_t param_2);  // FUN_0062edc0

} // namespace Giants
