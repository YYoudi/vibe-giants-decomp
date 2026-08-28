@echo off
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects GiantsRE -process Giants.exe -noanalysis -scriptPath G:\VibeRE\GiantsRE\scripts -postScript export_string_map.java G:\VibeRE\GiantsRE\decompiled\pc_function_strings.json
