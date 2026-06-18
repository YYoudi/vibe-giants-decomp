#include <cstdint>
// Generated .BIN loader (FUN_004b7c50) link stubs. Loader is DORMANT.
extern "C" {
int FUN_0053c970(const char* a, const char* b);   // strcmp-eq (defined in VanillaStubs.cpp)
uint32_t _DAT_005522b0 = 0;
uint32_t _DAT_005522c0 = 0;
uint32_t _DAT_00552344 = 0;
uint32_t _DAT_005524b4 = 0;
uint32_t _DAT_00552564 = 0;
uint32_t _DAT_005526c8 = 0;
uint32_t _DAT_005526d0 = 0;
uint32_t _DAT_005a5c9c = 0;
uint32_t DAT_0055c214 = 0;
uint32_t DAT_00562d10 = 0;
uint32_t DAT_005631f8 = 0;
uint32_t DAT_005632f0 = 0;
uint32_t DAT_005633c8 = 0;
uint32_t DAT_006313b0 = 0;
uint32_t DAT_006313b4 = 0;
uint32_t DAT_006552c0 = 0;
void FUN_00405080() {}
void FUN_00429100() {}
void FUN_0044ab90() {}
void FUN_00472560() {}
void FUN_00476d40() {}
void FUN_00491830() {}
void FUN_0049ccf0() {}
void FUN_0049cfd0() {}
// FUN_0049d2d0: obj-type lookup (walks DAT_006313b4 linked list; node [0]=next,
//   [1]=count, key at node+3, entries stride 0xc1 dwords). Returns matching entry
//   (node + iVar2*0xc1 + 2), else NULL. (vanilla 0049d2d0)
void* FUN_0049d2d0(int typeId) {
    uint32_t* node = (uint32_t*)(uintptr_t)DAT_006313b4;
    while (node) {
        int count = (int)node[1];
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                uint32_t* entry = node + 3 + i * 0xc1;
                if (*entry == (uint32_t)typeId) return node + i * 0xc1 + 2;
            }
        }
        node = (uint32_t*)(uintptr_t)node[0];
    }
    return 0;
}
void FUN_0049f3b0() {}
// FUN_004a1360: WorldAnim lookup. Walks world_state(DAT_006316ec)+0x210 array (count at
//   +0x20c, stride 0xc) comparing param_1 via FUN_0053c970. Returns matching entry
//   (base + iVar2*0xc), else logs "Failed to find WorldAnim" + returns 0. (vanilla 004a1360)
int FUN_004a1360(const char* name) {
    extern uint32_t DAT_006316ec;
    if (DAT_006316ec == 0) return 0;   // FIXME(defensive): world_state null while dormant
    int count = *(int*)(uintptr_t)(DAT_006316ec + 0x20c);
    if (count <= 0) return 0;
    uint32_t base = *(uint32_t*)(uintptr_t)(DAT_006316ec + 0x210);
    for (int i = 0; i < count; i++) {
        const char* entryName = *(const char**)(uintptr_t)(base + i * 0xc);
        if (FUN_0053c970(name, entryName) != 0) return base + i * 0xc;
    }
    return 0;   // vanilla logs "Failed to find WorldAnim '%s'" via FUN_00544b47+FUN_00523aa0
}
void FUN_004b7b30() {}
void FUN_0050e3c0() {}
void FUN_0051bd20() {}
void FUN_0053c810() {}
void FUN_0053c890() {}
void FUN_00544b47() {}
void FUN_00544b99() {}
extern const char s__s_anm_005632a8[] = " s anm";
extern const char s__s_bin_00555384[] = " s bin";
extern const char s_Bad_version_for__s___X_vs__X__005634cc[] = "Bad version for s  X vs X ";
extern const char s_Bad_version_for__s_0055e248[] = "Bad version for s";
extern const char s_C__Giants_Source_main_readwrls_c_00563174[] = "C Giants Source main readwrls c";
extern const char s_Can_t_find_object_type__d__OpAre_00563328[] = "Can t find object type d OpAre";
extern const char s_Can_t_find_object_type__d__OpLoc_00563264[] = "Can t find object type d OpLoc";
extern const char s_Can_t_find_object_type__d__OpObj_005633f4[] = "Can t find object type d OpObj";
extern const char s_Can_t_find_object_type__d__OpSmo_005632f4[] = "Can t find object type d OpSmo";
extern const char s_Error__Flick__s_not_in_world_fli_0055ea28[] = "Error Flick s not in world fli";
extern const char s_Failed_to_open__s_0055e25c[] = "Failed to open s";
extern const char s_fx_world_dust_005634ac[] = "fx world dust";
extern const char s_fx_world_snow_005634bc[] = "fx world snow";
extern const char s_Lock_level_nest_too_deep_0056328c[] = "Lock level nest too deep";
extern const char s_Lock_level_underflow_0055ea50[] = "Lock level underflow";
extern const char s_Obsolete_garden_opcode_00563388[] = "Obsolete garden opcode";
extern const char s_Obsolete_mesh_group_opcode_00563350[] = "Obsolete mesh group opcode";
extern const char s_Obsolete_mesh_single_opcode_0056336c[] = "Obsolete mesh single opcode";
extern const char s_sobjs_005634a4[] = "sobjs";
extern const char s_stobj_005631fc[] = "stobj";
extern const char s_teamripper_0056331c[] = "teamripper";
extern const char s_Too_many_animations_for_a_world_005632b0[] = "Too many animations for a world";
extern const char s_Too_many_flicks_for_world_00563248[] = "Too many flicks for world";
extern const char s_Too_many_objects_for_world_005633d8[] = "Too many objects for world";
extern const char s_Too_many_points_in_point_list_fo_005633a0[] = "Too many points in point list fo";
extern const char s_Unknown_opcode__d__last__d__in_w_00563204[] = "Unknown opcode d last d in w";
extern const char s_vopath_00563240[] = "vopath";
extern const char s_walist_005633d0[] = "walist";
extern const char s_World_gt_fogmax_gt__0_0f_00563474[] = "World gt fogmax gt 0 0f";
extern const char s_World_gt_fogmin_gt__0_0f_0056348c[] = "World gt fogmin gt 0 0f";
extern const char s_World_gt_waterfogmax_gt__0_0f_0056343c[] = "World gt waterfogmax gt 0 0f";
extern const char s_World_gt_waterfogmin_gt__0_0f_00563458[] = "World gt waterfogmin gt 0 0f";
extern const char s_WorldAnims_after_references__005632d0[] = "WorldAnims after references ";
} // extern "C"
