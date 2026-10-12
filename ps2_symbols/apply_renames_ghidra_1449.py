# Ghidra (Jython) script: apply PS2-derived names to matched PC functions.
# Generated from pc_ps2_matches_full.csv, conf>=0.9 only. Safe tier.
# @category GiantsRE
from ghidra.program.model.symbol import SourceType

RENAMES = [
    (0x00501740, 'teammecc_setup_enemies', 'teammecc_setup_enemies(OBJECT*, int)'),
    (0x00504980, 'teammecc_set_mode', 'teammecc_set_mode'),
    (0x00476dd0, 'marker_get_name', 'marker_get_name'),
    (0x00536170, 'chat_init', 'chat_init'),
    (0x0041c0c0, 'bldg_get_bldg_name', 'bldg_get_bldg_name'),
    (0x004498e0, 'fx_setupTextureAnimtion', 'fx_setupTextureAnimtion(FXSTACKTAG*, int, float)'),
    (0x0045ba70, 'AttackObject', 'AttackObject(OBJECT*, /*same*/, P3D*, /*same*/, float, int)'),
    (0x004f4c00, 'smartie_lock_to_player', 'smartie_lock_to_player'),
    (0x004f50c0, 'smartie_unlock_from_player', 'smartie_unlock_from_player'),
    (0x004f7c10, 'smartie_get_name', 'smartie_get_name(OBJECT*)'),
    (0x00409030, 'meccbaseitem_finish_building', 'meccbaseitem_finish_building'),
    (0x00449400, 'fx_setupEmitter', 'fx_setupEmitter(FxData*, FXSTACKTAG*, int, float, int, int, int, int, int, int)'),
    (0x004496d0, 'fx_setupTracer', 'fx_setupTracer(FXSTACKTAG*)'),
    (0x00459930, 'inv_award_item', 'inv_award_item'),
    (0x0045e9b0, 'validate_eat', 'validate_eat(OBJECT*, /*same*/)'),
    (0x00474440, 'alloc_bump_reference', 'alloc_bump_reference(Texture**, Texture*)'),
    (0x0047e0b0, 'mecc_fire_logic', 'mecc_fire_logic(OBJECT*)'),
    (0x00495f20, 'sound_get_free_sequence', 'sound_get_free_sequence(void)'),
    (0x004a5e10, 'player_draw_missile_lock', 'player_draw_missile_lock'),
    (0x004a8e10, 'KabutoProcAnimsCreate', 'KabutoProcAnimsCreate'),
    (0x004b0b70, 'read_world_list', 'read_world_list'),
    (0x004b5640, 'reaperbasebldg_finish_building', 'reaperbasebldg_finish_building'),
    (0x004bfcc0, 'reaper_finish_shrinker', 'reaper_finish_shrinker'),
    (0x004c0010, 'reaper_finish_slow_follow', 'reaper_finish_slow_follow(OBJECT*, unsigned int*)'),
    (0x004c62c0, 'firewall_create_fire', 'firewall_create_fire(OBJECT*, /*same*/, unsigned int, float, float, float, int)'),
    (0x00507970, 'TextPtrInit', 'TextPtrInit(void)'),
    (0x00518be0, 'FRateSlowTime', 'FRateSlowTime'),
    (0x00447270, 'fx_setupWeather', 'fx_setupWeather(int)'),
    (0x00449ba0, 'fx_setupVerticleFade', 'fx_setupVerticleFade(FXSTACKTAG*, float, float, float, float, float)'),
    (0x004776c0, 'lift_logic', 'lift_logic(OBJECT*)'),
    (0x004a8190, 'ProcAnimsCreate', 'ProcAnimsCreate(ObjectSet*, UsrAnmDef*)'),
    (0x004b4560, 'base_get_required_smarties', 'base_get_required_smarties(OBJECT*, int)'),
    (0x005309e0, 'smartie_move', 'smartie_move'),
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
