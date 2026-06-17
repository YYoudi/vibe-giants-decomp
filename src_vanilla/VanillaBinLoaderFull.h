// Giants Vanilla-Native Recomp — FULL faithful port of FUN_004b7c50 (readwrls.c).
//
// Source of truth: vanilla_decompiled/004b7c50.json (11736-byte decompiled body,
// vanilla 1.0 retail Giants.exe @ 0x004b7c50, base 0x400000). This is the workhorse
// W<level>.bin scene loader: validates magic 0x1a0002e5, parses the 7-u32 header,
// seeks to each section, dispatches the odef (object-definition) VM (~80 opcodes),
// recursively loads sub-scenes (<name>_bin), reads object placements, and seeds
// world globals on DAT_006316ec.
//
// WHY A SECOND FILE: a lighter `VanillaBinLoader.{h,cpp}` already exists with a
// select subset of opcodes and diagnostic logging. This "Full" port reproduces
// the *entire* decompiled body verbatim (every switch case, every DAT_ write,
// every FIXME-tagged callee) so the structure can be diffed 1:1 against Ghidra.
// It does NOT touch the lighter file.
//
// ANTI-DERIVE: every statement cites the DAT_ address or callee VA it came from.
// Nothing is invented. Unverified callees (not yet ported) are declared extern
// "C" and called verbatim with a `// FIXME(unverified): callee <addr>` tag — link
// resolves later against stubs you provide.
//
// READING MODEL (IAT-confirmed in VanillaFileIO.h):
//   FUN_0051d7b0(handle, off) = SetFilePointer(SEEK FILE_BEGIN)   [VA 0x0051d7b0]
//   FUN_0051d750(handle, buf, n) = ReadFile(buf, n)               [VA 0x0051d750]
//   FUN_0051d850(handle)        = CloseHandle                      [VA 0x0051d850]
//   FUN_00539e30(name)          = open -> handle (0=fail)          [VA 0x00539e30]
//
// HEADER (verified directly against Bin/w_intro_island.bin, 1514 bytes):
//   off 0x00 u32  magic            == 0x1a0002e5      (cmp @ 0x4b7cbe)
//   off 0x04 u32  hdr[0] odef_blob_off   (==0x20; at that off a u32 = blob size)
//   off 0x08 u32  hdr[1] name_list_off
//   off 0x0c u32  hdr[2] texmem_off      (FUN_0049a580 SFX seek target)
//   off 0x10 u32  hdr[3] world_off
//   off 0x14 u32  hdr[4] fx_off          (FUN_0050d8f0 texmem/entity seek target)
//   off 0x18 u32  hdr[5] reserved5
//   off 0x1c u32  hdr[6] sub_bins_off    (recursive sub-scene list)
// (The 7-u32 block at 0x04..0x1c is read in one FUN_0051d750(.., 0x1c) call @ 0x4b7cde.)
#pragma once
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------------
// Extern callees (declared here so the .cpp stays self-contained for linking).
// Each is tagged FIXME(unverified) — port fidelity is struct-only; the callee
// bodies are resolved by stubs the integrator provides.
// ----------------------------------------------------------------------------

// File I/O (ports in VanillaFileIO.h — verified, NOT unverified).
uint32_t FUN_00539e30(const char* filename);                       // open -> handle (0=fail)
void     FUN_0051d750(uint32_t handle, void* buf, uint32_t count); // ReadFile(buf,count)
void     FUN_0051d7b0(uint32_t handle, uint32_t offset);           // SetFilePointer(BEGIN)
void     FUN_0051d850(uint32_t handle);                            // CloseHandle

