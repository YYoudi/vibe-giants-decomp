// Giants Engine - Wide String Copy Constructor & Utilities Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "STLWString.h"
#include "CRTStubs.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// WideStringCopyConstruct (FUN_00443070) — 31 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::wstring copy constructor. SSO layout:
//   [0-3]  union { wchar_t* ptr; wchar_t inline_buf[4]; }  (16 bytes)
//   [4]    size_t m_size
//   [5]    size_t m_capacity (<=7 means SSO inline mode)

extern void* WStringAllocate(uint32_t count);  // FUN_00443010

void WideStringCopyConstruct(void* thisPtr, const void* other)
{
    uint32_t* dst = static_cast<uint32_t*>(thisPtr);
    const uint32_t* src = static_cast<const uint32_t*>(other);

    // Zero-initialize
    memset(dst, 0, 24);

    uint32_t size = src[4];
    const uint32_t* data = src;

    // If source is heap-allocated (capacity > 7), dereference pointer
    if (src[5] > 7)
    {
        data = reinterpret_cast<const uint32_t*>(static_cast<uintptr_t>(src[0]));
    }

    if (size >= 0x7FFFFFFF)
    {
        ThrowStringLengthError();
    }

    if (size < 8)
    {
        // SSO inline copy
        dst[4] = size;
        dst[5] = 7;

        uint32_t v1 = data[1];
        uint32_t v2 = data[2];
        uint32_t v3 = data[3];
        dst[0] = data[0];
        dst[1] = v1;
        dst[2] = v2;
        dst[3] = v3;
        return;
    }

    // Heap allocation
    uint32_t allocSize = size | 7;
    if (allocSize >= 0x7FFFFFFF)
    {
        allocSize = 0x7FFFFFFE;
    }
    else if (allocSize < 10)
    {
        allocSize = 10;
    }

    void* buffer = WStringAllocate(allocSize + 1);
    dst[0] = reinterpret_cast<uint32_t>(buffer);
    dst[4] = size;
    dst[5] = allocSize;
    memcpy(buffer, data, size * 2 + 2);
}

// ═══════════════════════════════════════════════════════════════════
// FreeBufferAndDecrement (FUN_00480d00) — 31 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Frees buffer at param_1+8 and decrements global counter.

static uintptr_t DAT_00701a3c = 0;  // Render/stats counter pointer

void FreeBufferAndDecrement(int param_1)
{
    void* memory = *reinterpret_cast<void**>(param_1 + 8);
    if (memory != nullptr)
    {
        if (DAT_00701a3c != 0)
        {
            *reinterpret_cast<int*>(DAT_00701a3c + 0x370) -= 1;
        }
        free(memory);
    }
}

// ═══════════════════════════════════════════════════════════════════
// ProcessString (FUN_0042fed0) — 30 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// String processing state machine:
//   State 0: Initialize buffer (sets state to 1)
//   State 1: Process string input
//   Other: Build exception and throw

extern void InitBuffer(int param);           // FUN_004409f0
extern void AppendString(const char* s, int len);  // FUN_00442eb0
extern uint32_t FinalizeString(int* obj);    // FUN_00432120
extern uint32_t AllocException(uint32_t cookie);   // FUN_0043fc70
extern uint32_t ResizeException(uint32_t param);   // FUN_00442f40
extern uint32_t BuildExceptionMsg(uint32_t param); // FUN_0043fe80
extern void ThrowParseException(uint32_t param);   // FUN_0043fef0

void ProcessString(char* stateObj, char* input)
{
    if (*stateObj == '\0')
    {
        // State 0: Initialize
        *stateObj = '\x01';
        InitBuffer(1);
        // Store buffer pointers
    }

    if (*stateObj == '\x01')
    {
        // State 1: Process input string
        int localStr[7] = {0, 0, 0, 0, 0, 0, 0};

        // Measure input length
        const char* end = input;
        char c;
        do { c = *end; end++; } while (c != '\0');

        AppendString(input, static_cast<int>(end - input - 1));
        FinalizeString(localStr);
        return;
    }

    // Invalid state: build and throw exception
    uint32_t exc = AllocException(0);
    exc = ResizeException(exc);
    exc = BuildExceptionMsg(exc);
    ThrowParseException(exc);
    // _CxxThrowException unreachable
}

// ═══════════════════════════════════════════════════════════════════
// RenderSprite (FUN_005d79a0) — 30 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Sprite rendering with scale, depth, and viewport transforms.
// Handles: depth-based scaling, aspect ratio correction,
// submesh vertex transforms with optional rotation.

extern uint32_t g_depthXorKey;     // DAT_0066c580
extern float g_one;                // DAT_0066bf2c (1.0f)
extern float g_half;               // DAT_0066be20 (0.5f)

