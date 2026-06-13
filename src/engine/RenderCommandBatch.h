// Giants Engine - Render Command Batch Processor
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ProcessRenderCommands (FUN_004e0b70) ── PASS ──
// Processes a batch of 0x18-byte render commands from a circular buffer.
// Mode 0 (flag bit 1 clear): strips duplicate commands by comparing fields.
// Mode 1 (flag bit 1 set): fills color field with sequential IDs, marks last 0xFFFFFFFF.
// Uses render device vtable for state setup/teardown.
// 20 callers, 2 callees (FUN_004e06c0, FUN_00643f70).
void ProcessRenderCommands(uint32_t* cmdBuffer);  // FUN_004e0b70

} // namespace Giants
