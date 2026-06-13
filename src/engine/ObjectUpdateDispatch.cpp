// Giants Engine - Object Update Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "ObjectUpdateDispatch.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── Global state ───────────────────────────────────────────────
extern int*      gLinkedListHead;       // DAT_00748b48
extern int       gGlobalState;          // DAT_006ff960
extern int       gConditionFlag;        // DAT_00702a58
extern int       gComparisonValue;      // DAT_00702924
extern int*      gSecondaryListHead;    // DAT_00747d40
extern int       gSecondaryListCount;   // DAT_007496c4
extern int       gSubStateFlag;         // DAT_00702a54
extern bool      gAltTimingFlag;        // DAT_00702bcc
extern float     gTimingIntervalA;      // DAT_0066bd7c
extern float     gTimingIntervalB;      // DAT_0066bd50
extern float     gLastUpdateTime;       // DAT_0073e76c
extern float     gCurrentTime;          // DAT_00727e40
extern int*      gActiveObjectPtr;      // DAT_00702d60
extern int       gFrameCounter;         // DAT_00702774

// ─── External callees ───────────────────────────────────────────
extern void FUN_004ea1b0();
extern void FUN_005255b0();  // GameLoopDispatch
extern void FUN_0046a110();  // GameMainLoop
extern int  FUN_004f0e40();
extern int  FUN_00558570();
extern void FUN_0055a160();
extern void FUN_0046ccf0();
extern void FUN_0048fba0();
extern void FUN_0056ca90();
extern void FUN_004e9b10();
extern void FUN_0049a040();  // UpdateActiveCamera

// Callback tables (stride 0x50 = 80 bytes per entry)
extern void (*gCallbackTableA[0x6c][0x14])(void*); // DAT_00682ea8
extern void (*gCallbackTableB[0x6c][0x14])(void*); // DAT_00682eac

