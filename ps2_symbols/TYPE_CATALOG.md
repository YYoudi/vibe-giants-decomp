# Giants engine — TYPE CATALOG (from PS2 signatures)

Derived from 4769 demangled PS2 function signatures. Shows the engine's type
architecture to guide naming/typing the PC Ghidra structs.

## Most central pointer types (structs to recover FIRST)

Ranked by how often each appears as a pointer parameter. `OBJECT*` is the
universal game-object struct — recover its layout first.

| type | as ptr param | total params | #funcs using it | example functions |
|------|-------------:|-------------:|----------------:|-------------------|
| `OBJECT*` | 785 | 786 | 781 | AI_AnimSelect, AI_GoalClear, AI_GoalProcess, AI_GoalSetDir |
| `P3D*` | 124 | 124 | 123 | AI_GoalSetLocation, AttackObject, BloodForwardFromPoint, CalculateAirSpace |
| `FXSTACKTAG*` | 65 | 65 | 65 | fx_attach, fx_createDecal, fx_interruptSoundSequence, fx_killLoggedObj |
| `VideoDec*` | 18 | 18 | 18 | decBs0, readMpeg, videoDecAbort, videoDecBeginPut |
| `FLK_Flick*` | 17 | 17 | 17 | FLK_ActorAdd, FLK_ActorAttach, FLK_ActorOrigin, FLK_ActorScale |
| `ViBuf*` | 15 | 15 | 15 | getFIFOindex, viBufAddDMA, viBufBeginPut, viBufCount |
| `ANM_KeyInfo*` | 14 | 14 | 14 | ANM_DU, ANM_InterpQuatBEZ, ANM_InterpQuatLIN, ANM_InterpQuatTCB |
| `FxData*` | 13 | 13 | 13 | fx_createFlame, fx_createGameLockedObj, fx_createObj, fx_killLoggedObj |
| `GEO_Vec4*` | 10 | 10 | 10 | ANM_BinderEvalVertices, ANM_BinderEvalVerticesBlended, ANM_InterpQuatBEZ, ANM_InterpQuatLIN |
| `AudioDec*` | 10 | 10 | 10 | audioDecBeginPut, audioDecCreate, audioDecDelete, audioDecEndPut |
| `ObjProcessInfo*` | 10 | 10 | 10 | AI_AnimSelect, AI_GoalProcess, ObjProcessInfoBegin, ObjProcessInfoEnd |
| `ANM_Keys*` | 9 | 9 | 9 | ANM_KeyInsert, ANM_KeyRemove, ANM_KeysAssignInterpolator, ANM_KeysFixPtrs |
| `GEO_Mat*` | 9 | 9 | 9 | ANM_BindingCollision, FLK_ActorGetMat, GEO_MatMultiplyFull, GEO_MatPerspectiveBlinn |
| `PathPoint*` | 9 | 9 | 9 | p3d_to_pathpoint, path_blocked_long, path_calculate_go, path_calculate_table |
| `VoBuf*` | 9 | 9 | 9 | voBufCreate, voBufDecCount, voBufDelete, voBufGetData |
| `ANODE*` | 8 | 8 | 8 | find_node, heap_siftdown, heap_siftup, path_est |
| `ReadBuf*` | 7 | 7 | 7 | readBufBeginGet, readBufBeginPut, readBufCreate, readBufDelete |
| `VECTOR4F*` | 6 | 6 | 6 | AudioListenerPositionSet, AudioSound3DSetPosition, AudioSoundPlay, AudioVoiceStreamOpen |
| `ANM_Node*` | 5 | 5 | 3 | ANM_NodeFixPtrs, ANM_NodeGetName, NodeSetUsrAnm |
| `FxOspec*` | 5 | 5 | 5 | fx_weatherCreateParticle, fx_weatherGetParticleLoc, fx_weatherRespawnParticle, fx_weatherSystemLogic |
| `Tracer*` | 5 | 5 | 5 | loadsave_tracer_to_index, tracer_calc_falloff, tracer_calc_rgb, tracer_draw |
| `Texture*` | 5 | 5 | 4 | alloc_bump_reference, free_land_texture, texture_free, texture_read_data |
| `SOUNDSEQUENCE*` | 5 | 5 | 5 | sound_free_sequence, sound_release_sequence, sound_remove_dup_sequence, sound_sequence_end |
| `Animation*` | 4 | 4 | 4 | ProcessTrigger, bone_proc_anim, finish_trigger, object_animate_check |
| `FXLISTTAG*` | 4 | 4 | 4 | fx_fix_logged_objects, fx_free, fx_free_effect, loadsave_fxlist_to_index |
| `ObjSpecKabuto*` | 4 | 4 | 4 | SpikeFindFree, SpikeFindLunch, SpikeRemove, check_target |
| `StrFile*` | 4 | 4 | 4 | readMpeg, strFileClose, strFileOpen, strFileRead |
| `Hud2DIcon*` | 4 | 4 | 4 | SelectMeccCrossAim, SelectMeccOtherInvRender, SelectMeccResourceRender, SelectMeccSpecialInvRender |
| `QUAT*` | 4 | 4 | 4 | euler_to_quat, matrix_to_quat, quat_mult, quat_to_matrix |
| `ANM_Skin*` | 3 | 3 | 3 | ANM_BinderDump, ANM_DumpObj, ANM_ObjRemapClusterIndices |
| `ANM_Obj*` | 3 | 3 | 3 | ANM_ObjFixPtrs, ANM_ObjRemapClusterIndices, ANM_ObjZeroWeightedVertices |
| `ArmyOrder*` | 3 | 3 | 3 | army_create_platoon_member, army_create_ripper, army_create_rpman |
| `BLOOD*` | 3 | 3 | 3 | blood_from_blood, process_blood1, render_blood1 |
| `GridGround*` | 3 | 3 | 3 | collide_movement_grid_air, collide_movement_grid_ground, collide_movement_grid_ground_z |
| `FLK_File*` | 3 | 3 | 3 | FLK_FileUnload, FLK_FlickCreate, ResPtr |

