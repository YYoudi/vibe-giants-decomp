// Giants Engine - Wide String to Narrow String Converter Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS (but uses MSVC string internals — simplified for MinGW)
#include "WStringToString.h"
#include <string>

namespace Giants {

std::string* WStringToString(std::wstring* wideStr, std::string* result)
{
    // Simplified: standard wide-to-narrow conversion
    // Original uses ___std_fs_convert_wide_to_narrow_20 with MSVC SSO internals
    if (wideStr == nullptr || result == nullptr)
        return result;

    std::string narrow;
    narrow.reserve(wideStr->size());
    for (wchar_t wc : *wideStr)
    {
        if (wc >= 0 && wc <= 127)
            narrow += static_cast<char>(wc);
        else
            narrow += '?';
    }
    *result = std::move(narrow);
    return result;
}

} // namespace Giants
