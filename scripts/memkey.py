#!/usr/bin/env python3
"""Memory-driven input driver for Giants under x64dbg (P1.1 unlock).

Synthesizes keyboard events by writing the DIK bitfields the game's
dinput_key_poll (0x00519930) maintains:
  held:    0x5DD0C0[dik>>5]  bit (1 << (dik&31))
  pressed: 0x5DD0E0[dik>>5]  same bit (consumed by the per-frame rotation)

Usage (import): from memkey import press, snap
Snapshots: RuntimeLab/logs/traces/snap_N.png (flipped, viewable)
"""
import subprocess, json, time, struct, os, ctypes, ctypes.wintypes as wt

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TRACE = os.path.join(REPO, 'RuntimeLab', 'logs', 'traces')
GW = 1116704  # Giants window handle (re-find via find_window if stale)

DIK = {'ESC': 0x01, 'ENTER': 0x1C, 'SPACE': 0x39, 'LEFT': 0xCB, 'RIGHT': 0xCD,
       'UP': 0xC8, 'DOWN': 0xD0, 'DELETE': 0xD3, 'F1': 0x3B}


def call(tool, args, timeout=30):
    r = subprocess.run(['python', os.path.join(REPO, 'scripts', 'xdbg_call.py'), tool,
                        json.dumps(args)], capture_output=True, text=True, timeout=timeout)
    return r.stdout


def ival(s):
    return int(s.strip().splitlines()[0].split(' ')[0], 16)


def _rw(addr):
    call('ExecuteDebuggerCommand', {'command': 'pause'})
    time.sleep(0.4)
    return ival(call('EvalExpression', {'expression': '[0x%X]' % addr}))


def press(key, hold=0.25):
    dik = DIK.get(key, key) if isinstance(key, str) else key
    idx, bit = dik >> 5, 1 << (dik & 31)
    ha, pa = 0x5DD0C0 + idx * 4, 0x5DD0E0 + idx * 4
    h = _rw(ha)
    call('WriteMemToAddress', {'address': hex(ha), 'byteString': ' '.join(
        '%02X' % b for b in (h | bit).to_bytes(4, 'little'))})
    p = _rw(pa)
    call('WriteMemToAddress', {'address': hex(pa), 'byteString': ' '.join(
        '%02X' % b for b in (p | bit).to_bytes(4, 'little'))})
    call('ExecuteDebuggerCommand', {'command': 'g'})
    time.sleep(hold)
    h = _rw(ha)
    call('WriteMemToAddress', {'address': hex(ha), 'byteString': ' '.join(
        '%02X' % b for b in (h & ~bit).to_bytes(4, 'little'))})
    call('ExecuteDebuggerCommand', {'command': 'g'})
    time.sleep(0.35)


def snap(name):
    u, g = ctypes.windll.user32, ctypes.windll.gdi32
    global GW
    h = GW
    r = wt.RECT()
    u.GetWindowRect(h, ctypes.byref(r))
    w, hh = r.right - r.left, r.bottom - r.top
    hdc = u.GetWindowDC(h)
    mem = g.CreateCompatibleDC(hdc)
    bmp = g.CreateCompatibleBitmap(hdc, w, hh)
    g.SelectObject(mem, bmp)
    g.BitBlt(mem, 0, 0, w, hh, hdc, 0, 0, 0x00CC0020)

    class BMIH(ctypes.Structure):
        _fields_ = [('biSize', ctypes.c_uint32), ('biWidth', ctypes.c_int32),
                    ('biHeight', ctypes.c_int32), ('biPlanes', ctypes.c_uint16),
                    ('biBitCount', ctypes.c_uint16), ('biCompression', ctypes.c_uint32),
                    ('biSizeImage', ctypes.c_uint32), ('biXPels', ctypes.c_int32),
                    ('biYPels', ctypes.c_int32), ('biClrUsed', ctypes.c_uint32),
                    ('biClrImportant', ctypes.c_uint32)]

    class BMI(ctypes.Structure):
        _fields_ = [('bmiHeader', BMIH), ('biColors', ctypes.c_uint32 * 3)]

    bmi = BMI()
    bmi.bmiHeader.biSize = ctypes.sizeof(BMIH)
    bmi.bmiHeader.biWidth = w
    bmi.bmiHeader.biHeight = -hh
    bmi.bmiHeader.biPlanes = 1
    bmi.bmiHeader.biBitCount = 32
    buf = ctypes.create_string_buffer(w * hh * 4)
    g.GetDIBits(mem, bmp, 0, hh, buf, ctypes.byref(bmi), 0)
    fs = 14 + 40 + w * hh * 4
    hdr = b'BM' + struct.pack('<IHHI', fs, 0, 0, 54) + struct.pack(
        '<IiiHHIIiiII', 40, w, hh, 1, 32, 0, w * hh * 4, 0, 0, 0, 0)
    path = os.path.join(TRACE, name + '.bmp')
    open(path, 'wb').write(hdr + buf.raw)
    from PIL import Image
    png = os.path.join(TRACE, name + '.png')
    Image.open(path).transpose(Image.FLIP_TOP_BOTTOM).save(png)
    u.ReleaseDC(h, hdc)
    g.DeleteObject(bmp)
    g.DeleteDC(mem)
    return png


if __name__ == '__main__':
    import sys
    for step in sys.argv[1:]:
        press(step)
    print(snap('drive_last'))
