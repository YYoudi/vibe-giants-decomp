@echo off
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects_gg GG -process gg_dx7r.dll -noanalysis -scriptPath G:\VibeRE\GiantsRE\scripts -postScript gg_dump2.java G:\VibeRE\GiantsRE\decompiled\gg_dx7r
