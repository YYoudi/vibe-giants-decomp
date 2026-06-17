#!/usr/bin/env bash
# tools/build.sh — serialized build for multi-agent operation.
# Multiple agents can edit disjoint files in parallel, but the BUILD must be serial
# (one mingw32-make at a time). This wrapper acquires a lockdir, builds, releases.
# Agents MUST use this instead of raw `mingw32-make`.
#
# Usage: tools/build.sh [make-target]   (default target: GiantsMain_vanilla)
set -u
cd "$(dirname "$0")/.."
export PATH="/c/msys64/mingw32/bin:$PATH"
TARGET="${1:-GiantsMain_vanilla}"
LOCKDIR="tools/.build.lock"
PIDF="$LOCKDIR/pid"

cleanup() { rm -rf "$LOCKDIR" 2>/dev/null; }
trap cleanup EXIT

# Acquire lock (mkdir is atomic). Retry with back-off up to ~5 min.
for i in $(seq 1 60); do
  if mkdir "$LOCKDIR" 2>/dev/null; then
    echo "$$" > "$PIDF"
    break
  fi
  # stale lock? (holder dead)
  if [[ -f "$PIDF" ]]; then
    OLD=$(cat "$PIDF" 2>/dev/null)
    if ! tasklist 2>/dev/null | grep -q "$OLD" && ! kill -0 "$OLD" 2>/dev/null; then
      rm -rf "$LOCKDIR" 2>/dev/null && continue
    fi
  fi
  sleep 5
done
if [[ -d "$LOCKDIR" && "$(cat "$PIDF" 2>/dev/null)" != "$$" ]]; then
  echo "BUILD LOCK: could not acquire $LOCKDIR after 5 min — another agent is building." >&2
  exit 3
fi

echo "BUILD LOCK acquired (pid $$) — make $TARGET"
mingw32-make "$TARGET"
RC=$?
# deploy if it built
if [[ $RC -eq 0 && -f build_recomp/GiantsMain_vanilla.exe ]]; then
  cp -f build_recomp/GiantsMain_vanilla.exe GameFiles-VanillaV1/GiantsMain_vanilla.exe
fi
echo "BUILD done rc=$RC"
exit $RC