// FIXME(unverified): callee 0x00544b47 — formatted log/printf into DAT_006552c0.
//   The body calls this BOTH as a logger (arg1 = &DAT_006552c0) AND as a sprintf
//   (arg1 = stack char buffer). Typed const void* to accept both uses verbatim.
void FUN_00544b47(const void* logCtx, const char* fmt, ...);
// FIXME(unverified): callee 0x00523700 — flush/emit log (DAT_006552c0)
void FUN_00523700(uint32_t logCtx);
// FIXME(unverified): callee 0x00523aa0 — assertion/warning print.
//   Body calls this with BOTH a log-ctx (DAT_006552c0) and a literal string;
//   typed void* to accept both verbatim.
void FUN_00523aa0(const void* msg);
// FIXME(unverified): callee 0x0049a580 — SFX load at current file pos (texmem section)
void FUN_0049a580(uint32_t handle);
// FIXME(unverified): callee 0x0050d8f0 — insert texture/entity nodes (name, handle, magic)
void FUN_0050d8f0(const char* name, uint32_t handle, uint32_t magic);
// FIXME(unverified): callee 0x0044ab90 — apply world FX preset by string
void FUN_0044ab90(const char* fxName);
// FIXME(unverified): callee 0x004b50b0 — read object placements -> DAT_006313c8 list
void FUN_004b50b0(uint32_t handle, const char* name);
// FIXME(unverified): callee 0x0053c810 — allocator (heapId, size, tag, file, line) -> ptr
void* FUN_0053c810(uint32_t heapId, uint32_t size, const void* tag,
                   const char* file, int line);
// FIXME(unverified): callee 0x0053c890 — allocator variant (returns into out param)
void FUN_0053c890(uint32_t heapId, const void* src, void* out,
                  const char* file, int line);
// FIXME(unverified): callee 0x0053c5c0 — deallocator (ptr, file, line)
void FUN_0053c5c0(void* ptr, const char* file, int line);
// FIXME(unverified): callee 0x0053c970 — string compare (a, b) -> 0 if equal
int  FUN_0053c970(const char* a, const void* b);
// FIXME(unverified): callee 0x0050e3c0 — texture lookup/resolve by name -> handle
uint32_t FUN_0050e3c0(const char* texName);
// FIXME(unverified): callee 0x0049d2d0 — object type lookup by id -> ObjData ptr (0=miss)
int  FUN_0049d2d0(float typeId);
// FIXME(unverified): callee 0x0049c190 — create placeholder object (type, flags) -> ptr
int  FUN_0049c190(int type, int flags);
// FIXME(unverified): callee 0x0049ccf0 — init placed object slot (stobj, objData)
void FUN_0049ccf0(void* stobj, int objData);
// FIXME(unverified): callee 0x0049cfd0 — copy defaults into stobj (stobj, objData)
void FUN_0049cfd0(void* stobj, int objData);
// FIXME(unverified): callee 0x0049f3b0 — set object kind/subtype (stobj, kind)
void FUN_0049f3b0(void* stobj, int kind);
// FIXME(unverified): callee 0x0049d280 — object-type lookup by u32 id -> ptr
int  FUN_0049d280(int typeId);
// FIXME(unverified): callee 0x004a1360 — load mesh/resource by name -> handle
uint32_t FUN_004a1360(const void* name);
// FIXME(unverified): callee 0x00405080 — load .anm by path -> handle
uint32_t FUN_00405080(const char* path);
// FIXME(unverified): callee 0x00472560 — apply position to stobj (stobj, vec3)
void FUN_00472560(void* stobj, const float* pos);
// FIXME(unverified): callee 0x00491830 — load sound (idx, count, name)
void FUN_00491830(uint8_t idx, uint32_t count, void* nameBuf);
// FIXME(unverified): callee 0x00429100 — error-context flush (logCtx)
void FUN_00429100(const void* logCtx);
// FIXME(unverified): callee 0x00476d40 — post-load name hook (terrain/sky name)
void FUN_00476d40(const char* name);
// FIXME(unverified): callee 0x0051bd20 — recompute fog tables after fog/waterfog change
void FUN_0051bd20(void);
// FIXME(unverified): callee 0x004b7b30 — finalize world defaults after seed writes
void FUN_004b7b30(void);
// FIXME(unverified): callee 0x00544b99 — dev warning (msg, file, line)
void FUN_00544b99(const char* msg, const char* file, int line);

