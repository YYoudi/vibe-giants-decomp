#!/usr/bin/env python3
"""LLM string-evidence naming wave 3 (tier-2 corpus)."""
import csv, os

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PS2 = os.path.join(REPO, "ps2_symbols")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

NAMES = {
    "004035d0": "anim_select_check",
    "004036f0": "anim_select_check2",
    "00403810": "ref_get_anode",
    "00403890": "ref_get_anode2",
    "00426f40": "dlog_push_level",
    "00427040": "dlog_swap_check",
    "00429510": "comm_player_actions_menu",
    "00439df0": "wredit_group_select",
    "0043a440": "wredit_object_select",
    "0043bcc0": "wredit_flick_list2",
    "0043c420": "wredit_flick_list3",
    "0043efb0": "wredit_marker_menu2",
    "00440230": "wredit_marker_menu3",
    "00440770": "wredit_minishop_icons",
    "00448af0": "fx_lifespan_setup",
    "00449200": "fx_orient_ground",
    "00450d10": "gameover_menu",
    "00457440": "level_config_load",
    "00473ff0": "landscape_bump_check",
    "00483ba0": "mission_intro_load",
    "00484340": "savegame_cam_section",
    "00484b00": "mission_load_cheat",
    "00485020": "mission_load_world",
    "00488a80": "mission_load_world2",
    "00489120": "mission_menu_load",
    "004897d0": "mission_menu_load2",
    "0048f310": "story_script_scan",
    "00490c50": "scenario_list_load",
    "00493960": "mission_flick_load",
    "00495c70": "sound_play_checked",
    "00496bc0": "object_uniqueid_alloc",
    "00497bd0": "objobj_type_lookup",
    "0049e350": "cmdline_parse",
    "0049f510": "chat_log_close",
    "004a9e10": "weapondefs_load",
    "004ed910": "water_fx_test",
    "005187f0": "datetime_format",
    "00519930": "dinput_key_poll",
    "0051b1c0": "textrender_texture_alloc",
    "00521150": "comm_player_name",
    "005219d0": "comm_team_name",
    "00521c20": "comm_allowjoiners_menu",
    "00521cf0": "comm_damagemates_menu",
    "00521dd0": "comm_capture_points_menu",
    "00521ed0": "comm_capture_time_menu",
    "00522170": "comm_difficulty_menu",
    "00522360": "comm_playerscore_menu",
    "00522470": "comm_teamscore_menu",
    "00522720": "comm_version_check",
    "0052ab90": "comm_team_name2",
    "00528820": "comm_player_name2",
    "00528ee0": "comm_team_status",
    "0052adf0": "comm_player_name3",
    "0052aed0": "comm_player_name4",
    "0052b020": "comm_chatlog_write",
    "0052ebd0": "comm_team_broadcast_menu",
    "0052f5b0": "comm_fakehost_toggle",
    "00530520": "comm_kill_message",
    "005308b0": "comm_kill_message2",
    "00537120": "base_hint_menu",
    "005371e0": "comm_entergame_message",
    "0053d1c0": "editor_anim_skin",
    "00540020": "map_memfree",
    "00545d1b": "crt_cpu_features_check",
}

def main():
    claimed = set()
    used = set()
    for f in ["unified_names_1449.csv", "module_names_wave.csv", "module_bands.csv",
              "bsim_wave.csv", "system_wave2.csv", "crt_llm_names.csv", "crt_llm_names2.csv",
              "llm_strings_wave.csv"]:
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
        rows.append({"pc_addr": a, "pc_name": f"FUN_{a.upper()}", "ps2_addr": "",
                     "ps2_name": nm, "conf": 0.9, "tier": "llm-strings2", "shared": ""})
    outp = os.path.join(PS2, "llm_strings_wave2.csv")
    with open(outp, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(rows)
    print(f"llm-strings wave 2: {len(rows)} names -> {outp}")

if __name__ == "__main__":
    main()
