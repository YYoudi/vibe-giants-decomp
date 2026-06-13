// Giants Engine - CRC32 with Skip Pattern Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "Crc32WithSkip.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_00658738[];  // CRC32 lookup table (256 entries)

uint32_t Crc32WithSkip(uint8_t* data, uint32_t length, uint32_t initCrc)
{
    uint32_t crc = ~initCrc;
    uint32_t baseCrc = crc;

    if (length == 0) {
        // Null-terminated string mode
        uint8_t b = *data;
        while (b != 0) {
            uint8_t* next = data + 1;
            // Check for "###" pattern (3 x 0x23)
            if (b == 0x23 && *next == 0x23 && data[2] == 0x23) {
                crc = baseCrc;  // Reset CRC on skip marker
            }
            crc = (crc >> 8) ^ DAT_00658738[(crc & 0xFF) ^ b];
            data = next;
            b = *next;
        }
        return ~crc;
    }

    // Length-specified mode
    uint32_t remaining = length;
    while (remaining > 0) {
        // Check for "###" skip pattern
        if (*data == 0x23 && remaining >= 3 && data[1] == 0x23 && data[2] == 0x23) {
            // Process the '#' normally but reset CRC after triple
            crc = (baseCrc >> 8) ^ DAT_00658738[(baseCrc & 0xFF) ^ 0x23];
            data++;
            remaining--;
            continue;
        }
        crc = (crc >> 8) ^ DAT_00658738[(crc & 0xFF) ^ *data];
        data++;
        remaining--;
    }
    return ~crc;
}
} // namespace Giants
