// GiantsRE — COM subsystem registry implementation (see ComRegistry.h).
#include "ComRegistry.h"
#include <cstring>

namespace Giants {

namespace {
// Fixed-capacity registry (the original registers a bounded set of subsystems
// during init — the live dump showed count=10 arrays). GUID-pointer keyed.
struct Entry { ComGuid guid; void* obj; };
constexpr int kMaxEntries = 64;
Entry g_entries[kMaxEntries];
int g_count = 0;
} // namespace

void* ComRegister(ComGuid guid, void* obj) {
    if (!guid || !obj) return obj;
    // Replace if already registered under this GUID.
    for (int i = 0; i < g_count; i++) {
        if (g_entries[i].guid == guid) {
            g_entries[i].obj = obj;
            return obj;
        }
    }
    if (g_count < kMaxEntries) {
        g_entries[g_count].guid = guid;
        g_entries[g_count].obj = obj;
        g_count++;
    }
    return obj;
}

void* ComQuery(ComGuid guid) {
    if (!guid) return nullptr;
    for (int i = 0; i < g_count; i++) {
        if (g_entries[i].guid == guid) return g_entries[i].obj;
    }
    return nullptr;
}

int ComRegistryCount() { return g_count; }

} // namespace Giants
