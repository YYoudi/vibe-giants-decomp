#!/usr/bin/env python3
"""Parallel full-decompilation export: splits the function list across N
worker processes (each opens the GOG144 project READ-ONLY with its own JVM),
decompiles its shard, and the parent merges shards in address order.

Same outputs as export_decomp_pyghidra.py (all_decompiled.c, index.json,
stats.txt). ~N x faster on a multi-core box.

Usage: python scripts/export_decomp_parallel.py [out_dir] [workers=4]
"""
import json, os, subprocess, sys, time

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "decompiled", "gog144_full")
WORKERS = int(sys.argv[2]) if len(sys.argv) > 2 else 4
os.makedirs(OUT, exist_ok=True)

def worker_cmd(lo, hi, shard):
    """Run one shard: functions with lo <= addr < hi."""
    return [sys.executable, os.path.join(REPO, "scripts", "_export_shard.py"),
            OUT, lo, hi, shard]

def main():
    t0 = time.time()
    # 1) function list (address order) from the last index
    idx = json.load(open(os.path.join(OUT, "index.json"), encoding="utf-8"))
    addrs = sorted(int(a, 16) for a in idx)
    # shard bounds: with maxVa parameter, reuse _export_shard via [lo,hi)
    n = len(addrs)
    step = (n + WORKERS - 1) // WORKERS
    procs = []
    shards = []
    for w in range(WORKERS):
        lo = addrs[w * step]
        hi = addrs[min((w + 1) * step, n - 1)] + 1
        shard = os.path.join(OUT, f"_shard_{w}.json")
        shards.append(shard)
        logw = open(os.path.join(OUT, f"_shard_{w}.log"), "w")
        procs.append(subprocess.Popen(worker_cmd(hex(lo), hex(hi), os.path.abspath(shard)),
                                      stdout=logw, stderr=subprocess.STDOUT, cwd=REPO))
        print(f"worker {w}: [0x{lo:X}, 0x{hi:X})  pid={procs[-1].pid}", flush=True)
    fails = 0
    for w, p in enumerate(procs):
        if p.wait() != 0:
            fails += 1
            print(f"worker {w} FAILED rc={p.returncode}")
    if fails:
        sys.exit(f"{fails} shard workers failed — fallback to serial export")

    # 2) merge in address order
    entries = []
    for shard in shards:
        entries.extend(json.load(open(shard, encoding="utf-8")))
    entries.sort(key=lambda e: e["addr"])
    done = failed = named = 0
    vmin, vmax = 1 << 62, 0
    with open(os.path.join(OUT, "all_decompiled.c"), "w", encoding="utf-8") as big:
        idxo = {}
        for e in entries:
            va, name, c = e["addr"], e["name"], e["c"]
            vmin, vmax = min(vmin, va), max(vmax, va)
            ok = not c.startswith("// DECOMPILE FAILED")
            if not ok:
                failed += 1
            if not name.startswith("FUN_"):
                named += 1
            big.write(f"/* ===== {name} @ 0x{va:08X} ===== */\n{c}\n\n")
            idxo[f"0x{va:08X}"] = {"name": name, "named": ok and not name.startswith("FUN_"), "len": len(c)}
            done += 1
    json.dump(idxo, open(os.path.join(OUT, "index.json"), "w", encoding="utf-8"), indent=1)
    for shard in shards:
        os.remove(shard)
    stats = (f"total_nonthunk={done} done={done} failed={failed} named={named} "
             f"({100.0*named/max(1,done):.1f}%) skipped_gt_maxva=0 va_range=0x{vmin:X}..0x{vmax:X}\n")
    open(os.path.join(OUT, "stats.txt"), "w", encoding="utf-8").write(stats)
    print(f"DONE {stats.strip()} in {time.time()-t0:.0f}s ({WORKERS} workers)")

if __name__ == "__main__":
    main()
