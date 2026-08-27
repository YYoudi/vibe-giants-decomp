# Ghidra (Jython) post-script: apply pc_ps2_matches_full.csv.
#  conf>=0.9  -> real function name (PS2 name)
#  conf< 0.9  -> plate comment "PS2 candidate: <name> (conf x)" (draft tier)
# Args: <pc_ps2_matches_full.csv>
# @category GiantsRE
import csv
from ghidra.program.model.symbol import SourceType
from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.util.task import ConsoleTaskMonitor

ARGS = getScriptArgs()
CSV_PATH = ARGS[0]

fm = currentProgram.getFunctionManager()
af = currentProgram.getAddressFactory().getDefaultAddressSpace()
listing = currentProgram.getListing()
mon = ConsoleTaskMonitor()

renamed = commented = missed = 0
with open(CSV_PATH) as f:
    for row in csv.DictReader(f):
        va = int(row["pc_addr"], 16)
        name = row["ps2_name"]
        conf = float(row["conf"])
        addr = af.getAddress(va)
        fn = fm.getFunctionContaining(addr)
        if fn is None:
            cmd = CreateFunctionCmd(addr)
            cmd.applyTo(currentProgram, mon)
            fn = fm.getFunctionContaining(addr)
        if fn is None:
            missed += 1
            continue
        if conf >= 0.9:
            try:
                fn.setName(name, SourceType.USER_DEFINED)
                renamed += 1
                continue
            except Exception:
                pass
        plate = listing.setPlate(addr, "PS2 candidate: %s (conf %.2f)" % (name, conf))
        if plate:
            commented += 1
print("matches: renamed=%d candidate-commented=%d no-func=%d" % (renamed, commented, missed))
