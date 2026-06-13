// Giants Engine - Vector Element Push Back (16-byte elements)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── VectorElementPushBack (FUN_004437a0) ── FAIL (usable ~80%) ──
// Pushes a 16-byte element (VectorElement: id+pad+field8+fieldC) into
// a std::vector-like container. Handles capacity grow with 1.5x strategy.
// Moves element via field-by-field copy, zeroing source.
// 13 callers, ~4 callees.
struct VectorElement { uint32_t id, pad, field8, fieldC; };
VectorElement* VectorElementPushBack(VectorElement** container, VectorElement* elem);  // FUN_004437a0

} // namespace Giants
