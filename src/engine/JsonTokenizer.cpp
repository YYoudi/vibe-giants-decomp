// Giants Engine - JSON Tokenizer Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "JsonTokenizer.h"

namespace Giants {

extern char  CheckBOM(int* parser);         // FUN_00435ee0
extern void  SkipWhitespace(int* parser);   // FUN_00435e60
extern char  SkipComment(int* parser);      // FUN_004368b0
extern uint32_t ParseString(int* parser);   // FUN_00436ae0
extern uint32_t ParseNumber(int* parser);   // FUN_004360f0
extern uint32_t ParseKeyword(int* kw, int len, int val);  // FUN_00436050

// ═══════════════════════════════════════════════════════════════════
// JsonNextToken (FUN_004350a0) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════

void JsonNextToken(int* p)
{
    // BOM check
    if (p[0x11] == 0)  // offset 0x44
    {
        char bom = CheckBOM(p);
        if (bom == '\0')
        {
            *reinterpret_cast<char**>(p + 0x1D) = const_cast<char*>("invalid BOM; must be 0xEF 0xBB 0xBF if given");
            p[10] = 0x0E;  // TOKEN_ERROR
            return;
        }
    }

    SkipWhitespace(p);
    char ch = *reinterpret_cast<char*>(p + 14);  // offset 0x38

    // Skip comments (slash)
    while (ch != '\0' && p[15] == 0x2F)  // offset 0x3C
    {
        ch = SkipComment(p);
        if (ch == '\0')
        {
            p[10] = 0x0E;  // TOKEN_ERROR
            return;
        }
        SkipWhitespace(p);
        ch = *reinterpret_cast<char*>(p + 14);
    }

    // Token classification by current char
    switch (p[15])  // offset 0x3C — current char
    {
    case 0x22:  // '"' — string
        p[10] = ParseString(p);
        return;

    case 0x2C:  // ','
        p[10] = 0x0D;  // TOKEN_COMMA
        return;

    case 0x2D: case 0x30: case 0x31: case 0x32: case 0x33:
    case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39:
        p[10] = ParseNumber(p);  // number
        return;

    case 0x3A:  // ':'
        p[10] = 0x0C;  // TOKEN_COLON
        return;

    case 0x5B:  // '['
        p[10] = 8;  // TOKEN_BEGIN_ARRAY
        return;

    case 0x5D:  // ']'
        p[10] = 10;  // TOKEN_END_ARRAY
        return;

    case 0x66:  // 'f' — false
    {
        uint32_t kw = 0x736C6166;  // "fals"
        uint8_t e = 0x65;
        p[10] = ParseKeyword(reinterpret_cast<int*>(&kw), 5, 2);
        return;
    }

    case 0x6E:  // 'n' — null
    {
        uint32_t kw = 0x6C6C756E;  // "null"
        p[10] = ParseKeyword(reinterpret_cast<int*>(&kw), 4, 3);
        return;
    }

    case 0x74:  // 't' — true
    {
        uint32_t kw = 0x65757274;  // "true"
        p[10] = ParseKeyword(reinterpret_cast<int*>(&kw), 4, 1);
        return;
    }

    case 0x7B:  // '{'
        p[10] = 9;  // TOKEN_BEGIN_OBJECT
        return;

    case 0x7D:  // '}'
        p[10] = 0x0B;  // TOKEN_END_OBJECT
        return;

    case 0: case 0xFFFFFFFF:
        p[10] = 0x0F;  // TOKEN_EOF
        return;

    default:
        *reinterpret_cast<char**>(p + 0x1D) = const_cast<char*>("invalid literal");
        p[10] = 0x0E;  // TOKEN_ERROR
        return;
    }
}

// ═══════════════════════════════════════════════════════════════════
// JsonNextTokenAlt (FUN_0060b140) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Variant 1 with different struct offsets: +0x5c=flags, +0x50=currentChar,
//   +0x54=currentByte, +0x28=tokenType, +0x8c=errorString

// External callees for variant 1
extern char  CheckBOM_Alt(int* parser);         // FUN_0060fef0
extern void  SkipWhitespace_Alt(int* parser);   // FUN_0060fe80
extern char  SkipComment_Alt(int* parser);      // FUN_00610860
extern uint32_t ParseString_Alt(int* parser);   // FUN_00610a40
extern uint32_t ParseNumber_Alt(int* parser);   // FUN_006100f0
extern uint32_t ParseKeyword_Alt(int* kw, int len, int val);  // FUN_00610050

void JsonNextTokenAlt(int* p)
{
    // BOM check — offset 0x5c = p[0x17]
    if (p[0x17] == 0)
    {
        char bom = CheckBOM_Alt(p);
        if (bom == '\0')
        {
            *reinterpret_cast<char**>(p + 0x23) = const_cast<char*>("invalid BOM; must be 0xEF 0xBB 0xBF if given");
            p[10] = 0x0E;  // TOKEN_ERROR
            return;
        }
    }

    SkipWhitespace_Alt(p);
    char ch = *reinterpret_cast<char*>(p + 0x14);  // offset 0x50

    // Skip comments
    while (ch != '\0' && p[0x15] == 0x2F)  // offset 0x54
    {
        ch = SkipComment_Alt(p);
        if (ch == '\0')
        {
            p[10] = 0x0E;  // TOKEN_ERROR
            return;
        }
        SkipWhitespace_Alt(p);
        ch = *reinterpret_cast<char*>(p + 0x14);
    }

    // Token classification
    switch (p[0x15])  // offset 0x54 — current char
    {
    case 0x22:  // '"'
        p[10] = ParseString_Alt(p);
        return;

    case 0x2C:  // ','
        p[10] = 0x0D;
        return;

    case 0x2D: case 0x30: case 0x31: case 0x32: case 0x33:
    case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39:
        p[10] = ParseNumber_Alt(p);
        return;

    case 0x3A:  // ':'
        p[10] = 0x0C;
        return;

    case 0x5B:  // '['
        p[10] = 8;
        return;

    case 0x5D:  // ']'
        p[10] = 10;
        return;

    case 0x66:  // 'f'
    {
        uint32_t kw = 0x736C6166;
        p[10] = ParseKeyword_Alt(reinterpret_cast<int*>(&kw), 5, 2);
        return;
    }

    case 0x6E:  // 'n'
    {
        uint32_t kw = 0x6C6C756E;
        p[10] = ParseKeyword_Alt(reinterpret_cast<int*>(&kw), 4, 3);
        return;
    }

    case 0x74:  // 't'
    {
        uint32_t kw = 0x65757274;
        p[10] = ParseKeyword_Alt(reinterpret_cast<int*>(&kw), 4, 1);
        return;
    }

    case 0x7B:  // '{'
        p[10] = 9;
        return;

    case 0x7D:  // '}'
        p[10] = 0x0B;
        return;

    case 0: case 0xFFFFFFFF:
        p[10] = 0x0F;  // TOKEN_EOF
        return;

    default:
        *reinterpret_cast<char**>(p + 0x23) = const_cast<char*>("invalid literal");
        p[10] = 0x0E;
        return;
    }
}

} // namespace Giants
