#!/usr/bin/env python3
"""Wave 4: tier-3 string evidence + call-pattern (all named neighbors share
one family prefix). Emits ps2_symbols/llm_wave4.csv + ps2_symbols/callpat_wave.csv.
"""
import csv, json, os, re, glob, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

STRNAMES = {
    "0041b660": "fxb_build_select",
    "0042df60": "fx_blastmark",
    "0042e1f0": "fx_kabuto_footprint",
    "0042e690": "fx_rp_spark",
    "00435bc0": "fx_blob_shadow",
    "00443480": "flk_file_open",
    "00446650": "flk_file_open2",
    "004574d0": "options_defplayer",
    "00484870": "mission_cheat_check",
    "00485b00": "mission_mpworld_load",
    "00488d00": "mission_load_world3",
    "00495650": "sound_play_2",
    "004957d0": "sound_play_3",
    "004958b0": "sound_play_4",
    "004959e0": "sound_play_5",
    "004be850": "fxb_splash_create",
    "004bf8c0": "fxb_firewall_create",
    "004bfbf0": "fxb_cloak_create",
    "004c0210": "fxb_firecircle_create",
    "004c6a30": "fxn_firering",
    "004cc7e0": "ai_island_init",
    "004ce880": "time_format_hms",
    "004ee080": "env_texture_load",
    "004f5710": "fx_reaper_bubble",
    "00514d60": "elevation_texture_load",
    "00515f60": "farclip_config",
    "00518670": "filedate_log",
    "00518d30": "gg_dll_name",
    "00518f20": "fps_display",
    "005217b0": "comm_worldname_menu",
    "00521830": "comm_worldname_menu2",
    "00521b40": "comm_maxplayers_menu",
    "00522020": "comm_smartie_diff_menu",
    "00522260": "comm_timelimit_menu",
    "00528a00": "comm_progress_display",
    "0052a940": "comm_server_ping",
    "0052f040": "comm_entergame_msg",
    "0052f0a0": "comm_entergame_msg2",
    "0052f980": "cam_mode_toggle",
    "00532f60": "comm_entergame_msg3",
    "00533140": "comm_wincond_team",
    "00533c60": "base_warn_missing",
    "00537400": "comm_wincond_destroy",
}

def emit(rows, fname, tier_base):
    claimed = set()
    used = set()
    for f in ["unified_names_1449.csv", "module_names_wave.csv", "module_bands.csv",
              "bsim_wave.csv", "system_wave2.csv", "crt_llm_names.csv", "crt_llm_names2.csv",
              "llm_strings_wave.csv", "llm_strings_wave2.csv", "llm_wave4.csv",
              "callpat_wave.csv", "crt_llm_names2.csv"]:
        try:
            for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
                claimed.add(norm(r["pc_addr"]))
                used.add(r["ps2_name"])
        except FileNotFoundError:
            pass
    out = []
    for a, nm in sorted(rows):
        if a in claimed:
            continue
        base, i = nm, 2
        while nm in used:
            nm = f"{base}_{i}"
            i += 1
        used.add(nm)
        claimed.add(a)
        out.append({"pc_addr": a, "pc_name": f"FUN_{a.upper()}", "ps2_addr": "",
                    "ps2_name": nm, "conf": 0.9, "tier": tier_base, "shared": ""})
    outp = os.path.join(PS2, fname)
    with open(outp, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(out)
    print(f"{fname}: {len(out)}")
    return out

def main():
    emit([(a, n) for a, n in STRNAMES.items()], "llm_wave4.csv", "llm-strings3")

    # call-pattern: unnamed functions whose >=3 named neighbors ALL share a family
    funcs = {}
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        funcs[d["address"]] = d
    CALL = re.compile(r"\bFUN_([0-9a-fA-F]{8})\s*\(")
    named = {}
    for f in ["unified_names_1449.csv", "module_names_wave.csv", "module_bands.csv",
              "bsim_wave.csv", "system_wave2.csv", "crt_llm_names.csv", "crt_llm_names2.csv",
              "llm_strings_wave.csv", "llm_strings_wave2.csv", "llm_wave4.csv"]:
        try:
            for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
                if float(r["conf"]) >= 0.9:
                    named[norm(r["pc_addr"])] = r["ps2_name"]
        except FileNotFoundError:
            pass
        except FileNotFoundError:
            pass
    callers = collections.defaultdict(set)
    callees = collections.defaultdict(set)
    for a, d in funcs.items():
        for m in CALL.finditer(d["decompiled"]):
            c = m.group(1).lower()
            if c != a:
                callers[c].add(a)
                callees[a].add(c)

    def family(nm):
        base = nm.split("__F")[0]
        toks = [t for t in re.split(r"[^A-Za-z0-9]+", base) if t]
        # module-wave names end with a hex address: main_collgrid_00426f40
        # -> semantic family is the token before the address
        if len(toks) >= 3 and re.fullmatch(r"[0-9a-fA-F]{8}", toks[-1]):
            return toks[-2].lower()
        return toks[0].lower() if toks else ""

    GENERIC = {"fun_", "crt", "func"}
    rows = []
    for a, d in funcs.items():
        if a in named or not d["name"].startswith("FUN_"):
            continue
        fam = collections.Counter()
        for nb in callers.get(a, set()) | callees.get(a, set()):
            nm = named.get(nb)
            if nm:
                fam[family(nm)] += 1
        if not fam:
            continue
        best, n = fam.most_common(1)[0]
        if n >= 3 and best not in GENERIC and len(best) >= 4:
            rows.append((a, f"{best}_{a}"))
    emit(rows, "callpat_wave.csv", "call-pattern")

if __name__ == "__main__":
    main()
