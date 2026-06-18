# Vanilla 3D camera candidates (post-purge)

SetCameraProjection (`DAT_00654940+0x20`) callers — CORRECTION after reading 00430810:
- **00430810** (3964B) = OBJECT WORLD-MATRIX setup (builds 4x4 from object transform
  param_1+0x298..0x2c8 orientation / param_1+0xa0 position), NOT camera projection. It's
  the per-entity world transform the renderer applies before drawing each object.
- So +0x20 is used for WORLD transforms (per-object), not just camera. The camera
  PROJECTION (perspective matrix) is set elsewhere — need to find which fn calls +0x20
  with a PERSPECTIVE matrix (fov/aspect/znear/zfar) vs a world matrix.

NEXT: find the perspective-projection caller — the fn that builds a perspective matrix
(1/tan(fov/2), aspect ratio, znear/zfar) + calls +0x20. That's the camera projection.
Scene-chain addrs verified stable vanilla=v1.5 (src_vanilla/ ports valid).

UPDATE: perspective-projection candidates (ref VideoWidth DAT_00631818 + renderer):
00455640 (205B, smallest — likely projection), 004833d0 (317B), 0048ba90 (2462B), 005222c0 (boot).
