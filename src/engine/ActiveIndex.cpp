// Giants Engine - Active Index Setter Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ActiveIndex.h"

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static int   s_currentIndex = 0;       // DAT_00748a30
static int   s_minIndex = 0;           // DAT_00682e98
static int   s_maxIndex = 0;           // DAT_0068298c
static bool  s_flag1 = false;          // DAT_00702b30
static bool  s_flag2 = false;          // DAT_00702b34
static bool  s_flag3 = false;          // DAT_00702b50
static bool  s_flag4 = false;          // DAT_00702bb8
static int   s_activeArray[64] = {};   // DAT_00748b50 (3 ints per entry)
static float s_value1 = 0.0f;          // DAT_00702c1c
static float s_value2 = 0.0f;          // DAT_00702c24
static float s_value3 = 0.0f;          // DAT_00702c20
static float s_value4 = 0.0f;          // DAT_00702c28
static float s_scaleFactor = 1.0f;     // DAT_0066be20
static int   s_tableBase = 0;          // DAT_0074b5f8
static int   s_tableIndex = 0;         // DAT_0074b5fc
static int   s_divisor1 = 1;           // DAT_0074b604
static int   s_divisor2 = 1;           // DAT_0074b608

extern void OnIndexChanged();  // FUN_00558360

// ═══════════════════════════════════════════════════════════════════
// SetActiveIndex (FUN_00541690) — 26 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Clamps index to [minIndex, maxIndex-1], updates active array,
// optionally triggers callback, then computes scaled float values
// from a table entry at the new index.

void SetActiveIndex(int index)
{
    int oldIndex = s_currentIndex;

    // Clamp to valid range
    if (index < s_minIndex)
    {
        index = s_maxIndex - 1;
    }
    else if (index > s_maxIndex - 1)
    {
        index = s_minIndex;
    }

    // Update active array (3 ints per entry)
    bool wasInactive = (s_flag1 == 0);
    s_activeArray[s_currentIndex * 3] = 0;
    s_currentIndex = index;
    s_activeArray[index * 3] = 1;

    // Trigger callback if all flags clear and index actually changed
    if (wasInactive && s_flag2 == 0 && s_flag3 == 0 &&
        index != oldIndex && s_flag4 == 0)
    {
        OnIndexChanged();
        index = s_currentIndex;
    }

    // Look up table entry and compute scaled values
    int tableEntry = *reinterpret_cast<int*>(s_tableBase + s_tableIndex * 0x24);
    int entryPtr = *reinterpret_cast<int*>(tableEntry + 4 + index * 4);

    // Compute value1 (quantized scaled range)
    float raw1 = *reinterpret_cast<float*>(entryPtr + 0x44) * s_scaleFactor
               + *reinterpret_cast<float*>(entryPtr + 0x38) * s_scaleFactor;
    s_value1 = static_cast<float>(static_cast<int>(raw1 / s_divisor1)) * s_divisor1;
    s_value2 = s_value1;

    // Compute value3 (quantized scaled range)
    float raw3 = *reinterpret_cast<float*>(entryPtr + 0x48) * s_scaleFactor
               + *reinterpret_cast<float*>(entryPtr + 0x3c) * s_scaleFactor;
    s_value3 = static_cast<float>(static_cast<int>(raw3 / s_divisor2)) * s_divisor2;
    s_value4 = s_value3;
}

} // namespace Giants
