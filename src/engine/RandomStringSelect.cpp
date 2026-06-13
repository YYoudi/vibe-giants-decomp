// Giants Engine - Random String Selector Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RandomStringSelect.h"
#include "CRTStubs.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

extern void   AppendString(const char* s, int len);   // FUN_00442eb0
extern void*  QueryStringPool();                       // FUN_005e85e0
extern void   SelectPoolEntry(char** out, int* idx);   // FUN_005e8690
extern void   ReleaseStringRef();                      // FUN_004439b0

// ═══════════════════════════════════════════════════════════════════
// SelectRandomString (FUN_005e81d0) — 24 callers — PASS
// ═══════════════════════════════════════════════════════════════════

char* SelectRandomString(char* param_1)
{
    if (param_1 == nullptr)
        return const_cast<char*>("Null");

    // Append input string to pool
    const char* ptr = param_1;
    char c;
    do { c = *ptr; ptr++; } while (c != '\0');
    AppendString(param_1, static_cast<int>(ptr - param_1 - 1));

    // Query for existing entry
    uint32_t* result = static_cast<uint32_t*>(QueryStringPool());

    if (result == nullptr)
    {
        // No match found — try up to 10 iterations
        int count = 1;
        int idx = 1;

        do
        {
            idx = count;
            SelectPoolEntry(&param_1, &idx);
            count++;

            void* check = QueryStringPool();
            if (check == nullptr)
            {
                ReleaseStringRef();
                break;
            }
            count = idx + 1;
            ReleaseStringRef();
            idx = count;
        } while (idx < 10);

        // Pick random entry
        int randVal = rand();
        idx = (randVal * (count - 1) >> 15) + 1;
        SelectPoolEntry(&param_1, &idx);

        result = static_cast<uint32_t*>(QueryStringPool());
        if (result != nullptr)
        {
            param_1 = reinterpret_cast<char*>(*result);
        }

        ReleaseStringRef();
    }
    else
    {
        param_1 = reinterpret_cast<char*>(*result);
    }

    return param_1;
}

} // namespace Giants
