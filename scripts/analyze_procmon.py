#!/usr/bin/env python3
"""Stream-filter and summarize a Procmon CSV boot capture for Giants.exe.

Usage: python scripts/analyze_procmon.py <big.csv> [outprefix]
Outputs (in RuntimeLab/logs):
  <prefix>_events.csv      chronological Giants.exe events (time,op,path,result)
  <prefix>_summary.txt     files/registry/images touched + counts + tail (stall)
"""
import csv
import io
import os
import sys
from collections import Counter

csv.field_size_limit(10_000_000)


def main():
    src = sys.argv[1]
    prefix = sys.argv[2] if len(sys.argv) > 2 else os.path.splitext(src)[0] + "_giants"
    out_events = prefix + "_events.csv"
    keep = []
    n_total = 0
    with io.open(src, "r", encoding="utf-8-sig", errors="replace", newline="") as f:
        rdr = csv.DictReader(f)
        for row in rdr:
            n_total += 1
            if (row.get("Process Name") or "").lower() == "giants.exe":
                keep.append((row.get("Time of Day", ""), row.get("Operation", ""),
                             row.get("Path", ""), row.get("Result", ""),
                             row.get("Detail", "")[:120]))
    with io.open(out_events, "w", encoding="utf-8", newline="") as f:
        w = csv.writer(f)
        w.writerow(["time", "op", "path", "result", "detail"])
        w.writerows(keep)

    files, keys, images, ops = Counter(), Counter(), Counter(), Counter()
    for _, op, path, res, _d in keep:
        ops[op] += 1
        p = path.lower()
        if op.startswith("reg"):
            keys[path] += 1
        elif "load image" in op.lower():
            images[path] += 1
        else:
            files[path] += 1

    with io.open(prefix + "_summary.txt", "w", encoding="utf-8") as f:
        f.write(f"total rows scanned: {n_total}\nGiants.exe events: {len(keep)}\n\n")
        f.write("== operations ==\n")
        for op, c in ops.most_common(40):
            f.write(f"{c:6d}  {op}\n")
        f.write("\n== registry paths (top 60) ==\n")
        for k, c in keys.most_common(60):
            f.write(f"{c:5d}  {k}\n")
        f.write("\n== images loaded ==\n")
        for k, c in images.most_common():
            f.write(f"{c:3d}  {k}\n")
        f.write("\n== file paths (top 80) ==\n")
        for k, c in files.most_common(80):
            f.write(f"{c:5d}  {k}\n")
        f.write("\n== LAST 60 events (stall point) ==\n")
        for t, op, path, res, d in keep[-60:]:
            f.write(f"{t} {op:28s} {path[:100]} [{res}] {d[:60]}\n")
    print(f"[done] {len(keep)} Giants events of {n_total} -> {out_events} + summary")


if __name__ == "__main__":
    main()
