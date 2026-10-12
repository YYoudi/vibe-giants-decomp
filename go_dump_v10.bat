@echo off
rem Dump function bytes from the v1.0 vanilla project (separate from GOG144).
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects GiantsRE -process Giants.exe -noanalysis -scriptPath G:\VibeRE\GiantsRE\scripts -postScript dump_func_bytes.java G:\VibeRE\GiantsRE\decompiled\v10_func_bytes.csv
