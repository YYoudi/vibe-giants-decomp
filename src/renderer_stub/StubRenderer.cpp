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
    if (self && self->d3d9)
        return self->d3d9->Clear(0, nullptr, D3DCLEAR_TARGET,
                                 D3DCOLOR_XRGB(20, 40, 100), 1.0f, 0);
    return 0;
}
static HRESULT __attribute__((thiscall)) Stub_Present(StubDevice* self) {
    if (self && self->d3d9)
        return self->d3d9->Present(nullptr, nullptr, self->hWnd, nullptr);
    return 0;
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
