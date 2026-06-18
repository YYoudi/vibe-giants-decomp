# Ghidra headless postScript: find + decompile the camera/scene functions for faithful 3D porting.
# The decompile export covers only 0x401000-0x551c50 (~40%); camera/renderer-math (0x49xxx/0x5fxxx)
# are missing/misaligned. This finds them by XREF (who calls SetCameraProjection +0x20, who
# references the render-list globals DAT_006313c8) and decompiles their real bodies.
# Run: analyzeHeadless ghidra_projects GiantsRE -process <prog> -postScript ghidra_decomp_camera.py
#@category Giants
from ghidra.app.decompiler import DecompInterface

di = DecompInterface()
di.openProgram(currentProgram)
fm = currentProgram.getFunctionManager()
listing = currentProgram.getListing()

def decomp_at(va):
    addr = toAddr(va)
    fn = fm.getFunctionContaining(addr)
    if not fn:
        fn = fm.getFunctionAt(addr)
    if not fn:
        print("### no function at %s ###" % addr); return
    res = di.decompileFunction(fn, 120, None)
    if res and res.decompileCompleted():
        print("\n========== %s @ %s (size %d) ==========" % (fn.getName(), fn.getEntryPoint(), fn.getBody().getNumAddresses()))
        print(res.getDecompiledFunction().getC())
    else:
        print("### decompile FAILED at %s ###" % addr)

# Candidate camera/renderer-math addresses (CLAUDE.md — some may be misaligned, decompile anyway).
candidates = [
    0x0049a040,  # UpdateActiveCamera (claimed — verify)
    0x005f9d00,  # SetupProjection (projection matrix + depth XOR)
    0x005f9eb0,  # BuildViewMatrix
    0x005fa1a0,  # SetWorldTransform
    0x005f8480,  # AnimateCameraPath
    0x004f7e60,  # BeginScene (ref-counted render stage init)
    0x00522310,  # SceneBegin (object sort + cull + dispatch)
    0x004f3230,  # SetupGame (spawn object classes)
]
for c in candidates:
    try: decomp_at(c)
    except Exception as e: print("ERR %x: %s" % (c, e))
