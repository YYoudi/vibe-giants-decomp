// Giants Engine - Display Mode & Font Initialization Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include <cstdlib>
#include <cstring>
#include "DisplayMode.h"
#include <windows.h>

namespace Giants {

// ─── External data references ─────────────────────────────────
static uint32_t DAT_0074beb0 = 0;        // Font system initialized flag
static uint32_t DAT_007028a0 = 0;        // Screen resolution height
static uint32_t DAT_007028a4 = 0;        // Screen resolution width
static void*    DAT_0074bedc = nullptr;  // Glyph bitmap buffer (64KB)
static float    DAT_0066bf64 = 1.333f;   // Aspect ratio threshold (4:3)
static float    DAT_0066c190 = 0;        // Medium font threshold
static float    DAT_0066c15c = 0;        // Small font threshold
static uint8_t  DAT_0074beb8[0x554] = {0}; // Font metrics table
static HDC      DAT_0074be60 = nullptr;  // Memory DC
static HBITMAP  DAT_0074be64 = nullptr;  // DIB section bitmap
static void*    DAT_0074be68 = nullptr;  // DIB section bits pointer
static HFONT    DAT_0074be6c = nullptr;  // Font handle
static char     DAT_0074be70[32] = {0};  // Font face name
static float    _DAT_0074beb4 = 0;       // Font pixel size
static float    _DAT_0066c460 = 0;       // LOGFONT width
static uint32_t _UNK_0066c464 = 0;       // LOGFONT escapement
static uint32_t _UNK_0066c468 = 0;       // LOGFONT orientation
static uint32_t _UNK_0066c46c = 0;       // LOGFONT weight

// ─── InitDisplayMode (FUN_0062b9c0) — FAIL (usable ~50%) ───────

void InitDisplayMode()
{
    if (DAT_0074beb0 != 0) return;  // Already initialized

    // Determine font size based on screen resolution
    int fontSize;
    if ((float)DAT_007028a4 < DAT_0066c190) {
        fontSize = (DAT_0066c15c <= (float)DAT_007028a4) ? 0x18 : 0x0c;
    } else {
        fontSize = 0x20;
    }

    // Initialize font metrics table and glyph bitmap buffer
    memset(&DAT_0074beb8, 0, 0x554);
    DAT_0074bedc = malloc(0x10000);  // 64KB glyph buffer
    memset(DAT_0074bedc, 0, 0x10000);

    // Create GDI device context
    DAT_0074be60 = CreateCompatibleDC(nullptr);

    // Create monochrome DIB section (128x64 pixels, 1-bit)
    BITMAPINFO bmi = {};
    bmi.bmiHeader.biSize = 0x28;
    bmi.bmiHeader.biWidth = 0x80;          // 128 pixels
    bmi.bmiHeader.biHeight = -0x40;        // 64 pixels, top-down
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 1;          // Monochrome
    bmi.bmiHeader.biCompression = 0;
    bmi.bmiColors[0].rgbBlue = 0;
    bmi.bmiColors[0].rgbGreen = 0;
    bmi.bmiColors[0].rgbRed = 0;
    bmi.bmiColors[0].rgbReserved = 0;

    DAT_0074be64 = CreateDIBSection(DAT_0074be60, &bmi, 0,
                                     &DAT_0074be68, nullptr, 0);
    SelectObject(DAT_0074be60, DAT_0074be64);
    SetBkMode(DAT_0074be60, 1);             // TRANSPARENT
    SetTextColor(DAT_0074be60, 0x00ffffff);
    SetTextAlign(DAT_0074be60, 0x18);       // TA_CENTER | TA_BASELINE

    // Create font
    LOGFONTA lf = {};
    lf.lfHeight = fontSize;
    lf.lfWidth = _DAT_0066c460;
    lf.lfEscapement = _UNK_0066c464;
    lf.lfOrientation = _UNK_0066c468;
    lf.lfWeight = _UNK_0066c46c;
    lf.lfItalic = 0;
    lf.lfUnderline = 0;
    lf.lfStrikeOut = 0;
    lf.lfCharSet = 0;
    lf.lfOutPrecision = 0;
    lf.lfClipPrecision = 0;
    lf.lfQuality = 1;           // PROOF_QUALITY? or CLEARTYPE?
    lf.lfPitchAndFamily = 0x22; // VARIABLE_PITCH | SWISS

    // Copy font face name from config
    for (int i = 0; i < 32; i++) {
        lf.lfFaceName[i] = DAT_0074be70[i];
        if (DAT_0074be70[i] == '\0') break;
    }

    _DAT_0074beb4 = (float)fontSize;

    DAT_0074be6c = CreateFontIndirectA(&lf);
    SelectObject(DAT_0074be60, DAT_0074be6c);
    DAT_0074beb0 = 1;  // Mark initialized

    // Additional font setup (glyph widths, character metrics)
    // 14 callees handle glyph extraction and metric computation
}

// ─── ComputeBoundingBox (FUN_005de6b0) — FAIL (usable ~55%) ────

void ComputeBoundingBox(int* params)
{
    if (*params == 0) return;

    // Set initial viewport bounds from screen resolution
    params[9]  = DAT_007028a0;  // Screen width
    params[10] = DAT_007028a4;  // Screen height

    // Compute letterbox/pillarbox based on aspect ratio
    float aspectRatio = (float)DAT_007028a0 / (float)DAT_007028a4;
    float viewWidth, viewOffset;

    if (aspectRatio > DAT_0066bf64) {
        // Wide screen: letterbox sides
        viewWidth = DAT_0066bf64 / aspectRatio;
        viewOffset = (1.0f - viewWidth) * (float)DAT_007028a0;
    } else {
        viewWidth = 1.0f;
        viewOffset = 0.0f;
    }

    params[0xb] = (int)viewWidth;
    params[0xc] = (int)viewOffset;
    params[0xd] = 0;
    params[0xe] = 0;

    // Iterate linked list of objects to compute bounding box
    // Each object has vertex data; find min/max X,Y extents
    int* obj = (int*)params[4];
    int next = *obj;

    while (next != 0) {
        if ((*(uint8_t*)(obj + 6) & 1) != 0) {
            // Get vertex buffer for this object
            int vertBuf = *(int*)(params[2] + obj[0x14] * 4);
            int idxBuf  = *(int*)(params[3] + obj[0x14] * 4);

            // Get first vertex coordinates
            int idx1 = *(int*)(vertBuf + 0x94 + obj[5] * 0x90);
            int count = *(int*)(vertBuf + 0x98 + obj[5] * 0x90);

            float minX = *(float*)(idxBuf + idx1 * 0x38);
            float minY = *(float*)(idxBuf + idx1 * 0x38 + 4);
            float maxX = minX;
            float maxY = minY;

            // Scan remaining vertices for min/max
            float* verts = (float*)(idxBuf + idx1 * 0x38);
            for (int i = count; i > 0; i--) {
                float vx = *verts;
                float vy = verts[1];
                if (vx < minX) { obj[8] = (int)vx; minX = vx; }
                if (vy < minY) { obj[9] = (int)vy; minY = vy; }
                if (maxX < vx) { obj[0xb] = (int)vx; maxX = vx; }
                if (maxY < vy) { obj[0xc] = (int)vy; maxY = vy; }
                verts += 0xe;  // stride = 56 bytes (14 floats)
            }
        }
        obj += 0x17;  // next object in linked list
        next = *obj;
    }
}

} // namespace Giants
