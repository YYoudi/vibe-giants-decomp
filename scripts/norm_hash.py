#!/usr/bin/env python3
"""Semantic byte hash for cross-version function matching.

Disassembles each function (capstone x86-32) and rebuilds a byte image where
relocation-sensitive operands are zeroed:
  - rel32 in call/jmp/jcc  -> 0
  - any absolute dword that lands inside a PE section (image-range VA) -> 0
Then md5 over the rebuilt image. Two functions with the same norm-md5 implement
the same code against possibly-moved globals/callees.

Usage: python scripts/norm_hash.py <pe_path> <funcs_csv> <out_csv>
  funcs_csv: addr,size,... (as produced by dump_func_bytes.java)
  out_csv:   addr,normmd5
"""
import csv, hashlib, struct, sys, os

HERE = os.path.dirname(os.path.abspath(__file__))

def load_pe(path):
    raw = open(path, "rb").read()
    e = struct.unpack_from("<I", raw, 0x3C)[0]
    coff = e + 4
    nsec = struct.unpack_from("<H", raw, coff + 2)[0]
    opt_size = struct.unpack_from("<H", raw, coff + 16)[0]
    opt = coff + 20
    image_base = struct.unpack_from("<I", raw, opt + 28)[0]
    sec0 = opt + opt_size
    secs = []
    for i in range(nsec):
        off = sec0 + 40 * i
        vsize, va, rsize, roff = struct.unpack_from("<IIII", raw, off + 8)
        secs.append((va, vsize, roff, rsize))
    return raw, image_base, secs

def read_va(raw, base, secs, va, n):
    rva = va - base
    for sva, vsize, roff, rsize in secs:
        if sva <= rva < sva + max(vsize, rsize):
            fo = roff + (rva - sva)
            return raw[fo:fo + n]
    return None

def in_image(base, secs, va):
    rva = va - base
    return any(sva <= rva < sva + max(vsize, rsize) for sva, vsize, _, rsize in secs)

REL32_MNEMS = {"call", "jmp", "je", "jne", "jz", "jnz", "ja", "jae", "jb", "jbe",
               "jg", "jge", "jl", "jle", "js", "jns", "jo", "jno", "jp", "jnp",
               "loop", "loope", "loopne", "jecxz"}

def norm_md5(raw, base, secs, va, size):
    data = bytearray(read_va(raw, base, secs, va, size) or b"")
    if not data:
        return ""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = False
    code = bytes(data)
    for ins in md.disasm(code, va):
        off = ins.address - va
        m = ins.mnemonic
        if m in REL32_MNEMS and ins.op_str.startswith("0x"):
            # rel32 operand = last 4 bytes of instruction (branch rel32 forms)
            if ins.size >= 5:
                for k in range(4):
                    data[off + ins.size - 4 + k] = 0
        elif ("0x" in ins.op_str) and ins.size >= 6 and m not in ("lea", "movzx", "movsx"):
            # crude absolute-imm/disp32 zeroing: scan operand-position dwords
            # that decode to image-range VAs; check last-4 and last-8 windows
            for win in (4, 8):
                if ins.size >= win:
                    doff = off + ins.size - win
                    dw = struct.unpack_from("<I", data, doff)[0]
                    if 0x400000 <= dw < 0x600000 and in_image(base, secs, dw):
                        for k in range(4):
                            data[doff + k] = 0
    return hashlib.md5(bytes(data)).hexdigest()

def main():
    pe_path, funcs_csv, out_csv = sys.argv[1], sys.argv[2], sys.argv[3]
    raw, base, secs = load_pe(pe_path)
    out = open(out_csv, "w", newline="", encoding="utf-8")
    w = csv.writer(out)
    w.writerow(["addr", "normmd5"])
    n = 0
    for r in csv.DictReader(open(funcs_csv, encoding="utf-8")):
        va = int(r["addr"], 16)
        size = int(r["size"])
        if size <= 0 or size > 0x20000:
            continue
        h = norm_md5(raw, base, secs, va, size)
        w.writerow([r["addr"], h])
        n += 1
        if n % 500 == 0:
            print(f"  {n}")
    out.close()
    print(f"norm-hashed {n} functions -> {out_csv}")

if __name__ == "__main__":
    main()
