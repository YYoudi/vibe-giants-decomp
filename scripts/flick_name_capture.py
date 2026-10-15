#!/usr/bin/env python3
"""Capture flick_file_load(param_1, param_2=ID, param_3=name*) pairs during gamegauge.

At each pause @0x00443480: dump stack args, read the name string from each pointer-
like arg, record {id, name}, resume. Also auto-resumes any other x32dbg pause
(DLL-entry breaks etc.) so the game keeps running.

Uses the CURRENT MCP protocol (JSON-RPC tools/call + Bearer header) via
scripts/xdbg_call.py:call — the old inline token-in-body client gets 401 silently.
Writes RuntimeLab/logs/traces/flick_id_map.json.
"""
import json, os, re, sys, time

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, 'scripts'))
from xdbg_call import call

BP = 0x00443480

def read_mem(addr, n):
    out = call('ReadMemory', {'address': hex(addr), 'length': n})
    if '[ReadMemory]' not in out:
        return None
    hexes = re.findall(r'^\s*[0-9A-F]+:\s+((?:[0-9A-F]{2} )+)', out, re.M)
    data = bytes(int(h, 16) for line in hexes for h in line.split())
    return data[:n]

def read_str(addr, maxlen=48):
    d = read_mem(addr, maxlen)
    if d is None:
        return None
    z = d.find(b'\0')
    s = d[:z if z >= 0 else maxlen]
    if len(s) >= 3 and all(32 <= b < 127 for b in s):
        return s.decode('latin1')
    return None

def eval_arg(off):
    out = call('EvalExpression', {'expression': '[esp+%d]' % off})
    m = re.search(r'^0x([0-9A-Fa-f]+)', out)
    return int(m.group(1), 16) if m else 0

def main():
    out_path = os.path.join(REPO, 'RuntimeLab', 'logs', 'traces', 'flick_id_map.json')
    pairs = []
    if os.path.exists(out_path):
        pairs = json.load(open(out_path))
        print('resumed with %d existing records' % len(pairs), flush=True)
    t0 = time.time()
    last_hb = 0.0
    while time.time() - t0 < float(sys.argv[1] if len(sys.argv) > 1 else 30) * 60:
        st = call('GetDebugState')
        if time.time() - last_hb > 30:
            print('hb %ds: %s' % (int(time.time() - t0), st.strip().splitlines()[-3:]), flush=True)
            last_hb = time.time()
        if 'isDebugging: false' in st:
            time.sleep(1.0)
            continue
        if 'status: RUNNING' in st:
            time.sleep(0.4)
            continue
        m = re.search(r'currentAddress: (0x[0-9A-Fa-f]+)', st)
        if not m:
            time.sleep(0.4)
            continue
        cur = int(m.group(1), 16)
        if cur != BP:
            call('ExecuteDebuggerCommand', {'command': 'g'})
            time.sleep(0.5)
            continue
        # hit: read stack args
        args = [eval_arg(o) for o in (4, 8, 12, 16)]
        names = {}
        for i, a in enumerate(args):
            if 0x10000 <= a < 0x80000000:
                s = read_str(a)
                if s:
                    names['arg%d' % i] = s
        # resolved filename: ctx(param_1) + *(ctx+0x14) is a name string (sprintf "%s" source)
        if 0x10000 <= args[0] < 0x80000000:
            try:
                out = call('EvalExpression', {'expression': '[[esp+4]+0x14]'})
                m2 = re.search(r'^0x([0-9A-Fa-f]+)', out)
                if m2:
                    namep = (args[0] + int(m2.group(1), 16)) & 0xFFFFFFFF
                    s = read_str(namep)
                    if s:
                        names['ctx_name'] = s
            except Exception:
                pass
        rec = {'t': int(time.time()), 'eip': hex(cur), 'args': [hex(a) for a in args], 'names': names}
        pairs.append(rec)
        json.dump(pairs, open(out_path, 'w'), indent=1)
        print('HIT %d %s %s' % (len(pairs), hex(args[1]), names), flush=True)
        call('ExecuteDebuggerCommand', {'command': 'g'})
        time.sleep(0.2)
    print('done', len(pairs), 'hits')

if __name__ == '__main__':
    main()
