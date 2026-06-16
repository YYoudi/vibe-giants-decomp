// Giants Vanilla-Native Recomp — Engine file I/O layer. See VanillaFileIO.h.
#include "VanillaFileIO.h"
#include "VanillaVFS.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

extern FILE* g_vTrace;

namespace {

struct VFile {
    std::vector<uint8_t> data;
    uint32_t pos = 0;
    bool used = false;
};
VFile g_table[64];   // up to 64 concurrent open files (handle = index+1, 0=invalid)

VFile* slot(uint32_t h) {
    if (h == 0 || h > 64) return nullptr;
    VFile* f = &g_table[h - 1];
    return f->used ? f : nullptr;
}

std::string basename(const char* p) {
    std::string s = p;
    // strip drive/dir: keep after last \ or /
    size_t bs = s.find_last_of("\\/");
    if (bs != std::string::npos) s = s.substr(bs + 1);
    return s;
}
std::string lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return (char)tolower(c); });
    return s;
}

// Try to resolve a filename to bytes: loose Bin/<base> first, then all Bin/*.gzp archives.
bool resolve(const char* filename, std::vector<uint8_t>& out) {
    std::string base = basename(filename);
    // 1. loose file: Bin\<base>
    char path[512];
    snprintf(path, sizeof(path), "Bin\\%s", base.c_str());
    FILE* f = fopen(path, "rb");
    if (f) {
        fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
        if (n > 0) { out.resize(n); size_t r = fread(out.data(), 1, n, f); fclose(f); return r == (size_t)n; }
        fclose(f);
    }
    // 2. search all Bin/*.gzp archives
    std::string baseL = lower(base);
    WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA("Bin\\*.gzp", &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            char gzpPath[512]; snprintf(gzpPath, sizeof(gzpPath), "Bin\\%s", fd.cFileName);
            std::vector<VanillaVFS::GzpEntry> entries;
            if (VanillaVFS::GzpOpen(gzpPath, entries)) {
                for (auto& e : entries) {
                    if (lower(e.name) == baseL) {
                        fclose(fopen(gzpPath, "rb")); // touch
                        auto data = VanillaVFS::GzpReadFile(gzpPath, e.name.c_str());
                        if (!data.empty()) { out = std::move(data); FindClose(h); return true; }
                    }
                }
            }
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
    return false;
}

} // namespace

extern "C" uint32_t FUN_00539e30(const char* filename) {
    std::vector<uint8_t> data;
    if (!resolve(filename, data)) {
        if (g_vTrace) { fprintf(g_vTrace, "[VFILE] open FAILED: %s\n", filename); fflush(g_vTrace); }
        return 0;
    }
    for (uint32_t i = 0; i < 64; i++) {
        if (!g_table[i].used) {
            g_table[i].data = std::move(data);
            g_table[i].pos = 0;
            g_table[i].used = true;
            if (g_vTrace) { fprintf(g_vTrace, "[VFILE] open '%s' -> handle %u (%zu bytes)\n", filename, i + 1, g_table[i].data.size()); fflush(g_vTrace); }
            return i + 1;
        }
    }
    return 0;
}

extern "C" void FUN_0051d750(uint32_t handle, void* buf, uint32_t count) {
    VFile* f = slot(handle);
    if (!f || !buf) return;
    uint32_t avail = (uint32_t)f->data.size() - f->pos;
    uint32_t n = count < avail ? count : avail;
    if (n) memcpy(buf, f->data.data() + f->pos, n);
    f->pos += n;
}

extern "C" void FUN_0051d7b0(uint32_t handle, char* buf) {
    VFile* f = slot(handle);
    if (!f || !buf) return;
    // read a C-string (until null or end) — the engine stores null-terminated strings.
    uint32_t start = f->pos;
    while (f->pos < f->data.size() && f->data[f->pos] != 0) f->pos++;
    uint32_t len = f->pos - start;
    if (len) memcpy(buf, f->data.data() + start, len);
    buf[len] = 0;
    if (f->pos < f->data.size()) f->pos++; // skip the null terminator
}

extern "C" void FUN_0051d850(uint32_t handle) {
    VFile* f = slot(handle);
    if (!f) return;
    f->data.clear(); f->pos = 0; f->used = false;
}

namespace VanillaFileIO {
int SelfTest() {
    // Open WorldList.bin (loose) + read its magic, and open a GZP file.
    uint32_t h = FUN_00539e30("WorldList.bin");
    if (h) {
        uint32_t magic = 0;
        FUN_0051d750(h, &magic, 4);
        // read first world name line
        char name[64] = {0};
        FUN_0051d7b0(h, name);
        if (g_vTrace) { fprintf(g_vTrace, "[VFILE] WorldList.bin magic=%08x first='%s'\n", magic, name); fflush(g_vTrace); }
        FUN_0051d850(h);
    }
    // GZP-resident file
    uint32_t h2 = FUN_00539e30("intro_island.gti");
    if (h2) {
        uint32_t magic = 0;
        FUN_0051d750(h2, &magic, 4);
        if (g_vTrace) { fprintf(g_vTrace, "[VFILE] intro_island.gti magic=%08x (expect 94965003)\n", magic); fflush(g_vTrace); }
        FUN_0051d850(h2);
    }
    int leak = 0;
    for (auto& f : g_table) if (f.used) leak++;
    return leak;
}
} // namespace VanillaFileIO
