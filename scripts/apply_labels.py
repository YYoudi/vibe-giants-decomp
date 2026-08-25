#!/usr/bin/env python3
"""Apply the RE database (scripts/re_db.json) as labels/comments in the live
x64dbg session. Idempotent. Run any time — labels persist in the .dd32 database
saved next to the exe (RuntimeLab copy only, never vanilla).

Usage: python scripts/apply_labels.py [--comments]
"""
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xdbg_call import call  # noqa: E402

DB = os.path.join(os.path.dirname(os.path.abspath(__file__)), "re_db.json")


def main():
    mode = "Comment" if "--comments" in sys.argv else "Label"
    db = json.load(open(DB, encoding="utf-8"))
    n = 0
    for section in ("functions", "globals"):
        for addr, info in db.get(section, {}).items():
            name = info["name"] if isinstance(info, dict) else info
            r = call("CommentOrLabelAtAddress",
                     {"address": addr, "value": name, "mode": mode}, timeout=15)
            ok = "error" not in r.lower()
            n += ok
            print(f"[{'ok' if ok else '!!'}] {addr} {name}")
    print(f"[done] {n} {mode}s applied from {DB}")


if __name__ == "__main__":
    main()
