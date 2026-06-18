# DX7 Callback Oracle — the 21 REAL vanilla callbacks (captured via proxy C5)

Captured by deploying `proxy_dx7/gg_dx7r.dll` AS gg_dx7r.dll (real → gg_dx7r_orig.dll),
running `Giants_nocd.exe`, logging `UpCallsLoad(0x2775, 21, table=DAT_005dc8e0)`.

The table is built by FUN_00521a60 (audio UpCalls) — SAME 21 callbacks shared by renderer + audio.

| idx | vanilla addr | recomp callback (VanillaRenderer.cpp) | role |
|-----|-------------|---------------------------------------|------|
| 0  | 0051d890 | cbVFSOpenFile-adjacent? | file open / string copy |
| 1  | 00523ad0 | — | cleanup |
| 2  | 00429100 | — | debug log |
| 3  | 00542410 | — | show error |
| 4  | 0051d860 | — | error string accessor |
| 5  | 0051eca0 | (ported: VanillaStobj err-str copy) | error string copy |
| 6  | 00523b50 | — | post-frame |
| 7  | 004a1320 | — | scene begin |
| 8  | 004a1340 | — | scene end |
| 9  | 0050dd10 | (cbSceneBegin_DrawTerrain-adjacent) | texture load |
| 10 | 0050e360 | — | buffer dealloc |
| 11 | 0050d7f0 | — | get file position |
| 12 | 0040d430 | — | localized string |
| 13 | 00510fb0 | — | texture loader |
| 14 | 0051e7a0 | — | sin/cos lookup |
| 15 | 0053a2b0 | — | time accessor |
| 16 | 0053a090 | cbVFSOpenFileVariant | VFS open variant |
| 17 | 00539f00 | cbVFSOpenFile | VFS open file |
| 18 | 00521a20 | Stub_Alloc (engine allocator) | allocator |
| 19 | 00521a40 | Stub_Free | CRT free |
| 20 | 00523aa0 | FUN_00523aa0 (ScenePipelineEntry) | scene pipeline |

To validate bit-exact: the recomp's callbacks[] (VanillaRenderer.cpp) must produce identical
output to the original's callback at these addresses, for the same input. Self-test: call
the recomp's callback with known args, call the original's (via proxy detour), compare.
