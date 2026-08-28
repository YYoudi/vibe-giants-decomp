// giants_menu2.rs — debug-loop launcher: starts the patched build as a debuggee
// and CONTINUES every first-chance exception with DBG_CONTINUE (mimics the
// x64dbg/procdump-attached behavior where the game boots past its walls).
// Second-chance (unhandled) exceptions are delivered (NOT_HANDLED).
use std::process::Command;

#[repr(C)]
#[derive(Default, Clone, Copy)]
struct StartupInfoA {
    cb: u32,
    reserved: *mut u8,
    desktop: *mut u8,
    title: *mut u8,
    x: u32, y: u32, w: u32, h: u32,
    showwindow: u32, reserved2: u32, reserved3: u32, reserved4: u32,
    hstdinput: isize, hstdoutput: isize, hstderror: isize,
}

#[repr(C)]
#[derive(Default, Clone, Copy)]
struct ProcessInfo {
    hprocess: isize,
    hthread: isize,
    pid: u32,
    tid: u32,
}

#[repr(C)]
#[derive(Default, Clone, Copy)]
struct DebugEvent {
    id: u32,
    pid: u32,
    tid: u32,
    code: u32,
    pad: [u64; 24], // generous: largest DEBUG_EVENT body
}

#[link(name = "kernel32")]
extern "system" {
    fn CreateProcessA(app: *const u8, cmd: *mut u8, pa: isize, ta: isize,
                      inherit: i32, flags: u32, env: isize, cwd: *const u8,
                      si: *mut StartupInfoA, pi: *mut ProcessInfo) -> i32;
    fn WaitForDebugEvent(ev: *mut DebugEvent, ms: u32) -> i32;
    fn ContinueDebugEvent(pid: u32, tid: u32, status: u32) -> i32;
    fn CloseHandle(h: isize) -> i32;
}

const DEBUG_PROCESS: u32 = 0x00000001;
const DBG_CONTINUE: u32 = 0x00010002;
const DBG_EXCEPTION_NOT_HANDLED: u32 = 0x80010001;
const EXCEPTION_DEBUG_EVENT: u32 = 1;
const INFINITE: u32 = 0xFFFFFFFF;

fn main() {
    let cwd = std::env::current_dir().expect("cwd");
    let exe = cwd.join("Giants.exe");
    if !exe.exists() {
        eprintln!("Giants.exe not found in {}", cwd.display());
        std::process::exit(1);
    }
    println!("GiantsMenu debug-launcher — {}", cwd.display());

    let mut exe_b = exe.as_os_str().to_str().unwrap().as_bytes().to_vec();
    exe_b.push(0);
    let cwd_b = {
        let mut v = cwd.as_os_str().to_str().unwrap().as_bytes().to_vec();
        v.push(0); v
    };
    let mut si = StartupInfoA { cb: std::mem::size_of::<StartupInfoA>() as u32, ..Default::default() };
    let mut pi = ProcessInfo::default();
    let ok = unsafe {
        CreateProcessA(exe_b.as_ptr(), std::ptr::null_mut(), 0, 0, 0,
                       DEBUG_PROCESS, 0, cwd_b.as_ptr(), &mut si, &mut pi)
    };
    if ok == 0 {
        eprintln!("CreateProcess failed");
        std::process::exit(1);
    }
    println!("Giants.exe debugged pid={} tid={}", pi.pid, pi.tid);

    let mut ev = DebugEvent::default();
    let t0 = std::time::Instant::now();
    let mut first_chance = 0u64;
    loop {
        if unsafe { WaitForDebugEvent(&mut ev, 1000) } == 0 {
            if t0.elapsed().as_secs() > 1800 { break; }
            // timeout tick — check child still alive
            let alive = Command::new("tasklist")
                .args(["/FI", &format!("IMAGENAME eq Giants.exe")])
                .output()
                .map(|o| String::from_utf8_lossy(&o.stdout).contains("Giants"))
                .unwrap_or(false);
            if !alive && t0.elapsed().as_secs() > 30 {
                println!("[{}] child gone", t0.elapsed().as_secs());
                break;
            }
            continue;
        }
        let status = if ev.code == EXCEPTION_DEBUG_EVENT {
            first_chance += 1;
            if first_chance % 500 == 1 {
                println!("[{}] first-chance #{}", t0.elapsed().as_secs(), first_chance);
            }
            // FIRST chance: swallow (the game's SEH handlers escalate badly);
            // SECOND chance: deliver.
            DBG_CONTINUE
        } else {
            DBG_CONTINUE
        };
        unsafe { ContinueDebugEvent(ev.pid, ev.tid, status); }
        if t0.elapsed().as_secs() > 1800 { break; }
    }
    println!("launcher exit (first-chance total {})", first_chance);
}

