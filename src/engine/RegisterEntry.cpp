// Giants Engine - Register Entry Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: FAIL (usable ~80%)
#include "RegisterEntry.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

// ListNode layout (0x38 bytes)
struct ListNode {
    ListNode* prev;        // +0x00
    ListNode* next;        // +0x04
    float     x;           // +0x08
    char      strBuf[24];  // +0x0C (inline SSO string)
    uint32_t  hash;        // +0x24
    float     y;           // +0x28
    float     z;           // +0x2C
    uint32_t  param2;      // +0x30
    uint32_t  param3;      // +0x34
};

extern ListNode* g_listSentinel;  // DAT_00728348
extern uint32_t  g_listSize;      // DAT_0072834c
extern uint32_t  DAT_0067d280;    // Security cookie

extern uint32_t FUN_00632760(const char* name, uint32_t cookie); // ComputeHash
extern void     FUN_0043cb70(const char* src, int len);  // CopyStringData
extern void     FUN_004431a0(void* dest);                // InitNodeString
extern void     FUN_004439b0();                          // PostInsertNotify

int RegisterEntry(const char* name, uint32_t param2, uint32_t param3,
                  float xmm1, float xmm2, float xmm3)
{
    uint32_t cookie = DAT_0067d280 ^ reinterpret_cast<uint32_t>(&name);
    uint32_t hash = FUN_00632760(name, cookie);

    // Search existing entries by hash
    for (ListNode* node = g_listSentinel->prev; node != g_listSentinel; node = node->prev)
    {
        if (node->hash == hash)
        {
            node->x = xmm3;
            return 0;
        }
    }

    // Compute string length
    const char* p = name;
    char c;
    do { c = *p; p++; } while (c != '\0');
    uint32_t len = static_cast<uint32_t>(reinterpret_cast<intptr_t>(p) - reinterpret_cast<intptr_t>(name + 1));

    // Copy string data into local SBO buffer
    FUN_0043cb70(name, len);

    // Check list capacity
    if (g_listSize == 0x4924924)
        return 0;

    // Allocate new node
    ListNode* newNode = static_cast<ListNode*>(malloc(sizeof(ListNode)));
    memset(newNode, 0, sizeof(ListNode));
    newNode->x = xmm3;

    FUN_004431a0(&newNode->strBuf);  // Init node string

    newNode->hash = hash;
    newNode->y = xmm1;
    newNode->z = xmm2;
    newNode->param2 = param2;
    newNode->param3 = param3;

    // Insert at head of intrusive doubly-linked list
    g_listSize++;
    ListNode* oldHead = g_listSentinel->next;
    newNode->prev = g_listSentinel;
    newNode->next = oldHead;
    g_listSentinel->next = newNode;
    oldHead->prev = newNode;

    FUN_004439b0();

    return 1;
}

} // namespace Giants
