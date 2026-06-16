// Ghidra headless export (Java GhidraScript) — reliable without PyGhidra.
// Emits one JSON object per line (JSONL): addr, name, size, callees, strings, fp.
//@category version_bridge
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ExportFunctions extends GhidraScript {
    static final String OUT_DEFAULT = "G:\\GiantsRE\\version_bridge\\vanilla_functions.jsonl";

    String esc(String s){
        if(s==null) s="";
        StringBuilder b=new StringBuilder();
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            switch(c){
                case '"': b.append("\\\""); break;
                case '\\': b.append("\\\\"); break;
                case '\n': b.append("\\n"); break;
                case '\r': break;
                case '\t': b.append("\\t"); break;
                default:
                    if(c<0x20) b.append(String.format("\\u%04x",(int)c));
                    else b.append(c);
            }
        }
        return b.toString();
    }
    String arr(TreeSet<String> set){
        StringBuilder sb=new StringBuilder("[");
        boolean first=true;
        for(String x:set){ if(!first)sb.append(","); sb.append("\"").append(esc(x)).append("\""); first=false; }
        return sb.append("]").toString();
    }

    @Override
    public void run() throws Exception {
        String out = (getScriptArgs().length > 0) ? getScriptArgs()[0] : OUT_DEFAULT;
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();
        Listing listing = currentProgram.getListing();
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out),"UTF-8"));
        int n=0;
        FunctionIterator it = fm.getFunctions(true);
        while(it.hasNext()){
            Function fn = it.next();
            AddressSetView body = fn.getBody();
            long size = body.getNumAddresses();
            TreeSet<String> callees = new TreeSet<String>();
            TreeSet<String> strings = new TreeSet<String>();
            StringBuilder fp = new StringBuilder();
            InstructionIterator ii = listing.getInstructions(body, true);
            int cnt=0;
            while(ii.hasNext() && cnt<6000){
                Instruction ins = ii.next();
                fp.append(ins.getMnemonicString()).append(' ');
                Address a = ins.getAddress();
                for(Reference r : rm.getReferencesFrom(a)){
                    RefType rt = r.getReferenceType();
                    if(rt.isCall()){ callees.add(r.getToAddress().toString()); }
                    else if(rt.isData() || rt.isRead()){
                        Data d = listing.getDataAt(r.getToAddress());
                        if(d!=null){
                            String dtn = d.getDataType().getName().toLowerCase();
                            if(dtn.contains("string") || dtn.contains("char") || dtn.contains("cstring")){
                                Object v = d.getValue();
                                if(v!=null){
                                    String s = v.toString();
                                    if(s.length()>=4) strings.add(s);
                                }
                            }
                        }
                    }
                }
                cnt++;
            }
            StringBuilder sb=new StringBuilder();
            sb.append("{\"addr\":\"").append(fn.getEntryPoint().toString()).append('"');
            sb.append(",\"name\":\"").append(esc(fn.getName())).append('"');
            sb.append(",\"size\":").append(size);
            sb.append(",\"callees\":").append(arr(callees));
            sb.append(",\"strings\":").append(arr(strings));
            // fp: first 64 mnemonics (relocation-invariant fingerprint), capped length
            String fps = fp.toString(); if(fps.length()>400) fps=fps.substring(0,400);
            sb.append(",\"fp\":\"").append(esc(fps)).append("\"}");
            pw.println(sb.toString());
            n++;
        }
        pw.close();
        println("EXPORTED "+n+" functions -> "+OUT);
    }
}
