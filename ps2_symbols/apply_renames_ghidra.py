# Ghidra (Jython) script: apply PS2-derived names to matched PC functions.
# Generated from pc_ps2_matches_full.csv, conf>=0.9 only. Safe tier.
# @category GiantsRE
from ghidra.program.model.symbol import SourceType

RENAMES = [
    (0x005e3840, 'teammecc_set_mode', 'teammecc_set_mode'),
    (0x00453370, 'chat_init', 'chat_init'),
    (0x005e30e0, 'mecc_shot', 'mecc_shot'),
    (0x004aca40, 'smartie_base_attack_comment', 'smartie_base_attack_comment(OBJECT*)'),
    (0x004aa710, 'bldg_get_bldg_name', 'bldg_get_bldg_name'),
    (0x005038f0, 'item_check', 'item_check'),
    (0x005b5140, 'rpman_move', 'rpman_move'),
    (0x005d1e20, 'smartie_get_name', 'smartie_get_name(OBJECT*)'),
    (0x004a9570, 'smartie_move', 'smartie_move'),
    (0x00494d50, 'meccbaseitem_finish_building', 'meccbaseitem_finish_building'),
    (0x004e3c50, 'firewall_create_fire', 'firewall_create_fire(OBJECT*, /*same*/, unsigned int, float, float, float, int)'),
    (0x00504a20, 'inv_award_item', 'inv_award_item'),
    (0x00537130, 'mecc_fire_logic', 'mecc_fire_logic(OBJECT*)'),
    (0x0057eb60, 'reaperbasebldg_finish_building', 'reaperbasebldg_finish_building'),
    (0x0058acd0, 'reaper_finish_shrinker', 'reaper_finish_shrinker'),
    (0x005d29a0, 'mecc_special_weapon_logic', 'mecc_special_weapon_logic(OBJECT*)'),
    (0x005ebca0, 'player_draw_missile_lock', 'player_draw_missile_lock'),
    (0x00532f00, 'mecc_logic', 'mecc_logic'),
]

fm = currentProgram.getFunctionManager()
ok = miss = 0
for addr, name, sig in RENAMES:
    fn = fm.getFunctionContaining(toAddr(addr))
    if fn is None:
        print('  miss 0x%08x' % addr); miss += 1; continue
    fn.setName(name, SourceType.USER_DEFINED)
    fn.setComment('PS2 match: ' + sig)
    ok += 1
print('applied %d, missed %d' % (ok, miss))
