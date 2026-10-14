# AUDIO — stack, banks, events

Status: 🔶 top-level API + assets mapped; DLL boundary and bank container details open.

**Evidence:** corpus function names + asset tree (`GameFiles-VanillaV1/`). **Derived**
unless noted.

## Stack

- **`eaxman.dll` + `gs_ds.dll`** ship in the game root (DirectSound + EAX wrappers).
  They are NOT in the exe import table (only 8 system DLLs) → loaded at runtime via
  `LoadLibrary` and called through function-pointer tables. The DLLs themselves do NOT
  need reversing for a reimplementation: a modern audio layer (e.g. SDL2/-openal) can
  replace them; only the event semantics below must match.
- 3D listener: `audio_listener_update @ 0x004319C0` — driven from the camera
  (`XFGetCameraOrigin` / `XFGetCameraAxis` every frame).
- Streams (music/ambient): `audio_streams_update_all @ 0x00432950`,
  `audio_stream_update_one @ 0x00432270`, `audio_stream_tied @ 0x00434280` —
  multi-stream mixer fed from `Music/` and `Stream/<lang>/`.

## Assets

| asset | location | notes |
|---|---|---|
| SFX banks | `Bin/VO_Sfx<Lang>.gzp` | GZP package (✅ format) of `.wav` |
| music | `Music/` | streamed files |
| voice/cinematics | `Stream/`, `Stream<Lang>/` | streamed per language |
| per-world sfx env | `Bin/sfxlev*.bin` + `read_sfx_bin @ 0x004950A0` | section of every `w_*.bin` (docs/formats/bin_objects.md) |
| mission voice | op 132 `strz → WS[0x50E0]` (voice path) | |
| music per world | ops 114/115/116 name+f32 triplets → `WS[0x4F20..4F34]` | |
| game options | `AudioSetSpeakerConfig(SPEAKER_SYSTEM)` (4 variants in corpus) + `dlog_audio_options_process` | speaker layout |

## Event API

- `sound_play_obj(id, obj) @ 0x004954E0` — THE play entry (sound id + source object);
  used by AI (`facing_player_bark` 0x682/0x683), weapons, UI (`dlog_list_navigate_sound`).
- `sound_checked_big @ 0x0049BD90` — the gameplay-side gate: plays with
  distance/occlusion checks, `sound_play_3/4/_checked` variants, `sound_stop_obj`.
- Player voices: `sound_player_voice_mecc @ 0x0040D370`,
  `sound_player_voice_smartie @ 0x0040D280`.
- Music director: `scenerio_handle_music @ 0x004429C0` (scenario-driven music changes).

## Validation

- P1.1 traces `sound_play_obj` — every hit logs `(id, obj)`; correlating ids with
  in-game moments builds the sound-id catalog incrementally.
- Open: the wav/sample format inside VO_Sfx (plain PCM expected — verify at P2.3), the
  gs_ds.dll export surface (only if a 1:1 replacement is ever wanted).
