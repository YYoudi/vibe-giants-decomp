// GiantsRE: dump {function_entry -> [string literals]} for the PS2 ELF
// (MIPS) using Ghidra's own string definition + reference analysis.
// Args: <out_json>
// @category GiantsRE
import java.io.File;
import java.io.PrintWriter;
import java.util.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.RefType;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.data.StringDataInstance;
import ghidra.util.task.ConsoleTaskMonitor;

public class ps2_dump_string_refs extends GhidraScript {
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        var listing = currentProgram.getListing();
        var fm = currentProgram.getFunctionManager();

        // 1) defined strings: addr -> text
        var strmap = new LinkedHashMap<String, String>();
        var it = listing.getDefinedData(true);
        int nstr = 0;
        while (it.hasNext()) {
            Data d = it.next();
            if (!d.hasStringValue()) continue;
            String v = d.getValue().toString();
            if (v.length() >= 4) {
                strmap.put(d.getAddress().toString(), v);
                nstr++;
            }
        }
        println("defined strings: " + nstr);

        // 2) references: string addr -> containing function of referer
        var fmap = new LinkedHashMap<String, LinkedHashSet<String>>();
        var rit = currentProgram.getReferenceManager().getReferenceIterator(monitor);
        int nref = 0;
        while (rit.hasNext()) {
            Reference r = rit.next();
            Address to = r.getToAddress();
            String s = strmap.get(to.toString());
            if (s == null) continue;
            Function fn = fm.getFunctionContaining(r.getFromAddress());
            if (fn == null || fn.isThunk() || fn.isExternal()) continue;
            fmap.computeIfAbsent(fn.getEntryPoint().toString(), k -> new LinkedHashSet<>()).add(s);
            nref++;
        }
        println("string refs into functions: " + nref + " across " + fmap.size() + " functions");

        PrintWriter w = new PrintWriter(new File(out), "UTF-8");
        w.println("{");
        boolean first = true;
        for (var e : fmap.entrySet()) {
            if (!first) w.println(",");
            first = false;
            w.print("  \"" + e.getKey() + "\": " + jsonArr(e.getValue()));
        }
        w.println("\n}");
        w.close();
        println("wrote " + out);
    }

    static String esc(String s) {
        StringBuilder b = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == '"' || c == '\\') b.append('\\').append(c);
            else if (c == '\n') b.append("\\n");
            else if (c == '\t') b.append("\\t");
            else if (c < 0x20) { /* drop */ }
            else b.append(c);
        }
        return b.toString();
    }

    static String jsonArr(LinkedHashSet<String> v) {
        StringBuilder b = new StringBuilder("[");
        boolean f = true;
        for (String s : v) {
            if (!f) b.append(",");
            f = false;
            b.append("\"").append(esc(s)).append("\"");
        }
        return b.append("]").toString();
    }
}
