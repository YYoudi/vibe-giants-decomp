// GiantsRE: decompile gg_dx7r.dll upcall-failure chain.
// Args: <out_dir>
// @category GiantsRE
import java.io.File;
import java.io.PrintWriter;
import java.util.*;
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.util.task.ConsoleTaskMonitor;

public class gg_dump extends GhidraScript {
    record Anchor(String label, long va) {}

    public void run() throws Exception {
        String outDir = getScriptArgs()[0];
        var fm = currentProgram.getFunctionManager();
        var af = currentProgram.getAddressFactory().getDefaultAddressSpace();

        List<Anchor> anchors = List.of(
            new Anchor("gg_method_null_ret", 0x100025C0L),
            new Anchor("gg_grow_fn", 0x10002410L),
            new Anchor("gg_enum_cb", 0x100010A0L),
            new Anchor("gg_enum_wrapper", 0x10001050L),
            new Anchor("gg_enum_driver", 0x1000D2B0L),
            new Anchor("gg_dev_add", 0x10001300L));

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        var mon = new ConsoleTaskMonitor();
        File out = new File(outDir);
        if (!out.exists()) out.mkdirs();
        for (Anchor an : anchors) {
            Address addr = af.getAddress(an.va());
            Function fn = fm.getFunctionContaining(addr);
            if (fn == null) {
                new ghidra.app.cmd.function.CreateFunctionCmd(addr).applyTo(currentProgram, mon);
                fn = fm.getFunctionContaining(addr);
            }
            if (fn == null) { println("no fn " + an.label()); continue; }
            var res = di.decompileFunction(fn, 120, mon);
            if (!res.decompileCompleted()) { println("fail " + an.label()); continue; }
            try (PrintWriter pw = new PrintWriter(new File(out, "gg_" + an.label() + ".c"), "UTF-8")) {
                pw.println("// gg_dx7r.dll - " + an.label() + String.format(" @ 0x%08X", an.va()));
                pw.print(res.getDecompiledFunction().getC());
            }
            println("ok " + an.label());
        }
    }
}
