// GiantsRE — D3D9 wrapper stub renderer.
// Creates a REAL D3D9 device, wraps it with a Giants-compatible vtable layout:
//   vtable[43] = Clear, vtable[41] = BeginScene,
//   vtable[42] = EndScene (draws the scene), vtable[47] = Present.
// Other entries are no-ops. This gives the recomp VISIBLE rendering — a richer
// 3D scene (rotating cube + grid floor + animated background) — while avoiding
// the original renderer's callback-driven render path.
//
// This is the visual proof-of-life for the recompiled GiantsMain.exe: the
// engine's ProcessGameLogic 11-phase loop drives these wrappers every frame.
#include <windows.h>
#include <cstdint>
#include <cmath>
#include <cstdio>
#include <d3d9.h>

static IDirect3D9* g_d3d = nullptr;
static IDirect3DDevice9* g_dev = nullptr;

// Naked no-op (cdecl, caller cleanup).
extern "C" __attribute__((naked)) long DevStub() {
    __asm__ volatile ("xor %eax, %eax\n\t ret");
}

// Wrapper object: Giants vtable at [0], real D3D9 device at [4].
struct Wrap { void** vtbl; IDirect3DDevice9* dev; } g_wrap = {};

// ─── Minimal matrix math (D3D left-handed, row-major) ───────────────
struct Vec3 { float x, y, z; };

static Vec3 vsub(Vec3 a, Vec3 b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }
static Vec3 vadd(Vec3 a, Vec3 b) { return { a.x + b.x, a.y + b.y, a.z + b.z }; }
static Vec3 vscale(Vec3 a, float s) { return { a.x*s, a.y*s, a.z*s }; }
static float vdot(Vec3 a, Vec3 b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
static Vec3 vcross(Vec3 a, Vec3 b) {
    return { a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x };
}
static Vec3 vnorm(Vec3 a) {
    float len = sqrtf(vdot(a, a));
    if (len < 1e-8f) return {0,0,0};
    return vscale(a, 1.0f / len);
}

// D3D left-handed LookAt view matrix (row-major, 4x4).
static void ViewMatrixLH(float* m, Vec3 eye, Vec3 at, Vec3 up) {
    Vec3 z = vnorm(vsub(at, eye));
    Vec3 x = vnorm(vcross(up, z));
    Vec3 y = vcross(z, x);
    m[0]=x.x; m[1]=y.x; m[2]=z.x; m[3]=0;
    m[4]=x.y; m[5]=y.y; m[6]=z.y; m[7]=0;
    m[8]=x.z; m[9]=y.z; m[10]=z.z; m[11]=0;
    m[12]=-vdot(x,eye); m[13]=-vdot(y,eye); m[14]=-vdot(z,eye); m[15]=1;
}

// D3D left-handed perspective projection matrix (row-major, 4x4).
static void PerspectiveLH(float* m, float fovy, float aspect, float zn, float zf) {
    float yScale = 1.0f / tanf(fovy * 0.5f);
    float xScale = yScale / aspect;
    m[0]=xScale; m[1]=0; m[2]=0; m[3]=0;
    m[4]=0; m[5]=yScale; m[6]=0; m[7]=0;
    m[8]=0; m[9]=0; m[10]=zf/(zf-zn); m[11]=1;
    m[12]=0; m[13]=0; m[14]=-zn*zf/(zf-zn); m[15]=0;
}

// thiscall wrappers (ECX=this=Wrap*, access dev at [ecx+4]).
extern "C" __attribute__((fastcall)) long Wrap_Clear(struct Wrap* self, uint32_t) {
    if (self->dev) {
        // Sky-blue clear (background fill — the intro_island menu is under open sky).
        D3DCOLOR c = D3DCOLOR_XRGB(120, 165, 220);
        self->dev->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, c, 1.0f, 0);
    }
    return 0;
}
extern "C" __attribute__((fastcall)) long Wrap_BeginScene(struct Wrap* self) {
    if (self->dev) {
        self->dev->BeginScene();
        // Set up a proper 3D camera once per frame.
        float view[16], proj[16];
        ViewMatrixLH(view, {0.0f, 3.0f, -6.0f}, {0,0,0}, {0,1,0});
        PerspectiveLH(proj, 0.9f, 16.0f/9.0f, 0.1f, 100.0f);
        self->dev->SetTransform((D3DTRANSFORMSTATETYPE)2, (const D3DMATRIX*)view);   // VIEW
        self->dev->SetTransform((D3DTRANSFORMSTATETYPE)3, (const D3DMATRIX*)proj);   // PROJECTION
        self->dev->SetRenderState(D3DRS_LIGHTING, FALSE);
        self->dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
        self->dev->SetRenderState(D3DRS_ZENABLE, TRUE);
    }
    return 0;
}

