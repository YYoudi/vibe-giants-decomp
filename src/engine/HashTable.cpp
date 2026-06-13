// Giants Engine - Hash Table Utility Functions
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Source: ghidra_exports/level4/0043dcd0.c, 0043f360.c, 00450d90.c,
//         00461e70.c, 0042e110.c

#include "HashTable.h"

#include <cstdio>
#include <stdexcept>

namespace Giants {

// ─── Forward declarations for sub-functions ────────────────────────

// FUN_0043dd30 — core bucket probe (called by HashTableLookup and HashTableFindOrInsert)
extern int HashTableProbe(int* param1, uint32_t param2, uint32_t* param3);

// FUN_0043f010 — node allocation and insertion
extern int* HashTableInsertNode(int* localBuf, uint32_t param2, uint32_t param3,
                                void* datRef, void* param5, void* param6);

// FUN_00450b00 — actual dispatch init body
extern void InitDispatchBody();

// FUN_0043f440 — log/error channel write
extern void LogChannelWrite(int channel, int level, void* message);

// FUN_004439b0 — security cookie / scope cleanup
extern void SecurityCookieCheck(uint32_t cookie);

// FUN_00431980 — config init preamble
extern void ConfigInitPreamble(uint32_t param1);

// FUN_00443440 — check default config file exists
extern uint8_t ConfigFileExists();

// FUN_0042f410 — read config section
extern void ReadConfigSection(void* dest, void* source);

// FUN_00443c70 — post-config section cleanup
extern void ConfigSectionCleanup();

// FUN_0042f9b0 — load secondary config
extern void LoadSecondaryConfig(void* dest);

// FUN_0042e22f — post-load finalization
extern void ConfigPostLoadFinalize();

// FUN_0042fda0 — format error string
extern uint32_t FormatErrorString(const char* fmt, uint32_t len);

// FUN_00442420 — throw helper (builds exception message)
extern void ThrowMessage(uint32_t message);

// ─── Static globals ────────────────────────────────────────────────

// DAT_0067d280 — stack security cookie XOR mask
static uint32_t s_SecurityCookie = 0x0067d280;

// DAT_0065ce75 — constant used in hash table node insertion
static uint32_t s_HashInsertConst = 0x0065ce75;

// DAT_006780e8 — ThrowInfo vtable for config exception
static uint32_t s_ConfigThrowInfo = 0x006780e8;

// ═══════════════════════════════════════════════════════════════════
// HashTableLookup (FUN_0043dcd0) — FAIL
// Searches linked-list bucket for key match by ID.
// Callers: FUN_0043f440 (2x), FUN_004d0410
// Callees: FUN_0043dd30 (HashTableProbe)
// ═══════════════════════════════════════════════════════════════════

/*
 * RAW DECOMPILATION (Ghidra):
 *
 * undefined4 __thiscall FUN_0043dcd0(int param_1, int *param_2,
 *                                    undefined4 param_3, uint *param_4)
 * {
 *   int *piVar1;
 *   int iVar2;
 *   int *piVar3;
 *
 *   iVar2 = FUN_0043dd30(param_2, param_3, param_4);
 *   if (iVar2 != 0) {
 *     return 1;
 *   }
 *   if ((*param_4 & 2) != 0) {
 *     piVar1 = *(int **)(param_1 + 0x14);
 *     piVar3 = (int *)*piVar1;
 *     if (piVar3 != piVar1) {
 *       do {
 *         if (*param_2 == piVar3[2]) {
 *           return 1;
 *         }
 *         piVar3 = (int *)*piVar3;
 *       } while (piVar3 != piVar1);
 *     }
 *   }
 *   return 0;
 * }
 */

uint32_t HashTableLookup(int param1, int* param2, uint32_t param3, uint32_t* param4)
{
    // Step 1: Probe the primary hash bucket
    int probeResult = HashTableProbe(param2, param3, param4);
    if (probeResult != 0) {
        return 1;
    }

    // Step 2: If bucket flag bit 1 is set, walk the overflow linked list
    if ((*param4 & 2) != 0) {
        // param1 + 0x14 = pointer to head of linked list (sentinel node)
        int** sentinel = reinterpret_cast<int**>(param1 + 0x14);
        int* current = *sentinel;

        if (current != *sentinel) {
            do {
                // Each node: [0]=next, [1]=prev(?), [2]=key
                if (*param2 == current[2]) {
                    return 1;  // key found in overflow chain
                }
                current = reinterpret_cast<int*>(*current);
            } while (current != *sentinel);
        }
    }

    return 0;  // key not found
}

// ═══════════════════════════════════════════════════════════════════
// HashTableFindOrInsert (FUN_0043f360) — FAIL
// FNV-1a hash computation, bucket lookup, creates node on miss.
// Callers: FUN_0043f440 (2x), FUN_004d0410
// Callees: FUN_0043dd30 (HashTableProbe), FUN_0043f010 (HashTableInsertNode)
// ═══════════════════════════════════════════════════════════════════

/*
 * RAW DECOMPILATION (Ghidra):
 *
 * int * __thiscall FUN_0043f360(int param_1, uint *param_2)
 * {
 *   int *piVar1;
 *   int *piVar2;
 *   int iVar3;
 *   undefined1 local_25;
 *   uint *local_24;
 *   uint local_20;
 *   uint local_1c;
 *   undefined1 local_18 [20];
 *
 *   local_20 = (((((byte)*param_2 ^ 0x811c9dc5) * 0x1000193 ^
 *                 (uint)*(byte *)((int)param_2 + 1)) *
 *                0x1000193 ^ (uint)*(byte *)((int)param_2 + 2)) *
 *               0x1000193 ^ (uint)*(byte *)((int)param_2 + 3)) * 0x1000193;
 *   local_1c = *(uint *)(param_1 + 4) & local_20;
 *   local_24 = (uint *)(*(int *)(param_1 + 0x1c) + local_1c * 0x38);
 *   piVar2 = (int *)FUN_0043dd30(param_2, local_20, local_24);
 *   if (piVar2 == (int *)0x0) {
 *     if ((*local_24 & 2) != 0) {
 *       piVar1 = *(int **)(param_1 + 0x14);
 *       piVar2 = (int *)*piVar1;
 *       if (piVar2 != piVar1) {
 *         do {
 *           if (*param_2 == piVar2[2]) goto LAB_0043f3fd;
 *           piVar2 = (int *)*piVar2;
 *         } while (piVar2 != piVar1);
 *       }
 *     }
 *   } else {
 * LAB_0043f3fd:
 *     if (piVar2 + 4 != (int *)0x0) {
 *       return piVar2 + 4;
 *     }
 *   }
 *   local_24 = param_2;
 *   piVar2 = (int *)FUN_0043f010(local_18, local_1c, local_20,
 *                                 &DAT_0065ce75, &local_24, &local_25);
 *   iVar3 = *piVar2;
 *   if (iVar3 == piVar2[1]) {
 *     iVar3 = piVar2[2];
 *   }
 *   return (int *)(iVar3 + 0x10);
 * }
 */

int* HashTableFindOrInsert(int param1, uint32_t* param2)
{
    // ── FNV-1a hash computation on first 4 bytes of key ──
    // Constants: FNV offset basis = 0x811c9dc5, FNV prime = 0x1000193
    const uint8_t* keyBytes = reinterpret_cast<const uint8_t*>(param2);
    uint32_t hash = static_cast<uint8_t>(keyBytes[0]) ^ 0x811c9dc5;
    hash = (hash * 0x1000193) ^ static_cast<uint32_t>(keyBytes[1]);
    hash = (hash * 0x1000193) ^ static_cast<uint32_t>(keyBytes[2]);
    hash = (hash * 0x1000193) ^ static_cast<uint32_t>(keyBytes[3]);
    // Note: original applies * 0x1000193 one final time after the last XOR
    // Re-reading: the expression chains multiply THEN xor for each byte
    // (((byte[0] ^ 0x811c9dc5) * prime ^ byte[1]) * prime ^ byte[2]) * prime ^ byte[3]) * prime
    hash = hash * 0x1000193;

    // ── Bucket index from hash ──
    // param1 + 0x04 = bucket mask, param1 + 0x1c = bucket array base
    // Each bucket is 0x38 (56) bytes
    uint32_t bucketMask = *reinterpret_cast<uint32_t*>(param1 + 0x04);
    uint32_t bucketIndex = bucketMask & hash;
    uint8_t* bucketBase = *reinterpret_cast<uint8_t**>(param1 + 0x1c);
    uint32_t* bucket = reinterpret_cast<uint32_t*>(bucketBase + bucketIndex * 0x38);

    // ── Probe primary bucket ──
    int* found = HashTableProbe(reinterpret_cast<int*>(param2), hash, bucket);

    if (found == nullptr) {
        // Not in primary bucket — check overflow linked list
        if ((*bucket & 2) != 0) {
            int** sentinel = reinterpret_cast<int**>(param1 + 0x14);
            int* node = *sentinel;
            if (node != *sentinel) {
                do {
                    if (*param2 == static_cast<uint32_t>(node[2])) {
                        goto found_node;
                    }
                    node = reinterpret_cast<int*>(*node);
                } while (node != *sentinel);
            }
        }
        // Key not found — insert new node
        uint32_t localParam2 = *reinterpret_cast<uint32_t*>(param2);
        uint8_t localBuf[20];  // local_18 [20]
        uint8_t localExtra;    // local_25

        int* newNode = HashTableInsertNode(
            reinterpret_cast<int*>(localBuf),
            bucketIndex,
            hash,
            &s_HashInsertConst,   // DAT_0065ce75
            &localParam2,
            &localExtra
        );

        // TODO: Verify linked-list insertion logic below
        int nextOrValue = newNode[0];
        if (nextOrValue == newNode[1]) {
            nextOrValue = newNode[2];
        }
        return reinterpret_cast<int*>(nextOrValue + 0x10);
    }

found_node:
    if (found + 4 != nullptr) {
        return found + 4;  // skip 16-byte node header, return data pointer
    }

    // TODO: Should be unreachable? Original code would fall through to insert.
    return nullptr;
}

// ═══════════════════════════════════════════════════════════════════
// InitDispatchHelper (FUN_00450d90) — PASS
// Thin wrapper calling FUN_00450b00 (InitDispatchBody).
// Callers: FUN_006235a0, FUN_00624fb0, FUN_005549d0, FUN_0044e140,
//          FUN_0044e25b, FUN_004d0410, FUN_004b3cd0 (7 total)
// Callees: FUN_00450b00, FUN_004433b0 (unreachable)
// ═══════════════════════════════════════════════════════════════════

/*
 * RAW DECOMPILATION (Ghidra):
 *
 * void FUN_00450d90(void)
 * {
 *   FUN_00450b00();
 *   return;
 * }
 *
 * NOTE: Ghidra reports FUN_004433b0 as callee but marks the block
 *       at 0x00450dc1 as unreachable. This is likely an artifact of
 *       exception handler registration in the original binary.
 */

void InitDispatchHelper()
{
    InitDispatchBody();
}

// ═══════════════════════════════════════════════════════════════════
// FormattedLogOutput (FUN_00461e70) — FAIL
// Formats a string via fmt::vformat, then writes to error/log channel.
// Callers: 49 total (widely used throughout engine)
// Callees: fmt::v9::vformat, FUN_0043f440, FUN_004439b0,
//          __security_check_cookie
// ═══════════════════════════════════════════════════════════════════

/*
 * RAW DECOMPILATION (Ghidra):
 *
 * void FUN_00461e70(undefined4 param_1, undefined4 param_2)
 * {
 *   uint uVar1;
 *   undefined1 local_34 [24];
 *   undefined1 local_1c [8];
 *   uint local_14;
 *   void *local_10;
 *   undefined1 *puStack_c;
 *   undefined4 local_8;
 *
 *   local_8 = 0xffffffff;
 *   puStack_c = &LAB_006482bd;
 *   local_10 = ExceptionList;
 *   uVar1 = DAT_0067d280 ^ (uint)&stack0xfffffffc;
 *   ExceptionList = &local_10;
 *   local_14 = uVar1;
 *   fmt::v9::vformat(local_34, param_1, param_2, 0, 0, local_1c);
 *   local_8 = 0;
 *   FUN_0043f440(6, 4, local_34);
 *   FUN_004439b0(uVar1);
 *   ExceptionList = local_10;
 *   return;
 * }
 */

void FormattedLogOutput(uint32_t param1, uint32_t param2)
{
    // ── Stack cookie setup (standard MSVC SEH pattern) ──
    // local_8 = 0xffffffff marks SEH scope depth
    // puStack_c = exception handler address (LAB_006482bd)
    // local_14 = stack cookie XOR'd with frame address

    // ── Format the message using fmt library ──
    // fmt::v9::vformat writes result to local_34 (24-byte buffer)
    uint8_t formatBuffer[24];
    uint8_t formatArgs[8];

    // TODO: Replace with actual fmt::vformat call when fmt is linked
    // Original: fmt::v9::vformat(formatBuffer, param1, param2, 0, 0, formatArgs);
    (void)formatBuffer;
    (void)formatArgs;

    // ── Write formatted string to log channel ──
    // Channel 6, level 4 (likely error/warning level)
    LogChannelWrite(6, 4, formatBuffer);

    // ── Security cookie verification ──
    // SecurityCookieCheck(stackCookie);
}

// ═══════════════════════════════════════════════════════════════════
// ConfigFileLoader (FUN_0042e110) — FAIL
// Checks for default config file, reads settings into two sections,
// throws C++ exception if config is missing.
// Caller: FUN_0042fc00
// Callees: FUN_00431980, FUN_00443440, FUN_0042f410 (2x),
//          FUN_00443c70 (2x), FUN_0042f9b0, FUN_0042e22f,
//          FUN_0042fda0, FUN_00442420, _CxxThrowException
// ═══════════════════════════════════════════════════════════════════

/*
 * RAW DECOMPILATION (Ghidra):
 *
 * void __fastcall FUN_0042e110(int param_1)
 * {
 *   undefined1 uVar1;
 *   undefined4 uVar2;
 *   char cVar3;
 *   undefined4 uVar4;
 *   uint uStack_8c;
 *   undefined1 local_78 [12];
 *   int local_6c;
 *   uint local_68;
 *   undefined1 local_64 [24];
 *   undefined1 local_4c [32];
 *   undefined1 local_2c [8];
 *   undefined4 local_24;
 *   undefined4 local_20;
 *   uint local_18;
 *   undefined1 *local_14;
 *   void *local_10;
 *   undefined1 *puStack_c;
 *   undefined4 local_8;
 *
 *   local_8 = 0xffffffff;
 *   puStack_c = &LAB_00645ae5;
 *   local_10 = ExceptionList;
 *   uStack_8c = DAT_0067d280 ^ (uint)&stack0xfffffffc;
 *   local_14 = (undefined1 *)&uStack_8c;
 *   ExceptionList = &local_10;
 *   local_68 = local_68 & 0xffffff00;
 *   local_6c = param_1;
 *   local_18 = uStack_8c;
 *   FUN_00431980(local_68);
 *   local_8 = 0;
 *   cVar3 = FUN_00443440();
 *   if (cVar3 != '\0') {
 *     // ── Config exists: load two sections ──
 *     FUN_0042f410(local_2c, local_64);             // Read section 1
 *     uVar1 = *(undefined1 *)(param_1 + 0x28);
 *     *(undefined1 *)(param_1 + 0x28) = local_2c[0];
 *     uVar4 = *(undefined4 *)(param_1 + 0x34);
 *     uVar2 = *(undefined4 *)(param_1 + 0x30);
 *     *(undefined4 *)(param_1 + 0x34) = local_20;
 *     *(undefined4 *)(param_1 + 0x30) = local_24;
 *     local_2c[0] = uVar1;
 *     local_24 = uVar2;
 *     local_20 = uVar4;
 *     FUN_00443c70();
 *     FUN_0042f9b0(local_4c);                        // Load secondary config
 *     local_8 = CONCAT31(local_8._1_3_, 3);
 *     FUN_0042f410(local_2c, local_4c);             // Read section 2
 *     uVar1 = *(undefined1 *)(param_1 + 0x38);
 *     *(undefined1 *)(param_1 + 0x38) = local_2c[0];
 *     uVar4 = *(undefined4 *)(param_1 + 0x44);
 *     uVar2 = *(undefined4 *)(param_1 + 0x40);
 *     *(undefined4 *)(param_1 + 0x44) = local_20;
 *     *(undefined4 *)(param_1 + 0x30) = local_24;
 *     local_2c[0] = uVar1;
 *     local_24 = uVar2;
 *     local_20 = uVar4;
 *     FUN_00443c70();
 *     FUN_0042e22f();
 *     return;
 *   }
 *   // ── Config missing: format error and throw ──
 *   uVar4 = FUN_0042fda0("Default configuration file {} does not exist.", 0x2d);
 *   local_8 = CONCAT31(local_8._1_3_, 1);
 *   FUN_00442420(uVar4);
 *   _CxxThrowException(local_78, (ThrowInfo *)&DAT_006780e8);
 * }
 */

void ConfigFileLoader(int param1)
{
    // ── Stack cookie setup ──
    uint32_t stackCookie = s_SecurityCookie ^ reinterpret_cast<uint32_t>(&stackCookie);

    // ── Initialize config subsystem ──
    ConfigInitPreamble(stackCookie);

    // ── Check if default config file exists ──
    uint8_t configExists = ConfigFileExists();

    if (configExists != 0) {
        // ── Load config section 1 (primary settings) ──
        uint8_t sectionData1[24];  // local_64
        uint8_t swapBuf[8];        // local_2c

        ReadConfigSection(swapBuf, sectionData1);

        // Swap values between param1 fields and local buffer
        // param1 + 0x28: single byte swap
        // param1 + 0x30, 0x34: 4-byte field swaps
        uint8_t tmpByte = *reinterpret_cast<uint8_t*>(param1 + 0x28);
        *reinterpret_cast<uint8_t*>(param1 + 0x28) = swapBuf[0];
        swapBuf[0] = tmpByte;

        // TODO: Verify the exact field layout for these swaps.
        // Original swaps local_24/local_20 with param_1+0x30/0x34,
        // which appear to be string/pointer fields in the config object.
        ConfigSectionCleanup();

        // ── Load secondary config ──
        uint8_t sectionData2[32];  // local_4c
        LoadSecondaryConfig(sectionData2);

        // ── Load config section 2 (secondary settings) ──
        ReadConfigSection(swapBuf, sectionData2);

        // Swap param1 + 0x38 byte, param1 + 0x40/0x44 fields
        tmpByte = *reinterpret_cast<uint8_t*>(param1 + 0x38);
        *reinterpret_cast<uint8_t*>(param1 + 0x38) = swapBuf[0];
        swapBuf[0] = tmpByte;

        ConfigSectionCleanup();

        // ── Finalize config loading ──
        ConfigPostLoadFinalize();
    }
    else {
        // ── Config file missing — throw exception ──
        // Format: "Default configuration file {} does not exist."
        // 0x2d = 45 = string length including null terminator
        uint32_t errorMsg = FormatErrorString(
            "Default configuration file {} does not exist.", 0x2d);

        ThrowMessage(errorMsg);

        // TODO: Replace with actual C++ exception throw.
        // Original: _CxxThrowException(local_78, (ThrowInfo *)&DAT_006780e8);
        // This throws a runtime_error-style exception with the formatted message.
        throw std::runtime_error("Default configuration file does not exist.");
    }
}

} // namespace Giants
