# Ghidra headless export script (Jython 2.7).
# Exports per-function data for cross-version matching:
#   addr, name, size, callees (call targets), referenced strings, mnemonic fingerprint.
# Output: <OUT> JSON file (one object per function). Relocation-invariant fingerprint
# so unchanged functions match across builds despite shifted addresses.
# @category version_bridge
#@author giants-re

import json, os

OUT = r"G:\GiantsRE\version_bridge\vanilla_functions.json"

prog = currentProgram
fm = prog.getFunctionManager()
rm = prog.getReferenceManager()
listing = prog.getListing()

results = []
nfunc = 0
for fn in fm.getFunctions(True):
    body = fn.getBody()
    size = int(body.getNumAddresses())
    callees = set()
    strings = set()
    mnems = []
    insts = listing.getInstructions(body, True)
    inst = insts.next() if insts is not None else None
    count = 0
    while inst is not None and count < 4000:
        mnems.append(inst.getMnemonicString())
        addr = inst.getAddress()
        for ref in rm.getReferencesFrom(addr):
            rt = ref.getReferenceType()
            try:
                if rt.isCall():
                    callees.add(ref.getToAddress().toString())
                elif rt.isData() or rt.isRead():
                    to = ref.getToAddress()
                    d = listing.getDataAt(to)
                    if d is not None:
                        dtname = d.getDataType().getName().lower()
                        if "string" in dtname or "char" in dtname or "cstring" in dtname:
                            val = d.getValue()
                            if val is not None:
                                s = str(val)
                                if len(s) >= 4:
                                    strings.add(s)
            except:
                pass
        inst = insts.next()
        count += 1
    results.append({
        "addr": fn.getEntryPoint().toString(),
        "name": fn.getName(),
        "size": size,
        "callees": sorted(callees),
        "strings": sorted(strings),
        "fp": " ".join(mnems),
    })
    nfunc += 1

with open(OUT, "w") as f:
    json.dump(results, f)
print("EXPORTED %d functions -> %s" % (nfunc, OUT))
