// GiantsRE Proxy — Detour.cpp
//
// Minimal x86-32 jmp detour with a conservative length disassembler.
// See Detour.h for the safety rationale.

#include "Detour.h"
#include "Logger.h"

#include <windows.h>
#include <cstring>

namespace {

// ─────────────────────────────────────────────────────────────────
// Conservative instruction-length decoder (x86-32, no MMX/SSE at entries).
// Returns the length of ONE instruction starting at `p`, or 0 if it can't
// decode it. Sets *relBranch=true for relative control flow (jcc/jmp/call/loop)
// — callers REFUSE to relocate across such instructions.
// ─────────────────────────────────────────────────────────────────
int InsnLen(const uint8_t* p, bool* relBranch) {
    *relBranch = false;
    int i = 0;

    // Prefixes: operand-size 66, address-size 67, lock/rep F0/F2/F3, segment 26/2E/36/3E/64/65
    for (;;) {
        uint8_t b = p[i];
        if (b == 0x66 || b == 0x67 || b == 0xF0 || b == 0xF2 || b == 0xF3 ||
            b == 0x26 || b == 0x2E || b == 0x36 || b == 0x3E || b == 0x64 || b == 0x65) {
            i++;
            if (i >= 16) return 0; // absurd prefix run — bail
            continue;
        }
        break;
    }

    uint8_t op = p[i];
    int base = i + 1; // byte after the opcode

    // modrm length (1 byte modrm + displacement + optional SIB)
    auto modrmLen = [&](int o) -> int {
        uint8_t m = p[o];
        int mod = m >> 6;
        int rm = m & 7;
        int l = 1;
        if (mod == 3) return l;              // register operand, no disp
        if (mod == 0) {
            if (rm == 5) l += 4;             // disp32
            else if (rm == 4) {              // SIB
                l += 1;
                uint8_t sib = p[o + 1];
                if ((sib & 7) == 5) l += 4;  // SIB+disp32
            }
        } else if (mod == 1) {
            l += 1;                          // disp8
            if (rm == 4) l += 1;             // SIB
        } else { // mod == 2
            l += 4;                          // disp32
            if (rm == 4) l += 1;             // SIB
        }
        return l;
    };

    switch (op) {
        // ── ALU r/m,r and r,r/m (modrm only) ──
        case 0x00: case 0x01: case 0x02: case 0x03:
        case 0x08: case 0x09: case 0x0A: case 0x0B:
        case 0x10: case 0x11: case 0x12: case 0x13:
        case 0x18: case 0x19: case 0x1A: case 0x1B:
        case 0x20: case 0x21: case 0x22: case 0x23:
        case 0x28: case 0x29: case 0x2A: case 0x2B:
        case 0x30: case 0x31: case 0x32: case 0x33:
        case 0x38: case 0x39: case 0x3A: case 0x3B:
        // ── test/xchg/mov/lea r/m ──
        case 0x84: case 0x85: case 0x86: case 0x87:
        case 0x88: case 0x89: case 0x8A: case 0x8B:
        case 0x8D: case 0x8E: case 0x8F:
        // ── shift/rotate r/m,1 or CL ──
        case 0xD0: case 0xD1: case 0xD2: case 0xD3:
        // ── misc group (FF: inc/dec/call/jmp/push r/m) ──
        case 0xFF:
            return base + modrmLen(base);

        // ── ALU AL/eAX, imm ──
        case 0x04: case 0x0C: case 0x14: case 0x1C:
        case 0x24: case 0x2C: case 0x34: case 0x3C:   // AL, imm8
            return base + 1;
        case 0x05: case 0x0D: case 0x15: case 0x1D:
        case 0x25: case 0x2D: case 0x35: case 0x3D:   // eAX, imm32 (16 with 0x66 — rare at entry)
            return base + 4;

        // ── 1-byte opcodes (no operands) ──
        case 0x50: case 0x51: case 0x52: case 0x53:   // push r
        case 0x54: case 0x55: case 0x56: case 0x57:
        case 0x58: case 0x59: case 0x5A: case 0x5B:   // pop r
        case 0x5C: case 0x5D: case 0x5E: case 0x5F:
        case 0x90: case 0x91: case 0x92: case 0x93:   // xchg/nop
        case 0x94: case 0x95: case 0x96: case 0x97:
        case 0x98: case 0x99:                          // cbw/cwde, cdq
        case 0x9C: case 0x9D: case 0x9E: case 0x9F:   // pushfd/popfd/sahf/lahf
        case 0xC3: case 0xCB:                          // ret retf (near/far)
        case 0xC9:                                     // leave
        case 0xF4: case 0xF5:                          // hlt cmc
        case 0xF8: case 0xF9: case 0xFA: case 0xFB:   // clc stc cli sti
        case 0xFC: case 0xFD:                          // cld std
        case 0xA4: case 0xA5: case 0xA6: case 0xA7:   // movs/cmps
        case 0xAA: case 0xAB: case 0xAC: case 0xAD:   // stos/lods
        case 0xAE: case 0xAF:                          // scas
            return base;

        // ── 0F two-byte escape (SSE/MMX/cmov/etc.) ──
        // Whitelist sub-opcodes that take a modrm (the common SIMD moves/arith).
        // Refuses anything else so we never mis-relocate. SSE2-using functions
        // (movss/movaps/...) are common in the math/trig modules — this unblocks
        // hooking them.
        case 0x0F: {
            uint8_t sub = p[base];                 // second opcode byte
            auto hasModrm = [](uint8_t s) -> bool {
                switch (s) {
                  // SSE moves / shuffle / arithmetic (all modrm)
                  case 0x10: case 0x11: case 0x12: case 0x13:
                  case 0x14: case 0x15: case 0x16: case 0x17:
                  case 0x28: case 0x29: case 0x2A: case 0x2B:
                  case 0x2C: case 0x2D: case 0x2E: case 0x2F:
                  case 0x40: case 0x41: case 0x42: case 0x43:
                  case 0x44: case 0x45: case 0x46: case 0x47:
                  case 0x48: case 0x49: case 0x4A: case 0x4B:
                  case 0x4C: case 0x4D: case 0x4E: case 0x4F:   // cmov
                  case 0x50: case 0x51: case 0x52: case 0x53:
                  case 0x54: case 0x55: case 0x56: case 0x57:
                  case 0x58: case 0x59: case 0x5A: case 0x5B:
                  case 0x5C: case 0x5D: case 0x5E: case 0x5F:   // SSE arith
                  case 0x60: case 0x61: case 0x62: case 0x63:
                  case 0x64: case 0x65: case 0x66: case 0x67:
                  case 0x68: case 0x69: case 0x6A: case 0x6B:
                  case 0x6C: case 0x6D: case 0x6E: case 0x6F:   // MMX/SSE2
                  case 0x70: case 0x71: case 0x72: case 0x73:
                  case 0x74: case 0x75: case 0x76: case 0x77:
                  case 0x7E: case 0x7F:
                  case 0xA4: case 0xA5: case 0xAC: case 0xAD: // shld/shrd
                  case 0xB0: case 0xB1: case 0xB6: case 0xB7:  // cmpxchg/movzx
                  case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF:
                  case 0xC0: case 0xC1: case 0xC2: case 0xC3:
                  case 0xC4: case 0xC5: case 0xC6: case 0xC7:
                  case 0xD0: case 0xD1: case 0xD2: case 0xD3:
                  case 0xD4: case 0xD5: case 0xD6: case 0xD7:
                  case 0xD8: case 0xD9: case 0xDA: case 0xDB:
                  case 0xDC: case 0xDD: case 0xDE: case 0xDF:
                  case 0xE0: case 0xE1: case 0xE2: case 0xE3:
                  case 0xE4: case 0xE5: case 0xE6: case 0xE7:
                  case 0xE8: case 0xE9: case 0xEA: case 0xEB:
                  case 0xEC: case 0xED: case 0xEE: case 0xEF:
                  case 0xF0: case 0xF1: case 0xF2: case 0xF3:
                  case 0xF4: case 0xF5: case 0xF6: case 0xF7:
                  case 0xF8: case 0xF9: case 0xFA: case 0xFB:
                  case 0xFC: case 0xFD: case 0xFE:
                    return true;
                  default:
                    return false;
                }
            };
            if (!hasModrm(sub)) return 0;          // refuse unknown 0F ops
            int mlen = modrmLen(base + 1);
            int imm = 0;
            // 0F sub-opcodes with a trailing imm8
            if (sub==0x70 || sub==0x71 || sub==0x72 || sub==0x73 ||
                sub==0xC2 || sub==0xC4 || sub==0xC5 || sub==0xC6 || sub==0xBA)
                imm = 1;
            return base + 1 + mlen + imm;          // 0F + sub + modrm [+ imm8]
        }


        // ── push/pop imm ──
        case 0x6A: return base + 1;   // push imm8
        case 0x68: return base + 4;   // push imm32

        // ── mov acc,moffs / moffs,acc (32-bit address) ──
        case 0xA0: case 0xA1: case 0xA2: case 0xA3:
            return base + 4;

        // ── mov r8,imm8 / mov r32,imm32 ──
        case 0xB0: case 0xB1: case 0xB2: case 0xB3:
        case 0xB4: case 0xB5: case 0xB6: case 0xB7:
            return base + 1;
        case 0xB8: case 0xB9: case 0xBA: case 0xBB:
        case 0xBC: case 0xBD: case 0xBE: case 0xBF:
            return base + 4;

        // ── group: r/m, imm8 ── (sub/add/cmp r/m,imm8 = 0x83 — the classic prologue)
        case 0x83: case 0x80: case 0x82:              // 0x82 alias of 0x80
            return base + modrmLen(base) + 1;
        // ── group: r/m, imm32 ──
        case 0x81:
            return base + modrmLen(base) + 4;
        // ── shift r/m, imm8 ──
        case 0xC0: case 0xC1:
            return base + modrmLen(base) + 1;
        // ── mov r/m, imm ──
        case 0xC6: return base + modrmLen(base) + 1;  // imm8
        case 0xC7: return base + modrmLen(base) + 4;  // imm32

        // ── unary group F6/F7 (test/not/neg/mul/div) — only /0,/1 take an imm ──
        case 0xF6: {
            int l = base + modrmLen(base);
            if (((p[base] >> 3) & 7) <= 1) l += 1;
            return l;
        }
        case 0xF7: {
            int l = base + modrmLen(base);
            if (((p[base] >> 3) & 7) <= 1) l += 4;
            return l;
        }

        // ── ret imm16 / int imm8 / enter ──
        case 0xC2: return base + 2;   // ret imm16
        case 0xCD: return base + 1;   // int imm8
        case 0xC8: return base + 3;   // enter imm16,imm8

        // ── relative control flow — decode length but FLAG as relocatable-unsafe ──
        case 0x70: case 0x71: case 0x72: case 0x73:
        case 0x74: case 0x75: case 0x76: case 0x77:
        case 0x78: case 0x79: case 0x7A: case 0x7B:
        case 0x7C: case 0x7D: case 0x7E: case 0x7F:   // jcc rel8
            *relBranch = true; return base + 1;
        case 0xEB: *relBranch = true; return base + 1; // jmp rel8
        case 0xE0: case 0xE1: case 0xE2: case 0xE3:   // loop/loopx/jcxz
            *relBranch = true; return base + 1;
        case 0xE8: *relBranch = true; return base + 4; // call rel32
        case 0xE9: *relBranch = true; return base + 4; // jmp rel32
        case 0xEA: return base + 6;                    // jmp far ptr16:32 (no rel flag)

        default:
            return 0; // unknown — caller refuses
    }
}

} // namespace