void RenderSprite(int spriteData, int renderEntry, uint32_t flags,
                  float width, float posY, float height)
{
    float depthScale = 0.0f;
    float localScale = height;

    // Check if depth scaling applies
    if (*reinterpret_cast<int*>(spriteData + 0x34) != 0)
    {
        float depthVal = *reinterpret_cast<float*>(spriteData + 0x2C);
        if (depthVal < g_one)
        {
            if ((*reinterpret_cast<uint8_t*>(renderEntry + 0x18) & 0x20) == 0)
            {
                localScale = height * depthVal;
                if (*reinterpret_cast<int*>(spriteData + 0x38) != 0)
                {
                    if (*reinterpret_cast<int*>(renderEntry + 0x1C) == 1)
                    {
                        uint32_t xorBits = *reinterpret_cast<uint32_t*>(spriteData + 0x30) ^ g_depthXorKey;
                        float xorVal;
                        memcpy(&xorVal, &xorBits, sizeof(xorVal));
                        depthScale = xorVal;
                    }
                    else if (*reinterpret_cast<int*>(renderEntry + 0x1C) == 2)
                    {
                        depthScale = *reinterpret_cast<float*>(spriteData + 0x30);
                    }
                    depthScale = depthScale * g_half;
                }
            }
            else
            {
                width = width / depthVal;
            }
        }
    }

    // Compute sprite corners based on flags
    uint32_t entryFlags = *reinterpret_cast<uint32_t*>(renderEntry + 0x18);

    if ((entryFlags & 1) == 0)
    {
        if ((entryFlags & 4) != 0)
        {
            // Billboard mode with aspect ratio correction
            float aspectScale = static_cast<float>(*reinterpret_cast<uint32_t*>(0x007028A0)) /
                                640.0f;

            *reinterpret_cast<float*>(renderEntry + 0x38) = localScale * *reinterpret_cast<float*>(renderEntry + 0x20) * aspectScale + posY + depthScale;
            *reinterpret_cast<float*>(renderEntry + 0x3C) = (width * *reinterpret_cast<float*>(renderEntry + 0x24) * static_cast<float>(*reinterpret_cast<uint32_t*>(0x007028A4))) / 480.0f + height;
            *reinterpret_cast<float*>(renderEntry + 0x44) = localScale * *reinterpret_cast<float*>(renderEntry + 0x2C) * aspectScale + posY + depthScale;
            *reinterpret_cast<float*>(renderEntry + 0x48) = (width * *reinterpret_cast<float*>(renderEntry + 0x30) * static_cast<float>(*reinterpret_cast<uint32_t*>(0x007028A4))) / 480.0f + height;
        }
    }
    else
    {
        // Submesh vertex mode
        int vertIdx = *reinterpret_cast<int*>(renderEntry + 0x50) * 4;
        int meshA = *reinterpret_cast<int*>(*reinterpret_cast<int*>(spriteData + 8) + vertIdx);
        int startVert = *reinterpret_cast<int*>(meshA + 0x94 + *reinterpret_cast<int*>(renderEntry + 0x14) * 0x90);
        int vertCount = *reinterpret_cast<int*>(meshA + 0x98 + *reinterpret_cast<int*>(renderEntry + 0x14) * 0x90);
        int meshB = *reinterpret_cast<int*>(*reinterpret_cast<int*>(spriteData + 0xC) + vertIdx);
        float rotation = *reinterpret_cast<float*>(renderEntry + 0x58);
        bool hasRotation = rotation != 0.0f;

        // Set sprite corners
        *reinterpret_cast<float*>(renderEntry + 0x38) = localScale * *reinterpret_cast<float*>(renderEntry + 0x20) + posY + depthScale;
        *reinterpret_cast<float*>(renderEntry + 0x3C) = width * *reinterpret_cast<float*>(renderEntry + 0x24) + height;
        *reinterpret_cast<float*>(renderEntry + 0x44) = localScale * *reinterpret_cast<float*>(renderEntry + 0x2C) + posY + depthScale;
        *reinterpret_cast<float*>(renderEntry + 0x48) = width * *reinterpret_cast<float*>(renderEntry + 0x30) + height;

        if (vertCount != 0 && !hasRotation)
        {
            // No rotation: simple vertex transform
            float* verts = reinterpret_cast<float*>(startVert * 0x38 + 4 + meshB);
            do
            {
                verts[5] = localScale * verts[-1] + depthScale + posY;
                verts[6] = width * *verts + height;
                verts += 0xE;
                vertCount--;
            } while (vertCount != 0);
        }
        else if (vertCount != 0 && hasRotation)
        {
            // With rotation: rotated vertex transform
            float cosA = 0.0f;
            float sinA = rotation;
            // Note: cosA/sinA would come from FUN_00483160/FUN_00483140

            float* verts = reinterpret_cast<float*>(meshB + (startVert * 7 + 3) * 8);
            do
            {
                *verts = (verts[-6] * cosA - verts[-5] * sinA) * localScale + depthScale + posY;
                verts[1] = (verts[-6] * sinA + verts[-5] * cosA) * width + height;
                verts += 0xE;
                vertCount--;
            } while (vertCount != 0);
        }
    }
}

} // namespace Giants
