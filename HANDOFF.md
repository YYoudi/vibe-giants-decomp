# HANDOFF — cold start for the Rust+Bevy reimplementation agent

> You are the second agent. This repo (GiantsRE) is your reference library. You will
> build a NEW engine in a NEW repo (suggested: `giants-rs`) that consumes the original
> game's assets. You should never need Ghidra — everything below links the evidence.

## 0. Ground rules (read first)

1. The user owns the game (GOG 1.449). Your engine reads their install
   (`G:\Games\Giants\`), converts nothing into the repo, redistributes nothing.
2. Provenance discipline: every constant/behavior you port cites
   `observed` (runtime trace) / `derived` (decomp) / `inferred` (hypothesis).
   Addresses/offsets stay in THIS repo, not yours (cite function names instead).
3. Determinism from day one: one `sim::step(world, tick, input, dt)` authority, replay
   tests, headless runs (see docs/systems/SIM_LOOP.md).

## 1. Read order

1. `README.md` — repo map, status.
2. `docs/systems/SIM_LOOP.md` — the frame skeleton you must reproduce (update order is
   gameplay-visible: velocity → per-class AI → apply → projectiles).
3. `docs/systems/MISSION_VM.md` — **architecture decision**: missions are data (28
   fixed-size commands), cutscenes are a bytecode VM (31 ops) — port the flick VM,
   run original `flk_*.bin`.
4. `docs/formats/*.md` + `docs/specs/formats.json` — asset containers
   (`.bin` worlds/opcodes, `.abx` placements, `world.gb2`, `WorldList.bin`).
   `tools_spec/bin_formats.py` is the reference parser + golden metadata
   (`docs/golden/format_validation_summary.json`).
5. `docs/systems/COLLISION.md`, `docs/systems/AI.md`, `docs/systems/AUDIO.md`,
   `docs/systems/RENDERER.md`, `docs/systems/NETCODE.md` — system contracts.
6. `docs/constants/gameplay_constants.json` — provenance-tracked constants.
7. `decompiled/gog144_modules/_INDEX.md` — the full named corpus (76 modules), for
   algorithm-level questions. Function names are stable; addresses are GOG-1.449.

## 2. Suggested milestones

1. **Formats crate**: implement `formats.json` parsers; byte-identical validation
   against `tools_spec/bin_formats.py` outputs on the user's install.
2. **Render one island**: GTI terrain (✅ solved: `scripts/gti_parse.py`) + GBS meshes
   (blender importer = format ref) + `w_<world>.gzp` textures in Bevy/wgpu.
3. **Sim loop**: frame order from SIM_LOOP.md with placeholder systems; dt semantics
   (`FRateGetSecsframe`, slow zones).
4. **Player**: Mecc controller (movement, camera, `collgrid_collide_walk` semantics,
   `trajectory_throw_calc` for grenades).
5. **Entities**: object model (`OBJECT` layout in `ps2_symbols/OBJECT_LAYOUT`),
   class-spec dispatch, smartie/reaper/vimp basics; `wm_*` mission state.
6. **Cutscenes**: the flick VM (31 ops) + FLK_Actor 0x874 struct.
7. **Audio**: WAV banks + `sound_play_obj` event mapping.
8. **Netcode**: `comm_msg_dispatch` message layer (see NETCODE.md; `giantsd` as
   protocol counterpart).

## 3. Known risks / unknowns

- Collision grid cell scale + full cell-flag map (COLLISION.md open items).
- FLK per-op payload details (31 ops — decode against the trace harness).
- Savegame structure (registry + `savegame_%d` files) — not yet decoded.
- The 11 world `.bin` files hitting the op-41 size variant (bin_objects.md).
- `world.gb2` component vertex layouts (prologue known, bodies are renderer-side).
- Exact tick rate + RNG seeding (SIM_LOOP.md — confirm via `RUNTIME_TRACES.md` harness).

## 4. The oracle

`docs/RUNTIME_TRACES.md` — how to run the original game under the elevated debugger and
capture `{function, args, time}` traces (JSONL) + milestone screenshots. Traces live in
`RuntimeLab/logs/traces/` (local). Validate every ported system against them.
