// GiantsMenu — compiled launcher for the RE-patched Giants v1.0 build.
// Launches RuntimeLab\menu_build\Giants.exe, then auto-dismisses the known
// init dialogs (Enter for custom dialogs, OK-click for "Giants Error" boxes)
// until the main menu state. Build: rustc giants_menu.rs -o GiantsMenu.exe
use std::process::Command;

#[link(name = "user32")]
extern "system" {
    fn SetForegroundWindow(h: isize) -> i32;
    fn ShowWindow(h: isize, cmd: i32) -> i32;
    fn keybd_event(k: u8, s: u8, f: u32, e: usize);
    fn SetCursorPos(x: i32, y: i32) -> i32;
    fn mouse_event(f: u32, dx: i32, dy: i32, d: i32, e: usize);
    fn FindWindowW(cls: *const u16, title: *const u16) -> isize;
    fn OpenProcess(access: u32, inherit: i32, pid: u32) -> isize;
    fn WriteProcessMemory(h: isize, addr: *mut u8, buf: *const u8, size: usize, written: *mut usize) -> i32;
    fn EnumProcessModulesEx(h: isize, mods: *mut isize, cb: u32, needed: *mut u32, filter: u32) -> i32;
    fn GetModuleFileNameExW(h: isize, m: isize, buf: *mut u16, size: u32) -> u32;
    fn CloseHandle(h: isize) -> i32;
}

const PROCESS_VM_OPERATION: u32 = 0x0008;
const PROCESS_VM_READ: u32 = 0x0010;
const PROCESS_VM_WRITE: u32 = 0x0020;
const PROCESS_QUERY_INFORMATION: u32 = 0x0400;
const LIST_MODULES_32BIT: u32 = 0x01;

/// After the SND dialog is dismissed: write the vtable-slot redirect into the
/// live game (slot = gg_base+0x37A0 -> gg_base+0x19E38 stub baked in .data).
fn apply_redirect(pid: u32) {
    unsafe {
        let h = OpenProcess(
            PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION,
            0, pid);
        if h == 0 { println!("  redirect: OpenProcess failed"); return; }
        let mut mods = [0isize; 1024];
        let mut needed = 0u32;
        if EnumProcessModulesEx(h, mods.as_mut_ptr(),
            (mods.len() * std::mem::size_of::<isize>()) as u32, &mut needed, LIST_MODULES_32BIT) == 0 {
            println!("  redirect: EnumProcessModulesEx failed"); CloseHandle(h); return;
        }
        let count = (needed as usize / std::mem::size_of::<isize>()).min(mods.len());
        let mut gg_base = 0usize;
        let mut namebuf = [0u16; 512];
        for i in 0..count {
            let n = GetModuleFileNameExW(h, mods[i], namebuf.as_mut_ptr(), 512);
            let s = String::from_utf16_lossy(&namebuf[..n as usize]);
            if s.to_lowercase().ends_with("gg_dx7r.dll") { gg_base = mods[i] as usize; break; }
        }
        if gg_base == 0 { println!("  redirect: gg_dx7r not found"); CloseHandle(h); return; }
        let slot = gg_base + 0x37A0;
        let scratch = gg_base + 0x2B000; // loader-zeroed .data tail, outside pools
        // 1) write stub into scratch: mov eax, scratch ; ret
        let stub = {
            let mut v = vec![0xB8u8];
            v.extend_from_slice(&(scratch as u32).to_le_bytes());
            v.push(0xC3);
            v
        };
        let mut w1 = 0usize;
        let ok1 = WriteProcessMemory(h, scratch as *mut u8, stub.as_ptr(), stub.len(), &mut w1);
        // 2) redirect slot -> scratch
        let mut w2 = 0usize;
        let ok2 = WriteProcessMemory(h, slot as *mut u8, (scratch as u32).to_le_bytes().as_ptr(), 4, &mut w2);
        println!("  redirect: stub@{:#x} w={} ok={} ; slot {:#x} -> {:#x} w={} ok={}",
                 scratch, w1, ok1, slot, scratch, w2, ok2);
        CloseHandle(h);
    }
}

