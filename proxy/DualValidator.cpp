// GiantsRE Proxy — DualValidator implementation
//
// Static per-slot counters + reporting. See DualValidator.h for the rationale
// (in-game shadow-predict vs deterministic self-test).

#include "DualValidator.h"
#include "Logger.h"
#include "HookTable.h"

#include <cstdio>
#include <cstdarg>

namespace DualValidator {

static Stats g_stats[MAX] = {};

void RecordCall(int idx) {
    if (idx >= 0 && idx < MAX) g_stats[idx].calls++;
}

void RecordMismatch(int idx, const char* fmt, ...) {
    if (idx < 0 || idx >= MAX) return;
    g_stats[idx].mismatches++;
    char buf[512];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    Logger::Log("MISMATCH[%2d] %-22s #%u: %s",
                idx, HookTable::SLOT_NAMES[idx], g_stats[idx].calls, buf);
}

void SelfTestRecord(int idx, uint32_t /*n*/) {
    if (idx >= 0 && idx < MAX) g_stats[idx].selftest_calls++;
}

void SelfTestMismatch(int idx, const char* fmt, ...) {
    if (idx < 0 || idx >= MAX) return;
    g_stats[idx].selftest_mismatch++;
    char buf[512];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    Logger::Log("SELFTEST-MISMATCH[%2d] %-22s: %s",
                idx, HookTable::SLOT_NAMES[idx], buf);
}

void MarkHasImpl(int idx) {
    if (idx >= 0 && idx < MAX) g_stats[idx].has_impl = true;
}

const Stats& Get(int idx) { return g_stats[idx]; }

void ReportAll() {
    Logger::Separator();
    Logger::Log("[DualValidator] Validation report:");
    Logger::Separator();
    for (int i = 0; i < MAX; i++) {
        const Stats& s = g_stats[i];
        if (!s.has_impl && s.calls == 0 && s.selftest_calls == 0) continue;

        Logger::Log("  [%2d] %-22s impl=%s | in-game: %u calls, %u mismatches | selftest: %u calls, %u mismatches",
                    i, HookTable::SLOT_NAMES[i],
                    s.has_impl ? "YES" : "no ",
                    s.calls, s.mismatches,
                    s.selftest_calls, s.selftest_mismatch);
    }
    Logger::Separator();
}

} // namespace DualValidator
