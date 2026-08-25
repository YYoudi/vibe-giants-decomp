# Format & knowledge inventory — check HERE before deriving anything

Rule: before reversing any format, check this table. If covered → reuse the code.
Only reverse what is NOT covered. Update this file when coverage changes.

## Game file formats

| Format | Role | Covered by | Status |
|---|---|---|---|
| **GZP** | asset package (any files inside) | `git_repos_from_amazed/gck-map-extract-objects/read_gzp.py` + `lib/fileutils.py` (LZSS 0xFEE/0x1000) | ✅ COMPLETE — TOC = `{u32 csize, u32 usize, u32 filetime, u32 blockOff, u8 comp, u8 namelen, name}`; data block at blockOff = 16B header `{csize, usize, crc, type}` + payload; comp 1=LZ else stored |
| **SKN** | skeletons | `gck-map-extract-objects/skn.py`, `lib/skn_anm.py` | ✅ |
| **ANM** | animations | `gck-map-extract-objects/anm.py` | ✅ |
| **GBS** | models | `blender-giants-plugin/gbs_plugin/importer.py`, `obj2gbs.py`, `id_to_gbs.py` | ✅ (blender import round-trip) |
| **wdefs.bin** | weapon definitions | `giants-wdefs-importer-gui` | ✅ |
| **GCK** | world containers (zip) | documented `sent_by_Amazed/game_structure.txt` ("just zip files") | ✅ (zip) |
| **.bin map logic** | objects/spawns/map attrs | `map2obj.py` needs external `giantslib` (absent) | ⚠️ PARTIAL |
| **GTI (terrain)** | map terrain | — | 🔶 STARTED: header decoded (see gaps) |
| **GText*.bin** | translations | — (`scripts/gtext_parse.py` now) | 🔶 ~95% solved (see gaps) |
| **WorldList.bin** | world registry | — (decoded this session) | 🔶 structure known |
| **GDF** | dedicated server defs | `dedicated.exe` generates (game_structure.txt) | 📝 tool exists |
| *.gdf/.abx | server defs/unknown | — | ❓ |

## Game structure knowledge (already documented)

- `sent_by_Amazed/game_structure.txt` — full file tree semantics (Bin/w_*.gzp = map textures,
  *.bin = loadable components linking assets, Override = per-file override incl. by name,
  Worlds/*.gck, Music/Stream/StreamEnglish). NOTE: written for 1.4-era (Giants.exe=launcher,
  GiantsMain.exe=main) — in v1.0 Giants.exe IS the main binary.
- `sent_by_Amazed/fuel_mechanics.txt`, `debug-doc.txt` (+ debug.exe), `giants-linux.md`,
  `teamid_base.txt`, `Boss battle.pdf`, magazine PDFs (MC-DPL*) — mechanics & history docs.
- `sent_by_Amazed/gwd_maps`, `gwd_patches`, `gwd_tools` — GWD (Giants World Domination?) assets.
- `Patches_extracts/` — 1.4→1.520 patch binaries incl. DX9/DX11/DX12 renderers
  (renderer interface reference: GDVSysCreate/GFXGetCapabilities/UpCallsLoad).
- `Giants Mecc/Reaper Demo/` — clean DX7 renderers + demo game files.

## Symbol resources

- `ps2_symbols/` — 4769 named PS2 functions, 378 PC↔PS2 matches (`pc_ps2_matches_full.csv`),
  OBJECT_LAYOUT, TYPE_CATALOG, MODULE_INDEX. PC addrs valid for v1.0 image (0x260000 virt).
- Renderer interface exports (any gg_*r.dll): GDVSysCreate / GFXGetCapabilities / UpCallsLoad.

## Binaries & environments

- Vanilla v1.0: `GameFiles-VanillaV1/Giants.exe` (MD5 330c6a…ec27) — GROUND TRUTH, never modify.
- PS2 prototype ISO + ELF (unstripped): `sent_by_Amazed/…PS2.7z`, `ps2_symbols/SLUS_201.78`.
- Working runtime copy: `RuntimeLab/GiantsWork/` (vanilla exe + Mecc gg_dx7r + dgVoodoo2
  DDraw/D3DImm + ddraw shim `.off` variants kept). Boot recipe: `scripts/boot_session.py`.

## RE gaps worth attacking (unique value)

1. **GTI terrain** — ✅ SOLVED (loader +0x76D40, `scripts/gti_parse.py` validated: 958
   records / 0 bad / rendered max == maxh). Open tails: the 829 post-RLE bytes in stunt_show
   (texture/lightmap section?), chunk records for v2/v3 (count>0 files unseen).
2. **GText*.bin** — ✅ SOLVED 100% (loader +0x10D660; `scripts/gtext_parse.py` clean on
   EN/FR/DE/IT/ES).
3. **WorldList.bin** — decoded: {?, payloadLen, count, offsets[], name+id records}.
4. **world.gb2** — still undecoded; world table at +0xF4070 references {wav, gti, bin, gb2}.
5. **.bin object format (0x1A0002E5)** — loader at +0xB7C50; body structure unmapped.
   **.abx (0x1A0002DD)** — loader at +0xBA83B region; body unmapped.
6. System-layer functions — `scripts/re_db.json` (28 fns / 14 globals, apply_labels.py).
7. Main-loop / frame architecture — blocked on the real menu (D3DEnum filter rejects
   dgVoodoo devices; GOG D3D8 renderer crashes on v1.0 exe).

## Behavioral quirks (user-provided, empirically validated)

- **`Bin/intros.bin`** (29 bytes, plain CRLF text) = the intro slide list:
  `dmlarge000`, `planetmoon`, `legal` — 3 fullscreen clickable images with fades.
  Temporarily renaming/removing it in the WORK COPY skips the intro entirely and
  boots straight to the main menu (validated via vision loop: starfield menu
  renders directly, no slides). Vanilla copy untouched.
