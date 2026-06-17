# Claim board — multi-agent file/work ownership

When an agent starts work on a file or chantier, it **claims** it here (so no other
agent edits the same file → no race, no broken build). One writer per file. Reading
and searching can be fully parallel; only WRITES need a claim.

## Format
Append one line: `- [<file-or-chantier>] @<agent> (status: active|done) [<date>]`

Release the claim (mark `done` or delete the line) when finished.

## Active claims
_(empty — agents add their claims here)_

## Conventions
- **Build = serial**: always go through `tools/build.sh` (lockdir-protected). Never raw `mingw32-make` with other agents active.
- **Disjoint files**: fork agents only on files nobody else is editing. Portage of independent functions (`RE_<fn>.cpp`) is embarrassingly parallel.
- **Worktree per agent**: for heavy parallel editing, use `EnterWorktree` so each agent has an isolated copy; main integrates + builds.
- **Subagents use `sonnet`** (glm-5.1) for portage/RE; main (opus/glm-5.2) integrates + builds + decides.
- **Back-off on 529**: if the gateway returns 529, go sequential; don't immediately re-fork.
