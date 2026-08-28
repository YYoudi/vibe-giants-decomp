@echo off
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects GiantsRE -process Giants.exe -noanalysis -scriptPath G:\VibeRE\GiantsRE\scripts -postScript decompile_all.java G:\VibeRE\GiantsRE\vanilla_decompiled 0x552000
