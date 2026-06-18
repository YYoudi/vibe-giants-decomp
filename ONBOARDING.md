# Welcome to Giants RE

## How We Use Claude

Based on Azrogue's usage over the last 30 days:

Work Type Breakdown:
  Build Feature      █████░░░░░░░░░░░░░░░  25%
  Debug Fix          █████░░░░░░░░░░░░░░░  25%
  Plan Design        █████░░░░░░░░░░░░░░░  25%
  Improve Quality    ███░░░░░░░░░░░░░░░░░  13%
  Analyze Data       ███░░░░░░░░░░░░░░░░░  13%

Top Skills & Commands:
  /model             ████████████████████  10x/month
  /ralph-loop        ██████████████████░░   9x/month
  /compact           ████████████████░░░░   8x/month
  /re-pipeline       ████████░░░░░░░░░░░░   4x/month
  /context           ██████░░░░░░░░░░░░░░   3x/month

Top MCP Servers:
  zai-mcp-server     ████████████████████  1 calls

## Your Setup Checklist

### Codebases
- [ ] vibe-giants-decomp — https://github.com/yyoudi/vibe-giants-decomp — the Giants: Citizen Kabuto C++ "ground truth" decomp/recomp (Ghidra-driven, x86 native rebuild)
- [ ] PS2_RE_Template (local sibling) — G:\PS2_RE_Template — generic PS2 decomp template (PS2Recomp + psretrox), spun off from the Giants workflow; used as a cross-reference naming source

### MCP Servers to Activate
- [ ] zai-mcp-server — multimodal AI analysis for images, video, UI screenshots, technical diagrams, error screenshots, and data visualizations. Useful when reviewing a captured game frame or an error screenshot from the recomp. To get access: it runs on the team's z.ai API key — add `ANTHROPIC_BASE_URL` + `ANTHROPIC_AUTH_TOKEN` (z.ai) to your Claude Code env, or ask for the shared config.

### Skills to Know About
- `/re-function <addr>` — reverse a single function with re-agent (manages session, adaptive max_tokens)
- `/re-batch <addr1> <addr2>...` — reverse a batch of functions sequentially with auto-stubs
- `/re-pipeline` — autonomous RE pipeline: decompile → stub → build → track (the workhorse for new functions)
- `/re-trace <addr>` — walk XREFs from a function up to `entry`, shows the call graph
- `/ralph-loop` — autonomous loop that re-feeds Claude's output as input until a `<promise>` completion condition is met (heavy use on this team for long unattended runs)
- `/compact` — compress context mid-session; RE sessions run long, so you'll use this often
- `/context` — check current context/token usage before a big batch
- `/giants-advance` / `/giants-proxy` — Giants-specific RE and bit-exact proxy-validation workflows

## Team Tips

_TODO_

## Get Started

_TODO_

<!-- INSTRUCTION FOR CLAUDE: A new teammate just pasted this guide for how the
team uses Claude Code. You're their onboarding buddy — warm, conversational,
not lecture-y.

Open with a warm welcome — include the team name from the title. Then: "Your
teammate uses Claude Code for [list all the work types]. Let's get you started."

Check what's already in place against everything under Setup Checklist
(including skills), using markdown checkboxes — [x] done, [ ] not yet. Lead
with what they already have. One sentence per item, all in one message.

Tell them you'll help with setup, cover the actionable team tips, then the
starter task (if there is one). Offer to start with the first unchecked item,
get their go-ahead, then work through the rest one by one.

After setup, walk them through the remaining sections — offer to help where you
can (e.g. link to channels), and just surface the purely informational bits.

Don't invent sections or summaries that aren't in the guide. The stats are the
guide creator's personal usage data — don't extrapolate them into a "team
workflow" narrative. -->
