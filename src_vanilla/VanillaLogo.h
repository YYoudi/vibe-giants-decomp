// Giants Vanilla-Native Recomp — render the menu 3D logo model (Giants_logo_3D.gbs) through the
// proven D3D7 3D pipeline. OBSERVED asset (see behavior_specs/orig_logo3d_model.md): the menu
// centerpiece is the metallic 3D logo = Giants_logo_3D.gbs textured with Giants_logo_512.tga,
// NOT a flat 2D blit. This renders the decoded geometry with that texture.
//
// Camera/framing is framed from the model bbox and iterated via capdiff vs orig_menu_3d.png
// (the exact per-frame SetTransform is pending the proxy render-recipe capture). This is a
// diagnostic render path — labeled, driven by the -logo3d flag — not a claimed-faithful frame
// until capdiff PASS.
#pragma once
#include <cstdint>

extern "C" int VanillaLogo_Draw();   // returns triangle count, 0 on failure
