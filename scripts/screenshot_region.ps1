param([string]$OutFile = "C:\temp\giants_region.png")
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition 'using System; using System.Runtime.InteropServices; using System.Drawing; using System.Drawing.Imaging;
public class RC {
  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,R,B; }
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
  [DllImport("user32.dll")] public static extern IntPtr GetWindowDC(IntPtr h);
  [DllImport("user32.dll")] public static extern int ReleaseDC(IntPtr h, IntPtr dc);
  [DllImport("gdi32.dll")] public static extern bool BitBlt(IntPtr dst, int x, int y, int w, int h, IntPtr src, int x1, int y1, int rop);
  public static void Shot(IntPtr h, string path) {
    RECT r; GetWindowRect(h, out r);
    int w = r.R - r.L, ht = r.B - r.T;
    if (w <= 0 || ht <= 0) { Console.Error.WriteLine("bad rect"); return; }
    using (Bitmap b = new Bitmap(w, ht, PixelFormat.Format32bppArgb))
    using (Graphics g = Graphics.FromImage(b)) {
      IntPtr hdc = g.GetHdc();
      IntPtr sdc = GetWindowDC(h);
      BitBlt(hdc, 0, 0, w, ht, sdc, 0, 0, 0x00CC0020); // SRCCOPY
      ReleaseDC(h, sdc);
      g.ReleaseHdc(hdc);
      b.Save(path, ImageFormat.Png);
    }
    Console.WriteLine("saved " + path + " " + w + "x" + ht);
  }
}'
$p = Get-Process Giants -ErrorAction Stop
[RC]::Shot($p.MainWindowHandle, $OutFile)
