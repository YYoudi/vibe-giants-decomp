// GiantsRE — Minimal stub renderer DLL for recomp-exe testing.
// Creates a real D3D9 device but does NOT call back into the engine during render
// (no UpCalls invocations). This lets the recomp exe complete InitializeEngine +
// enter MainGameLoop without the render-path crash (which comes from the original
// renderer using incomplete engine state). The result: a RUNNING recomp exe that
// creates a window + D3D9 device + enters its game loop — even without rendering.
//
// Build: i686-w64-mingw32-g++ -shared -o gg_dx9r.dll recomp_stub_renderer.cpp -ld3d9
// Deploy: copy as gg_dx9r.dll in the run directory (GameFiles).

#include <windows.h>
#include <d3d9.h>

static IDirect3D9* g_d3d = nullptr;
static IDirect3DDevice9* g_device = nullptr;

extern "C" __declspec(dllexport)
int GFXGetCapabilities(void* caps) {
    if (caps) {
        // Fill minimal capability info (name + version)
        memset(caps, 0, 48);
        strcpy((char*)((char*)caps + 12), "GiantsRE Stub DX9");
        *((int*)caps + 0) = 1;   // maxAnisotropy
        *((int*)caps + 1) = 0;   // flags
        *((int*)caps + 2) = 0;   // priority
        *((int*)caps + 3) = 1;   // interfaceVersion
    }
    return 1;
}

// Minimal fake device — a struct with a vtable of no-op stubs. The recomp treats
// this as the render device. All vtable calls are no-ops (return S_OK/0). No real
// D3D9 interaction → no D3D9 threads → no D3D9 crashes. Lets the recomp's init
// path proceed to MainGameLoop.
// Naked no-op: returns 0 (S_OK) without cleaning any stack args (cdecl-like).
// The recomp's CallThiscall wrappers handle their own stack cleanup.
extern "C" __attribute__((naked)) long DevStub() {
    __asm__ volatile ("xor %eax, %eax\n\t ret");
}
static void* g_devVtable[64] = {0};
static struct { void** vtable; int pad[15]; } g_fakeDevice = { g_devVtable, {0} };

extern "C" __declspec(dllexport)
void* __cdecl GDVSysCreate(unsigned int context, HWND hWnd, DWORD* width,
                           DWORD* windowed, DWORD* mode, void* param) {
    // Fill vtable with no-op stubs (all device methods return S_OK).
    for (int i = 0; i < 64; i++) g_devVtable[i] = (void*)&DevStub;
    return &g_fakeDevice;
}

extern "C" __declspec(dllexport)
void __cdecl UpCallsLoad(unsigned int version, unsigned int count, unsigned int table) {
    // Store the callback table but do NOT call any callbacks during render.
    // This prevents the render-path crash (original renderer calls engine callbacks
    // that are stubbed → bad data → crash).
}

BOOL APIENTRY DllMain(HMODULE, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_DETACH) {
        if (g_device) { g_device->Release(); g_device = nullptr; }
        if (g_d3d) { g_d3d->Release(); g_d3d = nullptr; }
    }
    return TRUE;
}
