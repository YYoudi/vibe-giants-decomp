// ExportVanillaDecompiled.java — Ghidra headless script to export decompiled C
// bodies from the vanilla Giants.exe project. Produces vanilla_decompiled/*.json
// (one per function: addr, name, decompiled, callees, size).
//@category Analysis
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.util.*;

public class ExportVanillaDecompiled extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outDir = "G:/GiantsRE/vanilla_decompiled";
        new File(outDir).mkdirs();

        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        FunctionManager fm = currentProgram.getFunctionManager();
        FunctionIterator fi = fm.getFunctions(true);
        int count = 0;
        while (fi.hasNext() && !monitor.isCancelled()) {
            Function f = fi.next();
            String addr = f.getEntryPoint().toString(false); // no 0x prefix
            // Decompile
            DecompileResults res = decomp.decompileFunction(f, 30, monitor);
            String code = res.decompileCompleted() ? res.getDecompiledFunction().getC() : "";

            // Write JSON: {"addr":"...", "name":"...", "size":N, "decompiled":"..."}
            String name = f.getName();
            int size = (int) f.getBody().getNumAddresses();
            // Escape for JSON
            code = code.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n").replace("\r", "");
            name = name.replace("\\", "\\\\").replace("\"", "\\\"");

            String json = String.format("{\"addr\":\"%s\",\"name\":\"%s\",\"size\":%d,\"decompiled\":\"%s\"}",
                addr, name, size, code);
            // Write to file named by address
            FileWriter fw = new FileWriter(outDir + "/" + addr + ".json");
            fw.write(json);
            fw.close();
            count++;
            if (count % 200 == 0) println("Exported " + count + " functions...");
        }
        decomp.dispose();
        println("DONE: exported " + count + " decompiled functions to " + outDir);
    }
}
