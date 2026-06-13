// Giants Engine - Game Command Dispatcher
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── DispatchGameCommand (FUN_005d8fb0) ───────────────────────
// Interprets and dispatches a game command based on opcode type.
// Handles multiple command types (0, 0x39-0x40 range, etc.).
// Computes text display parameters and calls rendering functions.
// 65 callers — game script/command interpreter.
//
// @param param_1  Game state context (entity/system pointer)
// @param param_2  Command parameters (entity props array)
// @param param_3  Command mode (0 = execute)
// @param param_4  Command descriptor (opcode at +4)
// @return         0xFFFFFF on success, -1 on special opcodes
int DispatchGameCommand(int param_1, uint32_t* param_2, int param_3, int param_4);  // FUN_005d8fb0

// ─── DispatchGameCommandAlt (FUN_005d92d0) ─────────────────────
// Variant of DispatchGameCommand with different opcode ranges.
// Opcodes: 0x32-0x35 special, 0, 0x31, 0x36-0x38 with text spacing.
// Uses FUN_00548260 instead of FUN_005474a0 for entity name lookup.
// 57 callers — second game command interpreter.
int DispatchGameCommandAlt(int param_1, uint32_t* param_2, int param_3, int param_4);  // FUN_005d92d0

} // namespace Giants
