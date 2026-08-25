param([string]$OutFile = "C:\temp\giants_screen.png")
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition 'using System; using System.Runtime.InteropServices; using System.Drawing; using System.Drawing.Imaging;
public class SC {
  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L,T,R,B; }
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
  public static void Shot(IntPtr h, string path) {
    RECT r; GetWindowRect(h, out r);
    int w = r.R - r.L, ht = r.B - r.T;
    if (w <= 0 || ht <= 0) { Console.Error.WriteLine("bad rect"); return; }
    using (Bitmap b = new Bitmap(w, ht, PixelFormat.Format32bppArgb))
    using (Graphics g = Graphics.FromImage(b)) {
      g.CopyFromScreen(r.L, r.T, 0, 0, new Size(w, ht));
      b.Save(path, ImageFormat.Png);
    }
    Console.WriteLine("screen-captured " + path + " " + w + "x" + ht + " at " + r.L + "," + r.T);
  }
}'
$p = Get-Process Giants -ErrorAction Stop
[SC]::Shot($p.MainWindowHandle, $OutFile)
