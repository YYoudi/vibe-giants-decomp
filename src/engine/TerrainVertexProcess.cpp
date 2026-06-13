// Giants Engine - Terrain Vertex Process Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TerrainVertexProcess.h"
#include <cstdint>
namespace Giants {
void ProcessTerrainVertex(uint32_t param_1, uint8_t* vertexData, float* output)
{
    // Read vertex data bytes and compute height/normal
    // Vertex bytes encode position relative to terrain grid
    if (vertexData == nullptr) return;

    float scale = *reinterpret_cast<float*>(param_1 + 0x10);
    float height = static_cast<float>(vertexData[0]) * scale;
    output[0] = height;
}
} // namespace Giants
