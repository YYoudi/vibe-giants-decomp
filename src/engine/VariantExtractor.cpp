// Giants Engine - Variant Type Extractor Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VariantExtractor.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// ExtractVariantValue (FUN_004316b0) — 15 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Variant layout: [+0] = type byte, [+8..] = value data
// Type dispatch:
//   0x04 → bool (byte at +8)
//   0x05 → int32 (dword at +8)
//   0x06 → uint32 (dword at +8)
//   0x07 → float (float at +8, bitcast to uint)
//   0x08 → double (qword at +8, truncated to uint)
//   0x09 → string pointer (dword at +8 → string → parsed)
//   0x0A → raw pointer (dword at +8)

uint32_t ExtractVariantValue(const char* variant)
{
    char type = variant[0];

    switch (type) {
    case '\x04':  // bool
        if (type != '\x04') return 0;
        return static_cast<uint32_t>(*reinterpret_cast<const uint8_t*>(variant + 8));

    case '\x05':  // int32
    case '\x06':  // uint32
        if (type == '\x05' || type == '\x06') {
            return *reinterpret_cast<const uint32_t*>(variant + 8);
        }
        return 0;

    case '\x07':  // float → uint32 bitcast
        {
            float f = *reinterpret_cast<const float*>(variant + 8);
            uint32_t bits;
            memcpy(&bits, &f, sizeof(bits));
            return bits;
        }

    case '\x08':  // double → truncated to uint
        {
            double d = *reinterpret_cast<const double*>(variant + 8);
            return static_cast<uint32_t>(d);
        }

    case '\x09':  // string → parse to int
        {
            const char* str = *reinterpret_cast<const char* const*>(variant + 8);
            if (str != nullptr) {
                return static_cast<uint32_t>(atoi(str));
            }
            return 0;
        }

    case '\x0A':  // pointer
        return *reinterpret_cast<const uint32_t*>(variant + 8);

    default:
        return 0;
    }
}

} // namespace Giants
