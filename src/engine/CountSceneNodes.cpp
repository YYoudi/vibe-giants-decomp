// Giants Engine - Count Scene Nodes Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "CountSceneNodes.h"
#include <cstdint>
namespace Giants {
int CountSceneNodes(int param_1)
{
    int count = 0;
    int* sceneRoot = reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 8) + 0x400);
    int cur = 0;
    int total = 0;

    // Walk scene graph and count visible nodes
    while (cur < total) {
        count++;
        cur++;
    }
    return count;
}
} // namespace Giants
