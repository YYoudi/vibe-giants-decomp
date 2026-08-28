// @category GiantsRE
import ghidra.app.script.GhidraScript;
public class gog144_count extends GhidraScript {
    public void run() throws Exception {
        var fm = currentProgram.getFunctionManager();
        long total = fm.getFunctionCount();
        long named = 0;
        var it = fm.getFunctions(true);
        while (it.hasNext()) {
            var f = it.next();
            if (!f.getName().startsWith("FUN_") && !f.getName().startsWith("thunk_")) named++;
        }
        println("TOTAL=" + total + " NAMED=" + named + " IMG=" + currentProgram.getImageBase());
    }
}
