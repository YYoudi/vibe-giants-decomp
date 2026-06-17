import re, sys
syms = [l.strip().rstrip("'") for l in open('undef.txt') if l.strip()]
syms = [s for s in syms if s]
out = []
out.append('// Generated .BIN loader (FUN_004b7c50) link stubs. Loader is DORMANT.')
out.append('extern "C" {')
for s in syms:
    if s.startswith('_DAT_') or s.startswith('DAT_'):
        out.append('uint32_t ' + s + ' = 0;')
for s in syms:
    if s.startswith('FUN_'):
        out.append('void ' + s + '() {}')
def decode(name):
    base = re.sub(r'_00[0-9a-f]+$', '', name)
    if base.startswith('s_'): base = base[2:]
    txt = base.replace('__', '_').replace('_', ' ')
    txt = txt.replace('\\', '/')  # no backslash in C string
    txt = txt.replace('"', '')   # no dquote
    return txt
for s in syms:
    if s.startswith('s_'):
        out.append('extern const char ' + s + '[] = "' + decode(s) + '";')
out.append('} // extern "C"')
open('src_vanilla/_bin_stubs_gen.cpp', 'w').write('\n'.join(out) + '\n')
print('OK', len(syms))
