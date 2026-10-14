#!/usr/bin/env python3
"""Harvest gameplay constants (float/int immediates) from named corpus functions.
Writes docs/constants/gameplay_constants.json + .md mirror. Provenance per entry.
"""
import json, re, os, struct

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CORPUS = os.path.join(REPO, 'decompiled', 'gog144_full', 'all_decompiled.c')

# curated: function name -> list of (hex/dec literal in decomp, meaning)
CURATED = [
 ('FRateGetSecsframe', '0x00518B70', [
   ('DAT_006328e0', 'base dt register (frame seconds; runtime value, seed of all timing)'),
 ]),
 ('facing_player_bark', '0x0049DBD0', [
   ('10.0', 'player-facing half-angle threshold (degrees, ±10°)'),
   ('0x682', 'bark sound id A'),
   ('0x683', 'bark sound id B'),
   ('0x32', 'rand threshold 50/100 = 50%'),
   ('0xd04', 'cfg radius offset (squared dist gate, DAT_632ED8+0xD04)'),
 ]),
 ('reaper_target_range_check_c1', '0x0045BE30', [
   ('35.0', 'far range multiplier * spec+0xC4'),
   ('20.0', 'near range multiplier * spec+0xC4'),
   ('0x29d', 'target-owner self id guard'),
   ('0x3c00/0x3c0/0x3c', 'target weapon-class flag masks at +0x1CC'),
 ]),
 ('injured_state_start', '0x0046B7F0', [
   ('0x14', 'state id: injured-seek (obj+0xE4)'),
   ('0x3c', 'obj flag bits set (0x20|0x10|0x8|0x4)'),
 ]),
 ('injured_seek_state_set', '0x0046B850', [
   ('0x40a00000', 'timer 5.0 s (obj+0xEC)'),
   ('0x13', 'state id 19 (obj+0xE4)'),
 ]),
 ('smartie_house_scan', '0x004B6C00', [
   ('0x353', 'smartie-house object type id'),
   ('0x3f', 'occupancy mask (6 slots; full = 0x3F)'),
   ('9999999.0', 'best-dist sentinel'),
 ]),
 ('master_flagslot_claim', '0x0040ABF0', [
   ('0x47', 'first flagslot id returned (0x47+i, 12 slots)'),
   ('0xfff', 'all-slots-taken mask'),
 ]),
 ('vvel_decay_tick', '0x004A73A0', [
   ('0x10', 'obj+0xD8 flag 0x10 = no-decay'),
   ('0x80000', 'obj+0xD8 flag 0x80000 = no-decay variant'),
 ]),
 ('kabuto_laser_texture_init', '0x00467270', [
   ('0x80', 'laser texture 128x128'),
   ('0x1ec1/0x1eb0', 'allocation site line numbers (kabuto.c)'),
 ]),
 ('worldanim LOD curve', 'OP57', [
   ('0x1a8..0x1bc', 'WS LOD curve: (near², far², lo, hi) + derived slope'),
 ]),
 ('bldg defaults', 'OP121', [
   ('0x457a0000', '4000.0f default WS+0x50A0 (terrain palette scale)'),
   ('0x42000000', '32.0f default WS+0x50A4'),
   ('0x3f800000/0x3fc00000', '1.0f/1.5f defaults WS+0x50AC..B4'),
 ]),
 ('fog defaults', 'OP41', [
   ('0x447a0000', '1000.0f default WS+0x7C (fog near)'),
   ('0x3d000000', '0.03125f default (density reciprocal init)'),
   ('0x3f000000', '0.5f default WS+0x84'),
   ('0x42480000', '50.0f fallback for zero fog/music scale (ops 52-54/114-116/133-136)'),
 ]),
 ('sky defaults', 'OP101-102', [
   ('0x3f800000', '1.0f WS+0x4E8C'),
   ('0xbdcccccd', '0.05f WS+0x4E90'),
   ('0xbd4ccccd', '0.05f WS+0x4E94'),
   ('0.8726646304130554', 'default sky angle A (rad, = 50°) → cos = 0.642787'),
   ('1.0471975803375244', 'default sky angle B (rad, = 60°) → cos = 0.5'),
 ]),
 ('bubble_timeout_clear', '0x00536C60', [
   ('1.0', 'bubble timeout seconds (DAT_632E6C - DAT_5E273C > 1.0)'),
 ]),
 ('player_pet_follow_tick', '0x00501090', [
   ('0x40a00000', '5.0 s pet-follow timer (creature+0x134)'),
 ]),
 ('pet_command_set', '0x00501100', [
   ('0x40a00000', '5.0 s command window'),
 ]),
 ('heal threshold', 'fx_name_set_c77', [
   ('0.1', 'fx rate floor (param_3 float, obj+0x84)'),
   ('25.0', 'health-crossing threshold for fx name trigger (obj+0x278)'),
 ]),
 ('comm_scores_send', '0x0052B280', [
   ('999', 'score clamp max'),
 ]),
 ('comm echo', 'comm_echo_send', [
   ('0x547', 'max echo message length 1351'),
 ]),
 ('meccbasepit_food_take', '0x0040B1D0', [
   ('1.0', 'food ripeness timer threshold (pit food +0xEC < 1.0 → not ready)'),
   ('0x52c', 'pit slot array offset in base spec'),
 ]),
 ('trajectory_throw_calc', '0x004698F0', [
   ('0.1', 'throw velocity = dist * 0.1'),
 ]),
 ('walkable_floor_check', '0x004138C0', [
   ('0.64278', 'slope cos gate (≈50°) — walkable if slope-cos below'),
 ]),
 ('slope_walkable_check', '0x00413880', [
   ('0.64278', 'slope cos gate twin'),
 ]),
 ('ai_standoff_goal_calc', '0x0049DE80', [
   ('0xd00', 'cfg standoff radius (DAT_632ED8+0xD00, squared vs target)'),
 ]),
 ('rpman_hit_state_set', '0x004D7C60', [
   ('0xdd', 'guard state id (obj+0xE4 == 0xDD skips hit reaction)'),
   ('0x4d', 'rpman target class id'),
   ('0x65/0x66/0x67', 'special hit-cause ids (0x65<cause<0x68)'),
 ]),
 ('seq_index_assign', '0x00476EB0', [
   ('0x60', 'special chain class id'),
   ('0x8000000', 'obj+0x1C8 flag = chain member'),
 ]),
 ('gridcell_free_check_store', '0x004E7250', [
   ('0x1d8/0x1dc', 'grid width/height fields in DAT_6330E4'),
   ('0x0e', 'cell occupied flag offset (stride 0x10)'),
 ]),
 ('spawn_clearance_check', '0x004E3730', [
   ('40000.0', 'clearance radius² = 200 units'),
   ('5', 'max allowed neighbors within radius'),
 ]),
 ('bldg_spawn_state_tick', '0x004E9CE0', [
   ('0xf4c', 'cfg spawn timer offset (DAT_632ED8+0xF4C)'),
   ('0x30/0x20/0x21', 'anim ids: spawn/idle/alt'),
   ('1/2/3', 'building state machine states (obj+0xE4)'),
 ]),
 ('worldanim_assign', 'OP58', [
   ('0x400000', 'obj+0x72 flag: worldanim-attached'),
   ('0x36', 'ospec id for animattacher (op 58)'),
   ('0x4f', 'ospec id for worldanim (op 84)'),
 ]),
 ('teammecc_target_state_query', '0x00456090', [
   ('0x16', 'target type A (carried→1)'),
   ('0x313', 'target type B (carried→1)'),
   ('0x311', 'target type C (carried→3)'),
 ]),
 ('herd_promote_check', '0x005108F0', [
   ('0x98/0x9c/0xfc', 'owner slot idx / rank / promote-threshold float (spec+0xFC)'),
   ('100.0', 'promotion percent denominator'),
 ]),
 ('reaperbase_dock_check', '0x004C5B10', [
   ('36.0', 'dock distance² threshold (6 units)'),
   ('0xc', 'refpt index used for dock point'),
 ]),
 ('destroy_by_id_c33_c27', '0x004782F0', [
   ('0x33', 'class A (id at spec+0x134)'),
   ('0x27', 'class B (id at spec+0x14)'),
 ]),
 ('type0d7_unique_check', '0x004E21F0', [
   ('0xd7', 'unique-type id'),
   ('0x21', 'state exclusion (obj+0xE4 != 0x21)'),
   ('0x134', 'spec id field for uniqueness'),
 ]),
 ('injured_target_scan', '0x004D1A00', [
   ('0x4000c000', 'excluded obj flags (dead-ish)'),
   ('0x278/0x1c0', 'hp / max-hp fields (injured = hp<max)'),
 ]),
 ('flick timing', 'FLK', [
   ('0x874', 'FLK_Actor struct size'),
   ('0x310', 'FLK block record size'),
   ('0xc', 'FLK director record size'),
 ]),
 ('spec sizes', 'OP138', [
   ('0x304', 'static-object (stobj) record size'),
   ('0xc1', 'OpObj world-object slot size (dwords) per object, max 0x400'),
 ]),
 ('view range', 'OP71', [
   ('0x1c0..0x1cc', 'WS view-range block (near/far/2×u32)'),
 ]),
 ('master collision flags', 'COLLISION', [
   ('0x2', 'cell blocked bit (collision grid byte)'),
   ('0x400000/0x181808', 'obj+0x1C8 movement mode flags (collide_walk gates)'),
 ]),
 ('bubble/respawn misc', 'MISC', [
   ('0x40a00000', '5.0 s (recurring timer constant)'),
   ('0x447a0000', '1000.0 f (recurring distance/scale default)'),
   ('0x3dcccccd', '0.1 f (recurring small-rate default)'),
 ]),
]

def main():
    entries=[]
    for fname,addr,items in CURATED:
        for lit,meaning in items:
            entries.append({
                'value': lit,
                'function': fname,
                'address': addr,
                'source': 'decomp-static',
                'note': meaning,
            })
    os.makedirs(os.path.join(REPO,'docs','constants'),exist_ok=True)
    out=os.path.join(REPO,'docs','constants','gameplay_constants.json')
    json.dump(entries,open(out,'w'),indent=1)
    md=['# gameplay_constants — provenance-tracked constants','','| value | function | address | note |','|---|---|---|---|']
    for e in entries:
        md.append(f"| `{e['value']}` | {e['function']} | {e['address']} | {e['note']} |")
    open(os.path.join(REPO,'docs','constants','gameplay_constants.md'),'w',encoding='utf-8').write('\n'.join(md)+'\n')
    print(len(entries),'constants')

if __name__=='__main__':
    main()
