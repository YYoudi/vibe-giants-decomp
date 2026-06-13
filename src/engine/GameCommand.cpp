// Giants Engine - Game Command Dispatcher Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "GameCommand.h"
#include "CRTStubs.h"
#include <cstring>

namespace Giants {

// ─── Globals (shared with other modules) ──────────────────────
extern uint32_t* DAT_00702d50;    // String resolve callback (EntitySystem.cpp)
typedef int* (*ResolveCallbackFn)(uint32_t);
static inline ResolveCallbackFn GetResolveCallback() {
    return reinterpret_cast<ResolveCallbackFn>(reinterpret_cast<uintptr_t>(DAT_00702d50));
}
extern float     DAT_0066bf2c;    // Current time / wave period (FlickInterpreter.cpp)
extern float     DAT_0066bd5c;    // Time scale factor
extern float     _DAT_0074beb4;   // Font pixel size (DisplayMode.cpp)
extern uint32_t  DAT_0074bed4;    // Screen X offset (ErrorHandler.cpp)
extern void*     DAT_007280cc;    // Current text renderer callback

// External callees
extern int   LookupStringById(uint32_t id);          // FUN_005e80c0
extern char* GetEntityName();                         // FUN_005474a0
extern void  TextCommandDispatchPre();                // FUN_005d79a0
extern void  TextCommandDispatchPost();               // FUN_005d7de0
extern void  SetTextPosition(float y, int charCount); // FUN_0062c420
extern void  SetTextSpacing(float spacing);           // FUN_0062c690

// ═══════════════════════════════════════════════════════════════════
// DispatchGameCommand (FUN_005d8fb0) — 65 callers
// ═══════════════════════════════════════════════════════════════════
// Interprets and dispatches a game command. Handles opcode-based
// branching for different command types (text display, entity ops, etc.)
//
// Opcode ranges:
//   0x3a-0x3d (inclusive 0x3b): special pre/post dispatch
//   0x00: string lookup by ID (via FUN_005e80c0)
//   0x39, 0x3e, 0x3f, 0x40: standard with text positioning
//   other: entity name lookup (via FUN_005474a0)

int DispatchGameCommand(int param_1, uint32_t* param_2, int param_3, int param_4)
{
    if (param_3 != 0) {
        return 0xffffff;  // Non-execute mode: return success without action
    }

    int opcode = *reinterpret_cast<int*>(param_4 + 4);

    // ─── Special opcode range 0x3a-0x3d ──────────────────────
    if (static_cast<uint32_t>(opcode - 0x3a) < 4) {
        if (opcode == 0x3b) {
            // Opcode 0x3b: save/restore dispatch state around pre/post calls
            int ctx = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(param_1 + 0x18) + 0x480
                ) + 8
            );
            uint32_t saved = *reinterpret_cast<uint32_t*>(ctx + 0x1c);
            *reinterpret_cast<uint32_t*>(ctx + 0x1c) = 0;
            TextCommandDispatchPre();   // FUN_005d79a0
            TextCommandDispatchPost();  // FUN_005d7de0
            *reinterpret_cast<uint32_t*>(ctx + 0x1c) = saved;
        }
        return -1;
    }

    // ─── String resolution ────────────────────────────────────
    char* textPtr;
    int* resolvedObj;

    if (opcode == 0) {
        // Opcode 0: resolve string by ID
        textPtr = reinterpret_cast<char*>(LookupStringById(*param_2));
        resolvedObj = GetResolveCallback()(*reinterpret_cast<uint32_t*>(param_4 + 4));
    } else {
        // Other opcodes: resolve entity name
        textPtr = reinterpret_cast<char*>(GetEntityName());
        if (textPtr == nullptr) {
            return 0xffffff;
        }
        resolvedObj = GetResolveCallback()(*reinterpret_cast<uint32_t*>(param_4 + 4));
    }

    // ─── String length calculation (strlen) ───────────────────
    char* scan = textPtr;
    char ch;
    do {
        ch = *scan;
        scan = scan + 1;
    } while (ch != '\0');
    int strLen = reinterpret_cast<int>(scan) - reinterpret_cast<int>(textPtr + 1);
    resolvedObj[2] = strLen;

    // ─── Text renderer callback setup ────────────────────────
    // If resolved object has valid data with zero marker, set callback
    if ((*resolvedObj != 0) &&
        (reinterpret_cast<int*>(resolvedObj[1]) != nullptr) &&
        (*reinterpret_cast<int*>(resolvedObj[1]) == 0))
    {
        DAT_007280cc = reinterpret_cast<void*>(0x005423e0);  // Text render callback
    }

    int newOpcode = *reinterpret_cast<int*>(param_4 + 4);

    // ─── Text position computation ────────────────────────────
    float yPos;
    if ((newOpcode == 0) || (newOpcode == 0x39) ||
        (newOpcode == 0x3e) || (newOpcode == 0x3f) || (newOpcode == 0x40))
    {
        // These opcodes use text spacing (FUN_0062c690)
        float baseY = DAT_0066bf2c - static_cast<float>(param_2[0x12])
                      / static_cast<float>(*reinterpret_cast<int*>(param_1 + 0x28));

        // Recompute string length for spacing call
        char* scan2 = textPtr;
        char c2;
        do { c2 = *scan2; scan2++; } while (c2 != '\0');
        SetTextSpacing(baseY);  // FUN_0062c690 — applies text spacing

        // Recompute again for position call
        char* scan3 = textPtr;
        char c3;
        do { c3 = *scan3; scan3++; } while (c3 != '\0');

        yPos = (DAT_0066bd5c / _DAT_0074beb4) * static_cast<float>(DAT_0074bed4) + baseY;
    } else {
        // Simple opcodes: no spacing
        char* scan2 = textPtr;
        char c2;
        do { c2 = *scan2; scan2++; } while (c2 != '\0');

        yPos = (DAT_0066bf2c - static_cast<float>(param_2[0x12])
                / static_cast<float>(*reinterpret_cast<int*>(param_1 + 0x28)))
               + (DAT_0066bd5c / _DAT_0074beb4) * static_cast<float>(DAT_0074bed4);
    }

    // Set final text position
    char* scanFinal = textPtr;
    char cFinal;
    do { cFinal = *scanFinal; scanFinal++; } while (cFinal != '\0');
    SetTextPosition(yPos, reinterpret_cast<int>(scanFinal) - reinterpret_cast<int>(textPtr + 1));

    DAT_007280cc = nullptr;

    return 0xffffff;
}

