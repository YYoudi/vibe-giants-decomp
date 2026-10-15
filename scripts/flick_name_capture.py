#!/usr/bin/env python3
"""Capture flick_file_load(param_1, param_2=ID, param_3=name*) pairs during gamegauge.
At each pause @0x00443480: dump stack args, read the name string from each pointer-
like arg, record {id, name}, resume. Writes RuntimeLab/logs/traces/flick_id_map.json.
"""
import json, re, os, sys, time, urllib.request

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
cfg = json.load(open(r'G:/Tools/x64dbg/release/x32/mcp_config.json'))
TOKEN = cfg['AuthToken']
BP = 0x00443480

def call(tool, args=None, timeout=15):
    body = json.dumps({'token': TOKEN, 'tool': tool, 'arguments': args or {}})
    req = urllib.request.Request('http://127.0.0.1:9095/messages', data=body.encode(),
                                 headers={'Content-Type': 'application/json'})
    try:
        return urllib.request.urlopen(req, timeout=timeout).read().decode()
    except Exception as e:
        return 'ERR %s' % e

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

def main():
    out_path = os.path.join(REPO, 'RuntimeLab', 'logs', 'traces', 'flick_id_map.json')
    pairs = []
    t0 = time.time()
    while time.time() - t0 < float(sys.argv[1] if len(sys.argv) > 1 else 30) * 60:
        st = call('GetDebugState')
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
            time.sleep(0.3)
            continue
        # hit: read stack args
        args = []
        for off in (4, 8, 12, 16):
            v = call('EvalExpression', {'expression': '[esp+%d]' % off})
            mm = re.search(r'(0x[0-9A-Fa-f]+)', v)
            args.append(int(mm.group(1), 16) if mm else 0)
        names = {}
        for i, a in enumerate(args):
            if 0x400000 <= a < 0x80000000:
                s = read_str(a)
                if s:
                    names['arg%d' % i] = s
        rec = {'t': int(time.time()), 'args': [hex(a) for a in args], 'names': names}
        pairs.append(rec)
        json.dump(pairs, open(out_path, 'w'), indent=1)
        print('HIT', hex(args[1]), names, flush=True)
        call('ExecuteDebuggerCommand', {'command': 'g'})
        time.sleep(0.2)
    print('done', len(pairs), 'hits')

if __name__ == '__main__':
    main()
