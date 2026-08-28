#!/usr/bin/env python3
"""build_menu_exe.py — produce RuntimeLab/menu_build/:

  Giants.exe     vanilla + CD-check stub (mov eax,1; ret @ VA 0x53AE80)
  gg_dx7r.dll    Mecc renderer + format-NOP (0x100010D3) + vtable slot
                 0x100037A0 -> scratch stub baked into .data slack
  start_menu.exe compiled separately (launcher; see build_menu_loader.sh)

Files on disk in RuntimeLab/menu_build are PATCHED COPIES — the vanilla
GameFiles-VanillaV1 tree is never touched.
"""
import os
import shutil
import struct

import pefile

SRC_DIR = "G:/VibeRE/GiantsRE/RuntimeLab/GiantsWork"
OUT_DIR = "G:/VibeRE/GiantsRE/RuntimeLab/menu_build"

# Giants.exe patches: (VA, bytes)
EXE_PATCHES = [
    (0x53AE80, bytes.fromhex("B801000000C3")),      # cd_check -> return true
]

# gg_dx7r.dll patches
GG_FORMAT_NOP_VA = 0x100010D3
GG_VTABLE_SLOT_VA = 0x100037A0  # slot +0x10 of vtable at 0x10003790
STUB = bytes.fromhex("B8")      # mov eax, imm32 ; ret   (built below)


def rva_to_off(pe, rva):
    for s in pe.sections:
        va = pe.OPTIONAL_HEADER.ImageBase + s.VirtualAddress
        sz = max(s.Misc_VirtualSize, s.SizeOfRawData)
        if va <= rva < va + sz:
            delta = rva - va
            if delta < s.SizeOfRawData:
                return s.PointerToRawData + delta
    return None


def patch_bytes(buf, pe, va, data):
    off = rva_to_off(pe, va)
    assert off is not None, hex(va)
    buf[off:off + len(data)] = data
    return off


def find_zero_slack(buf, pe, min_len=96):
    """Find a run of >=min_len zero bytes in .data (VA, file offset)."""
    for s in pe.sections:
        if not s.Name.startswith(b".data"):
            continue
        raw = buf[s.PointerToRawData:s.PointerToRawData + s.SizeOfRawData]
        base_va = pe.OPTIONAL_HEADER.ImageBase + s.VirtualAddress
        run = 0
        for i, b in enumerate(raw):
            run = run + 1 if b == 0 else 0
            if run >= min_len:
                end = i + 1
                start = end - min_len
                return base_va + start, s.PointerToRawData + start
    return None, None


def main():
    os.makedirs(OUT_DIR, exist_ok=True)

    # ---- Giants.exe ----
    exe = open(f"{SRC_DIR}/Giants.exe", "rb").read()
    pe = pefile.PE(data=bytearray(exe))
    buf = bytearray(exe)
    for va, data in EXE_PATCHES:
        off = patch_bytes(buf, pe, va, data)
        print(f"[exe] patch @VA {hex(va)} -> file off {hex(off)}")
    open(f"{OUT_DIR}/Giants.exe", "wb").write(bytes(buf))
    print("[exe] written (len", len(buf), ")")

    # ---- gg_dx7r.dll ----
    dll = open(f"{SRC_DIR}/gg_dx7r.dll", "rb").read()
    pg = pefile.PE(data=bytearray(dll))
    gbuf = bytearray(dll)

    off = patch_bytes(gbuf, pg, GG_FORMAT_NOP_VA, bytes.fromhex("90" * 6))
    print(f"[gg] format-NOP @ {hex(GG_FORMAT_NOP_VA)} -> off {hex(off)}")

    # NO stub baked into .data: any byte we place inside the allocator pools
    # corrupts chunk headers (heap AV during enum). The launcher writes both
    # the stub and the slot redirect at runtime into the zero tail of .data.
    scratch_va = 0x1002B000  # deep in the loader-zeroed .data tail (beyond raw)
    print(f"[gg] .data left pristine; launcher will use scratch {hex(scratch_va)}")

    # NOTE: vtable redirect must NOT be static — the same slot is exercised
    # during device enumeration (temp bank test) where a scratch pointer gets
    # freed -> heap AV. It is applied by the launcher AFTER the SND dialog.
    # kill ASLR on the dll: absolute baked pointers require the preferred base
    dc = pg.OPTIONAL_HEADER.DllCharacteristics
    pg.OPTIONAL_HEADER.DllCharacteristics = dc & ~0x0040  # clear DYNAMIC_BASE
    print(f"[gg] DllCharacteristics {dc:#06x} -> {pg.OPTIONAL_HEADER.DllCharacteristics:#06x} (ASLR off)")
    pg.__data__ = None
    open(f"{OUT_DIR}/gg_dx7r.dll", "wb").write(bytes(gbuf))
    # rewrite header bytes via pefile to persist DllCharacteristics
    pe2 = pefile.PE(data=bytes(gbuf))
    pe2.OPTIONAL_HEADER.DllCharacteristics = dc & ~0x0040
    pe2.write(f"{OUT_DIR}/gg_dx7r.dll")
    print("[gg] written (ASLR disabled)")

    # sanity: vanilla untouched
    import hashlib
    h = hashlib.md5(open("G:/VibeRE/GiantsRE/GameFiles-VanillaV1/Giants.exe", "rb").read()).hexdigest()
    print("[check] vanilla md5:", h, "(must be 330c6a9a8ab0fa4b0173d925e1d5ec27)")


if __name__ == "__main__":
    main()
