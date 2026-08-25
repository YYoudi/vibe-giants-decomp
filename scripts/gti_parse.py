#!/usr/bin/env python3
"""GTI terrain parser — Giants v1.0, decoded from the exe loader at +0x76D40.

Format:
  u32 magic            0x94965001 / 0x94965002 / 0x94965003 (version)
  [v2/v3] u32 chunk_count + chunk records (~0x34B each; 0 seen in the wild)
  header: f32 minX, f32 minZ, f32 ?, f32 maxheight, u32 tilesX, u32 tilesZ,
          f32 tile_size, f32 0.5, f32 0.5, u32 color1, u32 color2,
          u8 flags, u8 mat_lo, u8 mat_hi, u8 ?, f32 1.0, char[16] "useless",
          ... tail (2 dwords + 0x20B struct consumed by loader)
  terrain rows z = 1..tilesZ-1 (interior only; border = default -4096.0):
      i8 run; (run+1) x { f32 height, u8 color16,
                          u8[3] rgb (if flags & 2), u8 extra (if flags & 4) }

Runtime model (from loader): grid = (tilesX+2) x (tilesZ+2) tiles of 16 bytes,
height at +0 (default -4096.0), RGB at +4, color16 at +0xC; row pointers at world+0x10.

Usage: python scripts/gti_parse.py <file.gti> [--png out_prefix]
"""
import struct
import sys


def parse(path):
    d = open(path, "rb").read()
    o = 0
    magic, = struct.unpack_from("<I", d, o); o += 4
    assert magic in (0x94965001, 0x94965002, 0x94965003), hex(magic)
    ver = magic & 0xFF
    chunks = 0
    if ver >= 2:
        chunks, = struct.unpack_from("<I", d, o); o += 4
        o += chunks * 0x34  # chunk records (structure partially mapped)
    words = struct.unpack_from("<11I", d, o)
    o += 44
    minx, minz = struct.unpack("<f", struct.pack("<I", words[0]))[0], \
        struct.unpack("<f", struct.pack("<I", words[1]))[0]
    unk4 = struct.unpack("<f", struct.pack("<I", words[2]))[0]
    maxh = struct.unpack("<f", struct.pack("<I", words[3]))[0]
    tx, tz = words[4], words[5]
    tile = struct.unpack("<f", struct.pack("<I", words[6]))[0]
    half1, half2, color1, color2 = words[7], words[8], words[9], words[10]
    flags, mat_lo, mat_hi, pad_b = d[o], d[o + 1], d[o + 2], d[o + 3]
    o += 8  # flags dword + 4 pad
    one, = struct.unpack_from("<I", d, o); o += 4
    useless = d[o:o + 16].split(b"\x00")[0].decode("latin1", errors="replace")
    o += 16 + 16  # 'useless' field + zero pad
    assert o == 0x60, hex(o)
    gx, gz = tx + 2, tz + 2
    # default grid
    grid_h = [[-4096.0] * gx for _ in range(gz)]
    grid_rgb = [[None] * gx for _ in range(gz)]
    x = 1
    z = 1
    while z < tz - 1:  # loader: z from 1 to tilesZ-2 inclusive
        run = struct.unpack_from("<b", d, o)[0]; o += 1
        if run < 0:
            # skip op (loader +0x775D4): advance x by |run|, wrapping rows
            x += -run
            while x >= tx - 1 and z < tz:
                x += 2 - tx  # loader +0x775E3: x += 2 - tilesX per row overflow
                z += 1
        else:
            for _ in range(run + 1):
                if o + 8 > len(d):
                    z = tz  # EOF guard: stop parsing (tail sections remain)
                    break
                h, = struct.unpack_from("<f", d, o); o += 4
                c16 = d[o]; o += 1
                rgb = None
                if flags & 2:
                    if flags & 4:
                        rgb = (d[o], d[o + 1], d[o + 2]); o += 4
                    else:
                        rgb = (d[o], d[o + 1], d[o + 2]); o += 3
                if 0 < z < gz and 0 < x < gx:
                    grid_h[z][x] = h
                    grid_rgb[z][x] = rgb if rgb else ((c16 & 0x1F) * 8,) * 3
                x += 1
                if x >= tx - 1:  # loader +0x775BD: row boundary INSIDE the run
                    x = 1
                    z += 1
    return dict(ver=ver, chunks=chunks, minx=minx, minz=minz, maxh=maxh,
                tiles=(tx, tz), grid=(gx, gz), tile=tile, flags=flags,
                mat=(mat_lo, mat_hi), useless=useless,
                heights=grid_h, rgbs=grid_rgb, consumed=o, size=len(d))


def main():
    path = sys.argv[1]
    t = parse(path)
    print(f"ver={t['ver']} chunks={t['chunks']} extents=({t['minx']:.0f},{t['minz']:.0f}) "
          f"maxh={t['maxh']:.1f} tiles={t['tiles']} grid={t['grid']} tile={t['tile']:.1f} "
          f"flags={t['flags']:#x} mat={t['mat']} useless={t['useless']!r} "
          f"consumed={t['consumed']}/{t['size']}")
    if "--png" in sys.argv:
        prefix = sys.argv[sys.argv.index("--png") + 1]
        from PIL import Image
        gz, gx = t["grid"]
        lo = min(min(r) for r in t["heights"])
        hi = max(max(r) for r in t["heights"])
        span = (hi - lo) or 1.0
        im = Image.new("L", (gx, gz))
        imc = Image.new("RGB", (gx, gz))
        for z in range(gz):
            for x in range(gx):
                h = t["heights"][z][x]
                im.putpixel((x, z), int(max(0, min(255, (h - lo) / span * 255))))
                r, g, b = t["rgbs"][z][x] or (0, 0, 0)
                imc.putpixel((x, z), (r, g, b))
        im.resize((gx * 6, gz * 6), Image.NEAREST).save(prefix + "_height.png")
        imc.resize((gx * 6, gz * 6), Image.NEAREST).save(prefix + "_color.png")
        print(f"height range {lo:.1f}..{hi:.1f}; wrote {prefix}_height.png / {prefix}_color.png")


if __name__ == "__main__":
    main()
