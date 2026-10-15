#!/usr/bin/env python3
"""Trace every file open (stream_player_start @ 0x005380E0) during a gamegauge run.

Logs each unique name argument (pointer to NUL string at [esp+4]) with first-seen
timestamp; auto-resumes every pause. Writes RuntimeLab/logs/traces/fileopen_trace.json.
"""
import json, os, re, sys, time

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, 'scripts'))
from xdbg_call import call

BP = 0x005380E0

def read_mem(addr, n):
    out = call('ReadMemory', {'address': hex(addr), 'length': n})
    if '[ReadMemory]' not in out:
        return None
    hexes = re.findall(r'^\s*[0-9A-F]+:\s+((?:[0-9A-F]{2} )+)', out, re.M)
    return bytes(int(h, 16) for line in hexes for h in line.split())[:n]

def read_cstr(addr, maxlen=128):
    d = read_mem(addr, maxlen)
    if not d:
        return None
    z = d.find(b'\0')
    s = d[:z if z >= 0 else maxlen]
    if len(s) >= 2 and all(32 <= b < 127 for b in s):
        return s.decode('latin1')
    return None

def main():
    out_path = os.path.join(REPO, 'RuntimeLab', 'logs', 'traces', 'fileopen_trace.json')
    trace = []
    if os.path.exists(out_path):
        trace = json.load(open(out_path))
        print('resumed with %d existing records' % len(trace), flush=True)
    seen = {r['name'] for r in trace}
    t0 = time.time()
    last_hb = 0.0
    while time.time() - t0 < float(sys.argv[1] if len(sys.argv) > 1 else 10) * 60:
        st = call('GetDebugState')
        if time.time() - last_hb > 30:
            print('hb %ds %s' % (int(time.time()-t0), st.strip().splitlines()[-3:-1]), flush=True)
            last_hb = time.time()
        if 'isDebugging: false' in st:
            print('target gone', flush=True)
            break
        if 'status: RUNNING' in st:
            time.sleep(0.3)
            continue
        m = re.search(r'currentAddress: (0x[0-9A-Fa-f]+)', st)
        if not m:
            time.sleep(0.3)
            continue
        cur = int(m.group(1), 16)
        if cur != BP:
            call('ExecuteDebuggerCommand', {'command': 'g'})
            time.sleep(0.15)
            continue
        out = call('EvalExpression', {'expression': '[esp+4]'})
        mm = re.search(r'^0x([0-9A-Fa-f]+)', out)
        name = None
        if mm:
            name = read_cstr(int(mm.group(1), 16))
        if name and name not in seen:
            seen.add(name)
            trace.append({'t': round(time.time()-t0, 1), 'name': name})
            json.dump(trace, open(out_path, 'w'), indent=1)
            print('#%d %s' % (len(trace), name), flush=True)
        call('ExecuteDebuggerCommand', {'command': 'g'})
        time.sleep(0.02)
    print('done %d unique names' % len(trace))

if __name__ == '__main__':
    main()
