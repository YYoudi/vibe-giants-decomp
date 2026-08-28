@echo off
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects GiantsRE -process Giants.exe -noanalysis -scriptPath G:\VibeRE\GiantsRE\scripts -postScript ghidra_apply_matches.java G:\VibeRE\GiantsRE\ps2_symbols\pc_ps2_matches_full.csv 0.6 ps2_ 0.35
