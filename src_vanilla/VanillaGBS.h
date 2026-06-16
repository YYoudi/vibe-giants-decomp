// Giants Vanilla-Native Recomp — GBS model parser.
// Parses .gbs meshes (magic 0xAA0100BE) — 3D models (characters, objects, props).
// Format (spec: memory/giants-format-specs.md):
//   [magic:u32=0xAA0100BE][options:u32][num_vertices:u32]
//   options: Normals=0x1, UVs=0x2, RGBs=0x4, CalcNormals=0x8
//   vertices: num_vertices × Vec3(f32×3)
//   [if Normals] nndefs:u32, num_normals:u32, normals:u16[num_normals]
//   nverts:u32, indexed_vertices:u16[nverts]
//   [if Normals] indexed_normals:u16[nverts]
//   [if UVs] vertuv:f32[2][nverts]   (V flipped: v*-1)
//   [if RGBs] vertrgb:u8[3][nverts]
//   MaxObjs: nmobjs:u32, each [vstart,vcount,nstart,ncount,noffset] i32×5
//   SubObjects: nsobjs:u32, each: objname[32], maxobjindex:i32, totaltris:i32, ntris:i32,
//     tridata:u16[ntris] (RLE [count:u16][count×3 idx]), verticeref_start:i32, verticeref_count:i32,
//     [if UVs] texname[32]+bumpname[32], falloff:f32, [if RGBs] blend:f32, flags:i32,
//     emissive/ambient/diffuse/specular:i32 (packed BBGGRR), power:f32
#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace VanillaGBS {

struct Model {
    uint32_t magic, options, numVertices;
    bool hasNormals, hasUVs, hasRGBs;
    std::vector<float>   vertices;   // numVertices*3
    uint32_t nverts;                 // indexed vertex count
    uint32_t numSubObjects;
    std::vector<std::string> subObjectNames;
    std::vector<std::string> texNames;
    bool ok = false;
};

Model Parse(const uint8_t* data, size_t len);
bool SelfTest();   // parses intro_1.gbs from xx_intro.gzp, logs structure
} // namespace VanillaGBS
