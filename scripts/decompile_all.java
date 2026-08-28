// GiantsRE: decompile EVERY function in the program.
// Args: <out_dir>  -> writes all_decompiled.c (one big stream), index.json,
//                     and stats.txt. Skips thunks/external.
// @category GiantsRE
import java.io.File;
import java.io.PrintWriter;
import java.nio.file.*;
import java.util.*;
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;

public class decompile_all extends GhidraScript {
    public void run() throws Exception {
        String outDir = getScriptArgs()[0];
        long maxVa = getScriptArgs().length > 1 ? Long.parseLong(getScriptArgs()[1].replace("0x", ""), 16) : Long.MAX_VALUE;
        File dir = new File(outDir);
        if (!dir.exists()) dir.mkdirs();

        var fm = currentProgram.getFunctionManager();
        long total = fm.getFunctionCount();
        println("total functions: " + total);

        DecompInterface di = new DecompInterface();
        di.setOptions(new DecompileOptions());
        di.openProgram(currentProgram);
        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();

        PrintWriter big = new PrintWriter(new File(dir, "all_decompiled.c"), "UTF-8");
        StringBuilder idx = new StringBuilder("{\n");
        int done = 0, failed = 0, named = 0, skipped = 0;
        long min = Long.MAX_VALUE, max = Long.MIN_VALUE;
        var fnIt = fm.getFunctions(true);
        while (fnIt.hasNext()) {
            Function fn = fnIt.next();
            if (fn.isThunk() || fn.isExternal()) continue;
            if (fn.getEntryPoint().getOffset() > maxVa) { skipped++; continue; }
            long va = fn.getEntryPoint().getOffset();
            min = Math.min(min, va); max = Math.max(max, va);
            String name = fn.getName();
            boolean isNamed = !(name.startsWith("FUN_"));
            if (isNamed) named++;
            var res = di.decompileFunction(fn, 25, mon);
            String c = res.decompileCompleted() ? res.getDecompiledFunction().getC()
                                                : "// DECOMPILE FAILED\n";
            if (!res.decompileCompleted()) failed++;
            big.printf("/* ===== %s @ 0x%08X ===== */\n%s\n\n", name, va, c);
            idx.append(String.format("\"0x%08X\": {\"name\": \"%s\", \"named\": %s, \"len\": %d},\n",
                                     va, name.replace("\\", "\\\\").replace("\"", ""),
                                     isNamed, c.length()));
            done++;
            if (done % 100 == 0) {
                println(String.format("  %d/%d (failed=%d named=%d)", done, total, failed, named));
                big.flush();
            }
        }
        idx.append("}\n");
        big.close();
        Files.writeString(new File(dir, "index.json").toPath(), idx.toString());
        String stats = String.format(
            "total_nonthunk=%d done=%d failed=%d named=%d (%.1f%%) skipped_gt_maxva=%d va_range=0x%X..0x%X%n",
            done, done, failed, named, 100.0 * named / Math.max(1, done), skipped, min, max);
        Files.writeString(new File(dir, "stats.txt").toPath(), stats);
        println("DONE " + stats);
    }
}
