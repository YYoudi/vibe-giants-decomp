#!/usr/bin/env python3
"""Q13 proof: xx section-3 offsets are relative to the buffer AFTER the
leading u32 section tag — the decomp walk (+4) and the giants-rs walk (+8,
base including the tag) are the SAME bytes.

Run: python tools_spec/xx_section3_tag_proof.py
All asserts passing = the Q13 answer holds on the shipped file.
"""
import struct

PATH = "G:/Games/Giants/Bin/xx_mecclev1.bin"
SEC = 0x1A6B            # file offset of section 3 (M9 note)

def main():
    data = open(PATH, "rb").read()
    dw = lambda a: struct.unpack_from("<I", data, a)[0]

    # 1) the section starts with a u32 tag; the loader buffer starts after it
    tag = dw(SEC)
    assert tag == 0x4D0D, hex(tag)          # observed mecclev1 tag
    base = SEC + 4                          # == the MemAllocMsg buffer base

    # 2) name records: {u32 set_id @+0 ; strz @+4} in the buffer convention
    n_names = dw(base)
    assert n_names == 102, n_names
    off = [dw(base + 4 + i * 4) for i in range(n_names)]
    assert off[1] - off[0] == 0xC           # stride: 4 + len("mc_l0")+1 + pad
    for i, expect_id, expect_name in ((0, 0x14, b"mc_l0"), (1, 0x15, b"mc_l1"),
                                      (2, 0x16, b"mc_l2"), (3, 0x17, b"mc_l3")):
        a = base + off[i]                   # decomp convention
        assert dw(a) == expect_id, (i, hex(dw(a)))
        assert data[a + 4:a + 12].split(b"\0")[0] == expect_name
        # giants-rs convention (base includes the tag): one extra dword before
        aw = SEC + off[i]
        assert data[aw + 8:aw + 16].split(b"\0")[0] == expect_name

    # the "extra" dword the worker saw before rec1..3 is the TAIL of the
    # previous name string itself ("mc_l0": '0'=0x30 + NUL padding)
    a1w = SEC + off[1]
    assert dw(a1w) == 0x30 and data[a1w - 4:a1w + 1] == b"mc_l0", hex(dw(a1w))

    # 3) instance blocks: dword0 = type_id (object_find), stream @+4
    p = base + 4 + n_names * 4
    c1 = dw(p); p += 4 + c1 * 4             # skipped table
    n_specs = dw(p); p += 4 + n_specs * 4
    n_inst = dw(p); p += 4
    inst_off = [dw(p + i * 4) for i in range(n_inst)]
    a = base + inst_off[0]
    prev = dw(a - 4)
    # the dword before block0 carries the previous ospec stream terminator:
    # 0xff + the trailing 1.0f (0x3f800000) of the spec block (l.15224)
    assert (prev & 0xFF000000) == 0xFF000000 or prev == 0xFF3F8000, hex(prev)
    type_id = dw(a)
    assert data[a + 4] == 0x01, hex(data[a + 4])   # first opcode = op 1
    print("OK — tag convention proven:",
          f"n_names={n_names} C1={c1} n_specs={n_specs} n_inst={n_inst}",
          f"inst0 type_id={type_id} prev_dword={prev:#x}",
          "stream starts at buffer-base + inst_off + 4", sep="\n  ")

if __name__ == "__main__":
    main()
