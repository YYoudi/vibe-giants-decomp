@echo off
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects PS2 -process SLUS_201.78 -noanalysis -scriptPath G:\VibeRE\GiantsRE\scripts -postScript ps2_strrefs_dump.java G:\VibeRE\GiantsRE\ps2_symbols\ps2_string_refs.json
