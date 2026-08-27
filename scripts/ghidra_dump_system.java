// GiantsRE: apply system names + decompile anchors. Args: <names.json> <outDir>
// @category GiantsRE
import java.io.File;
import java.io.PrintWriter;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;

public class ghidra_dump_system extends GhidraScript {
    record Anchor(String label, long va) {}

    public void run() throws Exception {
        String[] a = getScriptArgs();
        String jsonPath = a[0];
        String outDir = a[1];

        Map<Long, String> names = new LinkedHashMap<>();
        Matcher m = Pattern.compile("\"(0x[0-9a-fA-F]+)\"\\s*:\\s*\"([^\"]+)\"")
                           .matcher(Files.readString(new File(jsonPath).toPath()));
        while (m.find()) names.put(Long.parseLong(m.group(1).substring(2), 16), m.group(2));
        println("names loaded: " + names.size());

        var fm = currentProgram.getFunctionManager();
        var af = currentProgram.getAddressFactory().getDefaultAddressSpace();
        int applied = 0, created = 0;
        for (var e : names.entrySet()) {
            Address addr = af.getAddress(e.getKey());
            Function fn = fm.getFunctionContaining(addr);
            if (fn == null) {
                new CreateFunctionCmd(addr).applyTo(currentProgram, monitor);
                fn = fm.getFunctionContaining(addr);
                if (fn != null) created++;
            }
            if (fn != null && (fn.getName().startsWith("FUN_") || fn.getName().startsWith("thunk_"))) {
                fn.setName(e.getValue(), SourceType.USER_DEFINED);
                applied++;
            }
        }
        println("names applied=" + applied + " created=" + created);

        List<Anchor> anchors = List.of(
            new Anchor("cd_check", 0x53AE80L),
            new Anchor("cd_monitor_set_valid", 0x523370L),
            new Anchor("BinFileRead", 0x53A090L),
            new Anchor("gzp_block_read", 0x53B490L),
            new Anchor("gzp_open_parse_toc", 0x53B9B0L),
            new Anchor("gzp_close_free", 0x53BB50L),
            new Anchor("mem_alloc_tagged", 0x53C810L),
            new Anchor("mem_free_tagged", 0x53C5C0L),
            new Anchor("gti_terrain_load", 0x476D40L),
            new Anchor("gtext_load", 0x510D660L),
            new Anchor("gtext_lookup", 0x510D7F0L),
            new Anchor("bin_load_1a0002e5", 0x4B7C50L),
            new Anchor("world_files_validate", 0x4F4070L),
            new Anchor("video_init_upcall_site_fn", 0x432F00L),
            new Anchor("renderer_load_caller_fn", 0x51EB00L),
            new Anchor("abx_load_region", 0x4BA700L));

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        File out = new File(outDir);
        if (!out.exists()) out.mkdirs();
        int ok = 0, fail = 0;
        for (Anchor an : anchors) {
            Address addr = af.getAddress(an.va());
            Function fn = fm.getFunctionContaining(addr);
            if (fn == null) { println("no function at 0x" + Long.toHexString(an.va()) + " (" + an.label() + ")"); fail++; continue; }
            var res = di.decompileFunction(fn, 120, monitor);
            if (res.decompileCompleted()) {
                String c = res.getDecompiledFunction().getC();
                File f = new File(out, String.format("%s_0x%08X.c", an.label(), an.va()));
                try (PrintWriter pw = new PrintWriter(f, "UTF-8")) {
                    pw.println("// GiantsRE system layer - " + an.label());
                    pw.println(String.format("// VA 0x%08X (ghidra name was %s)", an.va(), fn.getName()));
                    pw.println("// provenance: runtime anchors in scripts/re_db.json + PS2 symbols");
                    pw.println();
                    pw.println(c);
                }
                ok++;
                println("decompiled " + an.label());
            } else { println("decompile FAILED " + an.label()); fail++; }
        }
        println("decompile ok=" + ok + " fail=" + fail);
    }
}
