#!/usr/bin/env python3
"""TASK-016: gamegauge harness stability — 3 sequential runs of run_gauge.bat.

Per run: hash fps.txt BEFORE and AFTER (the game writes it itself — we never
touch G:\\Games\\Giants), one PrintWindow screenshot mid-run, process-exit
detection. Everything lands in RuntimeLab/runs/<timestamp>/ with a manifest.

Read-only on the game install; run it from repo root:
    python scripts/harness_stability.py [n_runs=3]
"""
import hashlib, json, os, subprocess, time, sys

GAME_DIR = r"G:\Games\Giants"
FPS = os.path.join(GAME_DIR, "fps.txt")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RUNS_ROOT = os.path.join(REPO, "RuntimeLab", "runs")

SHA256 = lambda p: hashlib.sha256(open(p, "rb").read()).hexdigest() if os.path.exists(p) else None

def wait_exit(timeout=300):
    t0 = time.time()
    while time.time() - t0 < timeout:
        try:
            out = subprocess.run(
                ["tasklist", "/FI", "IMAGENAME eq Giants.exe"],
                capture_output=True, text=True, errors="replace").stdout or ""
        except Exception:
            out = ""
        if "Giants.exe" not in out:
            return round(time.time() - t0, 1)
        time.sleep(2.0)
    return None

def screenshot(path):
    ps = (
        "$p = Get-Process Giants -ErrorAction SilentlyContinue;"
        "if ($p) { Add-Type -AssemblyName System.Drawing;"
        "$h = (Get-Process Giants).MainWindowHandle;"
        "$b = New-Object System.Drawing.Bitmap(640, 480);"
        "$g = [System.Drawing.Graphics]::FromImage($b);"
        "$g.CopyFromScreen(0,0,0,0,$b.Size); $b.Save('%s'); }" % path
    )
    subprocess.run(["powershell", "-Command", ps], capture_output=True)
    return os.path.exists(path)

def main():
    n = int(sys.argv[1]) if len(sys.argv) > 1 else 3
    ts = time.strftime("%Y%m%d_%H%M%S")
    outdir = os.path.join(RUNS_ROOT, ts)
    os.makedirs(outdir, exist_ok=True)
    manifest = {"started": ts, "runs": []}
    for i in range(1, n + 1):
        before_sha, before_sz = SHA256(FPS), os.path.getsize(FPS) if os.path.exists(FPS) else 0
        t0 = time.time()
        subprocess.run(["cmd", "/c", os.path.join(REPO, "RuntimeLab", "run_gauge.bat")],
                       cwd=REPO, capture_output=True)
        # give the process a moment to appear, then screenshot mid-run
        time.sleep(25)
        shot = os.path.join(outdir, f"run{i}_screen.png")
        has_shot = screenshot(shot)
        exit_after = wait_exit()
        dur = round(time.time() - t0, 1)
        after_sha = SHA256(FPS)
        after_sz = os.path.getsize(FPS) if os.path.exists(FPS) else 0
        run = {
            "run": i,
            "duration_s": dur,
            "process_exit_detected": exit_after is not None,
            "fps_sha256_before": before_sha,
            "fps_sha256_after": after_sha,
            "fps_size_before": before_sz,
            "fps_size_after": after_sz,
            "fps_changed": before_sha != after_sha,
            "fps_overwrote_not_appended": after_sz <= before_sz if before_sha != after_sha else None,
            "screenshot": os.path.basename(shot) if has_shot else None,
        }
        # keep a copy of the fps.txt state this run produced (read-only copy)
        if os.path.exists(FPS):
            import shutil
            shutil.copyfile(FPS, os.path.join(outdir, f"run{i}_fps.txt"))
        manifest["runs"].append(run)
        print(f"run {i}: {dur}s exit={run['process_exit_detected']} "
              f"fps_changed={run['fps_changed']} size {before_sz}->{after_sz}")
    manifest["fps_identical_across_runs"] = (
        len({r["fps_sha256_after"] for r in manifest["runs"] if r["fps_sha256_after"]}) == 1
    ) if manifest["runs"] else None
    mpath = os.path.join(outdir, "manifest.json")
    json.dump(manifest, open(mpath, "w", encoding="utf-8"), indent=1)
    print("manifest:", mpath, "| fps_identical_across_runs:", manifest["fps_identical_across_runs"])

if __name__ == "__main__":
    main()
