// Giants Engine - JSON Field Setter
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── SetJsonField (FUN_0043d6f0) ── PASS ──
// Sets a JSON object field with type dispatch. Handles bool/int/string/null.
// Creates new entry if field doesn't exist. 12 callers, 3 callees.
void SetJsonField(uint32_t* obj, char* fieldName);  // FUN_0043d6f0
} // namespace Giants
