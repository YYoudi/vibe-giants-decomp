// Giants Stub Renderer (gg_dx9r_stub.dll) — Route B for visible output.
//
// The real gg_dx9r.dll requires the full engine-context protocol (UpCalls + 22
// callbacks + engine-context vtable) which the recomp doesn't drive — its
// methods crash. This stub OWNS its own IDirect3DDevice9 and exposes a wrapper
// object whose vtable implements the slots the recomp's render path calls,
// using D3D9 directly. Deployed as gg_dx9r.dll (via registry Renderer name) it
// lets the recomp produce visible output (Clear + Present) without the protocol.
//
// Giants renderer exports (ordinals 1,2,3):
//   GDVSysCreate(cmdLine, hWnd, dispCfg, winCfg, modeCfg, engineCtx) → device
//   GFXGetCapabilities(idx) → DWORD
//   UpCallsLoad(version, count, table) → registers callbacks

#include <windows.h>
#include <d3d9.h>
#include <cstdio>
#include <cstdint>
#include <cstring>

static void StubLog(const char* msg);  // forward decl (defined below)

// ─── Stub wrapper object: [0]=vtable, [1]=IDirect3DDevice9*, [2..]=state ──
// The vtable must be large enough for all slots the recomp indexes. We provide
// no-op defaults and implement the known render slots via D3D9.
struct StubDevice {
    void** vtable;            // [0]
    IDirect3DDevice9* d3d9;   // [1] — the real D3D9 device we own
    HWND   hWnd;              // [2]
    uint32_t pad[130];        // state scratch (large so EngineInit's DUMP/D3D9SCAN
                              // reads of obj[0..128] stay within this object)
};

// ─── D3D9-backed vtable method implementations ─────────────────────────
// Slot mapping (from GameLogic.cpp comments + TextRender findings):
//   vtable[ 9] = begin text batch
//   vtable[41] = BeginScene
//   vtable[42] = EndScene / ShutdownSubsystems
//   vtable[43] = Clear / PrePresent
//   vtable[47] = Present

static HRESULT __attribute__((thiscall)) Stub_BeginScene(StubDevice* self) {
    if (self && self->d3d9) return self->d3d9->BeginScene();
    return 0;
}
static HRESULT __attribute__((thiscall)) Stub_EndScene(StubDevice* self) {
    if (self && self->d3d9) return self->d3d9->EndScene();
    return 0;
}
static HRESULT __attribute__((thiscall)) Stub_Clear(StubDevice* self) {
    // Clear via GDI FillRect on the backbuffer DC (more reliable than D3D Clear
    // when GetDC is used for text — avoids D3D/GDI composition issues).
    if (!self || !self->d3d9) return 0;
    IDirect3DSurface9* back = nullptr;
    if (FAILED(self->d3d9->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &back)) || !back) return 0;
    HDC hdc = nullptr;
    static bool s_loggedGetDC = false;
    HRESULT hr = back->GetDC(&hdc);
    if (!s_loggedGetDC) {
        s_loggedGetDC = true;
        char msg[128]; snprintf(msg, sizeof(msg), "[STUB] backbuffer GetDC hr=0x%08X, hdc=%p", (unsigned)hr, hdc);
        StubLog(msg);
    }
    if (SUCCEEDED(hr) && hdc) {
        RECT rc = { 0, 0, 1280, 720 };
        HBRUSH br = CreateSolidBrush(RGB(20, 40, 100));
        FillRect(hdc, &rc, br);
        DeleteObject(br);
        back->ReleaseDC(hdc);
    }
    back->Release();
    return 0;
}
static HRESULT __attribute__((thiscall)) Stub_Present(StubDevice* self) {
    if (self && self->d3d9)
        return self->d3d9->Present(nullptr, nullptr, self->hWnd, nullptr);
    return 0;
}

