#!/usr/bin/env python3
"""Runtime BP capture: polls x64dbg MCP, on each PAUSE at a target BP inside
giants records args ([esp+4..]), return address, then continues.
Writes hits to runtime_hits_log.json (append-friendly full log).

Usage: python scripts/runtime_capture.py [minutes] [bpfile]
bpfile: one hex addr per line (default: ps2_symbols/runtime_bps.txt)
"""
import subprocess, json, time, re, sys, os

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def call(tool, args, timeout=30):
    r = subprocess.run(['python', os.path.join(REPO, 'scripts', 'xdbg_call.py'), tool, json.dumps(args)],
                       capture_output=True, text=True, timeout=timeout)
    return r.stdout

def main():
    minutes = float(sys.argv[1]) if len(sys.argv) > 1 else 20
    bpfile = sys.argv[2] if len(sys.argv) > 2 else os.path.join(REPO, 'ps2_symbols', 'runtime_bps.txt')
    bps = set()
    for line in open(bpfile, encoding='utf-8'):
        s = line.strip().lower().lstrip('0x')
        if s:
            bps.add(s.lstrip('0').rjust(8, '0'))
    log_path = os.path.join(REPO, 'runtime_hits_log.json')
    log = []
    if os.path.exists(log_path):
        log = json.load(open(log_path, encoding='utf-8'))
    seen_at = {}
    t0 = time.time()
    print(f'capturing {len(bps)} bps for {minutes} min', flush=True)
    while time.time() - t0 < minutes * 60:
        st = call('GetDebugState', {})
        if 'status: RUNNING' in st:
            time.sleep(1.0)
            continue
        m = re.search(r'currentAddress: (0x[0-9A-Fa-f]+)', st)
        mod = re.search(r'currentModule: (\S+)', st)
        if not m:
            time.sleep(0.8)
            continue
        a = m.group(1).upper()
        core = a[2:].upper().lstrip('0')
        modname = mod.group(1) if mod else ''
        if modname != 'giants' or core not in bps:
            call('ExecuteDebuggerCommand', {'command': 'g'})
            time.sleep(0.6)
            continue
        addr = '0x' + core.rjust(8, '0')
        now = time.time()
        # same bp may re-hit in a loop: record each hit up to 5 per addr per pass
        if now - seen_at.get(addr, 0) < 1.0:
            call('ExecuteDebuggerCommand', {'command': 'g'})
            time.sleep(0.3)
            continue
        seen_at[addr] = now
        entry = {'addr': addr, 't': int(now), 'args': [], 'ret': None, 'stack': []}
        for off in (4, 8, 12, 16, 20, 24):
            v = call('EvalExpression', {'expression': f'[esp+{off}]'}).strip().split('\n')[0]
            entry['args'].append(v)
        entry['ret'] = call('EvalExpression', {'expression': '[esp]'}).strip().split('\n')[0]
        for i in range(1, 9):
            v = call('EvalExpression', {'expression': f'[esp+{4*i}]'}).strip().split('\n')[0]
            entry['stack'].append(v)
        log.append(entry)
        json.dump(log, open(log_path, 'w'), indent=1)
        print('HIT', addr, 'ret', entry['ret'], flush=True)
        call('ExecuteDebuggerCommand', {'command': 'g'})
        time.sleep(0.4)
    print(f'done, {len(log)} total entries in log', flush=True)

if __name__ == '__main__':
    main()