// Engine globals (DAT_ addresses — vanilla .data). Defined in VanillaStubs.cpp
// or by the integrator. Point to real engine contexts once wired.
extern uint32_t DAT_006316ec;   // world/game context base pointer (stored as uint)
extern uint32_t DAT_006313b4;   // fallback ObjData (error placeholder) base+8
extern uint32_t DAT_006313b0;   // placed-object linked-list head
extern float    _DAT_005a5c9c;  // current world-time float (in/out param)
extern float    _DAT_005522c0;  // k1.0f constant (1.0)
extern float    _DAT_005522b0;  // k0.0f constant (0.0)
extern float    _DAT_00552344;  // small-threshold constant for smoke size clamp
extern float    _DAT_005524b4;  // 1/255 scalar (byte->normalized color)
extern float    _DAT_00552564;  // deg->rad constant (pi/180)
extern float    _DAT_005526c8;  // preset angle (cos seed)
extern float    _DAT_005526d0;  // preset angle (cos seed)
extern uint32_t DAT_005631f8;   // string tag for vopath alloc ("\\")
extern uint32_t DAT_00562d10;   // alloc tag ("stobj"-class)

// String literals (vanilla .rdata). Pointed at by the s_* symbols in the body.
extern const char s_Failed_to_open__s_0055e25c[];
extern const char s_Bad_version_for__s___X_vs__X__005634cc[];
extern const char s_fx_world_dust_005634ac[];
extern const char s_fx_world_snow_005634bc[];
extern const char DAT_0055c214[];                  // fx preset "" (none)
extern const char s__s_bin_00555384[];              // "%s_bin"
extern const char s_C__Giants_Source_main_readwrls_c_00563174[]; // __FILE__ tag
extern const char s_sobjs_005634a4[];
extern const char s_flakpts_00563434[];
extern const char s_walist_005633d0[];
extern const char s_teamripper_0056331c[];
extern const char s_Unknown_opcode__d__last__d__in_w_00563204[];
extern const char s_Too_many_objects_for_world_005633d8[];
extern const char s_Can_t_find_object_type__d__OpObj_005633f4[];
extern const char s_Can_t_find_object_type__d__OpAre_00563328[];
extern const char s_Can_t_find_object_type__d__OpSmo_005632f4[];
extern const char s_Can_t_find_object_type__d__OpLoc_00563264[];
extern const char s_Too_many_points_in_point_list_fo_005633a0[];
extern const char s_Too_many_animations_for_a_world_005632b0[];
extern const char s_WorldAnims_after_references__005632d0[];
extern const char s__s_anm_005632a8[];
extern const char s_Lock_level_nest_too_deep_0056328c[];
extern const char s_Lock_level_underflow_0055ea50[];
extern const char s_Error__Flick__s_not_in_world_fli_0055ea28[];
extern const char s_Too_many_flicks_for_world_00563248[];
// NOTE: the vanilla symbols contain '>' which is illegal in C++ identifiers;
// renamed with _gt (greater-than) so they're callable while still traceable.
extern const char s_World_gt_fogmin_gt__0_0f_0056348c[];   // "World<fogmin<" ...
extern const char s_World_gt_fogmax_gt__0_0f_00563474[];
extern const char s_World_gt_waterfogmin_gt__0_0f_00563458[];
extern const char s_World_gt_waterfogmax_gt__0_0f_0056343c[];
extern const char s_Obsolete_garden_opcode_00563388[];
extern const char s_Obsolete_mesh_single_opcode_0056336c[];
extern const char s_Obsolete_mesh_group_opcode_00563350[];
extern const char s_Bad_version_for__s_0055e248[];
extern const char s_vopath_00563240[];
extern const char s_stobj_005631fc[];
extern const char DAT_005633c8[];                  // alloc tag
extern const char DAT_005632f0[];                  // alloc tag
extern uint32_t DAT_006552c0;                      // log context object

// The loader itself — signature matches vanilla (char* name, float a2, float a3).
// NOTE: decompiled body uses param_2/param_3 as floats (the recursion passes
// interpolated time bounds). Kept as float per the ground truth.
void FUN_004b7c50(char* name, float param_2, float param_3);

#ifdef __cplusplus
} // extern "C"
#endif

namespace VanillaBinLoaderFull {
// Self-test: opens Bin/w_intro_island.bin, validates magic 0x1a0002e5, logs the
// 7-section header offsets, the sub-bin list and the recovered object placements.
// No rendering. Returns 0 on success.
int SelfTest();
} // namespace VanillaBinLoaderFull
