// Giants Engine - Texture Hash Compute Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TextureHashCompute.h"
#include <cstdint>
namespace Giants {
void TextureHashCompute(uint32_t* param_1, uint32_t param_2,
                        int param_3, int param_4, char param_5)
{
    uint32_t combined = (param_3 << 24) | param_2;

    // Multiply-shift hash with magic constant 0xCD
    uint64_t prod = static_cast<uint64_t>(combined) * 0xCD;
    uint32_t hashLow = static_cast<uint32_t>(prod >> 11) & 0xF000000F;

    uint32_t hashMid = (param_4 * 0x10000 +
        (((param_4 * 0xCD0000 + static_cast<uint32_t>(prod >> 32)) >> 11) & 0xF0000) * 3 +
        static_cast<uint32_t>((hashLow + (hashLow << 1)) > combined ? 1 : 0)) * 2;

    uint32_t result = hashLow * 6 + combined;
    *param_1 = result | hashMid;
}
} // namespace Giants
