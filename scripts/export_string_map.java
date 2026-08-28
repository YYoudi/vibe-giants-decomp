// GiantsRE: build function -> referenced-strings map (wave-2 matcher input).
// Args: <out_json>
// @category GiantsRE
import java.io.File;
import java.io.PrintWriter;
import java.util.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.*;
import ghidra.util.task.ConsoleTaskMonitor;

public class export_string_map extends GhidraScript {
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        var fm = currentProgram.getFunctionManager();
        var listing = currentProgram.getListing();
        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();

        // defined strings
        var di = listing.getDefinedData(true);
        Map<Address, String> strings = new LinkedHashMap<>();
        int n = 0;
        while (di.hasNext()) {
            var d = di.next();
            if (d.hasStringValue()) { strings.put(d.getAddress(), d.getValue().toString()); n++; }
        }
        println("defined strings: " + n);

        // ref manager: for each string addr, get references TO it, map to containing fn
        var refMgr = currentProgram.getReferenceManager();
        Map<String, List<String>> fnMap = new LinkedHashMap<>(); // "va" -> strings
        int mi = 0;
        for (var e : strings.entrySet()) {
            Address sa = e.getKey();
            for (Reference r : refMgr.getReferencesTo(sa)) {
                Address from = r.getFromAddress();
                Function fn = fm.getFunctionContaining(from);
                if (fn == null) continue;
                if (fn.isThunk() || fn.isExternal()) continue;
                String key = String.format("0x%08X", fn.getEntryPoint().getOffset());
                fnMap.computeIfAbsent(key, k -> new ArrayList<>()).add(e.getValue());
            }
            mi++;
            if (mi % 500 == 0) println("  strings processed " + mi);
        }

        var p = new PrintWriter(new File(out), "UTF-8");
        p.println("{");
        int i = 0;
        for (var e : fnMap.entrySet()) {
            boolean last = ++i == fnMap.size();
            p.print(" \"" + e.getKey() + "\": " + jsonList(e.getValue()) + (last ? "\n" : ",\n"));
        }
        p.println("}");
        p.close();
        println("functions with strings: " + fnMap.size() + " -> " + out);
    }

    String jsonList(List<String> vals) {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < vals.size(); i++) {
            if (i > 0) sb.append(", ");
            String v = vals.get(i).replace("\\", "\\\\").replace("\"", "\\\"")
                             .replace("\n", "\\n").replace("\r", "").replace("\t", "\\t");
            sb.append("\"").append(v).append("\"");
        }
        return sb.append("]").toString();
    }
}
