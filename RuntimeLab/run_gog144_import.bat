@echo off
call "G:\Tools\ghidra_12.1.2_PUBLIC\support\analyzeHeadless.bat" G:\VibeRE\GiantsRE\ghidra_projects_gog144 GOG144 -import G:\Games\Giants\Giants.exe -processor x86:LE:32:default -cspec windows -analysisTimeoutPerFile 1800
