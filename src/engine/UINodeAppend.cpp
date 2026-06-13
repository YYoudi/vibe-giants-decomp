// Giants Engine - UI Node Append Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "UINodeAppend.h"
#include <cstdlib>
#include <cstring>
namespace Giants {
extern uint32_t* DAT_006fef88;  // UI linked list head
extern void FUN_004d3dd0();     // UI refresh after append

void UINodeAppend(uint32_t param_1, uint32_t eventId, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5)
{
    if (DAT_006fef88 == nullptr) return;

    // Allocate new node
    void* newNode = malloc(0x38);
    memset(newNode, 0, 0x38);

    // Walk to tail of linked list
    uint32_t* tail = DAT_006fef88;
    uint32_t* current = reinterpret_cast<uint32_t*>(*tail);
    while (current != nullptr) {
        tail = current;
        current = reinterpret_cast<uint32_t*>(*current);
    }

    // Link new node at tail
    *tail = reinterpret_cast<uint32_t>(newNode);

    // Set event ID at +0x8
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(newNode) + 8) = eventId;

    // Allocate and copy "O1" string at +0x28
    char* str = static_cast<char*>(malloc(3));
    *reinterpret_cast<char**>(reinterpret_cast<uintptr_t>(newNode) + 0x28) = str;
    str[0] = 'O'; str[1] = '1'; str[2] = '\0';

    // XMM2/XMM3 params stored at +0x10/+0x14 (simplified as param_3/param_4)
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(newNode) + 0x10) = param_3;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(newNode) + 0x14) = param_4;

    // Fixed float value 0.1f at +0x30
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(newNode) + 0x30) = 0x3CCCCCD;  // 0.1f

    // Command flags at +0xC
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(newNode) + 0xC) = 0x81000003;

    // param_5 at +0x34
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(newNode) + 0x34) = param_5;

    // Refresh UI
    FUN_004d3dd0();
}
} // namespace Giants
