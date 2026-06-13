// Giants Engine - Present Frame Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "PresentFrame.h"
#include <cstring>

namespace Giants {

// ─── Global state variables ────────────────────────────────────
extern int       g_TlsIndex;           // DAT_0074ef14
extern void*     g_pRenderInterface;   // DAT_0074ef18
extern int       g_bActive;            // DAT_00702d5c
extern int       g_bInitialized;       // DAT_00702be8
extern int       g_bInFrame;           // DAT_00748a34
extern int       g_RenderTargetCount;  // DAT_00749000
extern int       g_DepthStencilCount;  // DAT_00749004
extern int       g_FrameIndex;         // DAT_0074b5fc
extern int       g_FrameTable;         // DAT_0074b5f8
extern int       g_FrameCount;         // DAT_00682e9c
extern int       g_PresentWidth;       // DAT_00702d60
extern int       g_PresentHeight;      // DAT_00681dd0
extern int       g_FrameState;         // DAT_00681db0
extern uint32_t  g_FrameFlags;         // DAT_00681db4
extern int       g_FrameCounter;       // DAT_00681dec
extern int       g_SubmitCounter;      // DAT_00681e34

// ─── External callees ──────────────────────────────────────────
extern void TlsInit(int* pTlsIndex);                   // FUN_006435f8
extern void RegisterAtExit(void* pContext);             // FUN_004ad590
extern void TlsRegisterCallback(void* callback);        // FUN_0064389d
extern void TlsAllocate(int* pTlsIndex);               // FUN_006435a7
extern void BeginScene();                               // FUN_0049a040
extern void SetRenderTargets();                         // FUN_004d5b50
extern void ClearRenderTarget();                        // FUN_004e9bb0
extern void ExecuteDeferred();                          // FUN_005d7de0
extern void FlushCommandQueue();                        // FUN_005dec20
extern void EndFrame();                                 // FUN_005401b0
extern void PrePresent(int extraout_ECX);               // FUN_005fa390
extern void PostPresent();                              // FUN_00565580

// TLS cleanup callback — LAB_006519a0
void TlsCleanupCallback();

void PresentFrame()
{
    int extraout_ECX;

    // Thread-local storage initialization (MSVC __tls_init pattern)
    if (g_bInitialized == 0)
    {
        // Simplified TLS init — original uses MSVC ThreadLocalStoragePointer intrinsic
        if (g_TlsIndex == -1)
        {
            TlsInit(&g_TlsIndex);
            RegisterAtExit(&g_pRenderInterface);
            TlsRegisterCallback(&TlsCleanupCallback);
            TlsAllocate(&g_TlsIndex);
        }

        // Active rendering path
        if (g_bActive != 0)
        {
            // Already in frame - just reset flag and return
            if (g_bInFrame == 0)
            {
                BeginScene();

                if (g_RenderTargetCount == 0)
                {
                    if (g_DepthStencilCount == 0)
                        ClearRenderTarget();
                    else
                        SetRenderTargets();
                }
                else
                {
                    SetRenderTargets();
                }

                // Execute deferred commands for current frame
                for (int i = *(int*)(g_FrameTable + 4 + g_FrameIndex * 0x24);
                     i != 0;
                     i = i - 1)
                {
                    ExecuteDeferred();
                }

                FlushCommandQueue();
                EndFrame();
                return;
            }

            g_bInFrame = 0;
            return;
        }

        // First-time initialization path
        g_PresentHeight = g_PresentWidth;
        g_FrameFlags = 0;
        g_FrameCounter = 0;
        g_FrameState = 1;

        BeginScene();
        PrePresent(extraout_ECX);

        // Begin rendering via interface vtable (offset 8 = Begin)
        (*reinterpret_cast<void(__cdecl**)()>(**reinterpret_cast<void***>(g_pRenderInterface) + 8))();

        if (g_RenderTargetCount == 0)
        {
            if (g_DepthStencilCount == 0)
                ClearRenderTarget();
            else
                SetRenderTargets();
        }
        else
        {
            SetRenderTargets();
        }

        // Update frame index and execute deferred commands
        g_FrameIndex = g_FrameCount;
        for (int i = *(int*)(g_FrameTable + 4 + g_FrameCount * 0x24);
             i != 0;
             i = i - 1)
        {
            ExecuteDeferred();
        }

        FlushCommandQueue();

        // End rendering via interface vtable (offset 0x18 = End)
        (*reinterpret_cast<void(__cdecl**)()>(**reinterpret_cast<void***>(g_pRenderInterface) + 0x18))();

        // Reset frame state
        g_FrameState = 0;
        g_FrameFlags = 0xFFFFFFFF;
        g_FrameCounter = 0;
        g_SubmitCounter = 0;

        PostPresent();
        EndFrame();
    }
}

} // namespace Giants
