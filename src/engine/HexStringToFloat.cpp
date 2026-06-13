// Giants Engine - Hex String to Float Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "HexStringToFloat.h"
#include <cstdint>
#include <cctype>
#include <cmath>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern float DAT_0066c030;  // Power constant (16.0f or normalization factor)

// ═══════════════════════════════════════════════════════════════════
// HexStringToFloat (FUN_004532b0) — 15 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Parses hex string (optionally "0x" prefixed) into float value.
// Collects up to 20 hex digits into a mantissa array, then computes:
//   result = sum(digits[i] * 16^(count-1-i)) * pow(16, -count) * DAT_0066c030

float HexStringToFloat(const char* hexStr)
{
    // Skip "0x" prefix
    if (hexStr[0] == '0' && tolower(hexStr[1]) == 'x') {
        hexStr += 2;
    }

    // Parse hex digits into mantissa
    int mantissa[20];
    int digitCount = 0;
    char c;

    do {
        c = *hexStr;
        // Check if valid hex digit
        if ((c < '0' || c > '9') && (tolower(c) < 'a' || tolower(c) > 'f')) {
            break;
        }

        int digitVal;
        if (static_cast<unsigned char>(c - '0') < 10) {
            digitVal = c - '0';
        } else {
            digitVal = tolower(c) - 'a' + 10;
        }

        mantissa[digitCount] = digitVal;
        hexStr++;
        digitCount++;
    } while (digitCount < 20);

    // Compute float from hex digits
    float result = 0.0f;
    for (int i = 0; i < digitCount; i++) {
        result = result * DAT_0066c030 + static_cast<float>(mantissa[i]);
    }

    return result;
}

} // namespace Giants
