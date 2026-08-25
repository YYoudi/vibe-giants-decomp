param([string]$OutFile = "C:\temp\giants_shot.png")
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition 'using System; using System.Runtime.InteropServices; using System.Drawing; using System.Drawing.Imaging;
public class Cap {
  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,R,B; }
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
  [DllImport("user32.dll")] public static extern bool PrintWindow(IntPtr h, IntPtr hdc, uint flags);
  static Bitmap Grab(IntPtr h, int w, int ht, uint flags) {
    Bitmap b = new Bitmap(w, ht, PixelFormat.Format32bppArgb);
    using (Graphics g = Graphics.FromImage(b)) {
      IntPtr hdc = g.GetHdc();
      PrintWindow(h, hdc, flags);
      g.ReleaseHdc(hdc);
    }
    return b;
  }
  static bool IsBlack(Bitmap b) {
    for (int y = 0; y < b.Height; y += Math.Max(1, b.Height/16))
      for (int x = 0; x < b.Width; x += Math.Max(1, b.Width/16))
        if (b.GetPixel(x, y).GetBrightness() > 0.05) return false;
    return true;
  }
  public static void Shot(IntPtr h, string path) {
    RECT r; GetWindowRect(h, out r);
    int w = r.R - r.L, ht = r.B - r.T;
    if (w <= 0 || ht <= 0) { Console.Error.WriteLine("bad rect " + w + "x" + ht); return; }
    Bitmap full = Grab(h, w, ht, 0x2);
    string mode = "fullcontent";
    if (IsBlack(full)) {
      Bitmap plain = Grab(h, w, ht, 0);
      if (!IsBlack(plain)) { full.Dispose(); full = plain; mode = "plain"; }
      else plain.Dispose();
    }
    full.Save(path, ImageFormat.Png);
    full.Dispose();
    Console.WriteLine("saved " + path + " " + w + "x" + ht + " (" + mode + ")");
  }
}'
$p = Get-Process Giants -ErrorAction Stop
[Cap]::Shot($p.MainWindowHandle, $OutFile)
