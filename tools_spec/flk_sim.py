#!/usr/bin/env python3
"""Golden execution trace of a FLK under the gamegauge model (fixed-step 1/60).

Simulates FLK_FlickProcess over a .flk (documented semantics: MISSION_VM.md
MAJ 3/4/5 + ops 9/10 runtime-decoded 2026-10-15):
  - lazy cursor: instant ops chain within a frame; op 9/10 HOLD the cursor
  - op 9  = WAIT payload[0] frames (1 hud icon added per held frame; the
    parked counter persists across frames for a given cursor position)
  - op 10 = same with absolute icon count (unused in story4)
  - op 5 / op 52 (0x34) = frame-terminal (execute, return; cursor after them)
  - time flick+0x2c advances dt=1/60 per frame (gamegauge fixed-step)
Output: per-frame executed-op trace -> JSON golden oracle for the Rust
interpreter's headless unit test.
"""
import json, os, struct, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, 'tools_spec'))
from flk_decode import decode

DT = 1.0 / 60.0

def f32(v):
    return struct.unpack('<f', struct.pack('<I', v & 0xFFFFFFFF))[0]

def simulate(path, max_frames=6000):
    d = open(path, 'rb').read()
    r = decode(d)
    assert r['ok']
    recs = r['records']
    i = 0
    t = 0.0
    parked = {}          # record index -> frames parked so far
    frames = []
    done = False
    for frame in range(max_frames):
        t += DT
        ops_now = []
        while i < len(recs):
            x = recs[i]
            op, p = x['op'], x['payload']
            if op == 9:                       # WAIT payload[0] frames
                need = p[0] if p else 0
                done_n = parked.get(i, 0)
                if done_n < need:
                    parked[i] = done_n + 1
                    ops_now.append({'op': 9, 'hold': done_n + 1, 'of': need})
                    break
                ops_now.append({'op': 9, 'released_after': need})
                del parked[i]
                i += 1
                continue
            if op == 10:
                ops_now.append({'op': 10, 'assumption': 'unused-in-story4'})
                i += 1
                continue
            if op in (5, 52):                 # 52 = 0x34 terminal
                ops_now.append({'op': op, 'terminal': True})
                i += 1
                done = True
                break
            entry = {'op': op}
            if op in (7, 31):
                entry['target'] = round(f32(p[0]), 5) if p else None
                entry['dur'] = round(f32(p[1]), 5) if len(p) > 1 else None
            elif op in (26, 50, 51):
                entry['value'] = round(f32(p[0]), 5) if p else None
            elif op == 16:
                entry['text_off'] = p[0] if p else None
            ops_now.append(entry)
            i += 1
        frames.append({'frame': frame, 'time': round(t, 5), 'ops': ops_now})
        if done or i >= len(recs):
            break
    return {'file': os.path.basename(path), 'records': len(recs),
            'frames': len(frames), 'end_time': round(t, 5),
            'assumptions': ['op 9 hold = payload[0] frames (1 icon/frame, persistent)',
                            'op 10 unused in story4',
                            'ops 5/0x34 frame-terminal'],
            'trace': frames}

if __name__ == '__main__':
    src = sys.argv[1] if len(sys.argv) > 1 else 'G:/Games/Giants/Bin/flk_story4_T_square_2.bin'
    out = sys.argv[2] if len(sys.argv) > 2 else os.path.join(
        REPO, 'RuntimeLab', 'logs', 'traces', 'flk_sim_T_square_2.json')
    res = simulate(src)
    json.dump(res, open(out, 'w'), indent=1)
    print('records:', res['records'], 'frames:', res['frames'],
          'end_time:', res['end_time'], '(%.1fs)' % res['end_time'])
    segs = [(f['frame'], o) for f in res['trace'] for o in f['ops']
            if o.get('op') == 9 and 'released_after' in o]
    print('released waits:', segs)
    print('written', out)
