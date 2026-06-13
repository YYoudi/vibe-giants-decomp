cmake_minimum_required(VERSION 3.20)
project(GiantsRE CXX)

# ─── x86 32-bit target ────────────────────────────────────────
# GiantsMain.exe is PE32 x86, all stubs must compile as 32-bit
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(WARNING " GiantsRE requires 32-bit compilation.")
    message(WARNING " MSVC: run from 'x86 Native Tools Command Prompt'")
    message(WARNING " MinGW: set -DCMAKE_CXX_FLAGS=-m32")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler-specific flags
if(MSVC)
    add_compile_options(/W3 /Zi /Od)
    # Force 32-bit
    set(CMAKE_GENERATOR_PLATFORM Win32 CACHE STRING "" FORCE)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-m32 -g -Wall -Wno-unknown-pragmas -fpermissive)
    add_link_options(-m32 -static-libgcc -static-libstdc++ -Wl,-Bstatic,-lwinpthread,-Bdynamic)
endif()

# ─── Stub headers for missing Windows/DirectX types ──────────
# These provide minimal declarations so our reversed code compiles
# without requiring the full DX SDK
include_directories(${CMAKE_SOURCE_DIR}/stubs)

# ─── Source files ─────────────────────────────────────────────
# Auto-discover all source files — ensures new modules are always compiled
file(GLOB_RECURSE ENGINE_SOURCES
    "src/engine/*.cpp"
    "src/renderer/*.cpp"
    "src/vfs/*.cpp"
)

file(GLOB_RECURSE ENGINE_HEADERS
    "src/engine/*.h"
    "src/renderer/*.h"
    "src/vfs/*.h"
)

# ─── Main library target ─────────────────────────────────────
add_library(giants_engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

target_include_directories(giants_engine PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/stubs
)

# Link Windows libraries (no-op on non-Windows, but we only target Windows)
if(WIN32)
    target_link_libraries(giants_engine PRIVATE
        dinput8
        dxguid
        winmm
        advapi32
        user32
        gdi32
    )
endif()

# ─── Compilation check target ────────────────────────────────
# 'make check' or 'cmake --build . --target check' — compile only, no linking
add_custom_target(check
    COMMAND ${CMAKE_COMMAND} -E echo "Checking compilation..."
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target giants_engine
    COMMAND ${CMAKE_COMMAND} -E echo "Compilation check passed."
    VERBATIM
)

# ─── Verification report target ──────────────────────────────
add_custom_target(report
    COMMAND ${CMAKE_COMMAND} -E echo "RE-TRACKER stats:"
    COMMAND python -c "import json; d=json.load(open('${CMAKE_SOURCE_DIR}/RE-TRACKER.json')); print(f'  Tracked: {d[\"stats\"][\"tracked\"]}'); print(f'  Reversed: {d[\"stats\"][\"reversed\"]} (PASS: {d[\"stats\"][\"pass\"]}, FAIL: {d[\"stats\"][\"fail_usable\"]})'); print(f'  Queued: {d[\"stats\"][\"queued\"]}'); print(f'  Source: {d[\"stats\"][\"source_lines\"]} lines, {d[\"stats\"][\"source_files\"]} files')"
    VERBATIM
)

# ═══════════════════════════════════════════════════════════════════
# Proxy DLL — gg_dx9r.dll replacement
# Loads the real gg_dx9r_orig.dll and forwards all 3 renderer exports.
# Enables hooking of engine→renderer callbacks for gradual replacement.
# ═══════════════════════════════════════════════════════════════════

file(GLOB PROXY_SOURCES "proxy/*.cpp" "proxy/*.h")

add_library(gg_dx9r SHARED ${PROXY_SOURCES})

# Ensure frame pointers for leave+jmp tail-call forwarding in proxy hooks
target_compile_options(gg_dx9r PRIVATE -fno-omit-frame-pointer)

# Use .def file for exact export ordinals
target_sources(gg_dx9r PRIVATE ${CMAKE_SOURCE_DIR}/proxy/ProxyDef.def)

# Link against our RE'd engine code (static lib)
# NOTE: Disabled for now — proxy only needs forwarding, not the full engine.
#       Re-enable when we start replacing functions with our implementations.
target_link_libraries(gg_dx9r PRIVATE giants_engine)

# Windows libraries
if(WIN32)
    target_link_libraries(gg_dx9r PRIVATE
        dinput8 dxguid winmm advapi32 user32 gdi32
    )
endif()

target_include_directories(gg_dx9r PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/stubs
    ${CMAKE_SOURCE_DIR}/proxy
)

# Output name must match exactly what the game expects
set_target_properties(gg_dx9r PROPERTIES
    OUTPUT_NAME "gg_dx9r"
    PREFIX ""
    SUFFIX ".dll"
)

# ═══════════════════════════════════════════════════════════════════
# Standalone GiantsMain.exe — recompiled from reverse-engineered C++
# Links against giants_engine (static lib with all 6254 RE'd functions).
# Entry point: WinMain → InitializeEngine → MainGameLoop
# ═══════════════════════════════════════════════════════════════════

# Main entry point source (separate from engine library to avoid CRT conflicts)
set(MAIN_SOURCES
    "src/main/WinMain.cpp"
)

add_executable(GiantsMain WIN32 ${MAIN_SOURCES})

# Link against the full engine static lib
target_link_libraries(GiantsMain PRIVATE giants_engine)

# Emit a linker map so crash addresses (from the vectored handler's stack walk)
# can be resolved to function names.
target_link_options(GiantsMain PRIVATE -Wl,-Map,build_recomp/GiantsMain.map)

# Windows libraries (same as engine + proxy)
if(WIN32)
    target_link_libraries(GiantsMain PRIVATE
        dinput8 dxguid winmm advapi32 user32 gdi32
    )
endif()

target_include_directories(GiantsMain PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/stubs
)

# Output to build_recomp/ — NEVER clobber the original GameFiles/GiantsMain.exe
# (the original is the proxy's oracle; overwriting it breaks validation).
set_target_properties(GiantsMain PROPERTIES
    OUTPUT_NAME "GiantsMain"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build_recomp"
)
