#!/usr/bin/env python3
"""Decompile gg_dx7r.dll from the GGDX7 project into RuntimeLab/ggdx7_decomp."""
import os, sys
os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
import pyghidra
pyghidra.start()
from ghidra.base.project import GhidraProject
from ghidra.app.decompiler import DecompInterface, DecompileOptions

OUT = os.path.join(REPO, 'RuntimeLab', 'ggdx7_decomp')
os.makedirs(OUT, exist_ok=True)
project = GhidraProject.openProject(os.path.join(REPO, 'ghidra_projects_ggdx7'), 'GGDX7', True)
try:
    program = project.openProgram('/', 'gg_dx7r.dll', True)
    fm = program.getFunctionManager()
    st = program.getSymbolTable()
    exp = {}
    for addr in st.getExternalEntryPointIterator():
        s = st.getPrimarySymbol(addr)
        if s: exp[addr.getOffset()] = s.getName()
    di = DecompInterface()
    di.setOptions(DecompileOptions())
    di.openProgram(program)
    big = open(os.path.join(OUT, 'ggdx7_decompiled.c'), 'w', encoding='utf-8')
    idx = []
    n = 0
    it = fm.getFunctions(True)
    while it.hasNext():
        fn = it.next()
        if fn.isThunk():
            continue
        ep = fn.getEntryPoint().getOffset()
        tag = ' /* EXPORT %s */' % exp[ep] if ep in exp else ''
        res = di.decompileFunction(fn, 60, None)
        c = res.getDecompiledFunction().getC() if res.decompileCompleted() else '// FAIL'
        big.write('/* ===== %s @ 0x%08X ===== */%s\n%s\n\n' % (fn.getName(), ep, tag, c))
        idx.append('0x%08X %s%s' % (ep, fn.getName(), tag))
        n += 1
    big.close()
    open(os.path.join(OUT, 'ggdx7_index.txt'), 'w').write('\n'.join(idx))
    print('DONE', n, 'functions', len(exp), 'exports')
finally:
    project.close()