// ═══════════════════════════════════════════════════════════════════
// DispatchGameCommandAlt (FUN_005d92d0) — 57 callers
// ═══════════════════════════════════════════════════════════════════
// Variant of DispatchGameCommand with different opcode ranges.
// Very similar structure but:
//   - Special opcode range: 0x32-0x35 (vs 0x3a-0x3d)
//   - Text spacing opcodes: 0, 0x31, 0x36-0x38 (vs 0, 0x39, 0x3e-0x40)
//   - Uses FUN_00548260 for entity name (vs FUN_005474a0)

extern char* GetEntityNameAlt();  // FUN_00548260

int DispatchGameCommandAlt(int param_1, uint32_t* param_2, int param_3, int param_4)
{
    if (param_3 != 0) {
        return 0xffffff;
    }

    int opcode = *reinterpret_cast<int*>(param_4 + 4);

    // Special opcode range 0x32-0x35
    if (static_cast<unsigned int>(opcode - 0x32) < 4) {
        if (opcode == 0x32) {
            int ctx = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(param_1 + 0x18) + 0x480
                ) + 8
            );
            uint32_t saved = *reinterpret_cast<uint32_t*>(ctx + 0x1c);
            *reinterpret_cast<uint32_t*>(ctx + 0x1c) = 0;
            TextCommandDispatchPre();
            TextCommandDispatchPost();
            *reinterpret_cast<uint32_t*>(ctx + 0x1c) = saved;
        }
        return -1;
    }

    // String resolution
    char* textPtr;
    int* resolvedObj;

    if (opcode == 0) {
        textPtr = reinterpret_cast<char*>(LookupStringById(*param_2));
        resolvedObj = GetResolveCallback()(*reinterpret_cast<uint32_t*>(param_4 + 4));
    } else {
        textPtr = reinterpret_cast<char*>(GetEntityNameAlt());
        if (textPtr == nullptr) {
            return 0xffffff;
        }
        resolvedObj = GetResolveCallback()(*reinterpret_cast<uint32_t*>(param_4 + 4));
    }

    // String length
    char* scan = textPtr;
    char ch;
    do { ch = *scan; scan++; } while (ch != '\0');
    int strLen = reinterpret_cast<int>(scan) - reinterpret_cast<int>(textPtr + 1);
    resolvedObj[2] = strLen;

    // Text renderer callback
    if ((*resolvedObj != 0) &&
        (reinterpret_cast<int*>(resolvedObj[1]) != nullptr) &&
        (*reinterpret_cast<int*>(resolvedObj[1]) == 0))
    {
        DAT_007280cc = reinterpret_cast<void*>(0x005423e0);
    }

    int newOpcode = *reinterpret_cast<int*>(param_4 + 4);
    float yPos;

    if ((newOpcode == 0) || (newOpcode == 0x31) ||
        (newOpcode == 0x36) || (newOpcode == 0x37) || (newOpcode == 0x38))
    {
        float baseY = DAT_0066bf2c - static_cast<float>(param_2[0x12])
                      / static_cast<float>(*reinterpret_cast<int*>(param_1 + 0x28));
        char* scan2 = textPtr;
        char c2;
        do { c2 = *scan2; scan2++; } while (c2 != '\0');
        SetTextSpacing(baseY);
        char* scan3 = textPtr;
        char c3;
        do { c3 = *scan3; scan3++; } while (c3 != '\0');
        yPos = (DAT_0066bd5c / _DAT_0074beb4) * static_cast<float>(DAT_0074bed4) + baseY;
    } else {
        char* scan2 = textPtr;
        char c2;
        do { c2 = *scan2; scan2++; } while (c2 != '\0');
        yPos = (DAT_0066bf2c - static_cast<float>(param_2[0x12])
                / static_cast<float>(*reinterpret_cast<int*>(param_1 + 0x28)))
               + (DAT_0066bd5c / _DAT_0074beb4) * static_cast<float>(DAT_0074bed4);
    }

    char* scanFinal = textPtr;
    char cFinal;
    do { cFinal = *scanFinal; scanFinal++; } while (cFinal != '\0');
    SetTextPosition(yPos, reinterpret_cast<int>(scanFinal) - reinterpret_cast<int>(textPtr + 1));
    DAT_007280cc = nullptr;

    return 0xffffff;
}

} // namespace Giants