fn send_enter() {
    unsafe { keybd_event(0x0D, 0, 0, 0); }
    std::thread::sleep(std::time::Duration::from_millis(60));
    unsafe { keybd_event(0x0D, 0, 2, 0); }
}

fn wide(s: &str) -> Vec<u16> {
    s.encode_utf16().chain(std::iter::once(0)).collect()
}

fn foreground_menu_window() -> isize {
    unsafe { FindWindowW(std::ptr::null(), wide("Giants").as_ptr()) }
}

fn click(fx: f64, fy: f64) {
    // window-relative click using the 'Giants' window rect via GetWindowRect-lite:
    // we approximate with fixed screen guess from earlier sessions if rect fails.
    #[link(name = "user32")]
    extern "system" {
        fn GetWindowRect(h: isize, r: *mut i32) -> i32;
    }
    let h = foreground_menu_window();
    if h == 0 { return; }
    let mut r = [0i32; 4];
    unsafe { GetWindowRect(h, r.as_mut_ptr()); }
    let x = r[0] + ((r[2] - r[0]) as f64 * fx) as i32;
    let y = r[1] + ((r[3] - r[1]) as f64 * fy) as i32;
    unsafe {
        SetCursorPos(x, y);
        std::thread::sleep(std::time::Duration::from_millis(150));
        mouse_event(2, 0, 0, 0, 0);
        std::thread::sleep(std::time::Duration::from_millis(70));
        mouse_event(4, 0, 0, 0, 0);
    }
}

fn main() {
    let base = std::env::current_dir().expect("cwd");
    let exe = base.join("Giants.exe");
    println!("GiantsMenu launcher — cwd {}", base.display());
    if !exe.exists() {
        eprintln!("Giants.exe not found in current directory.");
        eprintln!("Run this from RuntimeLab\\menu_build (patched copy).");
        std::process::exit(1);
    }
    let child = Command::new(&exe).spawn().expect("spawn Giants.exe");
    println!("Giants.exe pid={}", child.id());

    // init takes ~2-4 min: enum rounds, dialogs.
    // Dialog/dismiss schedule (validated in sessions):
    //   t≈35-90s  custom renderer dialogs -> Enter
    //   t≈60-140s "Giants Error: ErrFailedSND" native box -> OK at (0.33, 0.90)
    //   t≈150s+   possible second SND box / menu appearing -> Enter + OK
    // rotation: OK-click (native 'Giants Error'), alt-click (custom dialogs), Enter
    let schedule: [(u64, u8); 12] = [
        (35, 1), (55, 2), (75, 0), (95, 1), (115, 2), (135, 0),
        (160, 1), (185, 2), (210, 0), (235, 1), (260, 2), (285, 0),
    ]; // 1 = OK (0.33,0.90)  2 = alt (0.26,0.74)  0 = Enter
    let mut redirect_done = false;
    let t0 = std::time::Instant::now();
    for (at, kind) in schedule {
        while t0.elapsed().as_secs() < at {
            std::thread::sleep(std::time::Duration::from_millis(500));
        }
        let h = foreground_menu_window();
        if h != 0 {
            unsafe { ShowWindow(h, 9); SetForegroundWindow(h); }
            std::thread::sleep(std::time::Duration::from_millis(250));
            match kind {
                0 => { send_enter(); println!("[{}] Enter", t0.elapsed().as_secs()); }
                9 => {}
                1 => { click(0.33, 0.90); println!("[{}] OK-click", t0.elapsed().as_secs()); }
                _ => { click(0.26, 0.74); println!("[{}] alt-click", t0.elapsed().as_secs()); }
            }
        } else {
            println!("[{}] no Giants window (exited?)", t0.elapsed().as_secs());
        }
    }
    println!("Launcher sequence done. If the menu is up, play; window title should be 'Giants'.");
}
