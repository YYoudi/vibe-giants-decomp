#pragma once
// Giants Engine - Main Entry Point & Initialization
// Reverse engineered from GiantsMain.exe v1.520.59 (FUN_00643daf, FUN_0062cd40)

namespace Giants {

// Forward declarations
class VFS;
class Renderer;
class GameLoop;

// Engine initialization sequence (FUN_0062cd40)
// Called from CRT entry point (FUN_00643daf) -> entry @ 0x00643f2e
bool EngineInitialize();

// Main game loop with Windows message pump (FUN_0062d100)
// Contains: Window creation, subsystem init, message loop, frame tick
int EngineRun();

} // namespace Giants
