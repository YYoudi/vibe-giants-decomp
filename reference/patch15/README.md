# reference/patch15/ — 1.5 / DX9-only reference material

Quarantine folder for repo content that concerns **only** the 1.520.59 community
patch (DX9/DX11/DX12 renderers + COM registry). Per the vanilla-canonical decision
(2026-06-16), these are **legacy reference**, not compiled into the vanilla recomp
and not the reverse target. Kept here so the patch-era analysis is not lost.

See `version_bridge/PATCH_LAYER_CLASSIFICATION.md` for the full stratification
(vanilla-core vs patch-only vs diagnostic).

## Contents

- **`com_dump.bin`** — a saved 1024-byte sample of the DX9 engine-context, dumped
  at runtime by the proxy (`proxy/Callbacks.cpp`, `fopen("com_dump.bin","wb")`).
  The proxy regenerates this on demand; the tracked copy is just a reference sample.
- **`com_scope.py`** — offline COM-subsystem scope mapper: walks the Ghidra callee
  graph from a root function and enumerates COM classes (the "COM wall"). Reads
  `ghidra_exports/*.json` (CWD-relative — run from the repo root).
  Both describe the COM subsystem that exists **only** in the 1.5/DX9 path
  (vanilla DX7 has no COM). See memory `com-subsystem-breakthrough`.
