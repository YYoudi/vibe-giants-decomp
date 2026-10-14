# RENDERER — fixed-function DX7 pipeline, plugin interface, modern reimplementations

Status: 🔶 interface + engine-side rendering mapped; per-stage state matrix open.

**Evidence:** corpus (`drawwrld_*`/`level_scene_mesh_render`/`status_hud_render`),
exe strings (`gg_%s` @ 0x17C984, `GDVSysCreate` @ 0x17C9CF), renderer DLLs in
`RESSOURCES_FOR_AI/Patches_extracts/GPatch*/gg_dx7r|dx9r|null.dll` and the demo
clean copies. **Derived** unless noted.

## Plugin interface (the contract a new renderer must honor)

The engine never links a renderer: at boot it builds `gg_%s` filenames (e.g.
`gg_dx7r.dll`, `gg_null.dll`) and `LoadLibrary`es the plugin, then resolves:

- `GDVSysCreate` — create the renderer instance (config passed in; the engine's
  device-enum filter fed the "menu 3D" investigations of earlier sessions).
- `GFXGetCapabilities` — caps query (drives the engine's feature fallbacks).
- `UpCallsLoad` — the plugin hands back / receives the **upcall table**: engine
  callbacks the renderer invokes (texture upload, vertex streams, state queries,
  `XFGetCameraOrigin`/`XFGetCameraAxis` seen as engine-side producers).

Renderer families shipped by the official 1.520 patches: `gg_dx7r.dll` (original),
`gg_dx9r.dll`, DX11/DX12 variants, `gg_null.dll` (null device — the cleanest spec
reference for the interface: it implements every upcall as a no-op).

## Engine side (what draws, in frame order)

- `render_view_xform @ 0x0042D550` — view/projection setup (feeds
  `textrender_3d_project`, `world_marker_3d_draw`).
- `level_scene_mesh_render @ 0x0042B5B0` — terrain + static scene (GTI patches, GBS
  meshes); `obj_in_render_range @ 0x0042B060` gates per-object draws.
- `main_drawwrld_* @ 0x004329B0/0x00432E10` + helpers — world render passes.
- `status_hud_render @ 0x0042C3E0` — HUD (icons, radar via `hud_radar_collide_sweep`,
  `hud_trilist_expand`); `hud_screen_text_render @ 0x00429E10` +
  `textrender_text_draw*` for all text (GText strings).
- Particles: `particle_lifespan_render`; FX: `fx_process`/`fx_logic` in the sim loop.
- Skinning is CPU-side (`anm_skin_verts_apply @ 0x0053D120`,
  `kabuto_skinning_eval_all @ 0x004676A0`) — vertices arrive transformed at the
  renderer (fixed-function friendly, and exactly what a wgpu port needs: upload
  transformed streams, no shaders required for parity).
- Procedural textures generated in-engine (e.g. `kabuto_laser_texture_init` 128×128
  radial falloff) — port those generators bit-exact.

## Modern reimplementations (reference behavior)

The official patch renderers (DX9/DX11/DX12 in `Patches_extracts/GPatch*`) prove the
upcall surface is version-stable: the same engine commands map onto newer APIs with
shader-based equivalents of the DX7 fixed-function pipeline (T&L → vertex shaders,
texture stages → pixel shaders). For the Rust/wgpu port: treat `gg_null.dll` as the
spec skeleton, port `GDVSysCreate/GFXGetCapabilities/UpCallsLoad` semantics, and start
with a WGSL passthrough of transformed vertex streams + multitexture terrain.

## Validation

- Screenshot oracle: engine-side HUD/text/marker layers are drawn through the same
  upcalls — `status_hud_render` hit cadence + `hud_trilist_expand` args give the
  draw-list shape per frame (P1.1).
- `render_error_poll @ 0x00426F20` + `render_error_dialog_check` — device-lost paths
  (the known menu-3D/D3DEnum saga in earlier sessions).
