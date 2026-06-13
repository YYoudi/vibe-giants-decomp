#pragma once
// GiantsRE Proxy Logger — simple file logging for debugging
// Writes to giants_proxy.log in the game directory

#include <cstdio>
#include <cstdarg>
#include <ctime>

namespace Logger {

inline FILE* GetLogFile() {
    static FILE* s_log = nullptr;
    if (!s_log) {
        s_log = fopen("giants_proxy.log", "a");
        if (!s_log) return nullptr;
    }
    return s_log;
}

inline void Log(const char* fmt, ...) {
    FILE* f = GetLogFile();
    if (!f) return;

    // Timestamp
    time_t now = time(nullptr);
    struct tm* t = localtime(&now);
    fprintf(f, "[%02d:%02d:%02d] ", t->tm_hour, t->tm_min, t->tm_sec);

    va_list args;
    va_start(args, fmt);
    vfprintf(f, fmt, args);
    va_end(args);

    fprintf(f, "\n");
    fflush(f);
}

inline void Separator() {
    FILE* f = GetLogFile();
    if (!f) return;
    fprintf(f, "══════════════════════════════════════════════════════\n");
    fflush(f);
}

} // namespace Logger
