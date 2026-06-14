// GiantsRE — D3D9 wrapper stub renderer.
// Creates a REAL D3D9 device, wraps it with a Giants-compatible vtable layout:
//   vtable[43] = Clear (green background), vtable[41] = BeginScene,
//   vtable[42] = EndScene, vtable[47] = Present.
// Other entries are no-ops. This gives the recomp VISIBLE rendering (a colored
// window) while avoiding the original renderer's callback-driven render path.
#include <windows.h>
#include <cstdint>
#include <cmath>
#include <d3d9.h>

static IDirect3D9* g_d3d = nullptr;
static IDirect3DDevice9* g_dev = nullptr;

// Naked no-op (cdecl, caller cleanup).
extern "C" __attribute__((naked)) long DevStub() {
    __asm__ volatile ("xor %eax, %eax\n\t ret");
}

// Wrapper object: Giants vtable at [0], real D3D9 device at [4].
struct Wrap { void** vtbl; IDirect3DDevice9* dev; } g_wrap = {};

// thiscall wrappers (ECX=this=Wrap*, access dev at [ecx+4]).
extern "C" __attribute__((fastcall)) long Wrap_Clear(struct Wrap* self, uint32_t) {
    if (self->dev) {
        // Animate: cycle blue channel for a visible pulsing effect.
        DWORD tick = GetTickCount() / 20;
        D3DCOLOR c = D3DCOLOR_XRGB(0, 64, (tick ^ (tick >> 4)) & 0x7F);
        self->dev->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, c, 1.0f, 0);
    }
    return 0;
}
extern "C" __attribute__((fastcall)) long Wrap_BeginScene(struct Wrap* self) {
    if (self->dev) self->dev->BeginScene(); return 0;
}
extern "C" __attribute__((fastcall)) long Wrap_EndScene(struct Wrap* self) {
    if (self->dev) {
        // Draw a spinning colored triangle — visible 3D from the recomp exe.
        struct Vertex { float x, y, z; D3DCOLOR color; };
        float a = GetTickCount() / 500.0f;
        float ca = cosf(a), sa = sinf(a);
        Vertex tri[3] = {
            { 0.0f,        0.5f,        0.0f, D3DCOLOR_XRGB(255, 0, 0) },
            { -0.5f * ca - (-0.5f) * sa, -0.5f * ca + (-0.5f) * sa, 0.0f, D3DCOLOR_XRGB(0, 255, 0) },
            {  0.5f * ca - (-0.5f) * sa,  0.5f * ca + (-0.5f) * sa, 0.0f, D3DCOLOR_XRGB(0, 0, 255) },
        };
        self->dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
        self->dev->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 1, tri, sizeof(Vertex));
        self->dev->EndScene();
    }
    return 0;
}
extern "C" __attribute__((fastcall)) long Wrap_Present(struct Wrap* self) {
    if (self->dev) self->dev->Present(nullptr, nullptr, nullptr, nullptr);
    return 0;
}

static void* g_vtbl[64];

extern "C" __declspec(dllexport)
int GFXGetCapabilities(void* caps) {
    if (caps) { memset(caps, 0, 48);
        strcpy((char*)((char*)caps + 12), "GiantsRE D3D9 Wrap");
        *((int*)caps) = 1; *((int*)caps + 3) = 1; }
    return 1;
}

extern "C" __declspec(dllexport)
void* __cdecl GDVSysCreate(unsigned int ctx, HWND hWnd, DWORD* w, DWORD* win, DWORD* mode, void* param) {
    if (!g_d3d) g_d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if (!g_d3d) return nullptr;
    D3DPRESENT_PARAMETERS pp = {};
    pp.Windowed = TRUE;
    pp.BackBufferWidth = w ? *w : 1280; pp.BackBufferHeight = 720;
    pp.BackBufferFormat = D3DFMT_A8R8G8B8; pp.BackBufferCount = 1;
    pp.SwapEffect = D3DSWAPEFFECT_DISCARD; pp.hDeviceWindow = hWnd;
    pp.EnableAutoDepthStencil = TRUE; pp.AutoDepthStencilFormat = D3DFMT_D24S8;
    pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
    HRESULT hr = g_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &g_dev);
    if (FAILED(hr)) g_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
                            D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &g_dev);
    if (!g_dev) return nullptr;
    // Build Giants-compatible vtable.
    for (int i = 0; i < 64; i++) g_vtbl[i] = (void*)&DevStub;
    g_vtbl[43] = (void*)&Wrap_Clear;      // PrePresent → Clear
    g_vtbl[41] = (void*)&Wrap_BeginScene; // BeginScene
    g_vtbl[42] = (void*)&Wrap_EndScene;   // EndScene
    g_vtbl[47] = (void*)&Wrap_Present;    // Present
    g_wrap.vtbl = g_vtbl; g_wrap.dev = g_dev;
    return &g_wrap;
}

extern "C" __declspec(dllexport)
void __cdecl UpCallsLoad(unsigned int ver, unsigned int count, unsigned int table) {
    // No-op — the stub renderer does not call back into the engine.
}

BOOL APIENTRY DllMain(HMODULE, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_DETACH) {
        if (g_dev) { g_dev->Release(); g_dev = nullptr; }
        if (g_d3d) { g_d3d->Release(); g_d3d = nullptr; }
    }
    return TRUE;
}
