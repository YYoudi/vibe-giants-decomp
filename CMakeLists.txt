cmake_minimum_required(VERSION 3.20)
project(GiantsRE CXX)

# ═════════════════════════════════════════════════════════════════
# Giants: Citizen Kabuto — vanilla 1.0 native recomp (CANONICAL TARGET).
# 100% vanilla-only. The 1.5/DX9 path was DELETED (it caused version/address drift:
# the Ghidra project + decompile were v1.5 GiantsMain.exe, not vanilla Giants_nocd.exe).
# Binary: GameFiles-VanillaV1/Giants_nocd.exe (2574 fns, DX7 gg_dx7r.dll).
# ═════════════════════════════════════════════════════════════════

# ─── x86 32-bit target (vanilla Giants_nocd.exe is PE32 x86) ───
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
    add_compile_options(/W3 /Zi /Od)
    set(CMAKE_GENERATOR_PLATFORM Win32 CACHE STRING "" FORCE)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-m32 -g -Wall -Wno-unknown-pragmas -fpermissive)
    add_link_options(-m32 -static-libgcc -static-libstdc++ -Wl,-Bstatic,-lwinpthread,-Bdynamic)
endif()

# ═════════════════════════════════════════════════════════════════
# Target 1: GiantsMain_vanilla — the vanilla 1.0 recomp (canonical).
# src_vanilla/ = vanilla-native source (ported from vanilla_decompiled/, which must be
# regenerated from Giants_nocd.exe — the OLD decompile was v1.5, DELETED).
# ═════════════════════════════════════════════════════════════════
file(GLOB VANILLA_SOURCES "src_vanilla/*.cpp")
add_executable(GiantsMain_vanilla WIN32 ${VANILLA_SOURCES})
target_link_libraries(GiantsMain_vanilla PRIVATE user32 gdi32 dinput dxguid ddraw)
target_compile_options(GiantsMain_vanilla PRIVATE -m32)
target_link_options(GiantsMain_vanilla PRIVATE -m32 -static-libgcc -static-libstdc++ -Wl,-Map,build_recomp/GiantsMain_vanilla.map)
set_target_properties(GiantsMain_vanilla PROPERTIES
    OUTPUT_NAME "GiantsMain_vanilla"
    RUNTIME_OUTPUT_DIRECTORY "build_recomp"
)

# ═════════════════════════════════════════════════════════════════
# Target 2: gg_dx7r_proxy — vanilla DX7 capture proxy (C5 oracle).
# Builds gg_dx7r.dll. Deploy: rename real gg_dx7r.dll → gg_dx7r_orig.dll, drop this AS
# gg_dx7r.dll. Captures the original's 21 UpCallsLoad callbacks + the D3D7 render trace.
# ═════════════════════════════════════════════════════════════════
add_library(gg_dx7r_proxy SHARED ${CMAKE_SOURCE_DIR}/proxy_dx7/dx7_proxy_main.cpp)
target_include_directories(gg_dx7r_proxy PRIVATE ${CMAKE_SOURCE_DIR}/proxy_dx7)
set_target_properties(gg_dx7r_proxy PROPERTIES OUTPUT_NAME "gg_dx7r" PREFIX "" SUFFIX ".dll")
target_sources(gg_dx7r_proxy PRIVATE ${CMAKE_SOURCE_DIR}/proxy_dx7/Dx7ProxyDef.def)
target_link_libraries(gg_dx7r_proxy PRIVATE psapi)
