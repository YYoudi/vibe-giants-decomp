// GiantsRE: apply pc_ps2_matches_full.csv (>=0.9 rename; else plate comment).
// Args: <pc_ps2_matches_full.csv>
// @category GiantsRE
import java.io.File;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;

public class ghidra_apply_matches extends GhidraScript {
    public void run() throws Exception {
        String csvPath = getScriptArgs()[0];
        var fm = currentProgram.getFunctionManager();
        var af = currentProgram.getAddressFactory().getDefaultAddressSpace();
        var listing = currentProgram.getListing();
        int renamed = 0, commented = 0, missed = 0;
        Pattern p = Pattern.compile("^([0-9a-fA-F]+),[^,]*,[^,]*,([^,]*),([0-9.]+),");
        for (String line : Files.readAllLines(new File(csvPath).toPath())) {
            Matcher m = p.matcher(line);
            if (!m.find()) continue;
            long va = Long.parseLong(m.group(1), 16);
            String name = m.group(2).trim();
            double conf = Double.parseDouble(m.group(3));
            Address addr = af.getAddress(va);
            Function fn = fm.getFunctionContaining(addr);
            if (fn == null) {
                new CreateFunctionCmd(addr).applyTo(currentProgram, monitor);
                fn = fm.getFunctionContaining(addr);
            }
            if (fn == null) { missed++; continue; }
            if (conf >= 0.9) {
                try { fn.setName(name, SourceType.USER_DEFINED); renamed++; continue; }
                catch (Exception ex) { /* fallthrough to comment */ }
            }
            { CodeUnit cu = listing.getCodeUnitAt(addr); if (cu != null) cu.setComment(CodeUnit.PLATE_COMMENT, "PS2 candidate: " + name + " (conf " + conf + ")"); }
                commented++;

        }
        println("matches: renamed=" + renamed + " candidate-commented=" + commented + " no-func=" + missed);
    }
}
