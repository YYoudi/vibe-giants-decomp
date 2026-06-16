// Giants Vanilla-Native Recomp — TGA texture parser.
// Parses .tga images (the engine's texture format — intro_sea.tga, intro_grnd.tga, etc.
// in the GZP archives). Standard TGA: 18-byte header [+ optional ID field] + image data.
// Supports the uncompressed true-color (type 2) variants the game uses (16/24/32-bit).
// A building block for the renderer's texture pipeline (callback[12] TextureLoader).
#pragma once
#include <cstdint>
#include <vector>

namespace VanillaTGA {
struct Image {
    uint16_t width, height;
    uint8_t  bitsPerPixel;     // 16/24/32
    uint8_t  imageType;        // 2 = uncompressed true-color, 10 = RLE true-color
    std::vector<uint8_t> pixels;  // width*height*(bpp/8) bytes
    bool ok = false;
};
Image Parse(const uint8_t* data, size_t len);
bool SelfTest();   // parses intro_sea.tga from w_intro_island.gzp, logs dims
} // namespace VanillaTGA