// Cube vertices: position + diffuse color (FVF XYZ|DIFFUSE).
struct Vertex { float x, y, z; D3DCOLOR color; };

// 12 triangles (6 faces x 2) of a unit cube centered at origin.
static const Vec3 kCubeV[8] = {
    {-1,-1,-1},{ 1,-1,-1},{ 1, 1,-1},{-1, 1,-1},  // back face
    {-1,-1, 1},{ 1,-1, 1},{ 1, 1, 1},{-1, 1, 1},  // front face
};
static const int kCubeTri[12][3] = {
    {0,1,2},{0,2,3},  // back
    {5,4,7},{5,7,6},  // front
    {4,0,3},{4,3,7},  // left
    {1,5,6},{1,6,2},  // right
    {3,2,6},{3,6,7},  // top
    {4,5,1},{4,1,0},  // bottom
};
static const D3DCOLOR kFaceColor[6] = {
    D3DCOLOR_XRGB(220, 60, 60),   // back  - red
    D3DCOLOR_XRGB(60, 220, 90),   // front - green
    D3DCOLOR_XRGB(70, 130, 240),  // left  - blue
    D3DCOLOR_XRGB(255, 200, 40),  // right - yellow
    D3DCOLOR_XRGB(220, 220, 220), // top   - white
    D3DCOLOR_XRGB(160, 90, 220),  // bottom- purple
};

// World rotation matrix (around Y then X), row-major.
static void RotWorld(float* m, float ay, float ax) {
    float ca = cosf(ay), sa = sinf(ay);
    float cb = cosf(ax), sb = sinf(ax);
    // Ry * Rx
    m[0]=ca;      m[1]=0;   m[2]=-sa;     m[3]=0;
    m[4]=sb*sa;   m[5]=cb;  m[6]=sb*ca;   m[7]=0;
    m[8]=cb*sa;   m[9]=-sb; m[10]=cb*ca;  m[11]=0;
    m[12]=0;      m[13]=0;  m[14]=0;      m[15]=1;
}

static void DrawCube(IDirect3DDevice9* dev, float t) {
    float world[16];
    RotWorld(world, t, t * 0.6f);
    dev->SetTransform((D3DTRANSFORMSTATETYPE)0, (const D3DMATRIX*)world); // WORLD

    Vertex tri[36];
    for (int f = 0; f < 6; f++) {
        for (int i = 0; i < 2; i++) {
            const int* idx = kCubeTri[f*2 + i];
            tri[f*6 + i*3 + 0] = { kCubeV[idx[0]].x, kCubeV[idx[0]].y, kCubeV[idx[0]].z, kFaceColor[f] };
            tri[f*6 + i*3 + 1] = { kCubeV[idx[1]].x, kCubeV[idx[1]].y, kCubeV[idx[1]].z, kFaceColor[f] };
            tri[f*6 + i*3 + 2] = { kCubeV[idx[2]].x, kCubeV[idx[2]].y, kCubeV[idx[2]].z, kFaceColor[f] };
        }
    }
    dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
    dev->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, tri, sizeof(Vertex));
}

