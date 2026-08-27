# Ghidra (Jython) post-script: apply GiantsRE system names + decompile anchors.
# Args: <system_names.json> <out_dir>
# @category GiantsRE
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

ARGS = getScriptArgs()
JSON_PATH = ARGS[0]
OUT_DIR = ARGS[1]

import json
names = json.load(open(JSON_PATH))

fm = currentProgram.getFunctionManager()
af = currentProgram.getAddressFactory().getDefaultAddressSpace()

# --- apply function names (only where no function yet -> create at VA) ---
applied = created = 0
for va_s, name in names.items():
    va = int(va_s, 16)
    addr = af.getAddress(va)
    fn = fm.getFunctionContaining(addr)
    if fn is None:
        try:
            CreateFunctionCmd = None  # not imported; fallback: name the address
        except Exception:
            pass
        # create function via FunctionManager API
        try:
            from ghidra.app.cmd.function import CreateFunctionCmd
            cmd = CreateFunctionCmd(addr)
            cmd.applyTo(currentProgram, ConsoleTaskMonitor())
            fn = fm.getFunctionContaining(addr)
            if fn:
                created += 1
        except Exception:
            pass
    if fn is not None:
        cur = fn.getName()
        if cur.startswith(('FUN_', 'thunk_')) or 'nullsub' in cur:
            try:
                fn.setName(name, SourceType.USER_DEFINED)
                applied += 1
            except Exception:
                pass
print("names applied=%d created=%d" % (applied, created))

# --- decompile anchor list ---
ANCHORS = [
    ("cd_check", 0x53AE80),
    ("cd_monitor_set_valid", 0x523370),
    ("vfs_fileread_load", 0x53A090),
    ("gzp_block_read", 0x53B490),
    ("gzp_open_parse_toc", 0x53B9B0),
    ("gzp_close_free", 0x53BB50),
    ("mem_alloc_tagged", 0x53C810),
    ("mem_free_tagged", 0x53C5C0),
    ("gti_terrain_load", 0x476D40),
    ("gtext_load", 0x510D660),
    ("gtext_lookup", 0x510D7F0),
    ("bin_load_1a0002e5", 0x4B7C50),
    ("world_files_validate", 0x4F4070),
    ("video_init_upcall_site_fn", 0x432F00),
    ("renderer_load_caller_fn", 0x51EB00),
    ("abx_load_region", 0x4BA700),
]
if not os.path.exists(OUT_DIR):
    os.makedirs(OUT_DIR)

di = DecompInterface()
di.openProgram(currentProgram)
mon = ConsoleTaskMonitor()
ok = fail = 0
for label, va in ANCHORS:
    addr = af.getAddress(va)
    fn = fm.getFunctionContaining(addr)
    if fn is None:
        print("no function at %s (%s)" % (hex(va), label))
        fail += 1
        continue
    res = di.decompileFunction(fn, 120, mon)
    if res.decompileCompleted():
        c = res.getDecompiledFunction().getC()
        hdr = ("// GiantsRE system layer — %s\n// VA 0x%08X  (ghidra name was %s)\n"
               "// provenance: runtime anchors in scripts/re_db.json + PS2 symbols\n\n"
               % (label, va, fn.getName()))
        path = os.path.join(OUT_DIR, "%s_0x%08X.c" % (label, va))
        f = open(path, "w")
        f.write(hdr + c)
        f.close()
        ok += 1
        print("decompiled %s -> %s" % (label, path))
    else:
        print("decompile FAILED %s" % label)
        fail += 1
print("decompile ok=%d fail=%d" % (ok, fail))
