#!/usr/bin/env python3
"""Build the ASSET MANIFEST of the gamegauge cinematic (story4 playlist).

Walks the 53 flicks of the playlist (see CINEMATIC_PIPELINE §7), extracts every
referenced name/asset via the record payloads:
  op 1  -> director {idx, name}
  op 2  -> actor {director_idx, name, slot, type}
  op 4  -> camera {director_idx, node_name, track_name}
  op 13 -> sound id
  op 16 -> GText subtitle name (per string slot)
  op 47 -> global message GText name
Name payloads are file-offsets of NUL-terminated strings INSIDE the .flk file
(the loader mallocs the whole file image; payload offsets are file offsets).

Output: RuntimeLab/logs/traces/story4_manifest.json
"""
import json, os, re, sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, 'tools_spec'))
from flk_decode import decode

BIN = 'G:/Games/Giants/Bin'
OUT = os.path.join(REPO, 'RuntimeLab', 'logs', 'traces', 'story4_manifest.json')

# playlist: ids 0x0D..0x41 = flk_story4_T_square_2..58 (see flick_playlist.json)
pl = json.load(open(os.path.join(REPO, 'RuntimeLab', 'logs', 'traces', 'flick_playlist.json')))
files = [e['file'] for e in pl['entries']]

def cstr(d, off):
    try:
        z = d.index(b'\0', off)
        s = d[off:z].decode('latin1')
        return s if s else None
    except Exception:
        return None

def resolve(d, v):
    if isinstance(v, int) and 0 < v < len(d):
        s = cstr(d, v)
        if s and all(32 <= ord(c) < 127 for c in s):
            return s
    return None

manifest = {}
tot = {'directors': set(), 'actors': set(), 'cameras': set(), 'texts': set(), 'sounds': set()}
for fn in files:
    path = os.path.join(BIN, fn)
    d = open(path, 'rb').read()
    r = decode(d)
    assert r['ok'], fn
    m = {'directors': [], 'actors': [], 'cameras': [], 'texts': [], 'sounds': [],
         'fades': 0, 'ops_count': len(r['records'])}
    seen_texts = []
    for x in r['records']:
        p = x['payload']
        if x['op'] == 1:
            m['directors'].append({'idx': p[0], 'name': resolve(d, p[1])})
        elif x['op'] == 2:
            m['actors'].append({'director': p[0], 'name': resolve(d, p[1]),
                                'slot': p[2], 'type': p[3]})
        elif x['op'] == 4:
            m['cameras'].append({'director': p[0], 'node': resolve(d, p[1]),
                                 'track': resolve(d, p[2])})
        elif x['op'] == 13:
            m['sounds'].append(p[1])
        elif x['op'] == 16:
            s = resolve(d, p[0])
            if s:
                seen_texts.append(s)
        elif x['op'] == 47:
            m['message'] = resolve(d, p[0])
        elif x['op'] == 31:
            m['fades'] += 1
    m['texts'] = seen_texts
    manifest[fn] = m
    tot['directors'] |= {(x['idx'], x['name']) for x in m['directors']}
    tot['actors'] |= {x['name'] for x in m['actors']}
    tot['cameras'] |= {(x['node'], x['track']) for x in m['cameras']}
    tot['texts'] |= set(seen_texts)
    tot['sounds'] |= set(m['sounds'])

summary = {
    'files': len(files),
    'directors': sorted([n for _, n in tot['directors'] if n]),
    'actors': sorted(n for n in tot['actors'] if n),
    'cameras': sorted(f'{n}/{t}' for n, t in tot['cameras'] if t or n),
    'text_names': sorted(tot['texts']),
    'sound_ids': sorted(tot['sounds']),
    'counts': {k: len(v) for k, v in summary_items(tot)} if False else None,
}
del summary['counts']
out = {'summary': summary, 'files': manifest}
json.dump(out, open(OUT, 'w'), indent=1)
print('files:', len(files))
print('directors:', len(summary['directors']), summary['directors'][:10])
print('actors:', len(summary['actors']), summary['actors'])
print('cameras:', summary['cameras'])
print('texts:', len(summary['text_names']), summary['text_names'][:6], '...')
print('sounds:', sorted(summary['sound_ids']))
print('written', OUT)
