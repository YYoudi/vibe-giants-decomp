# behavior_specs/ — observable-behavior source of truth

Every spec here is **measured from the original** (Frida timestamps, capture-diff,
decompiled `.data` constants with DAT_ addresses). The recomp MUST match each spec.
An observable behavior implemented WITHOUT a corresponding spec here is a **dérive**
violation (CLAUDE.md §0 rule 5).

Specs are LIVING: refine them as we measure more. Never weaken a spec to make the
recomp pass — fix the recomp.

## Current specs
- `boot_sequence.md` — full boot chain (FUN_005222c0, 15 steps, addresses)
- `intro_timings.md` — intros: 3 images, fade 0.2s, hold 12s, skip-on-input (FUN_00523b60)
- `loading_screen.md` — REAL loading screen = giants_loading.tga (FUN_0045a530), NOT int_loadisland
- `menu_render.md` — menu = 3D scene + 2D GUI together, loaded at boot step 4
