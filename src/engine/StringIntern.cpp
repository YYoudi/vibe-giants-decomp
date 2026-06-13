// Giants Engine - String Intern Table Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringIntern.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
// Page-based string intern table
// Each InternPage: {next(4), strings_ptr(4), pad(28), flags(4), hash(4), entries...}
// Free list at DAT_0074b820, Active list at DAT_0074b824
struct InternPage {
    InternPage* next;       // +0x00
    char* strings;          // +0x04
    uint32_t pad[7];        // +0x08..+0x23
    uint32_t flags;         // +0x24
    uint32_t hash;          // +0x28
    int32_t entries[12];    // +0x2C, stride 0x30 per entry
};

static InternPage* g_freePages = nullptr;     // DAT_0074b820
static InternPage* g_activePages = nullptr;   // DAT_0074b824

extern uint32_t ComputeStringHash(const char* str);  // FUN_00632790

// ═══════════════════════════════════════════════════════════════════
// InternString (FUN_005e99d0) — 32 callers — FAIL (usable ~85%)
// ═══════════════════════════════════════════════════════════════════
// String interning: returns a unique pointer for each unique string.
// Search order: free pages → active pages → allocate new.
// Hash-based lookup for O(1) average case per page.

char* InternString(char* str)
{
    if (str == nullptr) {
        return nullptr;
    }

    uint32_t hash = ComputeStringHash(str);

    // Phase 1: Search free pages
    InternPage* page = g_freePages;
    while (page != nullptr) {
        uint32_t entryCount = page->hash;

        if (entryCount != 0) {
            int* entry = reinterpret_cast<int*>(page) + 0x14;
            uint32_t idx = 0;
            do {
                if (*entry == static_cast<int>(hash)) {
                    // Found match — return string at this entry
                    return reinterpret_cast<char*>(
                        reinterpret_cast<uint32_t*>(page) + idx * 0xC + 0xB);
                }
                idx++;
                entry += 0xC;
            } while (idx < entryCount);

            if (idx < entryCount) break;  // re-agent: missing break
        }

        page = page->next;
    }

    // Phase 2: Search active pages
    InternPage* activePage = g_activePages;
    while (activePage != nullptr) {
        if (activePage->hash == hash) {
            return activePage->strings;
        }
        activePage = activePage->next;
    }

    // Phase 3: Allocate new page and copy string
    char* end = str;
    while (*end != '\0') end++;

    size_t allocSize = static_cast<size_t>(end + 0x38 - (str + 1));
    InternPage* newPage = static_cast<InternPage*>(malloc(allocSize));
    memset(newPage, 0, allocSize);

    newPage->next = g_activePages;
    newPage->strings = reinterpret_cast<char*>(newPage) + 0x34;
    g_activePages = newPage;

    // Copy string into page
    char* dst = newPage->strings;
    const char* src = str;
    char c;
    do {
        c = *src;
        src++;
        dst[src - str - 1] = c;
    } while (c != '\0');

    newPage->flags |= 0x1000;
    newPage->hash = ComputeStringHash(newPage->strings);

    return newPage->strings;
}

} // namespace Giants
