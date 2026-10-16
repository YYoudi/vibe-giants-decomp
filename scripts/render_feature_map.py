#!/usr/bin/env python3
"""Regenerate docs/FEATURE_MAP.html from docs/FEATURE_MAP.md.

The markdown is the source of truth (agents edit it); this script renders the
visual dashboard (colour-coded progress bars) next to it. Run after any edit:

    python scripts/render_feature_map.py

Reads  : docs/FEATURE_MAP.md   (GFM tables: | Feature | comp | impl | Preuve |)
Writes : docs/FEATURE_MAP.html (self-contained, open in any browser)
"""
import html
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
MD = ROOT / "docs" / "FEATURE_MAP.md"
OUTS = [ROOT.parent / "FEATURE_MAP.html", ROOT / "docs" / "FEATURE_MAP.html"]  # vue officielle au-dessus + copie git


def colour(pct: int) -> str:
    if pct >= 85:
        return "#16a34a"  # vert
    if pct >= 60:
        return "#65a30d"  # vert-olive
    if pct >= 40:
        return "#d97706"  # orange
    return "#dc2626"  # rouge


def bar(pct: int, label: str) -> str:
    return (
        f'<div class="barwrap" title="{label}: {pct}%">'
        f'<div class="barlabel">{label} <b>{pct}%</b></div>'
        f'<div class="barbg"><div class="bar" style="width:{pct}%;background:{colour(pct)}"></div></div>'
        f"</div>"
    )


def parse(md_text: str):
    sections = []  # (title, rows[(feature, comp, impl, proof)])
    current = None
    for line in md_text.splitlines():
        if line.startswith("## ") and not line.startswith("## Lecture"):
            title = line[3:].strip()
            if re.match(r"^\d+\.", title):
                current = (title, [])
                sections.append(current)
        elif current is not None and line.startswith("|"):
            cells = [c.strip() for c in line.strip().strip("|").split("|")]
            if len(cells) == 4 and cells[0] != "Feature" and not set(cells[1]) <= {"-", " "}:
                feature, comp, impl, proof = cells
                try:
                    ci, ii = int(comp), int(impl)
                except ValueError:
                    continue
                current[1].append((feature, ci, ii, proof))
    return sections


def render(sections) -> str:
    parts = []
    for title, rows in sections:
        avg_c = sum(r[1] for r in rows) / max(len(rows), 1)
        parts.append(
            f'<section><h2>{html.escape(title)} '
            f'<span class="avg">moyenne : compris {avg_c:.0f}% · moteur '
            f"{sum(r[2] for r in rows) / max(len(rows), 1):.0f}%</span></h2>"
        )
        for feature, comp, impl, proof in rows:
            parts.append(
                f'<div class="row"><div class="feature">{html.escape(feature)}</div>'
                f'<div class="bars">{bar(comp, "compris")}{bar(impl, "moteur")}</div>'
                f'<div class="proof">{html.escape(proof)}</div></div>'
            )
        parts.append("</section>")
    return "\n".join(parts)


def main() -> int:
    if not MD.exists():
        print(f"missing {MD}", file=sys.stderr)
        return 1
    sections = parse(MD.read_text(encoding="utf-8"))
    total = [(f, c, i) for _, rows in sections for (f, c, i, _) in rows]
    avg_all_c = sum(t[1] for t in total) / max(len(total), 1)
    avg_all_i = sum(t[2] for t in total) / max(len(total), 1)
    page = f"""<!DOCTYPE html>
<html lang="fr"><head><meta charset="utf-8">
<title>FEATURE_MAP — Giants: Citizen Kabuto (RE)</title>
<style>
 body {{ font-family: 'Segoe UI', sans-serif; margin: 0; background: #0f172a; color: #e2e8f0; }}
 header {{ padding: 24px 32px; background: #1e293b; }}
 h1 {{ margin: 0 0 6px; font-size: 22px; }}
 .global {{ display: flex; gap: 24px; margin-top: 12px; }}
 .gnum {{ font-size: 28px; font-weight: 700; }}
 .glabel {{ font-size: 12px; color: #94a3b8; }}
 section {{ padding: 8px 32px; }}
 h2 {{ font-size: 16px; color: #93c5fd; border-bottom: 1px solid #334155; padding-bottom: 6px; }}
 .avg {{ float: right; font-size: 12px; color: #64748b; font-weight: normal; }}
 .row {{ display: grid; grid-template-columns: 260px 340px 1fr; gap: 16px; align-items: center;
        padding: 10px 0; border-bottom: 1px solid #1e293b; }}
 .feature {{ font-size: 13px; }}
 .barwrap {{ margin: 3px 0; }}
 .barlabel {{ font-size: 10px; color: #94a3b8; display: flex; justify-content: space-between; }}
 .barbg {{ background: #1e293b; border-radius: 4px; height: 10px; overflow: hidden; }}
 .bar {{ height: 10px; border-radius: 4px; }}
 .proof {{ font-size: 11px; color: #94a3b8; }}
 footer {{ padding: 20px 32px; color: #475569; font-size: 11px; }}
</style></head><body>
<header>
 <h1>FEATURE_MAP — Giants: Citizen Kabuto (GOG 1.449)</h1>
 <div style="font-size:12px;color:#94a3b8">À quel point on sait comment le jeu le fait (compris) vs ce que le moteur Rust le fait (moteur). Source : FEATURE_MAP.md — toute tâche fermée met à jour sa ligne.</div>
 <div class="global">
  <div><div class="gnum" style="color:{colour(int(avg_all_c))}">{avg_all_c:.0f}%</div><div class="glabel">compréhension des bytes ({len(total)} features)</div></div>
  <div><div class="gnum" style="color:{colour(int(avg_all_i))}">{avg_all_i:.0f}%</div><div class="glabel">implémentation moteur</div></div>
 </div>
</header>
{render(sections)}
<footer>Généré par scripts/render_feature_map.py — régénérer après toute modification du markdown.</footer>
</body></html>
"""
    for out in OUTS:
        out.write_text(page, encoding="utf-8")
    print(f"{OUTS[0]} (+copie docs/) — {len(total)} features, compris {avg_all_c:.0f}%, moteur {avg_all_i:.0f}%")
    return 0


if __name__ == "__main__":
    sys.exit(main())
