// Giants Vanilla-Native Recomp — VFS data layer (GZP archive reader).
// Ports the GZP archive format (spec: memory/giants-format-specs.md, mined from
// Amazed's clean-room RE). GZP = the engine's packed-asset archive (textures,
// meshes, sounds). The renderer/scene loader need this to load real game data.
//
// Format (little-endian):
//   Header: [magic:u32 = 0x6608F101][metaOffset:u32]
//   At metaOffset: [unk:u32][count:u32]
//   Per entry: [compSize:u32][uncmpSize:u32][date:u32][start:u32][compr:u8][nameLen:u8][name:nameLen+null]
//   File content lives at (start + 16) — there's a 16-byte per-file sub-header.
//   If compr==0 the content is stored raw (compSize bytes); else LZ-compressed.
//
// LZ decompressor: bit-stream, bit=1 literal byte, bit=0 backref. backref:
//   decpos = ((b0 + ((b1 & 0xF0)<<4) - 0xFEE - j) & 0xFFF) - 0x1000 + j
//   declen = (b1 & 0xF) + 3 ; window 0xFEE, neg-offset → 0x20 (space).
#pragma once
#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>

namespace VanillaVFS {

struct GzpEntry {
    uint32_t compSize;
    uint32_t uncmpSize;
    uint32_t date;
    uint32_t start;     // content start (file offset); real content at start+16
    uint8_t  compr;
    std::string name;   // filename, no path, with extension
};

// Open + parse a .gzp archive. Returns false on bad magic / read error.
bool GzpOpen(const char* path, std::vector<GzpEntry>& outEntries);

// Load a file from an archive by name (case-insensitive, filename only).
// Returns the decompressed bytes, or empty vector if not found / error.
std::vector<uint8_t> GzpReadFile(const char* archivePath, const char* fileName);

// LZ decompress (the GZP codec). out must be sized to originalSize.
bool LzDecompress(const uint8_t* src, size_t srcLen, uint8_t* out, size_t originalSize);

// Self-test: open a real .gzp, list entries, decompress one. Logs to the vanilla trace.
// Returns the entry count (0 on failure). Used to validate the VFS data layer.
int SelfTest(const char* archivePath);

} // namespace VanillaVFS
