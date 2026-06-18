# Capture the recomp menu after natural boot (all intros + loading). Prints to stdout.
param([int]$Wait = 40)
$GameDir = "G:\GiantsRE\GameFiles-VanillaV1"
$Exe = "$GameDir\GiantsMain_vanilla.exe"
Get-Process GiantsMain_vanilla -ErrorAction SilentlyContinue | Stop-Process -Force
Start-Sleep -Seconds 3
Start-Process -FilePath $Exe -WorkingDirectory $GameDir -ArgumentList "-window","-frames","5000"
Start-Sleep -Seconds $Wait
$p = Get-Process GiantsMain_vanilla -ErrorAction SilentlyContinue
if (-not $p) { Write-Output "NO PROCESS"; exit 1 }
$hwnd = $p.MainWindowHandle
Add-Type -AssemblyName System.Drawing
$u = Add-Type -Name U32cap -MemberDefinition '
[DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, ref System.Drawing.Rectangle r);
[DllImport("user32.dll")] public static extern bool PrintWindow(IntPtr h, IntPtr hdc, int flags);
[DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);' -PassThru
[void]$u::SetForegroundWindow($hwnd)
Start-Sleep -Milliseconds 700
$r = New-Object System.Drawing.Rectangle(0,0,640,480)
[void]$u::GetClientRect($hwnd, [ref]$r)
$bmp = New-Object System.Drawing.Bitmap($r.Width, $r.Height)
$g = [System.Drawing.Graphics]::FromImage($bmp)
$hdc = $g.GetHdc()
[void]$u::PrintWindow($hwnd, $hdc, 2)
$g.ReleaseHdc($hdc); $g.Dispose()
$out = "C:\Users\Judi\AppData\Local\Temp\menu_pw.png"
$bmp.Save($out, [System.Drawing.Imaging.ImageFormat]::Png)
$bmp.Dispose()
Write-Output "captured $($r.Width)x$($r.Height) hwnd=$hwnd -> $out"
Get-Process GiantsMain_vanilla -ErrorAction SilentlyContinue | Stop-Process -Force
