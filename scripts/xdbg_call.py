#!/usr/bin/env python3
"""Thin CLI client for the x64dbg MCP server (HTTP, bearer token).

Usage:
  python scripts/xdbg_call.py <ToolName> [json-arguments]
  python scripts/xdbg_call.py GetDebugState
  python scripts/xdbg_call.py LoadBinary '{"path": "G:\\VibeRE\\GiantsRE\\GameFiles-VanillaV1\\Giants.exe"}'
  python scripts/xdbg_call.py ListCommandsByCategory

Token and port are read from G:\Tools\x64dbg\release\x32\mcp_config.json.
"""
import json
import os
import sys
import urllib.request

CONFIG_PATH = r"G:\Tools\x64dbg\release\x32\mcp_config.json"


def load_config():
    with open(CONFIG_PATH, "r", encoding="utf-8") as f:
        cfg = json.load(f)
    return f"http://localhost:{cfg['Port']}/", cfg["AuthToken"]


def call(tool: str, arguments: dict | None = None, timeout: int = 120):
    url, token = load_config()
    payload = {
        "jsonrpc": "2.0",
        "id": 1,
        "method": "tools/call",
        "params": {"name": tool, "arguments": arguments or {}},
    }
    req = urllib.request.Request(
        url,
        data=json.dumps(payload).encode("utf-8"),
        headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {token}",
        },
        method="POST",
    )
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        body = json.load(resp)
    if "error" in body:
        return f"ERROR: {body['error']}"
    parts = body.get("result", {}).get("content", [])
    return "\n".join(p.get("text", "") for p in parts)


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        sys.exit(1)
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    timeout = int(os.environ.get("XDBG_TIMEOUT", "120"))
    print(call(tool, args, timeout))


if __name__ == "__main__":
    main()
