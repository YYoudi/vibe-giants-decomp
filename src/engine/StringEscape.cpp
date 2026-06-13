// Giants Engine - String Escape with SSO Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: FAIL (usable ~80%)
#include "StringEscape.h"
#include "CRTStubs.h"
#include <cstring>

namespace Giants {

extern void FormatControlChar(void* buf, int size, const char* fmt, uint8_t val);  // FUN_00439290
extern void ShrinkLocalString(void* str, int newLen);  // FUN_00442880
extern void* AllocateBuffer(uint32_t size);            // FUN_00443120
extern void ReportOverflow(uint32_t cookie);           // FUN_00443110

// ═══════════════════════════════════════════════════════════════════
// BuildStringFromIterator (FUN_00434860) — 23 callers — FAIL (usable ~80%)
// ═══════════════════════════════════════════════════════════════════
// Iterates byte range [param_1+0x20 .. param_1+0x24), builds an SSO
// string in param_2. Control chars (< 0x20) formatted as "<U+XXXX>".

void BuildStringFromIterator(int param_1, uint32_t* outStr)
{
    // Initialize empty SSO string
    outStr[0] = 0;
    outStr[1] = 0;
    outStr[2] = 0;
    outStr[3] = 0;
    outStr[4] = 0;       // size = 0
    outStr[5] = 0x0F;    // capacity = 15 (SSO mode)
    *reinterpret_cast<char*>(outStr) = '\0';

    uint8_t* begin = *reinterpret_cast<uint8_t**>(param_1 + 0x20);
    uint8_t* end   = *reinterpret_cast<uint8_t**>(param_1 + 0x24);

    while (begin != end)
    {
        uint8_t ch = *begin;

        if (ch < 0x20)
        {
            // Control character — format as <U+XXXX>
            char fmtBuf[10];
            fmtBuf[0] = '\0';
            FormatControlChar(fmtBuf, 9, "<U+%.4X>", ch);

            // Get formatted string length
            const char* p = fmtBuf;
            char c;
            do { c = *p; p++; } while (c != '\0');
            int fmtLen = static_cast<int>(p - fmtBuf - 1);

            ShrinkLocalString(fmtBuf, fmtLen);
            // The formatted string would need to be appended to outStr
            // Full implementation requires character-by-character SSO append
        }
        else
        {
            // Printable character — direct append to SSO string
            uint32_t cap  = outStr[5];
            uint32_t size = outStr[4];

            if (size < cap)
            {
                outStr[4] = size + 1;
                char* buf = (cap > 0x0F) ? reinterpret_cast<char*>(outStr[0]) : reinterpret_cast<char*>(outStr);
                buf[size] = ch;
                buf[size + 1] = '\0';
            }
            else
            {
                // Need to grow — SSO reallocation
                if (size == 0x7FFFFFFF)
                    return;  // overflow guard

                uint32_t newCap = (size + 1) | 0x0F;
                if (newCap < 0x80000000)
                {
                    uint32_t grow = (cap >> 1) + cap;
                    if (newCap < grow)
                        newCap = grow;
                    if (0x7FFFFFFF - (cap >> 1) < cap)
                        newCap = 0x7FFFFFFF;
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
                    free(oldBuf);  // simplified — real code uses FUN_00643505
                }

                outStr[0] = reinterpret_cast<uint32_t>(newBuf);
            }
        }

        begin++;
    }
}

} // namespace Giants
