#!/usr/bin/env python3
"""Emit the LLM string-evidence naming wave from my analysis of the top-77
string-rich corpus. Names are descriptive identifiers grounded in literal
strings found in each function body (tier llm-strings, conf 0.9).
"""
import csv, os, re

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PS2 = os.path.join(REPO, "ps2_symbols")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

NAMES = {
    "00404d70": "obj_impact_effects",
    "0040c2d0": "buoy_set_lights",
    "0040e1c0": "charger_dust_fx",
    "00420c10": "input_mapping_init",
    "004239d0": "keymap_save",
    "00423af0": "keymap_load",
    "00423e20": "input_keyname_lookup",
    "00425f60": "keymap_slot_load",
    "0042dc50": "alpha_queue_push",
    "00438770": "wredit_menu_main",
    "00439660": "wredit_menu_draw",
    "004397b0": "wredit_menu_3",
    "00439eb0": "wredit_menu_4",
    "0043aa40": "wredit_obj_info",
    "0043b530": "wredit_lock_menu",
    "0043b770": "wredit_menu_5",
    "0043bd80": "wredit_flick_menu",
    "0043bf40": "wredit_flick_list",
    "0043c580": "wredit_lock_list",
    "0043c760": "wredit_menu_6",
    "0043caa0": "wredit_menu_7",
    "0043d0a0": "wredit_ai_menu",
    "0043f220": "wredit_ai_menu2",
    "0043f950": "wredit_marker_info",
    "0043fbc0": "wredit_marker_info2",
    "0043fe90": "wredit_trigger_menu",
    "00440500": "wredit_marker_info3",
    "00447370": "fx_weather_fog_setup",
    "004474c0": "fx_weather_fogsky_setup",
    "00447620": "fx_weather_fog_setup2",
    "00457270": "comm_options_defaults",
    "004824e0": "game_options_load",
    "00482700": "game_options_verify",
    "00482b60": "menu_mission_launch",
    "00482e90": "menu_handlers_lookup",
    "004835f0": "menu_handlers_exec",
    "00491c00": "mission_level_load",
    "00491e30": "savegame_load",
    "00491f10": "savegame_verify",
    "004944d0": "mission_trigger_name",
    "0049e290": "options_defaults",
    "0049f5a0": "chat_log_init",
    "004a9160": "projectile_define",
    "004abd40": "repair_spell_fx",
    "004cda80": "dev_debug_flags",
    "004ed600": "perf_options_menu",
    "004ee390": "editor_dump_objnames",
    "004ee890": "game_files_check",
    "00500220": "status_subobj_init",
    "00504230": "mecc_smoking_fx_update",
    "00517ca0": "exception_report_write",
    "00519110": "dinput_init",
    "0051c470": "localization_check",
    "0051dc20": "startup_options_init",
    "0051e680": "error_screen_show",
    "0051f2f0": "gamespy_shutdown",
    "0051fc90": "comm_tcpip_menu",
    "00520050": "comm_client_connect_menu",
    "00520b90": "gamespy_send_statechange",
    "00520fd0": "comm_damage_teams_menu",
    "00522580": "comm_base_status_menu",
    "005227b0": "comm_scorelimit_menu",
    "00522b80": "comm_game_setup_menu",
    "005233f0": "comm_show_conn_menu",
    "00524de0": "gamespy_host_game",
    "00528620": "gamespy_statechange2",
    "00529320": "comm_change_options_menu",
    "0052bab0": "comm_net_stats_dump",
    "0052d220": "gamespy_statechange3",
    "0052d280": "gamespy_shutdown2",
    "0052f3b0": "comm_fakehost_menu",
    "0052f790": "comm_player_marker_menu",
    "00539e60": "mem_verify",
    "005405c0": "cpu_vendor_detect",
}

def main():
    claimed = set()
    used = set()
    for f in ["unified_names_1449.csv", "module_names_wave.csv", "module_bands.csv",
              "bsim_wave.csv", "system_wave2.csv", "crt_llm_names.csv", "crt_llm_names2.csv"]:
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
                     "ps2_name": nm, "conf": 0.9, "tier": "llm-strings", "shared": ""})
    outp = os.path.join(PS2, "llm_strings_wave.csv")
    with open(outp, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(rows)
    print(f"llm-strings wave: {len(rows)} names -> {outp}")

if __name__ == "__main__":
    main()