namespace Detour {

bool Hook(void* target, void* hook, void** trampoline) {
    if (!target || !hook || !trampoline) return false;
    *trampoline = nullptr;

    uint8_t* t = static_cast<uint8_t*>(target);

    // Safety gate: only hook the canonical MSVC frame prologue (55 8B EC =
    // push ebp; mov ebp,esp). Proven safe across millions of calls (FLICK, Math).
    // esp-frame starts (81 EC / 83 EC) are clean function starts but one such
    // target (Audio_InitAudioSystem) crashes when hooked — likely a non-cdecl
    // convention or SEH prologue — so we restrict to ebp-frame for now and
    // revisit esp-frame targets once their real entry + convention are confirmed.
    Logger::Log("[detour] bytes@0x%p: %02X %02X %02X %02X %02X %02X %02X %02X",
                target, t[0], t[1], t[2], t[3], t[4], t[5], t[6], t[7]);
    if (!(t[0] == 0x55 && t[1] == 0x8B && t[2] == 0xEC)) {
        Logger::Log("[detour] REFUSE 0x%p: not the canonical ebp-frame prologue "
                    "(interior addr or esp-frame/SEH start — skipped for safety)", target);
        return false;
    }

    // 1) Accumulate whole instructions until ≥5 bytes; refuse on any relative
    //    branch in the relocated region or any unknown opcode.
    int copylen = 0;
    while (copylen < 5) {
        bool rel = false;
        int len = InsnLen(t + copylen, &rel);
        if (len == 0) {
            Logger::Log("[detour] REFUSE 0x%p: undecoded opcode at +%d (bytes %02X %02X %02X %02X)",
                        target, copylen, t[copylen], t[copylen+1], t[copylen+2], t[copylen+3]);
            return false;
        }
        if (rel) {
            Logger::Log("[detour] REFUSE 0x%p: relative branch in prologue at +%d", target, copylen);
            return false;
        }
        copylen += len;
        if (copylen > 16) {
            Logger::Log("[detour] REFUSE 0x%p: prologue too long (%d)", target, copylen);
            return false;
        }
    }

    // 2) Build the trampoline: [relocated prologue bytes][jmp target+copylen]
    uint8_t* tr = static_cast<uint8_t*>(
        VirtualAlloc(nullptr, 32, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));
    if (!tr) { Logger::Log("[detour] VirtualAlloc(trampoline) failed %u", GetLastError()); return false; }
    std::memcpy(tr, t, copylen);
    tr[copylen] = 0xE9;
    int32_t jmpBack = static_cast<int32_t>((t + copylen) - (tr + copylen + 5));
    std::memcpy(tr + copylen + 1, &jmpBack, 4);
    *trampoline = tr;

    // 3) Patch the target: jmp hook, NOP the remainder.
    DWORD oldProt = 0;
    if (!VirtualProtect(t, static_cast<SIZE_T>(copylen), PAGE_EXECUTE_READWRITE, &oldProt)) {
        Logger::Log("[detour] VirtualProtect(target) failed %u", GetLastError());
        VirtualFree(tr, 0, MEM_RELEASE);
        *trampoline = nullptr;
        return false;
    }
    t[0] = 0xE9;
    int32_t jmpIn = static_cast<int32_t>(static_cast<uint8_t*>(hook) - (t + 5));
    std::memcpy(t + 1, &jmpIn, 4);
    for (int i = 5; i < copylen; i++) t[i] = 0x90; // NOP pad
    DWORD dummy = 0;
    VirtualProtect(t, static_cast<SIZE_T>(copylen), oldProt, &dummy);
    FlushInstructionCache(GetCurrentProcess(), t, static_cast<SIZE_T>(copylen));

    Logger::Log("[detour] OK 0x%p -> hook 0x%p (trampoline 0x%p, copylen=%d)",
                target, hook, tr, copylen);
    return true;
}

} // namespace Detour