static void DrawGrid(IDirect3DDevice9* dev, float t) {
    float world[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
    dev->SetTransform((D3DTRANSFORMSTATETYPE)0, (const D3DMATRIX*)world); // WORLD

    const int N = 20;           // grid half-extent in cells
    const float S = 1.0f;       // cell size
    const float y = -2.0f;
    D3DCOLOR c1 = D3DCOLOR_XRGB(60, 60, 90);
    D3DCOLOR c2 = D3DCOLOR_XRGB(120, 120, 160);

    // Batch ALL grid lines into ONE draw call (2 verts * 2*(2N+1) lines) — far
    // gentler on the GPU driver than ~80 individual DrawPrimitiveUP calls.
    const int kLineCount = 2 * (2 * N + 1);
    Vertex lines[2 * 2 * 21 * 2]; // sized for N<=20; index below
    int n = 0;
    for (int i = -N; i <= N; i++) {
        D3DCOLOR c = (i == 0) ? c2 : c1;
        lines[n++] = { (float)i * S, y, (float)-N * S, c };
        lines[n++] = { (float)i * S, y, (float) N * S, c };
        lines[n++] = { (float)-N * S, y, (float)i * S, c };
        lines[n++] = { (float) N * S, y, (float)i * S, c };
    }
    dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
    dev->DrawPrimitiveUP(D3DPT_LINELIST, n / 2, lines, sizeof(Vertex));
    (void)t; (void)kLineCount;
}

// ─── Terrain rendering (reads decoded heights from terrain_heights.bin) ───
// The recomp decodes intro_island.gti (115x142 grid) and writes the heights to
// terrain_heights.bin. Here we read it once + render the terrain mesh — REAL
// game content (the actual intro island) rendered by the recomp.
struct TVertex { float x, y, z; D3DCOLOR color; };
static int      g_tW = 0, g_tH = 0;
static float*   g_tHeights = nullptr;
static uint8_t* g_tLightmap = nullptr;   // RGB per cell (real terrain colors)
static TVertex* g_tMesh = nullptr;
static int      g_tTriCount = 0;
static bool     g_tTried = false;
// Real terrain world placement (from GTI header) — render at engine coords.
static float    g_tOffX = 0, g_tOffY = 0, g_tStretch = 40.0f, g_tMinH = 0;
// Real camera keyframes from flk_intro_island_1.bin (engine frame: X, Y, Z=height).
// Camera01's flight path + its look-at target (Camera01.Target).
struct CamKey { float ex, ey, ez; };
static const CamKey g_camKeys[] = {
    { 2758.73f, -2020.50f, 2868.66f },
    { -1333.42f, 5655.65f, 3078.72f },
    { -1979.81f, 4736.02f,  715.19f },
    { -3230.62f, 4058.18f,  374.02f },
};
static const CamKey g_camTarget = { -1239.0f, 1776.8f, 222.8f };
// Last frame's camera state (set by DrawTerrain, used by DrawLogo).
static Vec3 g_lastCamPos = {0,0,0}, g_lastCamFwd = {0,0,1};

static void LoadTerrain() {
    if (g_tTried) return;
    g_tTried = true;
    FILE* f = fopen("terrain_heights.bin", "rb");
    if (!f) return;
    float stretch, offX, offY, minH, maxH;
    if (fread(&g_tW, 4, 1, f) != 1) { fclose(f); return; }
    if (fread(&g_tH, 4, 1, f) != 1) { fclose(f); return; }
    fread(&stretch, 4, 1, f); fread(&offX, 4, 1, f); fread(&offY, 4, 1, f);
    fread(&minH, 4, 1, f); fread(&maxH, 4, 1, f);
    g_tOffX = offX; g_tOffY = offY; g_tStretch = stretch; g_tMinH = minH;
    if (g_tW <= 0 || g_tH <= 0 || g_tW > 256 || g_tH > 256) { fclose(f); return; }
    int cc = g_tW * g_tH;
    g_tHeights = (float*)malloc(cc * 4);
    if (fread(g_tHeights, 4, cc, f) != (size_t)cc) { fclose(f); return; }
    g_tLightmap = (uint8_t*)malloc(cc * 3);
    size_t lr = fread(g_tLightmap, 1, cc * 3, f);  // may be absent in old files
    fclose(f);
    bool hasLightmap = (lr == (size_t)(cc * 3));
    (void)maxH;
    const float hRange = (maxH - minH > 0.001f) ? (maxH - minH) : 1.0f;
    // Render at REAL engine world coords (GTI: pos = offset + index*stretch, height
    // from heights[]). Engine is Z-up (height=Z); D3D is Y-up → we put height in Y,
    // engine-X in X, engine-Y in Z (the documented Y/Z swap).
    auto vpos = [&](int x, int y) {
        float ex = offX + x * stretch;        // engine X
        float ey = offY + y * stretch;        // engine Y
        float h  = g_tHeights[y * g_tW + x];  // engine Z (height)
        return TVertex{ ex, h, ey };          // D3D: (X, Y=height, Z=engineY)
    };
    auto realColor = [&](int x, int y) -> D3DCOLOR {
        if (hasLightmap) {
            int i = (y * g_tW + x) * 3;
            return D3DCOLOR_XRGB(g_tLightmap[i], g_tLightmap[i+1], g_tLightmap[i+2]);
        }
        float fr = (g_tHeights[y * g_tW + x] - minH) / hRange;
        if (fr > 0.8f) return D3DCOLOR_XRGB(240, 240, 255);
        if (fr > 0.5f) return D3DCOLOR_XRGB(120, 90, 60);
        if (fr > 0.15f) return D3DCOLOR_XRGB(60, 110, 50);
        return D3DCOLOR_XRGB(40, 70, 120);
    };
    g_tMesh = (TVertex*)malloc((g_tW - 1) * (g_tH - 1) * 6 * sizeof(TVertex));
    g_tTriCount = 0;
    for (int y = 0; y < g_tH - 1; y++) {
        for (int x = 0; x < g_tW - 1; x++) {
            TVertex a = vpos(x, y); a.color = realColor(x, y);
            TVertex b = vpos(x + 1, y); b.color = realColor(x + 1, y);
            TVertex c = vpos(x, y + 1); c.color = realColor(x, y + 1);
            TVertex d = vpos(x + 1, y + 1); d.color = realColor(x + 1, y + 1);
            g_tMesh[g_tTriCount * 3 + 0] = a; g_tMesh[g_tTriCount * 3 + 1] = b; g_tMesh[g_tTriCount * 3 + 2] = c;
            g_tTriCount++;
            g_tMesh[g_tTriCount * 3 + 0] = b; g_tMesh[g_tTriCount * 3 + 1] = d; g_tMesh[g_tTriCount * 3 + 2] = c;
            g_tTriCount++;
        }
    }
    // Marker file so the build harness can verify the terrain mesh loaded
    // (the visual is the user's; this confirms the data path headlessly).
    FILE* m = fopen("terrain_loaded.txt", "w");
    if (m) { fprintf(m, "loaded W=%d H=%d tris=%d hasLightmap=%d\n",
                     g_tW, g_tH, g_tTriCount, hasLightmap ? 1 : 0); fclose(m); }
}

static void DrawTerrain(IDirect3DDevice9* dev) {
    LoadTerrain();
    if (!g_tMesh || g_tTriCount == 0) return;
    // REAL camera from flk_intro_island_1.bin: interpolate the 4 FLICK keyframes
    // (Camera01's flight). Engine frame (X,Y,Z=height) → D3D Y-up via Y/Z swap:
    //   cam render pos = (ex, ez, ey), target render = (tex, tez, tey).
    constexpr int NKEYS = sizeof(g_camKeys)/sizeof(g_camKeys[0]);
    float seg = fmodf(GetTickCount() / 4000.0f, (float)NKEYS);  // ~4s per keyframe
    int k0 = (int)floorf(seg) % NKEYS;
    int k1 = (k0 + 1) % NKEYS;
    float frac = seg - floorf(seg);
    // smoothstep for ease in/out
    frac = frac*frac*(3 - 2*frac);
    const CamKey &a = g_camKeys[k0], &b = g_camKeys[k1];
    float ex = a.ex + (b.ex - a.ex) * frac;
    float ey = a.ey + (b.ey - a.ey) * frac;
    float ez = a.ez + (b.ez - a.ez) * frac;
    Vec3 camPos  = { ex, ez, ey };                          // (X, Z, Y)
    Vec3 target  = { g_camTarget.ex, g_camTarget.ez, g_camTarget.ey };
    g_lastCamPos = camPos;
    g_lastCamFwd = vnorm(vsub(target, camPos));
    float view[16], proj[16];
    ViewMatrixLH(view, camPos, target, {0, 1, 0});
    PerspectiveLH(proj, 0.9f, 16.0f / 9.0f, 1.0f, 20000.0f);  // large far plane (world is ~5000 units)
    dev->SetTransform((D3DTRANSFORMSTATETYPE)2, (const D3DMATRIX*)view);
    dev->SetTransform((D3DTRANSFORMSTATETYPE)3, (const D3DMATRIX*)proj);
    dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
    dev->DrawPrimitiveUP(D3DPT_TRIANGLELIST, g_tTriCount, g_tMesh, sizeof(TVertex));
}

// ─── Logo rendering (Giants_logo_3D.gbs — the menu's always-visible 3D logo) ───
// The logo is camera-fixed (moves WITH the camera in the menu, so it stays
// screen-centered while the terrain scrolls behind). We render it in front of
// the camera each frame, matching that behavior.
struct LVertex { float x, y, z; D3DCOLOR color; };
static LVertex* g_logoMesh = nullptr;
static int      g_logoTris = 0;
static bool     g_logoTried = false;

static void DrawLogo(IDirect3DDevice9* dev, Vec3 camPos, Vec3 camFwd) {
    if (!g_logoTried) {
        g_logoTried = true;
        FILE* f = fopen("logo_mesh.bin", "rb");
        if (f) {
            uint32_t nv = 0, nt = 0;
            fread(&nv, 4, 1, f);
            if (nv > 0 && nv < 100000) {
                // Read indexed verts: 3 floats (pos) + 3 bytes (color), 15 bytes each.
                float* vpos = (float*)malloc(nv * 3 * 4);
                for (uint32_t i = 0; i < nv; i++) {
                    fread(&vpos[i*3], 4, 1, f);
                    fread(&vpos[i*3+1], 4, 1, f);
                    fread(&vpos[i*3+2], 4, 1, f);
                    uint8_t rgb[3]; fread(rgb, 1, 3, f);  // skip color (use metallic)
                }
                fread(&nt, 4, 1, f);
                if (nt > 0 && nt < 100000) {
                    uint32_t* tri = (uint32_t*)malloc(nt * 3 * 4);
                    fread(tri, 4, nt * 3, f);
                    g_logoMesh = (LVertex*)malloc(nt * 3 * sizeof(LVertex));
                    g_logoTris = 0;
                    for (uint32_t i = 0; i < nt; i++) {
                        uint32_t a = tri[i*3], b = tri[i*3+1], c = tri[i*3+2];
                        if (a >= nv || b >= nv || c >= nv) continue;  // bounds check
                        D3DCOLOR col = D3DCOLOR_XRGB(210, 190, 130);  // metallic gold
                        g_logoMesh[g_logoTris*3+0] = {vpos[a*3], vpos[a*3+1], vpos[a*3+2], col};
                        g_logoMesh[g_logoTris*3+1] = {vpos[b*3], vpos[b*3+1], vpos[b*3+2], col};
                        g_logoMesh[g_logoTris*3+2] = {vpos[c*3], vpos[c*3+1], vpos[c*3+2], col};
                        g_logoTris++;
                    }
                    free(tri);
                }
                free(vpos);
            }
            fclose(f);
            FILE* m = fopen("logo_loaded.txt", "w");
            if (m) { fprintf(m, "logo tris=%d\n", g_logoTris); fclose(m); }
        }
    }
    if (!g_logoMesh || g_logoTris == 0) return;
    // Logo is camera-fixed: scale + place in front of camera (screen-centered).
    float world[16];
    float s = 0.08f;
    float cx = camPos.x + camFwd.x * 30.0f;
    float cy = camPos.y + camFwd.y * 30.0f;
    float cz = camPos.z + camFwd.z * 30.0f;
    world[0]=s;  world[1]=0;  world[2]=0;  world[3]=0;
    world[4]=0;  world[5]=s;  world[6]=0;  world[7]=0;
    world[8]=0;  world[9]=0;  world[10]=s; world[11]=0;
    world[12]=cx-5.0f; world[13]=cy; world[14]=cz; world[15]=1;
    dev->SetTransform((D3DTRANSFORMSTATETYPE)0, (const D3DMATRIX*)world);
    dev->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
    dev->DrawPrimitiveUP(D3DPT_TRIANGLELIST, g_logoTris, g_logoMesh, sizeof(LVertex));
}

extern "C" __attribute__((fastcall)) long Wrap_EndScene(struct Wrap* self) {
    if (self->dev) {
        DrawTerrain(self->dev);   // REAL intro_island terrain (if decoded)
        // Logo is camera-fixed: render it in front of the camera (screen-centered).
        DrawLogo(self->dev, g_lastCamPos, g_lastCamFwd);
        float t = GetTickCount() / 700.0f;
        DrawGrid(self->dev, t);   // grid floor (fallback if no terrain)
        DrawCube(self->dev, t);
        self->dev->EndScene();
    }
    return 0;
}
extern "C" __attribute__((fastcall)) long Wrap_Present(struct Wrap* self) {
    if (self->dev) self->dev->Present(nullptr, nullptr, nullptr, nullptr);
    return 0;
}

static void* g_vtbl[64];

// ─── Factory interface (renderer → engine) ────────────────────────────
// InitGraphicsResources calls Wrap vtable[2]/[3]/[4] as free functions
// (cdecl, no `this`) to obtain device/buffer handles. The returned objects
// are COM-like Resources; BeginScene calls their vtable[4] (stage setup),
// ShutdownSubsystems their vtable[1] (shutdown), bindBuffer their vtable[2].
// All Resource vtable entries are cdecl no-ops (the stub owns rendering via the
// Wrap's Clear/BeginScene/EndScene/Present slots; these just satisfy the
// ref-counted stage machinery so it runs instead of being skipped).
struct Resource { void** vtable; int ref; };

extern "C" long Res_Vtbl0()                                        { return 0; }
extern "C" long Res_Vtbl1(void* /*self*/, uint32_t /*param*/)      { return 0; } // shutdown(this,param)
extern "C" long Res_Vtbl2(void* /*device*/)                        { return 0; } // bind(device)
extern "C" long Res_Vtbl4(void* /*self*/, int, int)                { return 0; } // setup(this,stage,param)

static void* g_resVtable[8] = {
    (void*)Res_Vtbl0, (void*)Res_Vtbl1, (void*)Res_Vtbl2, (void*)Res_Vtbl0,
    (void*)Res_Vtbl4, (void*)Res_Vtbl0, (void*)Res_Vtbl0, (void*)Res_Vtbl0,
};
static Resource g_capsResource   = { g_resVtable, 1 };
static Resource g_deviceResource = { g_resVtable, 1 };

// Factory methods — cdecl free functions (called via the Wrap vtable).
extern "C" void* Factory_GetCaps() { return &g_capsResource; }
extern "C" void* Factory_CreateDevice() { return &g_deviceResource; }
extern "C" void* Factory_CreateBuffer(uint32_t, uint32_t, uint32_t, void*,
                                      uint32_t, uint32_t, uint32_t, uint32_t) {
    Resource* r = (Resource*)malloc(sizeof(Resource));
    if (r) { r->vtable = g_resVtable; r->ref = 1; }
    return r;
}

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
    // Factory interface (InitGraphicsResources calls these as cdecl free fns).
    g_vtbl[2]  = (void*)&Factory_CreateDevice; // vtable[2]  = CreateDevice → device Resource
    g_vtbl[3]  = (void*)&Factory_GetCaps;      // vtable[3]  = GetCaps → caps Resource
    g_vtbl[4]  = (void*)&Factory_CreateBuffer; // vtable[4]  = CreateBuffer → buffer Resource
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
