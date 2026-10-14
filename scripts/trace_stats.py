#!/usr/bin/env python3
"""Aggregate runtime_hits_log.json into a normalized trace report.
Usage: python scripts/trace_stats.py [hits.json]
Outputs: per-function counts, timeline, arg histograms; writes
RuntimeLab/logs/traces/trace_report.json + prints a summary.
"""
import json, sys, os, collections, datetime

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
src = sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, 'runtime_hits_log.json')

names = json.load(open(os.path.join(REPO, 'graph_names.json')))
hits = json.load(open(src))
for h in hits:
    h['fn'] = names.get(h['addr'].lower(), names.get(h['addr'], h['addr']))

span = (hits[-1]['t'] - hits[0]['t']) if len(hits) > 1 else 0
by_fn = collections.Counter(h['fn'] for h in hits)
timeline = [(datetime.datetime.fromtimestamp(h['t']).strftime('%H:%M:%S'), h['fn']) for h in hits]

# arg value histograms per function (top 8)
argh = {}
for h in hits:
    a = h['args'][0] if h['args'] else '?'
    argh.setdefault(h['fn'], collections.Counter())[a.split(' ')[0]] += 1

report = {
    'source': src, 'hits': len(hits), 'span_s': span,
    'start': datetime.datetime.fromtimestamp(hits[0]['t']).isoformat() if hits else None,
    'per_function': dict(by_fn),
    'arg0_top': {k: v.most_common(8) for k, v in argh.items()},
}
os.makedirs(os.path.join(REPO, 'RuntimeLab', 'logs', 'traces'), exist_ok=True)
out = os.path.join(REPO, 'RuntimeLab', 'logs', 'traces', 'trace_report.json')
json.dump(report, open(out, 'w'), indent=1)
print(f"hits={len(hits)} span={span}s -> {out}")
for fn, c in by_fn.most_common():
    print(f"  {fn}: {c}")
if span:
    print("first/last:", timeline[0], timeline[-1])
