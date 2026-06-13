#pragma once
// GiantsRE Proxy — Generic Dual-Mode Validation Framework
//
// Centralizes bookkeeping for validating RE'd callbacks against the ORIGINAL
// engine functions, in two modes:
//
//   IN-GAME (shadow-predict): the game calls our hook; we compute the expected
//   result, call the original, compare, and ALWAYS return the original's result
//   (zero-risk — the game never breaks during validation).
//
//   SELF-TEST (deterministic): the PROXY itself drives both implementations
//   with a fixed vector (e.g. an angle sweep for SinCosLookup) and compares.
//   This decouples validation from game coverage — pure callbacks become
//   batch-validatable the moment we RE them, without waiting for the game to
//   exercise them.
//
// One slot per UpCalls callback index (0..21). All counters live here so
// proxy_main's DETACH report and per-hook logging stay consistent.

#include <cstdint>

namespace DualValidator {

constexpr int MAX = 22;   // matches HookTable::MAX_HOOKS

struct Stats {
    uint32_t calls;             // in-game invocations (from hooks)
    uint32_t mismatches;        // in-game divergences vs original
    uint32_t selftest_calls;    // deterministic self-test invocations
    uint32_t selftest_mismatch; // self-test divergences
    bool     has_impl;          // do we have an RE'd implementation for this slot?
};

// ── In-game hook API ──────────────────────────────────────────
void RecordCall(int idx);
void RecordMismatch(int idx, const char* fmt, ...);
// Throttle for routine VALIDATE logs: first 10, then every 200.
inline bool ShouldLog(uint32_t n) { return n <= 10 || (n % 200) == 0; }

// ── Self-test API (proxy drives, not the game) ────────────────
void SelfTestRecord(int idx, uint32_t n);
void SelfTestMismatch(int idx, const char* fmt, ...);

// ── Bookkeeping ───────────────────────────────────────────────
void MarkHasImpl(int idx);
const Stats& Get(int idx);

// Full report — called from DllMain DLL_PROCESS_DETACH.
void ReportAll();

} // namespace DualValidator
