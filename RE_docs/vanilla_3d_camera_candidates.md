# Vanilla 3D camera candidates (post-purge, correct vanilla addresses)

From the fresh vanilla decompile (2574 fns), the SetCameraProjection (`DAT_00654940+0x20`)
callers that ALSO build matrices (3D camera setup candidates):
- **00430810** (3964B) — largest, likely full camera + perspective setup
- **004494c0** (2945B)
- **00435a20** (1889B)
- (others: 00427240, 0042f390, 004327a0, 00435440, 00438090 — no matrix math, probably 2D/HUD)

Scene-chain addresses are STABLE vanilla=v1.5 (verified: 004913c0/0045a530/004b7c50/004f3230/
0053a3e0/00523b60/00433900 all exist at same addr+size in vanilla → src_vanilla/ ports valid).

NEXT: decompile+read 00430810 (the camera setup) → port it → set the camera → drive the
renderer's scene walk (0x7370) → measure if 3D renders. This is the faithful 3D path.
