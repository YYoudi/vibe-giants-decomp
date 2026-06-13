// Giants Engine - Engine Lifecycle Stubs
// Reverse engineered from GiantsMain.exe v1.520.59
//
// PreInitCheck (FUN_005c45f0) — Full game initialization entry point
// ShutdownAudio (FUN_005c4d20) — Engine shutdown/cleanup
// InitGlobals (FUN_0062d590) — Command line parser + global defaults

#pragma once

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── PreInitCheck (FUN_005c45f0) — FAIL (usable ~80%) ───────────
// Full game initialization: logs version string, initializes COM,
// seeds random, creates COM objects (3 IUnknown-based with ref counting),
// validates game files via VFS, loads intro scene.
// 1 caller (InitializeEngine), 36 callees.
/// Returns 1 on success (proceeds to game loop), 0 on error.
int PreInitCheck();  // FUN_005c45f0

// ─── ShutdownAudio (FUN_005c4d20) — FAIL (usable ~75%) ──────────
// Full engine shutdown: releases COM objects, frees all allocated
// buffers, deletes critical sections, cleans up entity lists,
// calls CoUninitialize. 19 callees.
/// Returns 1 on completion.
int ShutdownAudio();  // FUN_005c4d20

// ─── InitGlobals (FUN_0062d590) — FAIL (usable ~70%) ────────────
// Command-line argument parser + global defaults initializer.
// Parses whitespace-delimited tokens, matches switch strings
// ("-window", "-dedicated", etc.), sets global flags.
// 28 callees. This is one of the most complex arg parsers.
void InitGlobals(char* commandLine);  // FUN_0062d590

// ─── InitCOMSubsystem (FUN_0042fc00) — PASS ──────────────────────
// Allocates 0x58-byte COM object, initializes refcount, registers with
// class factory at DAT_0073c924. Called during PreInitCheck Phase 4.
// 1 caller, 7 callees.
void InitCOMSubsystem();  // FUN_0042fc00

// ─── InitStringSubsystem (FUN_00443e20) — FAIL (usable ~70%) ────
// String subsystem init: allocates 0x14-byte COM object, registers with
// class factory. Called during PreInitCheck Phase 10.
// 1 caller, 5 callees.
/// Returns 0 on completion.
int InitStringSubsystem();  // FUN_00443e20

// ─── InitRenderObject (FUN_0044e140) — PASS ─────────────────────
// Initializes 0x34-field render object with vtable PTR_FUN_0065dce4.
/// @param param_1  Pointer to render object (0x34 uint32_t fields)
void InitRenderObject(uint32_t* param_1);  // FUN_0044e140

// ─── InitCriticalSectionSubsystem (FUN_004630d0) — FAIL (usable ~60%)
// Thread sync init: zeroes globals, creates critical sections, registers
// 4 COM objects with class factory. Called during PreInitCheck Phase 10.
// 1 caller, 8 callees.
int* InitCriticalSectionSubsystem();  // FUN_004630d0

// ─── CreateCOMInstance (FUN_0046fd40) — PASS (trivial) ──────────
// COM class factory helper: creates instance via vtable[2] dispatch.
/// @param param_1  Class ID (masked with ~(0xfffffffc) for alignment)
/// @return Pointer to 2-field [obj, classFactory] pair, or nullptr
int* CreateCOMInstance(uint32_t param_1);  // FUN_0046fd40

// ─── InitAudioObject (FUN_00471ba0) — PASS ──────────────────────
// Initializes audio COM object (vtable PTR_FUN_00660260), inits driver,
/// sets flags, configures audio.
/// @param param_1  Pointer to audio object (6 uint32_t fields)
/// @return param_1
uint32_t* InitAudioObject(uint32_t* param_1);  // FUN_00471ba0

// ─── LoadDisplaySettings (FUN_00561a70) — PASS ──────────────────
// Reads video settings from Windows registry: resolution, antialiasing,
// windowed mode, vsync, triple buffering, aspect ratio, device/driver GUIDs.
// Uses LockGraphics/UnlockGraphics for registry access.
// 1 caller, 5 callees.
void LoadDisplaySettings();  // FUN_00561a70

// ─── LoadProjectileDefs (FUN_0056f920) — FAIL (usable ~65%) ─────
// Loads "wdefs.bin" weapon definitions from VFS. Creates COM object,
/// validates checksum. On failure sets DAT_007281e4 = 1.
// 1 caller, 19 callees.
int* LoadProjectileDefs();  // FUN_0056f920

// ─── LoadGameObjDefs (FUN_00575e10) — PASS ──────────────────────
// Parses "GameObj.bin" game object definitions. Byte-oriented records
// with type codes 1-9, each followed by two null-terminated strings.
// 1 caller, 7 callees.
void LoadGameObjDefs();  // FUN_00575e10

// ─── LoadGDataFile (FUN_00576050) — FAIL (usable ~65%) ──────────
// Loads "GData.gbn" game data binary: two integer arrays with checksum
// validation. Allocates/reuses buffers at DAT_007028f4/028fc.
// 1 caller, 10 callees.
void LoadGDataFile();  // FUN_00576050

// ─── LoadWorldData (FUN_005791c0) — FAIL (usable ~60%) ──────────
// Massive world data loader (~2000 lines Ghidra). Opens worlds binary,
/// validates version, loads skybox/textures/lights/entities.
// 2 callers, 38 callees.
/// @param param_1  World file path (as float* due to Ghidra typing)
/// @return Pointer to loaded world data
float* LoadWorldData(float* param_1);  // FUN_005791c0

// ─── DispatchSceneCommand (FUN_0057ce00) — PASS ─────────────────
// Packs (opcode, string, value) into struct and calls FUN_00444db0.
/// @param param_1  Command opcode
/// @param param_2  String parameter
/// @param param_3  Value parameter
/// @return param_1
uint32_t DispatchSceneCommand(uint32_t param_1, char* param_2, uint32_t* param_3);  // FUN_0057ce00

// ─── ClearLinkedList (FUN_005e8720) — PASS ──────────────────────
// Clears intrusive doubly-linked list: walks nodes, frees 0x24-byte blocks,
/// resets sentinel. 5 callers, 4 callees.
/// @param param_1  List container (offset +4 = sentinel, +8 = count)
void ClearLinkedList(int param_1);  // FUN_005e8720

// ─── CleanupEntityListA (FUN_006259b0) — PASS ───────────────────
// Walks entity list, frees 0x24-byte node extensions, then clears list.
/// @param param_1  List container
void CleanupEntityListA(int param_1);  // FUN_006259b0

// ─── CleanupEntityListB (FUN_006259f0) — PASS ───────────────────
// Walks entity list, frees 0x1C-byte node extensions, then clears list.
/// @param param_1  List container
void CleanupEntityListB(int param_1);  // FUN_006259f0

// ─── InitMathTables (FUN_00638e40) — PASS ───────────────────────
// Builds sin (0x5000 entries), 1/sin (0x4000), acos (0x4000) lookup tables
/// using SSE2 sin/acos. Sets cos table base pointer.
// 1 caller, 2 callees.
void InitMathTables();  // FUN_00638e40

// ─── DisplayCleanup (FUN_0062be00) — PASS (trivial) ─────────────
// Releases GDI resources (font, bitmap, DC), renderer surface, and buffer.
/// Guards with DAT_0074beb0 flag. 8 callers, 4 callees.
void DisplayCleanup();  // FUN_0062be00

} // namespace Giants
