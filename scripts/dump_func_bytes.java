// GiantsRE: dump (addr,size,name,md5full,md5first32) for every non-thunk function.
// Args: <out_csv>. Used to byte-match functions across builds (v1.0 <-> GOG 1.449).
// @category GiantsRE
import java.io.File;
import java.io.PrintWriter;
import java.nio.file.*;
import java.security.MessageDigest;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.*;
import ghidra.util.task.ConsoleTaskMonitor;

public class dump_func_bytes extends GhidraScript {
    static String hex(byte[] b) {
        StringBuilder sb = new StringBuilder(b.length * 2);
        for (byte x : b) sb.append(String.format("%02x", x));
        return sb.toString();
    }

    public void run() throws Exception {
        String out = getScriptArgs()[0];
        var fm = currentProgram.getFunctionManager();
        var mem = currentProgram.getMemory();
        MessageDigest md = MessageDigest.getInstance("MD5");
        PrintWriter w = new PrintWriter(new File(out), "UTF-8");
        w.println("addr,size,name,md5full,md5first32");
        int n = 0, noread = 0;
        var it = fm.getFunctions(true);
        while (it.hasNext()) {
            Function fn = it.next();
            if (fn.isThunk() || fn.isExternal()) continue;
            long size = fn.getBody().getNumAddresses();
            String md5full = "", md5first = "";
            if (size > 0 && size < 0x100000) {
                byte[] data = new byte[(int) size];
                int got = mem.getBytes(fn.getEntryPoint(), data);
                if (got == data.length) {
                    md5full = hex(md.digest(data));
                    byte[] head = new byte[(int) Math.min(32, size)];
                    System.arraycopy(data, 0, head, 0, head.length);
                    md5first = hex(md.digest(head));
                } else noread++;
            }
            w.printf("%X,%d,%s,%s,%s%n", fn.getEntryPoint().getOffset(), size,
                     fn.getName().replace(",", "_"), md5full, md5first);
            n++;
        }
        w.close();
        println("dumped " + n + " functions (no-bytes=" + noread + ") -> " + out);
    }
}
