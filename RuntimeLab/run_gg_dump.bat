@echo off
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects_gg GG -import G:\VibeRE\GiantsRE\RuntimeLab\GiantsWork\gg_dx7r.dll -processor x86:LE:32:default -cspec windows -analysisTimeoutPerFile 600 -scriptPath G:\VibeRE\GiantsRE\scripts -postScript gg_dump.java G:\VibeRE\GiantsRE\decompiled\gg_dx7r
