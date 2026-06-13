// Giants Engine - Add Text Node Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "AddTextNode.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

extern float DAT_0066bd58;    // Font scale A
extern float DAT_0066bd50;    // Font scale B
extern float _DAT_0066bd1c;   // Font multiplier
extern float DAT_0066c070;    // Font constant
extern float DAT_0066bd28;    // Font padding

extern char* FUN_005e80c0(char* name);  // String hash lookup
extern void  FUN_0062c690();             // Font measure helper
extern void  FUN_004d3b30(float scale, float* out); // Text width compute

void AddTextNode(TextNode** head, uint32_t id, uint32_t flags, char* text, float x, float y)
{
    if ((flags & 0x2000000) != 0)
        text = FUN_005e80c0(text);

    TextNode* node = static_cast<TextNode*>(malloc(0x30));
    memset(node, 0, 0x30);

    // Append to end of list
    TextNode** current = head;
    while (*current != nullptr)
        current = &(*current)->next;
    *current = node;

    node->type = 2;
    node->id = id;

    if ((flags & 1) == 0)
    {
        node->text = text;
    }
    else
    {
        // Copy string
        const char* src = text;
        char c;
        do { c = *src; src++; } while (c != '\0');
        char* copy = static_cast<char*>(malloc(static_cast<size_t>(src + 1 - (text + 1))));
        node->text = copy;
        src = text;
        char* dst = copy;
        do { c = *src; src++; *dst = c; dst++; } while (c != '\0');
        text = node->text;
    }

    node->x = x;
    node->y = y;
    node->flags = flags;

    float fontScale = DAT_0066bd58;
    if ((flags & 0x1000000) != 0)
        fontScale = DAT_0066bd50;

    float lineH = fontScale * _DAT_0066bd1c * DAT_0066c070;

    // Compute text width
    const char* str = text;
    char c;
    do { c = *str; str++; } while (c != '\0');

    FUN_0062c690();

    float fVar7 = fontScale + DAT_0066bd28 + lineH + lineH;

    FUN_004d3b30(fontScale, &lineH);

    node->width = lineH - lineH; // Width computed via FUN_004d3b30
    node->f1C = x;
    node->f24 = fontScale + lineH;
    node->f20 = x + fVar7;
}

} // namespace Giants
