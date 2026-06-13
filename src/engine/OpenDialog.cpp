// Giants Engine - Open Dialog Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "OpenDialog.h"
#include <cstring>

namespace Giants {

// ─── Dialog level stack ─────────────────────────────────────────
struct DialogLevelEntry {
    void*    updateFn;   // +0x00
    void*    renderFn;   // +0x04
    uint32_t field_08;   // +0x08
    uint32_t field_0C;   // +0x0C
    uint32_t field_10;   // +0x10
    uint32_t field_14;   // +0x14
};

static int sDialogLevelStackDepth;           // DAT_00682204
static DialogLevelEntry sDialogLevelStack[10]; // DAT_00747b60

// ─── Globals ────────────────────────────────────────────────────
extern uint32_t sDialogFlags;       // DAT_00747d2c
extern uint32_t sDialogSubFlag;     // DAT_00682264
extern uint32_t sActiveDialog;      // DAT_00702d60
extern uint32_t sScreenWidth;       // DAT_0074b604
extern uint32_t sScreenHeight;      // DAT_0074b608
extern uint32_t sDialogWidth;       // DAT_00702c1c
extern uint32_t sDialogHeight;      // DAT_00702c20
extern uint32_t sDialogWidth2;      // DAT_00702c24
extern uint32_t sDialogHeight2;     // DAT_00702c28
extern uint32_t sDialogState;       // DAT_00682e9c
extern uint32_t sDialogState2;      // DAT_0074b5fc
extern uint32_t sDialogState3;      // DAT_0074b600
extern uint32_t sDialogParam1;      // DAT_00681db0
extern uint32_t sDialogParam2;      // DAT_00681db4
extern uint32_t sDialogParam3;      // DAT_00681dec
extern uint32_t sDialogParam4;      // DAT_00681dd0
extern uint32_t sDialogParam5;      // DAT_00748a30
extern uint32_t sDialogParam6;      // DAT_00748bc8
extern uint32_t sDialogParam7;      // DAT_00702884
extern uint32_t sDialogParam8;      // DAT_00702bb8
extern uint32_t sDialogParam9;      // DAT_006ff960
extern uint32_t sDialogParam10;     // DAT_007028a0
extern uint32_t sDialogParam11;     // DAT_007028a4
extern float    sDialogScale;       // DAT_0066be20
extern void*    sDialogVtbl;        // DAT_0074b5f8
extern void*    sDialogRenderCallback; // PTR_DAT_00685890
extern void*    sDialogRenderFn;    // DAT_0072804c

// ─── External callees ──────────────────────────────────────────
extern void ErrorOverflow(const char* msg, int level); // FUN_00461e70
extern int  CheckCondition();    // FUN_005de9b0
extern void EarlyReturn();       // FUN_004d1070
extern int  CreateDialog();      // FUN_00559dc0
extern void SetupDialog(void*);  // FUN_00540fe0
extern void RenderDialog();      // FUN_00558360
extern void UpdateDialog();      // FUN_00549fd0
extern void RenderDialogA();     // FUN_00526be0
extern void RenderDialogB();     // FUN_00541860

void OpenDialog()
{
    if ((sDialogFlags == 0) || (sDialogSubFlag != 0))
    {
        if (sDialogLevelStackDepth >= 10)
        {
            ErrorOverflow("Overflow of dialog level stack", 0x1e);
            sDialogLevelStackDepth--;
        }
        sDialogLevelStackDepth++;
        sDialogLevelStack[sDialogLevelStackDepth].updateFn = reinterpret_cast<void*>(UpdateDialog);
        sDialogLevelStack[sDialogLevelStackDepth].renderFn = reinterpret_cast<void*>(RenderDialogA);
    }
    else
    {
        if (sDialogLevelStackDepth >= 10)
        {
            ErrorOverflow("Overflow of dialog level stack", 0x1e);
            sDialogLevelStackDepth--;
        }
        sDialogLevelStackDepth++;
        sDialogLevelStack[sDialogLevelStackDepth].updateFn = reinterpret_cast<void*>(UpdateDialog);
        sDialogLevelStack[sDialogLevelStackDepth].renderFn = reinterpret_cast<void*>(RenderDialogB);
    }

    sDialogLevelStack[sDialogLevelStackDepth].field_08 = 0;
    sDialogLevelStack[sDialogLevelStackDepth].field_0C = 0;
    sDialogLevelStack[sDialogLevelStackDepth].field_10 = 0;
    sDialogLevelStack[sDialogLevelStackDepth].field_14 = 0;

    if (sDialogLevelStackDepth != -1)
    {
        sDialogLevelStack[sDialogLevelStackDepth].field_10 = 1;
        sDialogRenderCallback = reinterpret_cast<void*>(0x006818b8);
    }

    int iVar5 = CheckCondition();
    if (iVar5 == 0)
    {
        EarlyReturn();
        return;
    }

    sScreenWidth = sDialogParam10;
    sScreenHeight = sDialogParam11;
    sDialogState = 0x1b;
    sDialogState2 = 0x1b;
    sDialogState3 = 0xffffffff;

    if (sActiveDialog != 0)
        *reinterpret_cast<uint32_t*>(sActiveDialog + 0x124) |= 0x8000;

    sActiveDialog = 0;

    iVar5 = CreateDialog();
    sActiveDialog = iVar5;
    *reinterpret_cast<uint32_t*>(iVar5 + 0x124) |= 0x40000000;

    if ((sDialogFlags != 0) && (sDialogSubFlag == 0))
    {
        sDialogParam2 = 0;
        sDialogParam3 = 0;
        sDialogParam1 = 1;
        sDialogParam4 = iVar5;
    }

    SetupDialog(nullptr);
    sDialogParam5 = 10;
    sDialogParam6 = 1;

    if ((sDialogFlags == 0) || (sDialogSubFlag != 0))
    {
        reinterpret_cast<void(*)()>(sDialogRenderFn)();
        if (sDialogParam9 != 6)
            sDialogParam7 = 1;
        if (sDialogParam8 == 0)
            RenderDialog();
    }

    // Compute dialog dimensions from vtable layout data
    int iVar5b = *reinterpret_cast<int*>(*reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(sDialogVtbl) + 0x3cc) + 4 + sDialogParam5 * 4);
    sDialogWidth = static_cast<uint32_t>(
        ((*reinterpret_cast<float*>(iVar5b + 0x44) * sDialogScale + *reinterpret_cast<float*>(iVar5b + 0x38) * sDialogScale)
         / static_cast<float>(sScreenWidth)) * static_cast<float>(sScreenWidth));
    sDialogWidth2 = sDialogWidth;
    sDialogHeight = static_cast<uint32_t>(
        static_cast<float>(sScreenHeight) *
        ((*reinterpret_cast<float*>(iVar5b + 0x48) * sDialogScale + *reinterpret_cast<float*>(iVar5b + 0x3c) * sDialogScale)
         / static_cast<float>(sScreenHeight)));
    sDialogHeight2 = sDialogHeight;
}

} // namespace Giants
