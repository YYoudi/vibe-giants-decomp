// Giants Engine - Escape String with SSO Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EscapeString.h"
#include "CRTStubs.h"
#include <cstring>

namespace Giants {

extern void   FormatString(void* buf, int sz, const char* fmt, uint8_t val);  // FUN_00439290
extern void   ShrinkToFit(void* str, int len);  // FUN_00442880
extern void*  AllocateBuffer(uint32_t size);     // FUN_00443120
extern void   ReportOverflow(uint32_t cookie);   // FUN_00443110

// ═══════════════════════════════════════════════════════════════════
// EscapeString (FUN_0060a930) — 23 callers — PASS
// ═══════════════════════════════════════════════════════════════════

uint32_t* EscapeString(int param_1, uint32_t* outStr)
{
    // Initialize empty SSO string
    outStr[0] = 0;
    outStr[1] = 0;
    outStr[2] = 0;
    outStr[3] = 0;
    outStr[4] = 0;       // size = 0
    outStr[5] = 0x0F;    // capacity = 15 (SSO mode)
    *reinterpret_cast<uint8_t*>(outStr) = '\0';

    uint8_t* begin = *reinterpret_cast<uint8_t**>(param_1 + 0x38);
    uint8_t* end   = *reinterpret_cast<uint8_t**>(param_1 + 0x3c);

    while (begin != end)
    {
        uint8_t ch = *begin;

        if (ch < 0x20)
        {
            // Control character — format as <U+XXXX>
            char fmtBuf[9];
            fmtBuf[0] = '\0';
            FormatString(fmtBuf, 9, "<U+%.4X>", ch);

            // Get formatted string length
            const char* p = fmtBuf;
            char c;
            do { c = *p; p++; } while (c != '\0');
            ShrinkToFit(fmtBuf, static_cast<int>(p - fmtBuf - 1));
        }
        else
        {
            // Printable character — append to SSO string
            uint32_t cap  = outStr[5];
            uint32_t size = outStr[4];

            if (size < cap)
            {
                outStr[4] = size + 1;
                char* buf = (cap > 0x0F) ? reinterpret_cast<char*>(outStr[0]) : reinterpret_cast<char*>(outStr);
                reinterpret_cast<uint8_t*>(buf)[size] = ch;
                reinterpret_cast<uint8_t*>(buf)[size + 1] = '\0';
            }
            else
            {
                // Grow: compute new capacity
                if (size == 0x7FFFFFFF)
                    ReportOverflow(0);

                uint32_t newCap = (size + 1) | 0x0F;
                if (newCap < 0x80000000)
                {
                    if (0x7FFFFFFF - (cap >> 1) < cap)
                        newCap = 0x7FFFFFFF;
                    else
                    {
                        uint32_t grow = (cap >> 1) + cap;
                        if (newCap < grow)
                            newCap = grow;
                    }
                }
                else
                {
                    newCap = 0x7FFFFFFF;
                }

                void* newBuf = AllocateBuffer(newCap + 1);
                outStr[4] = size + 1;
                outStr[5] = newCap;

                uint8_t* dst = reinterpret_cast<uint8_t*>(newBuf) + size;

                if (cap < 0x10)
                {
                    memcpy(newBuf, outStr, size);
                    *dst = ch;
                    dst[1] = '\0';
                }
                else
                {
                    void* oldBuf = reinterpret_cast<void*>(outStr[0]);
                    memcpy(newBuf, oldBuf, size);
                    *dst = ch;
                    dst[1] = '\0';

                    // Free old buffer
                    uint32_t freeSize = cap + 1;
                    void* toFree = oldBuf;
                    if (freeSize > 0xFFF)
                    {
                        toFree = *reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(oldBuf) - 4);
                        freeSize = cap + 0x24;
                    }
                    free(toFree);  // simplified — real code uses FUN_00643505
                }

                outStr[0] = reinterpret_cast<uint32_t>(newBuf);
            }
        }

        begin++;
    }

    return outStr;
}

} // namespace Giants
