@echo off
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects_gog144 GOG144 -process Giants.exe -noanalysis -scriptPath G:\VibeRE\GiantsRE\scripts -postScript gog144_count.java
