// Giants Engine - Mesh Grid Allocator
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── MeshGridAllocator (FUN_005f5550) ── PASS ──
// Allocates and initializes a mesh grid of width x height vertices.
// Allocates vertex data + index buffer, initializes linked list for free nodes.
// 2 callees, 6 callers.
void MeshGridAllocator(int width, int height);  // FUN_005f5550
} // namespace Giants