// ─── Cursor rendering (a crosshair / box at the mouse position) ────────
static void __attribute__((thiscall)) Stub_DrawCursor(StubDevice* self, int x, int y) {
    if (!self || !self->d3d9) return;
    IDirect3DSurface9* back = nullptr;
    if (FAILED(self->d3d9->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &back)) || !back) return;
    HDC hdc = nullptr;
    if (SUCCEEDED(back->GetDC(&hdc)) && hdc) {
        // Clamp cursor into the viewport; scale mouse units (~0..4096) to pixels.
        int px = (x < 0) ? 0 : (x * 1280) / 4096;
        int py = (y < 0) ? 0 : (y * 720) / 4096;
        HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 220, 0));
        HGDIOBJ old = SelectObject(hdc, pen);
        MoveToEx(hdc, px - 10, py, nullptr); LineTo(hdc, px + 10, py);
        MoveToEx(hdc, px, py - 10, nullptr); LineTo(hdc, px, py + 10);
        SelectObject(hdc, old); DeleteObject(pen);
        back->ReleaseDC(hdc);
    }
    back->Release();
}
// IDirect3DDevice9::GetBackBuffer → IDirect3DSurface9::GetDC → GDI DrawText
// → ReleaseDC. Draws the localized string the recomp passes each frame.
static HFONT g_stubFont = nullptr;
static void __attribute__((thiscall)) Stub_DrawTextString(StubDevice* self, const char* str) {
    if (!self || !self->d3d9 || !str || !*str) return;
    if (!g_stubFont) {
        g_stubFont = CreateFontA(28, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                                 DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                 CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
                                 DEFAULT_PITCH | FF_SWISS, "Arial");
    }
    IDirect3DSurface9* back = nullptr;
    if (FAILED(self->d3d9->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &back)) || !back)
        return;
    HDC hdc = nullptr;
    if (SUCCEEDED(back->GetDC(&hdc)) && hdc) {
        HFONT oldFont = (HFONT)SelectObject(hdc, g_stubFont);
        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, RGB(255, 255, 255));
        // Draw each '\n'-separated line at increasing Y.
        int y = 20;
        const char* p = str;
        while (*p) {
            const char* nl = strchr(p, '\n');
            int len = nl ? (int)(nl - p) : -1;
            RECT rc = { 20, y, 1260, y + 40 };
            DrawTextA(hdc, p, len, &rc, DT_LEFT | DT_TOP | DT_NOCLIP);
            y += 32;
            if (!nl) break;
            p = nl + 1;
        }
        SelectObject(hdc, oldFont);
        back->ReleaseDC(hdc);
    }
    back->Release();
}
static void __attribute__((thiscall)) Stub_NoOp(StubDevice* /*self*/) {}
static uint32_t __attribute__((thiscall)) Stub_GetCapability(StubDevice* /*self*/, int idx) {
    // index 1=width, 2=height, 0=windowed flag
    switch (idx) {
        case 0: return 1;     // windowed
        case 1: return 1280;  // width
        case 2: return 720;   // height
        default: return 0;
    }
}

// Build a large vtable (60 slots) of no-ops, then overlay the known slots.
static void** BuildStubVtable() {
    static void* vt[60];
    static bool init = false;
    if (!init) {
        for (int i = 0; i < 60; i++) vt[i] = (void*)&Stub_NoOp;
        vt[9]  = (void*)&Stub_NoOp;            // begin text batch (no-op)
        vt[41] = (void*)&Stub_BeginScene;
        vt[42] = (void*)&Stub_EndScene;
        vt[43] = (void*)&Stub_Clear;
        vt[44] = (void*)&Stub_DrawTextString;   // draw a localized string (thiscall str arg)
        vt[45] = (void*)&Stub_DrawCursor;        // draw cursor at (x,y) (thiscall int args)
        vt[47] = (void*)&Stub_Present;
        vt[53] = (void*)&Stub_GetCapability;   // 0xD4/4 = GetCapability
        init = true;
    }
    return vt;
}

static FILE* g_stubLog = nullptr;
static void StubLog(const char* msg) {
    if (!g_stubLog) g_stubLog = fopen("stub_renderer.log", "w");
    if (g_stubLog) { fprintf(g_stubLog, "%s\n", msg); fflush(g_stubLog); }
}

// ─── GDVSysCreate (ordinal 1) — create our OWN D3D9 device ─────────────
extern "C" __declspec(dllexport)
void* __cdecl GDVSysCreate(const char* cmdLine, HWND hWnd, void* dispCfg,
                           void* winCfg, void* modeCfg, void* engineCtx)
{
    StubLog("[STUB] GDVSysCreate called");
    if (!hWnd) { StubLog("[STUB] no hWnd"); return nullptr; }

    IDirect3D9* d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if (!d3d) { StubLog("[STUB] Direct3DCreate9 failed"); return nullptr; }

    D3DPRESENT_PARAMETERS pp = {};
    pp.Windowed = TRUE;
    pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    pp.BackBufferWidth = 1280;
    pp.BackBufferHeight = 720;
    pp.BackBufferFormat = D3DFMT_UNKNOWN;
    pp.hDeviceWindow = hWnd;
    pp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;  // required for GetDC on backbuffer

    IDirect3DDevice9* dev = nullptr;
    HRESULT hr = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                   D3DCREATE_HARDWARE_VERTEXPROCESSING, &pp, &dev);
    d3d->Release();
    if (FAILED(hr) || !dev) { StubLog("[STUB] CreateDevice failed"); return nullptr; }

    StubDevice* obj = (StubDevice*)calloc(1, sizeof(StubDevice));
    obj->vtable = BuildStubVtable();
    obj->d3d9 = dev;
    obj->hWnd = hWnd;
    StubLog("[STUB] GDVSysCreate OK — device created");
    return obj;
}

// ─── GFXGetCapabilities (ordinal 2) ────────────────────────────────────
extern "C" __declspec(dllexport)
uint32_t __cdecl GFXGetCapabilities(int idx)
{
    return Stub_GetCapability(nullptr, idx);
}

// ─── UpCallsLoad (ordinal 3) — store/ignore callbacks ──────────────────
extern "C" __declspec(dllexport)
void __cdecl UpCallsLoad(uint32_t version, uint32_t count, uint32_t table)
{
    (void)version; (void)count; (void)table;
    StubLog("[STUB] UpCallsLoad (no-op, stub owns its device)");
}

extern "C" BOOL WINAPI DllMain(HINSTANCE, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) StubLog("[STUB] gg_dx9r_stub.dll loaded");
    return TRUE;
}
