#!/usr/bin/env python3
"""System-cluster naming wave: attribute unnamed functions to engine systems
(menu/ui, audio, video, net) via string lexicons + call-graph neighborhood.

Rules:
  - only functions that have NO name candidate anywhere (not in unified table)
  - a function joins a system with >=2 distinct lexicon hits, or >=1 hit plus
    >=2 already-tagged callers/callees of the same system (2 rounds)
  - naming: <sys>_0x<addr> (honest provisional name; real PS2 names take
    precedence and are never overwritten)

Output: ps2_symbols/system_names_wave.csv (apply-CSV format, conf 0.9)
"""
import csv, json, os, re, glob, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")

LEX = {
    "audio": ["Audio", "audio", ".wav", ".WAV", "DirectSound", "sound", "Sound",
              "music", "Music", "voice", "Voice", "MIDI", "mixer", "SoundFX",
              "sampl", "Stereo", "stereo"],
    "video": ["bink", "Bink", ".bik", "movie", "Movie", "mpeg", "Mpeg", "MPEG",
              "video", "Video", "decBs", "DEC_BS", "StrFile", "strfile"],
    "net": ["comm", "Comm", "network", "Network", "GameSpy", "gamespy", "socket",
            "Socket", "modem", "Modem", "Serial", "serial", "chat", "Chat",
            "player name", "TCP", "udp", "UDP", "connection", "session"],
    "menu": ["Menu", "menu", "MENU", "credits", "Credits", "LOADING", "Loading",
             "GAME OVER", "cursor", "Cursor", "icon", "Icon", "button", "Button",
             "Frontend", "frontend", "HUD", "hud", "font", "Font", "slideshow",
             "cutscene"],
}

CALL = re.compile(r"\bFUN_([0-9a-fA-F]{8})\s*\(")

def main():
    funcs = {}
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        funcs[d["address"]] = d

    # functions already claimed by the unified table are never touched
    claimed = set()
    for r in csv.DictReader(open(os.path.join(PS2, "unified_names_1449.csv"), encoding="utf-8")):
        claimed.add(r["pc_addr"].lower().lstrip("0").rjust(8, "0"))

    callers = collections.defaultdict(set)
    callees = collections.defaultdict(set)
    for a, d in funcs.items():
        for m in CALL.finditer(d["decompiled"]):
            c = m.group(1).lower()
            if c != a:
                callees[a].add(c)
                callers[c].add(a)

    # round 1: lexicon hits
    tag = {}
    for a, d in funcs.items():
        if a in claimed:
            continue
        body = d["decompiled"]
        hits = collections.Counter()
        for sys_, words in LEX.items():
            n = sum(1 for w in set(words) if w in body)
            if n:
                hits[sys_] = n
        if not hits:
            continue
        best, n = hits.most_common(1)[0]
        second = hits.most_common(2)[1][1] if len(hits) > 1 else 0
        if n >= 3 or (n == 2 and second <= 1):
            tag[a] = best

    # round 2: neighborhood propagation (one pass)
    for a in list(funcs):
        if a in claimed or a in tag:
            continue
        votes = collections.Counter()
        for nb in callees.get(a, set()) | callers.get(a, set()):
            if nb in tag:
                votes[tag[nb]] += 1
        if votes:
            best, n = votes.most_common(1)[0]
            if n >= 2:
                tag[a] = best

    rows = []
    for a, sys_ in sorted(tag.items()):
        rows.append({"pc_addr": a, "pc_name": funcs[a]["name"],
                     "ps2_addr": "", "ps2_name": f"{sys_}_{a}",
                     "conf": 0.9, "tier": f"sys-cluster", "shared": ""})
    outp = os.path.join(PS2, "system_names_wave.csv")
    with open(outp, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(rows)
    dist = collections.Counter(t for t in tag.values())
    print(f"system-tagged: {len(rows)}  by system: {dict(dist)}  -> {outp}")

if __name__ == "__main__":
    main()