## Primitive parameter usage

| type | count |
|------|------:|
| `int` | 913 |
| `float` | 682 |
| `char` | 167 |
| `void` | 84 |
| `?N` | 36 |
| `short` | 32 |
| `f32vec3` | 31 |
| `dmaHdr` | 23 |
| `f32vec4` | 15 |
| `?F` | 13 |
| `?_` | 13 |

## Function arity distribution

| #params | #functions |
|--------:|----------:|
| 0 | 3023 |
| 1 | 742 |
| 2 | 473 |
| 3 | 296 |
| 4 | 94 |
| 5 | 52 |
| 6 | 42 |
| 7 | 17 |
| 8 | 10 |
| 9 | 8 |
| 10 | 6 |
| 11 | 1 |
| 12 | 2 |
| 13 | 1 |
| 19 | 1 |
| 28 | 1 |

## All named (struct-like) types seen

Alphabetical — each is a candidate Ghidra struct to define on the PC side.

- `ANM_Anim` (1 param uses, 1 funcs)
- `ANM_BezInterpolateInfo` (1 param uses, 1 funcs)
- `ANM_Binder` (2 param uses, 2 funcs)
- `ANM_Binding` (1 param uses, 1 funcs)
- `ANM_Blender` (2 param uses, 2 funcs)
- `ANM_Cluster` (1 param uses, 1 funcs)
- `ANM_Collisions` (1 param uses, 1 funcs)
- `ANM_Key` (1 param uses, 1 funcs)
- `ANM_KeyInfo` (14 param uses, 14 funcs)
- `ANM_Keys` (9 param uses, 9 funcs)
- `ANM_Node` (5 param uses, 3 funcs)
- `ANM_Obj` (3 param uses, 3 funcs)
- `ANM_Skin` (3 param uses, 3 funcs)
- `ANODE` (8 param uses, 8 funcs)
- `AU_ROSTER_TYPE` (1 param uses, 1 funcs)
- `AnimTrigger` (2 param uses, 2 funcs)
- `Animation` (4 param uses, 4 funcs)
- `ArmyOrder` (3 param uses, 3 funcs)
- `AudioDec` (10 param uses, 10 funcs)
- `BBOX` (1 param uses, 1 funcs)
- `BLOOD` (3 param uses, 3 funcs)
- `BRIDGELIST` (1 param uses, 1 funcs)
- `BasicUsrAnmDef` (1 param uses, 1 funcs)
- `ButtonStateFlags` (1 param uses, 1 funcs)
- `CByteStream` (2 param uses, 2 funcs)
- `CntrlInput` (81 param uses, 81 funcs)
- `DynamicSoundProxy` (2 param uses, 2 funcs)
- `FILESYSTEM` (1 param uses, 1 funcs)
- `FLK_Actor` (3 param uses, 3 funcs)
- `FLK_File` (3 param uses, 3 funcs)
- `FLK_Flick` (17 param uses, 17 funcs)
- `FLK_Fx` (2 param uses, 2 funcs)
- `FLK_Slider` (2 param uses, 2 funcs)
- `FNT_RenderInfo` (2 param uses, 2 funcs)
- `FXLISTTAG` (4 param uses, 4 funcs)
- `FXSTACKTAG` (65 param uses, 65 funcs)
- `FxData` (13 param uses, 13 funcs)
- `FxOspec` (5 param uses, 5 funcs)
- `GEO_Affine` (2 param uses, 1 funcs)
- `GEO_Mat` (9 param uses, 9 funcs)
- `GEO_RegionSpan` (1 param uses, 1 funcs)
- `GEO_Vec4` (10 param uses, 10 funcs)
- `GOAL` (1 param uses, 1 funcs)
- `GridGround` (3 param uses, 3 funcs)
- `HDWDV` (13 param uses, 12 funcs)
- `Hud2DIcon` (4 param uses, 4 funcs)
- `Hud3DIcon` (1 param uses, 1 funcs)
- `HurtType` (8 param uses, 8 funcs)
- `LINK` (1 param uses, 1 funcs)
- `LIST` (3 param uses, 3 funcs)
- `LLStreamStatus` (1 param uses, 1 funcs)
- `M4X4` (1 param uses, 1 funcs)
- `OBJECT` (786 param uses, 781 funcs)
- `ObjProcessInfo` (10 param uses, 10 funcs)
- `ObjSpecKabuto` (4 param uses, 4 funcs)
- `ObjSpecReaper` (2 param uses, 2 funcs)
- `ObjSpecSmartie` (1 param uses, 1 funcs)
- `ObjectData` (1 param uses, 1 funcs)
- `ObjectSet` (2 param uses, 2 funcs)
- `P3D` (124 param uses, 123 funcs)
- `P3P3DT3fi` (1 param uses, 1 funcs)
- `P7PLANE3D` (2 param uses, 2 funcs)
- `P8AudioDeci` (1 param uses, 1 funcs)
- `PLANE3D` (3 param uses, 3 funcs)
- `PROJ_File` (3 param uses, 3 funcs)
- `PROJ_Pc` (1 param uses, 1 funcs)
- `PathDir` (3 param uses, 3 funcs)
- `PathPoint` (9 param uses, 9 funcs)
- `QUAT` (4 param uses, 4 funcs)
- `QWORD` (1 param uses, 1 funcs)
- `REVERB_MODE` (2 param uses, 2 funcs)
- `ReadBuf` (7 param uses, 7 funcs)
- `SDKY` (7 param uses, 7 funcs)
- `SOUNDSEQUENCE` (5 param uses, 5 funcs)
- `SPEAKER_SYSTEM` (1 param uses, 1 funcs)
- `SlowFollowCustom` (1 param uses, 1 funcs)
- `StrFile` (4 param uses, 4 funcs)
- `T1iP9TimeStampi` (1 param uses, 1 funcs)
- `T3iP9TimeStampi` (1 param uses, 1 funcs)
- `T_AnimInfo` (3 param uses, 3 funcs)
- `T_CameraInfo` (1 param uses, 1 funcs)
- `T_WaveDatas` (2 param uses, 2 funcs)
- `T_WaveEffect` (3 param uses, 3 funcs)
- `TexFileEntry` (1 param uses, 1 funcs)
- `Texture` (5 param uses, 4 funcs)
- `TimeSnap` (3 param uses, 3 funcs)
- `TimeStamp` (3 param uses, 3 funcs)
- `Tracer` (5 param uses, 5 funcs)
- `TurretCommShoot` (1 param uses, 1 funcs)
- `UsrAnmDef` (1 param uses, 1 funcs)
- `VECTOR4F` (6 param uses, 6 funcs)
- `ViBuf` (15 param uses, 15 funcs)
- `VideoDec` (18 param uses, 18 funcs)
- `VoBuf` (9 param uses, 9 funcs)
- `VoData` (1 param uses, 1 funcs)
- `VoTag` (1 param uses, 1 funcs)
- `WOUND` (2 param uses, 2 funcs)
- `WorldAnim` (1 param uses, 1 funcs)
- `WorldData` (2 param uses, 2 funcs)