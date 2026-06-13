// GiantsRE Proxy — Hook Table Implementation

#include "HookTable.h"
#include "Logger.h"

#include <cstring>

namespace HookTable {

static HookEntry s_hooks[MAX_HOOKS] = {};

void SetOriginal(int index, void* originalFunc) {
    if (index < 0 || index >= MAX_HOOKS) return;
    s_hooks[index].originalFunc = originalFunc;
    if (!s_hooks[index].name) {
        s_hooks[index].name = SLOT_NAMES[index];
    }
}

void SetHook(int index, void* hookFunc) {
    if (index < 0 || index >= MAX_HOOKS) return;
    s_hooks[index].hookFunc = hookFunc;
    s_hooks[index].name = SLOT_NAMES[index];
    // Don't activate yet — call Apply() to activate
}

void* GetOriginal(int index) {
    if (index < 0 || index >= MAX_HOOKS) return nullptr;
    return s_hooks[index].originalFunc;
}

void Apply(void** callbackTable, uint32_t count) {
    int applied = 0;
    for (uint32_t i = 0; i < count && i < (uint32_t)MAX_HOOKS; i++) {
        if (s_hooks[i].hookFunc && !s_hooks[i].active) {
            s_hooks[i].active = true;
            callbackTable[i] = s_hooks[i].hookFunc;
            Logger::Log("  HOOK[%2u] %-25s : 0x%p → 0x%p",
                        i, SLOT_NAMES[i],
                        s_hooks[i].originalFunc, s_hooks[i].hookFunc);
            applied++;
        }
    }
}

bool IsHooked(int index) {
    if (index < 0 || index >= MAX_HOOKS) return false;
    return s_hooks[index].active;
}

int ActiveHookCount() {
    int count = 0;
    for (int i = 0; i < MAX_HOOKS; i++) {
        if (s_hooks[i].active) count++;
    }
    return count;
}

const HookEntry& GetEntry(int index) {
    return s_hooks[index];
}

} // namespace HookTable
