@echo off
rem Dump function bytes from the GOG 1.449 project.
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects_gog144 GOG144 -process Giants.exe -noanalysis -scriptPath G:\VibeRE\GiantsRE\scripts -postScript dump_func_bytes.java G:\VibeRE\GiantsRE\decompiled\v149_func_bytes.csv
