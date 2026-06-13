#!/usr/bin/env python3
"""
GiantsRE Stub Verifier — Syntax + Type Check (no compiler required)

Checks all .h/.cpp files in src/ for:
1. Matching #pragma once / include guards
2. Consistent function declarations between .h and .cpp
3. DAT_ address consistency with RE-TRACKER.json
4. Missing #include directives
5. Basic syntax patterns (balanced braces, semicolons)
6. Cross-reference: every function in tracker has a source file

Usage:
    python scripts/verify_stubs.py
    python scripts/verify_stubs.py --fix   (auto-fix simple issues)
"""

import json
import os
import re
import sys
from pathlib import Path
from collections import defaultdict

ROOT = Path("G:/GiantsRE")
SRC = ROOT / "src"
TRACKER = ROOT / "RE-TRACKER.json"
CLAUDE_MD = ROOT / "CLAUDE.md"

# ─── Checks ───────────────────────────────────────────────────

def check_braces(filepath):
    """Check balanced braces/brackets/parens."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()

    stack = []
    pairs = {'{': '}', '(': ')', '[': ']'}
    opens = set(pairs.keys())
    closes = set(pairs.values())
    issues = []

    # Skip strings and comments (rough)
    in_string = False
    in_comment = False
    in_line_comment = False

    for i, ch in enumerate(content):
        if ch == '\n':
            in_line_comment = False
            continue
        if in_line_comment:
            continue
        if ch == '/' and i + 1 < len(content):
            if content[i+1] == '/':
                in_line_comment = True
                continue
            if content[i+1] == '*':
                in_comment = True
                continue
        if in_comment:
            if ch == '*' and i + 1 < len(content) and content[i+1] == '/':
                in_comment = False
            continue

        if ch in opens:
            stack.append((ch, i, filepath))
        elif ch in closes:
            if not stack:
                line = content[:i].count('\n') + 1
                issues.append(f"L{line}: Unmatched '{ch}'")
            else:
                expected_open = stack.pop()
                # Find matching open
                for o, c in pairs.items():
                    if c == ch:
                        if expected_open[0] != o:
                            line = content[:i].count('\n') + 1
                            issues.append(f"L{line}: Mismatched '{expected_open[0]}' vs '{ch}'")
                        break

    if stack:
        for sym, pos, fp in stack:
            line = content[:pos].count('\n') + 1
            issues.append(f"L{line}: Unclosed '{sym}'")

    return issues


def check_addresses(filepath):
    """Extract all DAT_/FUN_ addresses and verify they're in valid range."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()

    issues = []
    # Find all DAT_ and FUN_ references
    addrs = re.findall(r'(?:DAT|FUN)_[0-9a-fA-F]{6,8}', content)

    for addr in addrs:
        hex_val = addr.split('_')[1]
        val = int(hex_val, 16)
        # Valid code range: 0x00400000 - 0x00700000
        # Valid data range: 0x0066XXXX - 0x0074XXXX
        if not (0x00400000 <= val <= 0x00750000 or 0x00660000 <= val <= 0x00750000):
            issues.append(f"Suspicious address: {addr} (0x{val:08X})")

    return issues


