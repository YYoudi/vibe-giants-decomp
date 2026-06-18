# Vanilla foundation post-1.5-purge (2026-06-18)

## State: 100% vanilla-only, foundation complete
- **Binary**: `GameFiles-VanillaV1/Giants_nocd.exe` (vanilla 1.0, DX7).
- **Ghidra project**: `ghidra_projects/VanillaProj` (Giants_nocd.exe — was v1.5, PURGED).
- **Decompile**: `vanilla_decompiled/` — **2574 functions**, COMPLETE, addresses **0x00401000–0x00551c50**
  (vanilla .text is SMALLER than v1.5 — the 0x6xxxxx/0x5fxxx addresses in old CLAUDE.md were
  V1.5 and DON'T EXIST in vanilla). Regenerated via ExportVanillaDecompiled.java headless.

## CRITICAL address correction
Old docs cited v1.5 addresses: UpdateActiveCamera 0x49a040, SetupProjection 0x5f9d00,
BuildViewMatrix 0x5f9eb0, etc. **These are V1.5 — wrong for vanilla.** In vanilla:
- The exe .text is 0x401000–0x551c50 (NO 0x5fxxx/0x6xxxxx engine range).
- Camera/projection fns found by their BEHAVIOR (calling SetCameraProjection `DAT_00654940+0x20`)
  at vanilla addresses: **00427240, 0042f390, 00430810, 004327a0, 00433900 (the 2D blitter),
  00435440, 00435a20, 00438090, 00448210, 004494c0**.
- The 3D camera setup is among these — identify by which builds a perspective/view matrix +
  reads the active camera object.

## Reconfigure done
- CMakeLists: vanilla-only (GiantsMain_vanilla + gg_dx7r_proxy). Build GREEN.
- CLAUDE.md: vanilla-only purge banner.
- skill giants-advance: 1.5 refs removed.
- All 1.5 trees deleted (src/, version_bridge/, proxy/, reference/patch15/, stubs/,
  ghidra_projects v1.5, ghidra_exports v1.5, GameFiles/ 1.5).

## Next (faithful 3D, now possible)
The 3D reproduction needs the vanilla camera + scene — now findable at CORRECT vanilla
addresses. Identify the 3D camera setup among the SetCameraProjection callers (the one that
builds a perspective matrix from the active camera), port it, set the camera, then drive the
renderer's scene walk. No more v1.5 address drift.
