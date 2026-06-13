// Giants Engine - UI/Console Linked List Operations Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "UIList.h"
#include "CRTStubs.h"
#include <cstring>
#include <cstdlib>

namespace Giants {

// ─── Globals ──────────────────────────────────────────────────
static uint32_t g_TypeA = 0;  // DAT_0066bd58 — default node type
static uint32_t g_TypeB = 0;  // DAT_0066bd50 — alternate node type (flag 0x1000000)

// External callees
extern char* LookupStringById(uint32_t id);  // FUN_005e80c0
extern void  NotifyUIListChanged();          // FUN_004d3dd0

// ═══════════════════════════════════════════════════════════════════
// AppendUIListNode (FUN_004d3bf0) — 54 callers
// ═══════════════════════════════════════════════════════════════════
// Appends a new node to a singly-linked list used for UI/console text.
// Supports two text modes: direct pointer assignment or strdup.
// Supports string ID resolution via FUN_005e80c0.

void AppendUIListNode(UIListNode** head, uint32_t id, uint32_t flags,
                       char* text, float x, float y)
{
    if (head == nullptr) {
        return;
    }

    // Allocate and zero-initialize new node
    UIListNode* newNode = static_cast<UIListNode*>(malloc(sizeof(UIListNode)));
    memset(newNode, 0, sizeof(UIListNode));

    // Traverse to tail
    UIListNode* current = *head;
    while (current != nullptr) {
        head = &current->next;
        current = *head;
    }

    // Link at tail
    newNode->id = id;
    *head = newNode;

    // String ID lookup (flag bit 25)
    if ((flags & 0x2000000) != 0) {
        text = LookupStringById(reinterpret_cast<uint32_t>(text));
    }

    // Type selection (flag bit 24)
    uint32_t type = g_TypeA;
    if ((flags & 0x1000000) != 0) {
        type = g_TypeB;
    }

    // Text handling: flag bit 0 = strdup, otherwise direct pointer
    if ((flags & 1) == 0) {
        newNode->text = text;
    } else {
        // Calculate string length
        char* scanner = text;
        char ch;
        do { ch = *scanner; scanner++; } while (ch != '\0');
        size_t len = static_cast<size_t>(scanner - text);

        // Allocate and copy
        char* buffer = static_cast<char*>(malloc(len));
        newNode->text = buffer;
        do {
            ch = *text;
            text++;
            *buffer = ch;
            buffer++;
        } while (ch != '\0');
    }

    // Set fields
    newNode->x = x;
    newNode->y = y;
    newNode->type = type;
    newNode->flags = flags;
    newNode->field_34 = 0;

    NotifyUIListChanged();
}

} // namespace Giants
