# Claim board — multi-agent file/work ownership

When an agent starts work on a file or chantier, it **claims** it here (so no other
agent edits the same file → no race, no broken build). One writer per file. Reading
and searching can be fully parallel; only WRITES need a claim.

## Format
Append one line: `- [<file-or-chantier>] @<agent> (status: active|done) [<date>]`

Release the claim (mark `done` or delete the line) when finished.

## Active claims
_(empty — agents add their claims here)_

## Conventions
- **Build = serial**: always go through `tools/build.sh` (lockdir-protected). Never raw `mingw32-make` with other agents active.
- **Disjoint files**: fork agents only on files nobody else is editing. Portage of independent functions (`RE_<fn>.cpp`) is embarrassingly parallel.
- **Worktree per agent**: for heavy parallel editing, use `EnterWorktree` so each agent has an isolated copy; main integrates + builds.
- **Subagents use `sonnet`** (glm-5.1) for portage/RE; main (opus/glm-5.2) integrates + builds + decides.
- **Back-off on 529**: if the gateway returns 529, go sequential; don't immediately re-fork.

## Overnight run 2026-06-18 — chantier queue
Priorité : bit-fidelity (mesure→spec→port vanilla documenté→auto-vérif). Subagents sonnet retournent code/docs (n'éditent pas les fichiers shared). Main intègre+build+commit.

- [Q1] Renderer method semantic map (obj+offset → D3D7 semantic) — RE_docs/DX7_METHOD_MAP_v2.md — @subagent-A
- [Q2] VFS callbacks 15-17 (FUN_006222d0/00621fe0/00621e50) — src_vanilla/VanillaVFSCallbacks.* — @subagent-B
- [Q3] Menu scene chain: .BIN loader FUN_004b7c50 port — src_vanilla/VanillaBinLoader.cpp — @main
- [Q4] Audio FUN_0051f900 (gs_ds.dll) port — src_vanilla/VanillaAudio.cpp — pending
- [Q5] Core fn batch (VERSION_MAP_v2 EXACT/HIGH) — new RE_<fn>.cpp each — pending
- [Q6] Renderer transform/texture path (for menu 3D fidelity) — pending

## Batch progress (overnight 2026-06-18)
DONE: Q1 renderer-method-map (DX7_METHOD_MAP_v2.md), Q2 VFS callbacks 15-17 (linked), Q4 audio full 59/59, FUN_0045a530 loading screen (verified giants_loading), scene-chain FUN_004913c0+FUN_004f3230 (linked, callees stubbed in VanillaStubs.cpp), MENU real +0xa8 Present (GDI hack removed).
IN-PROGRESS: @subagent-E selector callees (FUN_0053c970/0052f960/0045a520/004b7640/004b77c0 → make selector real), @subagent-F .BIN loader FUN_004b7c50.
NEXT: wire selector+.BIN loader into boot step 14; port remaining SetupGame callees; menu 3D via +0x20 projection (+0x14 world) per DX7_METHOD_MAP_v2.
