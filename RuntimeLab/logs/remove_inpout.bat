@echo off
echo === stop ===        >  "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt"
sc.exe stop InpOutx64   >> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt" 2>&1
echo === delete svc === >> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt"
sc.exe delete InpOutx64 >> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt" 2>&1
echo === takeown ===    >> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt"
takeown /f C:\Windows\System32\drivers\inpoutx64.sys >> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt" 2>&1
icacls C:\Windows\System32\drivers\inpoutx64.sys /grant Administrators:F >> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt" 2>&1
icacls C:\Windows\System32\drivers\inpoutx64.sys /grant Administrateurs:F >> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt" 2>&1
echo === delete file ===>> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt"
del /f C:\Windows\System32\drivers\inpoutx64.sys >> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt" 2>&1
echo === done ===       >> "G:\VibeRE\GiantsRE\RuntimeLab\logs\inpout_removal.txt"
exit
