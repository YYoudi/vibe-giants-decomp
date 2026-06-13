// Giants Engine - Game Loop (FUN_0062d100)
// The heart of the engine: window creation, subsystem init, frame loop
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Architecture:
//   1. Zero-init globals (memset 0x110 bytes)
//   2. InitGlobals(), SetProcessAffinityMask()
//   3. RegisterWndProc, InitMemory, InitCriticalSection
//   4. CheckProcessorSupport() - SSE2/AVX validation
//   5. RegisterClassA("GiantsWinClass"), CreateWindowExA("Giants")
//   6. InitializeEngine() - loads renderers, VFS, audio
//   7. Main loop: UpdateFrame -> RenderFrame -> PresentFrame -> ProcessGameLogic
//   8. Cleanup: COM Release, audio shutdown, renderer free

#pragma once

#include <windows.h>
#include <cstdint>

namespace Giants {

// Frame pipeline functions (called each frame by MainGameLoop)
bool ProcessRawKeyboardInput(); // FUN_0062aac0 - DirectInput keyboard polling
void UpdateTime();              // FUN_00629f50 - frame delta / time scaling
uint32_t ProcessMouseInput();   // FUN_0062abe0 - mouse input + bit-grid op
uint32_t ProcessGameLogic();    // FUN_00524f30 - AI, render pipeline, gameplay rules

// Lifecycle
void OnQuitRequested();      // FUN_00540770
void CleanupNetwork();       // FUN_004f86c0
void SaveGameState();        // FUN_004dff90
void FlushGameData();        // FUN_004dfe20
void ShutdownAudio();        // FUN_005c4d20

// Subsystem init
void InitGlobals();          // FUN_0062d590 - zero and set defaults
void InitMemory(void*);      // FUN_006403f0 - memory allocator init
void InitCriticalSection();  // FUN_00640030 - threading
void RegisterWndProc(void*); // FUN_00640160 - window proc registration
char CheckProcessorSupport();// FUN_006391d0 - SSE2/AVX check
int  InitializeEngine();     // FUN_0062e1a0 - renderer + audio + VFS init

// Window procedure
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Key globals (from .data section)
extern HWND      g_hWnd;               // DAT_007281d8
extern HINSTANCE g_hInstance;           // DAT_007281dc
extern HACCEL    g_hAccelTable;        // DAT_007281e0
extern int       g_shutdownRequested;  // DAT_007281e4
extern int       g_renderInitialized;  // DAT_007281d4
extern int       g_gameState;          // DAT_006866c4 (0=idle, 1=running, 3=quitting)

// The main game loop
uint32_t MainGameLoop(HINSTANCE hInstance, uint32_t param2, int nCmdShow);

} // namespace Giants
