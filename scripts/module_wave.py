#!/usr/bin/env python3
"""Module-attribution naming wave (string-proven, safe):
functions whose decompiled body cites an original source path
("C:\\Giants\\source\\<dir>\\<file>.c") get named <file>_<addr>.
Functions with system-string evidence (tight lexicons, no source-path funcs)
get <sys>_<addr>. Real PS2/unified names always win.

Output: ps2_symbols/module_names_wave.csv (conf 0.9)
"""
import csv, json, os, re, glob, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")

SRC_PATH = re.compile(r'C:[/\\]+Giants[/\\]+source[/\\]+([A-Za-z0-9_]+)[/\\]+([A-Za-z0-9_]+?)\.(?:c|cpp|h)', re.I)

# tight lexicons: system-distinctive words only (no generic gameplay terms)
LEX = {
    "audio": ["DirectSound", "DirectSound", "Audio", "audio", ".wav", ".WAV",
              "soundseq", "SoundFX", "mixer", "MIDI"],
    "video": ["bink", "Bink", ".bik", "mpeg", "Mpeg", "MPEG", "decBs", "DEC_BS",
              "StrFile", "strfile"],
    "net": ["gamespy", "GameSpy", "DirectPlay", "DirectPlay", "socket", "Socket",
            "modem", "Modem", "lobby", "Lobby", "hostname", "Hostname"],
    "menu": ["Frontend", "frontend", "credits", "Credits", "GAME OVER",
             "LOADING", "Loading", "cutscene", "binkw32"],
}

def main():
    funcs = {}
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        funcs[d["address"]] = d

    claimed = set()
    for r in csv.DictReader(open(os.path.join(PS2, "unified_names_1449.csv"), encoding="utf-8")):
        claimed.add(r["pc_addr"].lower().lstrip("0").rjust(8, "0"))
    try:
        for r in csv.DictReader(open(os.path.join(PS2, "module_names_wave.csv"), encoding="utf-8")):
            claimed.add(r["pc_addr"].lower().lstrip("0").rjust(8, "0"))
    except FileNotFoundError:
        pass

    rows, seen_names = [], set()
    def add(a, name, tier):
        if a in claimed or name in seen_names:
            return False
        seen_names.add(name)
        rows.append({"pc_addr": a, "pc_name": funcs[a]["name"], "ps2_addr": "",
                     "ps2_name": name, "conf": 0.9, "tier": tier, "shared": ""})
        return True

    # 1) source-file attribution (string-proven)
    modcount = collections.Counter()
    for a, d in funcs.items():
        ms = SRC_PATH.findall(d["decompiled"])
        if not ms:
            continue
        c = collections.Counter(f"{m[0]}_{m[1]}".lower() for m in ms)
        mod, n = c.most_common(1)[0]
        if add(a, f"{mod}_{a}", "module-srcpath"):
            modcount[mod] += 1

    # 2) system attribution — only funcs with NO source path, >=2 distinct words
    for a, d in funcs.items():
        if a in claimed or any(r["pc_addr"] == a for r in rows):
            continue
        body = d["decompiled"]
        if SRC_PATH.search(body):
            continue
        votes = collections.Counter()
        for sys_, words in LEX.items():
            n = sum(1 for w in set(words) if w in body)
            if n:
                votes[sys_] = n
        if votes:
            best, n = votes.most_common(1)[0]
            others = sum(v for s, v in votes.items() if s != best)
            if n >= 2 and others == 0:
                add(a, f"{best}_{a}", "sys-lexicon")

    outp = os.path.join(PS2, "module_names_wave.csv")
    with open(outp, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(rows)
    dist = collections.Counter(r["tier"] for r in rows)
    print(f"module/system tagged: {len(rows)}  {dict(dist)}")
    print(f"  top modules: {modcount.most_common(10)}")

if __name__ == "__main__":
    main()
