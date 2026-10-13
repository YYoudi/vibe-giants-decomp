#!/usr/bin/env python3
"""Wave 5: audio + render cluster names from string/caller evidence."""
import csv, os

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PS2 = os.path.join(REPO, "ps2_symbols")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

NAMES = {
    # audio / physics / mission cluster 0x48-0x4A
    "00480540": "physics_ground_check",
    "004810d0": "flaghint_drivegyro",
    "004832f0": "menu_selection_fx",
    "00493ea0": "story_flick_get_food",
    "00493ee0": "story_flick_pad",
    "00494890": "mission_fail_dialog",
    "004950a0": "sfxdefs_load",
    # render / fx cluster 0x4A-0x4D
    "004add70": "fx_create_hack_logic",
    "004b5d10": "reaperbasebldg_shot",
    "004cc810": "dome_render_text",
    # verified orphans restored via unified (kept here as documentation only)
}

def main():
    claimed = set()
    used = set()
    for f in ["unified_names_1449.csv", "module_names_wave.csv", "module_bands.csv",
              "bsim_wave.csv", "system_wave2.csv", "crt_llm_names.csv", "crt_llm_names2.csv",
              "llm_strings_wave.csv", "llm_strings_wave2.csv", "llm_wave4.csv", "callpat_wave.csv"]:
        try:
            for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
                claimed.add(norm(r["pc_addr"]))
                used.add(r["ps2_name"])
        except FileNotFoundError:
            pass
    rows = []
    for a, nm in sorted(NAMES.items()):
        if a in claimed:
            continue
        base, i = nm, 2
        while nm in used:
            nm = f"{base}_{i}"
            i += 1
        used.add(nm)
        claimed.add(a)
        rows.append({"pc_addr": a, "pc_name": f"FUN_{a.upper()}", "ps2_addr": "",
                     "ps2_name": nm, "conf": 0.9, "tier": "llm-audio-render", "shared": ""})
    outp = os.path.join(PS2, "llm_wave5.csv")
    with open(outp, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(rows)
    print(f"wave 5 (audio/render): {len(rows)}")

if __name__ == "__main__":
    main()