void UpdateObjectState()
{
    int iVar2 = reinterpret_cast<int>(gLinkedListHead);

    if (gLinkedListHead == nullptr)
    {
        // Fixed array path: structures at 0x00748b54, each 12 bytes (3 ints)
        int* piVar4 = reinterpret_cast<int*>(0x00748b54);
        do
        {
            if (piVar4[-1] == 0)
            {
                // Deallocate path
                if (piVar4[0] != 0)
                {
                    iVar2 = 0;
                    if (0 < piVar4[1])
                    {
                        do {
                            FUN_004ea1b0();
                            iVar2 = iVar2 + 1;
                        } while (iVar2 < piVar4[1]);
                    }
                    free(reinterpret_cast<void*>(piVar4[0]));
                    piVar4[0] = 0;
                }
            }
            else if ((piVar4[0] == 0) && (0 < piVar4[1]))
            {
                // Allocate path
                void* pvVar1 = malloc(piVar4[1] << 2);
                piVar4[0] = reinterpret_cast<int>(pvVar1);
                memset(pvVar1, 0, piVar4[1] << 2);
            }
            piVar4 = piVar4 + 3;
        } while (reinterpret_cast<int>(piVar4) < 0x749004);
    }
    else
    {
        // Linked list path
        do
        {
            if (*reinterpret_cast<int*>(iVar2 + 0x44) == 0)
            {
                if (*reinterpret_cast<int*>(iVar2 + 0x48) != 0)
                {
                    int iVar3 = 0;
                    if (0 < *reinterpret_cast<int*>(iVar2 + 0x4c))
                    {
                        do {
                            FUN_004ea1b0();
                            iVar3 = iVar3 + 1;
                        } while (iVar3 < *reinterpret_cast<int*>(iVar2 + 0x4c));
                    }
                    free(*reinterpret_cast<void**>(iVar2 + 0x48));
                    *reinterpret_cast<uint32_t*>(iVar2 + 0x48) = 0;
                }
            }
            else if ((*reinterpret_cast<int*>(iVar2 + 0x48) == 0) &&
                     (0 < *reinterpret_cast<int*>(iVar2 + 0x4c)))
            {
                void* pvVar1 = malloc(*reinterpret_cast<int*>(iVar2 + 0x4c) << 2);
                *reinterpret_cast<void**>(iVar2 + 0x48) = pvVar1;
                memset(pvVar1, 0, *reinterpret_cast<int*>(iVar2 + 0x4c) << 2);
            }
            iVar2 = *reinterpret_cast<int*>(iVar2 + 0x50);
        } while (iVar2 != 0);
    }

    // Main state processing
    if (((gGlobalState == 6) && (gConditionFlag != 0)) && (0xc < gComparisonValue))
    {
        FUN_005255b0();
    }
    else
    {
        FUN_0046a110();
        iVar2 = reinterpret_cast<int>(gSecondaryListHead);
        int iVar3 = gSecondaryListCount;
        while (iVar2 != 0)
        {
            iVar2 = FUN_004f0e40();
        }
        while (iVar3 != 0)
        {
            iVar3 = FUN_00558570();
        }
        FUN_0055a160();

        if ((gGlobalState == 6) && (gSubStateFlag == 0))
        {
            float fVar5 = gTimingIntervalA;
            if (gAltTimingFlag)
                fVar5 = gTimingIntervalB;

            if (fVar5 + gLastUpdateTime <= gCurrentTime)
            {
                FUN_0046ccf0();
                gLastUpdateTime = gCurrentTime;
            }
        }
    }

    // Object state update and callback dispatch
    iVar2 = reinterpret_cast<int>(gActiveObjectPtr);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(gActiveObjectPtr) + 0x124) =
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(gActiveObjectPtr) + 0x124) & 0xffffffbf;

    if ((iVar2 != 0) && ((*reinterpret_cast<uint32_t*>(iVar2 + 0x124) & 0xc000) == 0))
    {
        *reinterpret_cast<uint32_t*>(iVar2 + 0x164) = *reinterpret_cast<uint32_t*>(iVar2 + 0x154);
        *reinterpret_cast<uint32_t*>(iVar2 + 0x168) = *reinterpret_cast<uint32_t*>(iVar2 + 0x158);
        *reinterpret_cast<uint32_t*>(iVar2 + 0x16c) = *reinterpret_cast<uint32_t*>(iVar2 + 0x15c);
        *reinterpret_cast<uint32_t*>(iVar2 + 0x170) = *reinterpret_cast<uint32_t*>(iVar2 + 0x160);

        int idx = *reinterpret_cast<int*>(iVar2 + 0x22c);
        if ((idx < 0x6c) && (gCallbackTableA[idx][0] != nullptr))
        {
            gCallbackTableA[idx][0](reinterpret_cast<void*>(iVar2));
            iVar2 = reinterpret_cast<int>(gActiveObjectPtr);
        }
    }

    if ((*reinterpret_cast<uint8_t*>(iVar2 + 0x124) & 0x40) == 0)
    {
        int idx = *reinterpret_cast<int*>(iVar2 + 0x22c);
        if ((((((iVar2 != 0) && (*reinterpret_cast<int*>(iVar2 + 8) != 0)) &&
               ((*reinterpret_cast<uint32_t*>(iVar2 + 0x124) & 0xc000) == 0)) &&
              ((*reinterpret_cast<uint8_t*>(iVar2 + 0x214) & 0x10) == 0)) &&
             (idx < 0x6c)) &&
            (gCallbackTableB[idx][0] != nullptr))
        {
            gCallbackTableB[idx][0](reinterpret_cast<void*>(iVar2));
        }
        FUN_0048fba0();
        FUN_0056ca90();
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(gActiveObjectPtr) + 0x124) =
            *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(gActiveObjectPtr) + 0x124) | 0x20;
    }

    FUN_004e9b10();

    if (gFrameCounter == 0)
        gFrameCounter = -0x21524111;

    FUN_0049a040();

    if (gFrameCounter == -0x21524111)
        gFrameCounter = 0;
}

} // namespace Giants
