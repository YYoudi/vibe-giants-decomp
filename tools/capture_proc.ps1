# Capture a window by HWND (decimal) via PrintWindow(PW_RENDERFULLCONTENT). Robust for D3D windows.
# Usage: powershell -File tools\capture_proc.ps1 <hwndDecimal> <OutPng> [<flag>]
param([Parameter(Mandatory=$true)][long]$Hwnd,
      [Parameter(Mandatory=$true)][string]$OutPng,
      [int]$Flag = 2)
$u = Add-Type -Name U32cap4 -MemberDefinition '
[DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, ref System.Drawing.Rectangle r);
[DllImport("user32.dll")] public static extern bool PrintWindow(IntPtr h, IntPtr hdc, int flags);
[DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);
[DllImport("user32.dll")] public static extern bool ShowWindow(IntPtr h, int n);' -PassThru
$hwnd = [IntPtr]$Hwnd
[void]$u::ShowWindow($hwnd, 9); [void]$u::SetForegroundWindow($hwnd)
Start-Sleep -Milliseconds 600
$r = New-Object System.Drawing.Rectangle(0,0,640,480)
[void]$u::GetClientRect($hwnd, [ref]$r)
if ($r.Width -le 1 -or $r.Height -le 1) { Write-Output "BAD_RECT $($r.Width)x$($r.Height)"; exit 2 }
Add-Type -AssemblyName System.Drawing
$bmp = New-Object System.Drawing.Bitmap($r.Width, $r.Height)
$g = [System.Drawing.Graphics]::FromImage($bmp)
$hdc = $g.GetHdc()
$ok = $u::PrintWindow($hwnd, $hdc, $Flag)
$g.ReleaseHdc($hdc); $g.Dispose()
$bmp.Save($OutPng, [System.Drawing.Imaging.ImageFormat]::Png)
$bmp.Dispose()
Write-Output "OK $($r.Width)x$($r.Height) hwnd=$hwnd flag=$Flag ok=$ok -> $OutPng"
