// GiantsRE: decompile gg_dx7r crash chain (+0x28BB site).
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

public class gg_dump2 extends GhidraScript {
    record Anchor(String label, long va) {}

    public void run() throws Exception {
        String outDir = getScriptArgs()[0];
        var fm = currentProgram.getFunctionManager();
        var af = currentProgram.getAddressFactory().getDefaultAddressSpace();
        List<Anchor> anchors = List.of(
            new Anchor("crash28BB_site", 0x100028BBL),
            new Anchor("crash282A", 0x1000282AL),
            new Anchor("crash2780", 0x10002780L));
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        var mon = new ConsoleTaskMonitor();
        for (Anchor an : anchors) {
            Address addr = af.getAddress(an.va());
            Function fn = fm.getFunctionContaining(addr);
            if (fn == null) { println("no fn " + an.label()); continue; }
            var res = di.decompileFunction(fn, 120, mon);
            if (!res.decompileCompleted()) { println("fail " + an.label()); continue; }
            try (PrintWriter pw = new PrintWriter(new File(outDir, "gg_" + an.label() + ".c"), "UTF-8")) {
                pw.println("// gg_dx7r.dll - " + an.label() + String.format(" @ 0x%08X", an.va()));
                pw.print(res.getDecompiledFunction().getC());
            }
            println("ok " + an.label() + " -> fn " + fn.getName() +
                    String.format(" @ 0x%08X", fn.getEntryPoint().getOffset()));
        }
    }
}
