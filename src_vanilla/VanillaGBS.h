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

// A sub-object: a named mesh part with its own triangle indices (into indexedVertices)
// + material. tris is a flat list of vertex-pool indices (3 per triangle).
struct SubObj {
    std::string name;
    std::vector<uint16_t> tris;   // decoded RLE tridata; len = 3 * triangle_count
    int32_t  verticeref_start = 0;
    int32_t  verticeref_count = 0;
    uint32_t totaltris = 0;
    uint32_t diffuse = 0xFFFFFFFF;   // packed BBGGRR material diffuse
};

struct Model {
    uint32_t magic, options, numVertices;
    bool hasNormals, hasUVs, hasRGBs;
    std::vector<float>   vertices;        // numVertices*3 (base vertex pool)
    uint32_t nverts;                       // indexed vertex count
    std::vector<uint16_t> indexedVertices; // indexed_vertices: remap into base vertex pool
    std::vector<float>   vertuv;           // nverts*2 (u,v) — V already flipped (v*-1), per canonical reader
    std::vector<uint8_t>  verrgb;           // nverts*3 (r,g,b) if hasRGBs
    uint32_t numSubObjects;
    std::vector<SubObj>   subObjs;
    std::vector<std::string> subObjectNames;  // (kept for compat / logging)
    std::vector<std::string> texNames;
    bool ok = false;
    // Axis-aligned bounding box of the base vertex pool (min/max XYZ).
    float bboxMin[3] = {0,0,0}, bboxMax[3] = {0,0,0};

    // Build a flat position triangle list (XYZ per vertex, 3 per triangle) from ALL
    // sub-objects' decoded tris. Resolves tridata idx -> indexedVertices -> base vertex.
    std::vector<float> buildPositionTris() const;
    // Build interleaved XYZ+DIFFUSE+UV verts (8 floats: x,y,z, diff, u,v) per triangle vertex,
    // matching D3D7 FVF 0x142 (XYZ|DIFFUSE|TEX1). diff = per-subobj material diffuse (BBGGRR->ARGB).
    // outCount = number of vertices (== 3 * total triangles across subobjs).
    std::vector<float> buildTexturedTris(size_t* outVertCount = nullptr) const;
};

Model Parse(const uint8_t* data, size_t len);
bool SelfTest();   // parses intro_1.gbs from xx_intro.gzp, logs structure
bool LogoSelfTest();  // parses Giants_logo_3D.gbs (menu 3D logo), logs structure + textured-tri count
} // namespace VanillaGBS