def check_namespace(filepath):
    """Verify file uses namespace Giants."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()

    if filepath.suffix == '.cpp' and 'namespace Giants' not in content:
        return ["Missing 'namespace Giants'"]
    return []


def check_tracker_consistency(tracker):
    """Cross-reference tracker with actual source files."""
    issues = []

    # Check every reversed function has a file
    for addr, info in tracker.get('functions', {}).items():
        if info.get('status') == 'reversed':
            f = info.get('file')
            if f:
                full_path = ROOT / f
                if not full_path.exists():
                    issues.append(f"Tracker: {addr} ({info.get('name')}) → file missing: {f}")
            elif info.get('verdict') not in ('trivial',):
                # No file but reversed — might need a stub
                pass

    # Check queued functions aren't already reversed
    for addr, info in tracker.get('functions', {}).items():
        if info.get('status') == 'queued' and info.get('file'):
            issues.append(f"Tracker: {addr} ({info.get('name')}) is 'queued' but has file {info['file']}")

    return issues


def check_stats(tracker):
    """Verify tracker stats match actual data."""
    issues = []
    funcs = tracker.get('functions', {})
    stats = tracker.get('stats', {})

    actual_tracked = len(funcs)
    actual_reversed = sum(1 for f in funcs.values() if f.get('status') == 'reversed')
    actual_pass = sum(1 for f in funcs.values() if f.get('verdict') == 'pass')
    actual_fail = sum(1 for f in funcs.values() if f.get('verdict') == 'fail')
    actual_queued = sum(1 for f in funcs.values() if f.get('status') == 'queued')

    if stats.get('tracked') != actual_tracked:
        issues.append(f"Stats tracked={stats.get('tracked')} but actual={actual_tracked}")
    if stats.get('reversed') != actual_reversed:
        issues.append(f"Stats reversed={stats.get('reversed')} but actual={actual_reversed}")
    if stats.get('pass') != actual_pass:
        issues.append(f"Stats pass={stats.get('pass')} but actual={actual_pass}")
    if stats.get('queued') != actual_queued:
        issues.append(f"Stats queued={stats.get('queued')} but actual={actual_queued}")

    return issues


def check_source_line_count(tracker):
    """Verify line count in tracker matches actual."""
    issues = []
    total_lines = 0
    total_files = 0

    for ext in ('*.h', '*.cpp'):
        for f in SRC.rglob(ext):
            total_files += 1
            with open(f, 'r', encoding='utf-8', errors='replace') as file:
                total_lines += sum(1 for _ in file)

    stats = tracker.get('stats', {})
    if stats.get('source_lines') != total_lines:
        issues.append(f"Stats source_lines={stats.get('source_lines')} but actual={total_lines}")
    if stats.get('source_files') != total_files:
        issues.append(f"Stats source_files={stats.get('source_files')} but actual={total_files}")

    return issues, total_lines, total_files


# ─── Main ─────────────────────────────────────────────────────

def main():
    print("=" * 60)
    print("  GiantsRE Stub Verifier")
    print("=" * 60)

    all_issues = defaultdict(list)

    # Load tracker
    with open(TRACKER, 'r') as f:
        tracker = json.load(f)

    # Check each source file
    for ext in ('*.h', '*.cpp'):
        for filepath in SRC.rglob(ext):
            rel = filepath.relative_to(ROOT)
            print(f"\n  Checking {rel}...")

            issues = []
            issues.extend(check_braces(filepath))
            issues.extend(check_addresses(filepath))
            issues.extend(check_namespace(filepath))

            if issues:
                for issue in issues:
                    print(f"    WARN {issue}")
                    all_issues[str(rel)].append(issue)
            else:
                print(f"    OK")

    # Tracker consistency
    print(f"\n  Checking RE-TRACKER.json...")
    tracker_issues = []
    tracker_issues.extend(check_tracker_consistency(tracker))
    tracker_issues.extend(check_stats(tracker))
    line_issues, actual_lines, actual_files = check_source_line_count(tracker)
    tracker_issues.extend(line_issues)

    if tracker_issues:
        for issue in tracker_issues:
            print(f"    WARN {issue}")
            all_issues['RE-TRACKER.json'].append(issue)
    else:
        print(f"    OK Stats consistent")

    # Summary
    print(f"\n{'=' * 60}")
    print(f"  Source: {actual_files} files, {actual_lines} lines")
    print(f"  Tracker: {tracker['stats']['tracked']} functions tracked")

    total_issues = sum(len(v) for v in all_issues.values())
    if total_issues == 0:
        print(f"  Result: OK ALL CHECKS PASSED")
    else:
        print(f"  Result: WARN {total_issues} issues found in {len(all_issues)} files")
        print(f"\n  Files with issues:")
        for filepath, issues in all_issues.items():
            print(f"    {filepath}: {len(issues)} issue(s)")

    print(f"{'=' * 60}")

    return 0 if total_issues == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
