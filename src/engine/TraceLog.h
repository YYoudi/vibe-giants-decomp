#pragma once
// Giants Engine - Trace Logging for Standalone Recompilation
// TRACE_FUNC logs entry/exit of every function to giants_trace.log
// Each logged function gets a unique ID for compact crash analysis.

#include <cstdio>
#include <cstdint>

namespace Giants {

// Global trace log file — opened once at startup, flushed per entry
extern FILE* g_traceLog;

// Initialize trace logging (call once at startup)
inline void TraceInit() {
    g_traceLog = fopen("giants_trace.log", "w");
    if (g_traceLog) {
        fprintf(g_traceLog, "[TRACE] GiantsRE Standalone — trace started\n");
        fflush(g_traceLog);
    }
}

// Shutdown trace logging
inline void TraceShutdown() {
    if (g_traceLog) {
        fprintf(g_traceLog, "[TRACE] Trace shutdown\n");
        fflush(g_traceLog);
        fclose(g_traceLog);
        g_traceLog = nullptr;
    }
}

// Core trace function — logs function entry/exit with address tag
inline void TraceEvent(const char* tag, const char* funcName, const char* file, int line) {
    if (!g_traceLog) return;
    fprintf(g_traceLog, "[%s] %s (%s:%d)\n", tag, funcName, file, line);
    fflush(g_traceLog);
}

} // namespace Giants

// ─── TRACE_FUNC macro ─────────────────────────────────────────
// Place at the top of any function to log entry and exit:
//   void MyFunction() {
//       TRACE_FUNC;
//       ...
//   }
// Produces: [ENTER] MyFunction (file.cpp:42)
//           [EXIT ] MyFunction (file.cpp:42)

#define TRACE_FUNC \
    Giants::TraceEvent("ENTER", __FUNCTION__, __FILE__, __LINE__); \
    struct _TraceGuard { \
        const char* _fn; const char* _fl; int _ln; \
        ~_TraceGuard() { Giants::TraceEvent("EXIT ", _fn, _fl, _ln); } \
    } _traceGuard{__FUNCTION__, __FILE__, __LINE__}

// Lightweight version — just logs ENTER, no exit guard (for hot paths)
#define TRACE_ENTER \
    Giants::TraceEvent("ENTER", __FUNCTION__, __FILE__, __LINE__)
