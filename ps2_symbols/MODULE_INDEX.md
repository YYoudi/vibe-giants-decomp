# PS2 (SLUS_201.78) Function Index — by semantic module


Total: **4769** named functions across **507** prefixes.

Use this as the names dictionary when reverse-engineering the PC `GiantsMain.exe`:
find the PC `sub_*` whose structure matches a PS2 function below, then rename + type it.


| # | prefix | count | sample functions |
|---|--------|------|------------------|
| 1 | `_misc*` | 1571 | _start; _exit; _root; ObjectSetSubAnim; ObjectSetAnim |
| 2 | `sce*` | 249 | sceScfGetLanguage; sceScfSetT10kConfig; sceScfGetAspect; sceScfGetSpdif; sceScfGetTimeZone |
| 3 | `reaper*` | 149 | reaper_load; reaper_save; reaper_firecircle_load; reaper_firecircle_save; reaper_firewall_post |
| 4 | `fx*` | 113 | fx_init; fx_needsInit; fx_finit; fx_find; fx_setupWeather |
| 5 | `object*` | 99 | object_animate_refs; object_animate_process; object_animation_init; object_animation_get_max_anim_time; object_animate_check |
| 6 | `rpman*` | 88 | rpman_load; rpman_save; rpman_gunseat_ProcAnimsCreate; rpman_can_be_sfcaught; rpman_is_sfcaught |
| 7 | `mecc*` | 87 | mecc_reset; mecc_center_view; mecc_toggle_camera_mode; mecc_zoom_in; mecc_zoom_out |
| 8 | `kabuto*` | 61 | kabuto_reset; kabuto_zoom_in; kabuto_zoom_out; kabuto_move; kabuto_turn |
| 9 | `gl*` | 51 | gl2_test; gl2_powerUp; gl2_initView; gl2_allocSortMemChunk; gl2_systemBegin |
| 10 | `evilreaper*` | 45 | evilreaper_ai_cb; evilreaper_load; evilreaper_save; evilreaper_invalid_turbo_loc; evilreaper_get_turbo_loc |
| 11 | `smartie*` | 44 | smartie_base_attack_comment; smartie_kick_from_partyhouse; smartie_load; smartie_save; smartie_launch_seamonster |
| 12 | `base*` | 44 | base_store_cam; base_restore_cam; base_assign_smartie_building; base_setup_tentative; base_find_by_playergroup |
| 13 | `camera*` | 38 | camera_has_changed; camera_get_curcamdef; camera_cursor_fire; camera_is_camera1; camera_is_camera3 |
| 14 | `sound*` | 37 | sound_setup_reverb; sound_setup_occlusion; sound_music_toggle; sound_free_sample; sound_unload_free |
| 15 | `vimp*` | 34 | vimp_load; vimp_save; vimp_consider_graze_noise; vimp_gib; vimp_way_ahead |
| 16 | `kbos*` | 33 | kbos_target_valid; kbos_size_ospec; kbos_food_value; kbos_sizer; kbos_grow |
| 17 | `ai*` | 32 | ai_clear_move_goal; ai_goal_remove; ai_move_force_goal; ai_movedir_force_goal; ai_movedir_clear_set_goal |
| 18 | `ripper*` | 32 | ripper_load; ripper_save; ripper_on_steep_slope; ripper_check_los; ripper_choose_building |
| 19 | `gs*` | 32 | gs_powerUp; gs_shutdown; gs_reset; gs_init; gs_buildFrameStart |
| 20 | `get*` | 31 | getFOVSine; get_grid_ground_z; get_floor_z_point; get_floor_z_point_plat; get_mecc_jetpack_ground_z |
| 21 | `i*` | 31 | i_hate_life; iALLOc; iSetAlarm; iReleaseAlarm; iTerminateThread |
| 22 | `reaperbase*` | 30 | reaperbase_get_bldg_name; reaperbase_init; reaperbase_move; reaperbase_icon_test; reaperbase_update_icons |
| 23 | `collide*` | 28 | collide_movement_process; collide_fillin_ground_normal; collide_no_climb; collide_no_climb_locdir; collide_movement_grid_ground |
| 24 | `anim*` | 28 | animInitSystem; animDestroySystem; animBonesInvalidate; animBonesAllocate; animInitAnimation |
| 25 | `army*` | 27 | army_finit_bin; army_init_bin; army_create_platoon; army_find_active_order; army_find_alive_order |
| 26 | `audio*` | 25 | audio_startSound; audio_stopSound; audio_isHandleActive; audio_setSoundPosition; audio_mute |
| 27 | `teammecc*` | 24 | teammecc_get_datasize; teammecc_get_slavecount; teammecc_get_slave; teammecc_get_text; teammecc_set_text |
| 28 | `delphi*` | 23 | delphi_reset; delphi_zoom_in; delphi_zoom_out; delphi_move; delphi_turn |
| 29 | `rpboat*` | 22 | rpboat_load; rpboat_save; rpboat_stop_looping_sound; rpboat_unlock_from_boat; rpboat_lock_to_boat |
| 30 | `set*` | 21 | set_control_configuration; setImageTag; set_rfont_visible; setInstDrawLeafData; setCtrlConfig__7PS2Gameiii |
| 31 | `make*` | 21 | make_explosion; make_flash_explosion; make_explosion_small; make_explosion_medium; make_explosion_large |
| 32 | `marker*` | 21 | marker_target; marker_process; marker_load; marker_save; marker_get_numtypes |
| 33 | `kabutoai*` | 21 | kabutoai_hotspotshield; kabutoai_select_target; kabutoai_change_anim; kabutoai_is_punch_anim; kabutoai_select_punch_anim |
| 34 | `offspring*` | 21 | offspring_load; offspring_save; offspring_change_anim; offspring_select_turn_anim; offspring_select_run_anim |
| 35 | `scen*` | 21 | scenFindKeys; scenInterpF32Lin; scenDU; scenInterpF32Bez; scenHermiteBasis |
| 36 | `mission*` | 20 | mission_resetMissionStart; mission_start_at_marker; mission_init; mission_trigger; mission_smartie_grab |
| 37 | `playerobj*` | 20 | playerobj_zap_pctl; playerobj_move; playerobj_gravity_once; playerobj_normal_logic; playerobj_special_action_logic |
| 38 | `texture*` | 20 | texture_close_file; texture_add_file; texture_initialize; texture_read_data; texture_free |
| 39 | `dma*` | 20 | dmaX; dmaY; dmaInit; dmaRestart; dmaShutdown |
| 40 | `meccbase*` | 19 | meccbase_get_bldg_name; meccbase_init; meccbase_icon_test; meccbase_update_icons; meccbase_assign_smartie_to_building |
| 41 | `path*` | 19 | path_size_ospec; path_finit; path_est; path_init_add_bridge; path_world_finit |
| 42 | `control*` | 18 | control_init_ps2; control_read; controlInitButtons; controlInitExtendedButtons; controlReset |
| 43 | `tracer*` | 18 | tracer_call_back; tracer_draw_segment; tracer_get_lander_refs; tracer_add_ref; tracer_remove_ref |
| 44 | `link*` | 17 | link_get_free; link_remove_free; link_add_item; link_add_item_end; link_remove_list |
| 45 | `verm*` | 17 | verm_load; verm_save; verm_ai_cb; verm_move; verm_gib |
| 46 | `video*` | 17 | videoCallback; videoDecCreate; videoDecSetDecodeMode; videoDecSetStream; videoDecBeginPut |
| 47 | `meccbasepit*` | 16 | meccbasepit_move; meccbasepit_swap_model; meccbasepit_size_ospec; meccbasepit_get_smartie_table_dest; meccbasepit_smartie_leave_table |
| 48 | `read*` | 16 | readMpeg; read_sfx_bin; readBufCreate; readBufDelete; readBufBeginPut |
| 49 | `wave*` | 16 | wave_effect_reset; wave_effect_alloc; wave_effect_free; wave_effect_get_index; wave_effect_get_base |
| 50 | `bldg*` | 15 | bldg_add_energy; bldg_subtract_energy_basic; bldg_subtract_energy; bldg_get_energy; bldg_is_destroyed |
| 51 | `mapmode*` | 15 | mapmode_reset; mapmode_view; mapmode_exit; mapmode_save_camera; mapmode_restore_camera |
| 52 | `item*` | 15 | item_play_pickup_sound; item_check; item_get_ammo; item_use_ammo; item_loadgame |
| 53 | `physicshost*` | 15 | physicshost_size_ospec; physicshost_attach_object; physicshost_init; physicshost_collision_process; physicshost_collision |
| 54 | `charger*` | 14 | charger_do_fx; charger_dust_fx; charger_change_anim; charger_select_run_anim; charger_scan_for_enemy |
| 55 | `world*` | 14 | world_ripple_create; world_ripple_process; world_ripple_render; world_ripple_xform; world_to_grid |
| 56 | `vi*` | 14 | viBufCreate; viBufReset; viBufBeginPut; viBufEndPut; viBufAddDMA |
| 57 | `mtx*` | 14 | mtx3x3LookAt; mtx3x3yaw; mtx3x3pitch; mtx3x3roll; mtx3x3Transpose |
| 58 | `sonak*` | 13 | sonak_load; sonak_save; sonak_move; sonak_patrol_move; sonak_control |
| 59 | `tex*` | 13 | tex_powerUp; tex_shutdown; tex_init; tex_setMipZ; tex_buildLocTex |
| 60 | `lzo*` | 13 | lzo_assert; lzo_copyright; lzo_version; lzo_version_string; lzo_version_date |