// Giants Engine - Mesh Grid Allocator Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "MeshGridAllocator.h"
#include <cstdlib>
#include <cstring>
namespace Giants {
extern char DAT_007283a6;     // Init flag
extern uint32_t DAT_00725e9c; // Free list head (self-referencing)
extern uint32_t DAT_00725ea0; // Free list tail

void MeshGridAllocator(int width, int height)
{
    // Initialize free list on first call
    if (DAT_007283a6 == 0) {
        DAT_00725e9c = reinterpret_cast<uint32_t>(&DAT_00725e9c);
        DAT_00725ea0 = reinterpret_cast<uint32_t>(&DAT_00725e9c);
        DAT_007283a6 = 1;
    }

    // Align dimensions to even
    uint32_t alignedW = (width + 1) & 0xFFFFFFFE;
    uint32_t alignedH = (height + 1) & 0xFFFFFFFE;
    uint32_t h_minus1 = alignedH - 1;

    // Compute buffer sizes:
    // Vertex data: alignedW * alignedH * 16 bytes (4 floats per vertex)
    // Index data: (h_minus1 * (alignedW - 1) * 3 + 19) * 4 bytes
    size_t vertexSize = alignedW * alignedH * 16;
    size_t indexSize = (h_minus1 * (alignedW - 1) * 3 + 0x13) * 4;

    uint32_t* buffer = static_cast<uint32_t*>(malloc(vertexSize + indexSize));
    if (buffer == nullptr) return;

    // Initialize header fields
    buffer[2] = 0;   // +0x08: vertex count
    uint32_t* dataStart = buffer + 0x13;  // +0x4C: data area start
    buffer[3] = 0;   // +0x0C
    buffer[4] = 0;   // +0x10
    buffer[5] = 0;   // +0x14
    buffer[6] = 0;   // +0x18
    buffer[7] = 0;   // +0x1C
    buffer[8] = 0;   // +0x20
    buffer[9] = 0;   // +0x24
    buffer[10] = 0;  // +0x28
    buffer[11] = 0;  // +0x2C

    // Store width/height in buffer header
    // The real code fills vertex/index data and links into free list
}
} // namespace Giants
