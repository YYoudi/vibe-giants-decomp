# VERSION MAP: 1.520.59 -> vanilla 1.0

Hand-off artifact: maps the main agent's reversed 1.5 functions to vanilla 1.0
addresses, quantifying identity so 1.5 knowledge carries onto vanilla.

## Summary

- 1.5 functions total: **6254**
- matched to a vanilla counterpart: **123**
  - IDENTICAL (carry over 1:1): **8**
  - NEAR (small patch delta): **13**
  - MODIFIED (same func, heavier patch): **102**
- 1.5-only / patch-added (no vanilla match): **6131**

## How to use (main agent hand-off)

The reconstructed source is vanilla-canonical going forward. For each matched
function, cite the **vanilla_addr** as the canonical provenance. IDENTICAL pairs
= your 1.5 reverse transfers verbatim. NEAR/MODIFIED = re-verify against vanilla.
1.5-only functions are the post-1.4 patch layer (reimplement, don't inherit).

Full table in VERSION_MAP.csv.
