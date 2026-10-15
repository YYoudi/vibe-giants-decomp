# Ghidra PyGhidra postScript: dump functions + decompilation of gg_dx7r.dll
# args via getScriptArgs: [output_dir]
import os
from ghidra.app.decompiler import DecompInterface, DecompileOptions

out_dir = getScriptArgs()[0]
os.makedirs(out_dir, exist_ok=True)
fm = currentProgram.getFunctionManager()
st = currentProgram.getSymbolTable()

# exports with addresses
exp = {}
for sym in st.getExternalEntryPointIterator():
    exp[sym.getOffset()] = st.getPrimarySymbolAt(sym).getName()

di = DecompInterface()
di.setOptions(DecompileOptions())
di.openProgram(currentProgram)
big = open(os.path.join(out_dir, 'ggdx7_decompiled.c'), 'w', encoding='utf-8')
idx = []
n = 0
it = fm.getFunctions(True)
while it.hasNext():
    fn = it.next()
    if fn.isThunk():
        continue
    ep = fn.getEntryPoint().getOffset()
    name = fn.getName()
    tag = ''
    if ep in exp:
        tag = ' /* EXPORT %s */' % exp[ep]
    res = di.decompileFunction(fn, 60, None)
    c = res.getDecompiledFunction().getC() if res.decompileCompleted() else '// FAIL'
    big.write('/* ===== %s @ 0x%08X ===== */%s\n%s\n\n' % (name, ep, tag, c))
    idx.append('0x%08X %s%s' % (ep, name, tag))
    n += 1
big.close()
open(os.path.join(out_dir, 'ggdx7_index.txt'), 'w').write('\n'.join(idx))
print('DONE %d functions' % n)
