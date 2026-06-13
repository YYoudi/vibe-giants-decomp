// Giants Engine - Tree Node String Append Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TreeNodeAppend.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

void AppendStringToNode(int* rootNode, int nodeId, char* str, uint32_t param4)
{
    int* node = reinterpret_cast<int*>(*rootNode);
    if (node == nullptr)
        return;

    // Find node matching nodeId
    while (node[2] != nodeId)
    {
        node = reinterpret_cast<int*>(*node);
        if (node == nullptr)
            return;
    }

    // Walk to tail of child list at node[10]
    int* child = reinterpret_cast<int*>(node[10]);
    int** tailPtr = reinterpret_cast<int**>(&node[10]);
    while (child != nullptr)
    {
        tailPtr = reinterpret_cast<int**>(child);
        child = reinterpret_cast<int*>(*child);
    }

    // Measure string length
    const char* p = str;
    char c;
    do { c = *p; p++; } while (c != '\0');
    size_t strLen = p - str;
    size_t allocSize = 16 + strLen + 1;

    // Allocate and link new child node
    uint32_t* newChild = static_cast<uint32_t*>(malloc(allocSize));
    *tailPtr = reinterpret_cast<int*>(newChild);

    newChild[0] = 0;                          // next = null
    newChild[1] = param4;                     // param4
    newChild[2] = 0;                          // count
    newChild[3] = reinterpret_cast<uint32_t>(newChild + 4);  // data ptr

    // Copy string into child node data area
    memcpy(newChild + 4, str, strLen);

    // Mark node as modified
    node[3] |= 0x200;
}

} // namespace Giants
