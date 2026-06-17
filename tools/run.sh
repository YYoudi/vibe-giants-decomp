#!/usr/bin/env bash
# tools/run.sh — single-command iteration: build -> deploy -> capture -> diff vs original.
# Usage:
#   tools/run.sh <phase>           build + deploy + capdiff compare <phase>
#   tools/run.sh <phase> recomp    build + deploy + capture recomp only (no original)
#   tools/run.sh <phase> norebuild skip build (use deployed exe), capture+diff
# Phases: intro1 intro2 intro3 loading menu
set -u
cd "$(dirname "$0")/.."   # repo root
export PATH="/c/msys64/mingw32/bin:$PATH"

PHASE="${1:-menu}"
MODE="${2:-compare}"
REBUILD=1
[[ "${3:-}" == "norebuild" ]] && REBUILD=0

echo "=== run.sh: phase=$PHASE mode=$MODE rebuild=$REBUILD ==="

if [[ "$REBUILD" == "1" ]]; then
  echo "--- build ---"
  if ! mingw32-make GiantsMain_vanilla 2>&1 | tail -3; then
    echo "BUILD FAILED"; exit 1
  fi
  echo "--- deploy ---"
  cp -f build_recomp/GiantsMain_vanilla.exe GameFiles-VanillaV1/GiantsMain_vanilla.exe
fi

# clean stale processes (both use gg_dx7r.dll)
taskkill //F //IM GiantsMain_vanilla.exe 2>/dev/null >/dev/null
taskkill //F //IM Giants_nocd.exe 2>/dev/null >/dev/null
sleep 1

echo "--- capture + diff (phase=$PHASE) ---"
case "$MODE" in
  recomp)
    python tools/capdiff.py recomp "$PHASE" -o "RESSOURCES_FOR_AI/temp_screenshots/run_recomp_${PHASE}.png"
    ;;
  original)
    python tools/capdiff.py original "$PHASE" -o "RESSOURCES_FOR_AI/temp_screenshots/run_orig_${PHASE}.png"
    ;;
  compare|*)
    python tools/capdiff.py compare "$PHASE"
    ;;
esac
RC=$?
echo "=== run.sh done: rc=$RC (0=PASS/ok, 1=diff-FAIL, 2=capture-fail) ==="
exit $RC
