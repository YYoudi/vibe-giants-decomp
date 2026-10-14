import re
p='docs/formats/bin_objects.md'
src=open(p,encoding='utf-8').read()
start=src.find('### Opcode table')
end=src.find('Opcode **termination**')
table=open('p01_tmp/table.md',encoding='utf-8').read()
src=src[:start]+table+src[end:]
old_term=src[src.find('Opcode **termination**'):src.find('### After the stream')]
new_term=chr(10).join([
"Opcode **termination**: the stream ends on opcode `0xFF` (skips the switch -> post-loop",
"code) or on any of the switch `break` terminators `35/42/44/61/67/108/109/110/112`",
"(clean stop - **derived** from the bare-`break` case bodies, **observed** in shipped",
"files: 22/120 world bins end this way, the rest on `0xFF` or end-of-buffer). Ops in the",
"**E** group print `\"Unknown opcode %d (last %d) in w_%s\"` and abort the load.",
"",
""])+''
src=src.replace(old_term,new_term)
old_val=src[src.find('## Validation'):src.find('## Open items')]
new_val=chr(10).join([
"## Validation",
"",
"- **Observed**: magic + 7-offset table + env + texture-name string verified byte-exact",
"  (`sfxlev1.bin`, `xx_fish.bin`); map-name record (op 130 \"army_kstory3\"), terrain-name",
"  records (op 52 `kstory3_grnd`), texture/sun names (op 118 `vfx_sun_small`) read",
"  directly from shipped `w_*.bin` files.",
"- **Observed bulk**: 108/120 GOG `w_*.bin`/`xx_*.bin` opcode streams walk to a clean",
"  terminator or exact end-of-data with this table. 11 files stop on op `0x00` right",
"  after an op-41/118 region (a size variant remains - see Open items). 86 vanilla `Bin/`",
"  component files have empty logic sections (container-only) and pass trivially.",
"- Parser: `tools_spec/bin_formats.py` (container + opcode walker; structural metadata only).",
"",
""])+''
src=src[:src.find('## Validation')]+new_val+src[src.find('## Open items'):]
old_open=src[src.find('## Open items'):]
new_open=chr(10).join([
"## Open items",
"",
"- **Op 41 size variant**: 11 world bins (Kstory2-5, Rstory1/Rstory3 races, ...) hit a",
"  `0x00` byte shortly after an op-41/118 cluster - likely a 4th RGB byte or an extra",
"  field in a fog/record variant. Next step: re-read the op-41 handler and diff a failing",
"  file's bytes around the stop.",
"- `fx_world_dust.bin`: logic section lacks the two leading strz (reader variant) -",
"  confirm whether component bins use a stripped stream format.",
"- Field-level decode of object-creation records (70/64/66) beyond the first fields -",
"  needed for a map IMPORTER, not for a reimplementation (a new engine replays the",
"  stream through its own builders).",
""])
src=src[:src.find('## Open items')]+new_open
open(p,'w',encoding='utf-8').write(src)
print('doc updated')
