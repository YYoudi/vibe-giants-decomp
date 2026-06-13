#pragma once
// GiantsRE Proxy — Minimal x86-32 detour helper
//
// The 22 UpCalls callbacks are renderer-initiated, so they only cover a narrow
// slice of the engine. To observe/validate the REST of the engine (FLICK
// interpreter, audio, VFS, subtitles, animation, camera — all of which the intro
// cinematic exercises), we detour-hook engine functions directly inside the
// loaded GiantsMain.exe (the proxy runs in-process, so it can patch engine code).
//
// Hook() overwrites the first ≥5 bytes of `target` with a jmp to `hook` and
// builds a trampoline that executes the relocated prologue then jumps to
// target+len — so the hook can call the original via the trampoline.
//
// Prologue relocation is driven by a conservative length disassembler: it only
// copies WHOLE instructions (never splits one) and REFUSES (returns false) if it
// encounters a relative branch inside the relocated region or any opcode it
// can't decode. That makes the operation safe by construction — we never patch a
// function whose prologue we don't fully understand.

#include <cstdint>

namespace Detour {

// Install a jmp detour at engine function `target`.
//   hook       — our replacement (will receive the caller's stack/args as-is)
//   trampoline  — receives a pointer that runs the original function
// Returns true on success; false (logged) if the prologue can't be safely moved.
bool Hook(void* target, void* hook, void** trampoline);

} // namespace Detour
