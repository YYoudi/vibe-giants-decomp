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
                1 => { click(0.33, 0.90); println!("[{}] OK-click", t0.elapsed().as_secs()); }
                _ => { click(0.26, 0.74); println!("[{}] alt-click", t0.elapsed().as_secs()); }
            }
        } else {
            println!("[{}] no Giants window (exited?)", t0.elapsed().as_secs());
        }
    }
    println!("Launcher sequence done. If the menu is up, play; window title should be 'Giants'.");
}
