// Giants Engine - UI Menu Base Complete Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "UIMenuBaseComplete.h"
#include "CRTStubs.h"
#include <cstdlib>
#include <cstring>
namespace Giants {
// DAT_006ff960 from CRTStubs.h
// DAT_00702964 from CRTStubs.h
extern int DAT_00702924;       // Player count
extern HKEY DAT_0074be5c;      // Registry key handle
extern int* DAT_006fef88;      // UI linked list head
extern uint32_t DAT_0068197c;  // Current UI context

// External: FUN_005e80c0 — string lookup
extern const char* StringLookup(const char* key);
// External: FUN_004d3a50 — UI list refresh
extern void UIListRefresh();

void UIMenuBaseComplete(int enable, int param_2)
{
    // Registry write (skip for dedicated server with <=1 players)
    if (((DAT_006ff960 != 6) || (DAT_00702964 != 0)) && (1 < DAT_00702924)) {
        if (DAT_0074be5c != (HKEY)0x0) {
            RegSetValueExA(DAT_0074be5c, "BaseComplete", 0, 4,
                           reinterpret_cast<BYTE*>(&enable), 4);
        }
    }

    if (DAT_006fef88 == (int*)0x0) return;

    // Choose button text (inverted: enable=1 → ButtonYes, enable=0 → ButtonNo)
    const char* buttonText = (enable == 0) ? "ButtonNo" : "ButtonYes";
    buttonText = StringLookup(buttonText);

    // Find and remove existing node with event ID 0x1FA
    if (DAT_006fef88 != (int*)0x0) {
        int* prev = DAT_006fef88;
        int* current = *prev;
        while (current != 0 && *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(current) + 8) != 0x1FA) {
            prev = reinterpret_cast<int*>(*prev);
            current = *prev;
        }
        int* found = reinterpret_cast<int*>(*prev);
        if (found != (int*)0x0) {
            *prev = *found;
            UIListRefresh();
            free(found);
        }
    }

    // Append new node with event 0x1FA
    int* tail = DAT_006fef88;
    if (tail != (int*)0x0) {
        void* newNode = malloc(0x38);
        memset(newNode, 0, 0x38);
        int* current = reinterpret_cast<int*>(*tail);
        while (current != (int*)0x0) {
            tail = current;
            current = reinterpret_cast<int*>(*current);
        }
        *tail = reinterpret_cast<int>(newNode);
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(newNode) + 8) = 0x1FA;

        // Copy button text into node
        const char* src = buttonText;
        char* dst = reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(newNode) + 0xC);
        while (*src) { *dst++ = *src++; }
        *dst = '\0';
    }
}
} // namespace Giants
