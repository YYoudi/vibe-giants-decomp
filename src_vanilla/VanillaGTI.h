// Giants Vanilla-Native Recomp — GTI terrain parser.
// Parses the .gti heightfield (the island/world terrain — the main visible 3D content).
// Format (spec: memory/giants-format-specs.md, mined from Amazed's clean-room RE):
//   Header (96 bytes): [0]sig=0x94965003 [8]XOff:f32 [12]YOff:f32 [16]minH:f32 [20]maxH:f32
//                       [24]Width:u32 [28]Height:u32 [32]Stretch:f32 [56]version:u16 [68]texname[32]
//   RLE cells after header: byte b. if b>=0x80 → skip (256-b) cells (use default height=minH).
//     else read (b+1) cells, each 8 bytes: [height:f32][triFlag:u8][R:u8][G:u8][B:u8].
//   Total cells = Width*Height (a heightfield grid).
#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace VanillaGTI {

struct Cell {            // 8 bytes, matches the on-disk cell record
    float    height;
    uint8_t  triFlag;
    uint8_t  r, g, b;
};

struct Terrain {
    uint32_t sig;
    float    xOff, yOff, minH, maxH, stretch;
    uint32_t width, height;
    uint16_t version;
    char     texname[33];
    std::vector<Cell> cells;   // width*height
    bool     ok = false;
};

// Parse a .gti from a byte buffer (use VanillaVFS::GzpReadFile or FUN_00539e30 to obtain it).
Terrain Parse(const uint8_t* data, size_t len);

// Self-test: parse intro_island.gti (via VFS), log dimensions + height range + a sample.
bool SelfTest();

} // namespace VanillaGTI
