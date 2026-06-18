#!/usr/bin/env python3
"""GZP archive extractor ( Giants format, magic 0x6608F101) + LZ decompressor.
Extracts a named file from a .gzp to stdout/file. See memory/giants-format-specs.md."""
import sys, struct

def lz_decompress(src, expected):
    # Faithful port of VanillaVFS::LzDecompress. Control bits come from a bit-stream
    # (LSB-first within each byte); literal bytes + backref bytes are RAW from src.
    out = bytearray(expected)
    i = 0; j = 0; n = len(src)
    decByte = 0; decBits = 8
    buffStart = 0xFEE
    while j < expected:
        if decBits == 8:
            if i >= n: return bytes(out[:j])
            decByte = src[i]; i += 1; decBits = 0
        if ((decByte >> decBits) & 1) == 0:   # backref
            if i + 1 >= n: return bytes(out[:j])
            b0 = src[i]; b1 = src[i+1]; i += 2
            decPos = (((b0 + ((b1 & 0xF0) << 4) - buffStart - j) & 0xFFF) - 0x1000 + j)
            decLen = (b1 & 0xF) + 3
            while decLen > 0:
                out[j] = out[decPos] if decPos >= 0 else 0x20
                j += 1; decPos += 1; decLen -= 1
                if j >= expected: break
        else:   # literal
            if i >= n: return bytes(out[:j])
            out[j] = src[i]; j += 1; i += 1
        decBits += 1
    return bytes(out)

def read_gzp_index(path):
    d = open(path,'rb').read()
    magic, meta = struct.unpack_from('<II', d, 0)
    assert magic == 0x6608F101, f'bad magic {magic:#x}'
    unk, count = struct.unpack_from('<II', d, meta)
    entries = []
    p = meta + 8
    for _ in range(count):
        compSize, uncmpSize, date, start = struct.unpack_from('<IIII', d, p)
        compr = d[p+16]; nameLen = d[p+17]
        name = d[p+18:p+18+nameLen].split(b'\x00')[0].decode('latin1')
        entries.append((name, compSize, uncmpSize, start, compr))
        p += 18 + nameLen
    return d, entries

def extract(gzp_path, target):
    d, entries = read_gzp_index(gzp_path)
    target_lc = target.lower()
    for name, compSize, uncmpSize, start, compr in entries:
        if name.lower() == target_lc:
            content_off = start + 16
            raw = d[content_off:content_off+compSize]
            if compr == 0:
                return raw[:uncmpSize]
            return lz_decompress(raw, uncmpSize)
    return None

def tga_to_png(tga_bytes, out_png):
    # minimal TGA (type 2 truecolor) decoder
    idlen = tga_bytes[0]; cmaptype = tga_bytes[1]; imgtype = tga_bytes[2]
    w = struct.unpack_from('<H', tga_bytes, 12)[0]
    h = struct.unpack_from('<H', tga_bytes, 14)[0]
    bpp = tga_bytes[16]; desc = tga_bytes[17]
    pos = 18 + idlen
    pixels = bytearray()
    if imgtype == 2:
        bytespp = bpp//8
        row = w*bytespp
        data = tga_bytes[pos:pos+row*h]
        from PIL import Image
        # TGA is bottom-up unless bit 5 of desc
        if bpp == 24:
            im = Image.frombytes('RGB', (w,h), bytes(data), 'raw', 'BGR')
        elif bpp == 32:
            im = Image.frombytes('RGBA', (w,h), bytes(data), 'raw', 'BGRA')
        elif bpp == 8:
            im = Image.frombytes('L', (w,h), bytes(data))
        else:
            im = Image.frombytes('RGB',(w,h),bytes(data))
        if not (desc & 0x20):
            im = im.transpose(Image.FLIP_TOP_BOTTOM)
        im.save(out_png)
        print(f'{out_png}: {w}x{h} {bpp}bpp type{imgtype}')
        return im
    print(f'unsupported tga type {imgtype} bpp {bpp}')

if __name__ == '__main__':
    gzp = sys.argv[1]; name = sys.argv[2]; out = sys.argv[3] if len(sys.argv)>3 else None
    data = extract(gzp, name)
    if data is None:
        print(f'{name} NOT FOUND in {gzp}'); sys.exit(1)
    print(f'{name}: {len(data)} bytes extracted')
    if out:
        if name.lower().endswith('.tga'):
            tga_to_png(data, out)
        else:
            open(out,'wb').write(data)
