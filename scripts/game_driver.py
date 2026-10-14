#!/usr/bin/env python3
"""game_driver.py — OS-level input driver for Giants (P1.1 voie 3).

SendInput-based (raw scan codes, no external deps). MUST run elevated
(Giants.exe self-elevates; UIPI blocks non-elevated SendInput into it).
Pairs with the x32dbg trace sensor: drive gameplay while the BP sensor records.

Usage (elevated):
    python scripts/game_driver.py <HWND_HEX> [seconds]
Behavior: focus the game window, then a scripted activity sequence:
look around (mouse moves), walk forward (RMB hold), fire (LMB taps), repeat.
"""
import ctypes
import sys
import time

user32 = ctypes.windll.user32
SendInput = user32.SendInput

# SendInput structures
PUL = ctypes.POINTER(ctypes.c_ulong)


class KEYBDINPUT(ctypes.Structure):
    _fields_ = [("wVk", ctypes.c_ushort), ("wScan", ctypes.c_ushort),
                ("dwFlags", ctypes.c_ulong), ("time", ctypes.c_ulong),
                ("dwExtraInfo", PUL)]


class MOUSEINPUT(ctypes.Structure):
    _fields_ = [("dx", ctypes.c_long), ("dy", ctypes.c_long),
                ("mouseData", ctypes.c_ulong), ("dwFlags", ctypes.c_ulong),
                ("time", ctypes.c_ulong), ("dwExtraInfo", PUL)]


class INPUT_I(ctypes.Union):
    _fields_ = [("ki", KEYBDINPUT), ("mi", MOUSEINPUT)]


class INPUT(ctypes.Structure):
    _fields_ = [("type", ctypes.c_ulong), ("ii", INPUT_I)]


MOUSEEVENTF_MOVE = 0x0001
MOUSEEVENTF_LEFTDOWN = 0x0002
MOUSEEVENTF_LEFTUP = 0x0004
MOUSEEVENTF_RIGHTDOWN = 0x0008
MOUSEEVENTF_RIGHTUP = 0x0010
INPUT_MOUSE = 0
INPUT_KEYBOARD = 1
KEYEVENTF_KEYUP = 0x0002
KEYEVENTF_SCANCODE = 0x0008


def mouse_move(dx, dy):
    ii = INPUT_I()
    ii.mi = MOUSEINPUT(dx, dy, 0, MOUSEEVENTF_MOVE, 0, None)
    inp = INPUT(INPUT_MOUSE, ii)
    SendInput(1, ctypes.byref(inp), ctypes.sizeof(inp))


def mouse_btn(down, right=False):
    flag = (MOUSEEVENTF_RIGHTDOWN if right else MOUSEEVENTF_LEFTDOWN) if down else \
           (MOUSEEVENTF_RIGHTUP if right else MOUSEEVENTF_LEFTUP)
    ii = INPUT_I()
    ii.mi = MOUSEINPUT(0, 0, 0, flag, 0, None)
    inp = INPUT(INPUT_MOUSE, ii)
    SendInput(1, ctypes.byref(inp), ctypes.sizeof(inp))


def key(sc, down):
    ii = INPUT_I()
    ii.ki = KEYBDINPUT(0, sc, KEYEVENTF_SCANCODE if down else
                        KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP, 0, None)
    inp = INPUT(INPUT_KEYBOARD, ii)
    SendInput(1, ctypes.byref(inp), ctypes.sizeof(inp))


def focus(hwnd):
    user32.ShowWindow(hwnd, 9)
    user32.SetForegroundWindow(hwnd)
    time.sleep(0.8)


def activity_cycle():
    """One gameplay activity cycle: look, walk, fire."""
    # look right/left
    for dx in (40, 40, -80, -40):
        mouse_move(dx, 0)
        time.sleep(0.12)
    # walk forward: hold RMB + push cursor up (Giants walks toward cursor)
    mouse_btn(True, right=True)
    time.sleep(0.1)
    for _ in range(6):
        mouse_move(0, -30)
        time.sleep(0.12)
    mouse_move(0, -180)  # big pull = sustained walk
    time.sleep(1.4)
    mouse_btn(False, right=True)
    # fire a burst
    for _ in range(3):
        mouse_btn(True)
        time.sleep(0.15)
        mouse_btn(False)
        time.sleep(0.35)


def main():
    hwnd = int(sys.argv[1], 16 if sys.argv[1].startswith('0x') else 10)
    seconds = float(sys.argv[2]) if len(sys.argv) > 2 else 90
    focus(hwnd)
    t0 = time.time()
    n = 0
    while time.time() - t0 < seconds:
        activity_cycle()
        n += 1
        print('cycle', n, flush=True)
    print('done', n, 'cycles', flush=True)


if __name__ == '__main__':
    main()
