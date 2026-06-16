// Giants Vanilla-Native Recomp — ODEF VM (object-definition bytecode interpreter).
//
// Faithful port of the ODEF bytecode dispatcher embedded in Giants.exe!FUN_004b7c50
// (vanilla 1.0 retail, base 0x400000). The dispatcher lives at 0x4b809d inside the
// same function as the .BIN header parser (VanillaBinLoader.cpp): after the odef
// blob is read into a 0x1c9-byte template at 0x4b7eb2, the engine skips two
// NUL-terminated header strings (template-name + class-name @ 0x4b7eb7), seeds a
// block of default floats on the engine object (0x4b7ee4..0x4b7f95), then enters
// the dispatch loop at 0x4b809d.
//
// DISPATCH LOOP (0x4b809d):
//   eax = byte ptr [ebp]      ; ebp = cursor into the in-memory odef blob
//   inc ebp
//   if (eax == 0xff) goto end (0x4ba5d4)
//   ecx = eax - 0x13
//   if (ecx > 0x71) goto bad-opcode error (0x4ba592)
//   jmp [jump_table @ 0x4baa28 + ecx*4]   ; ~80 handlers, opcodes 0x13..0x84
//
// SPAWN PATH (the goal of this port):
//   The opcodes that CREATE entities are 0x2a and 0x46. They read a nameId (u32)
//   from the stream, call FUN_0049d2d0(nameId) to look up an existing entity in
//   g_EntityInstanceList (DAT_006313b4), and on miss fall through to
//   FUN_0049c190(0x406) which pops a 0x304-byte slot from the entity pool
//   (DAT_006313b4 free-list @ DAT_00631404), zeroes it, sets scale [+0xc4]=1.0f
//   and the active flag [+0xdc]|=0x80000000, then head-inserts a scene-list node
//   into g_PlacedObjectList (DAT_006313c8) via FUN_00472ef0. The handler then
//   writes the placement fields: position → [ebx+0xa0..0xa8], angle → [ebx+0xc8],
//   (opcode 0x46 only) two more angles → [ebx+0xcc], [ebx+0xd0].
//
//   ebx is the per-entity "current object" pointer. It is loaded by the spawn
//   handler's tail (0x4b8908..0x4b8938) from the scene-list inner slot array:
//     stride = (slotIdx*3 << 6) + slotIdx, *4 = slotIdx * 0x304 bytes.
//   (So the inner-list entity stride is 0x304 bytes — matches the FUN_0049c190
//   rep-stosd count of 0xc1 dwords.)
//
// OPCODE 0x84 (NAME) feeds the spawn slot's name field:
//   Reads a NUL-terminated string from the stream and copies it into
//   [engine+0x509c] (a scratch name slot the spawn path consumes).
//
// Non-spawn opcodes (the bulk of the table) set engine defaults, materials,
//   lights, paths, and other level-config state. They are advanced by their
//   documented fixed sizes (a few are variable-length: NUL-string + tail).
//
// See RE_docs/ODEF_VM.md for the full opcode map with handler VAs and sizes.
#pragma once
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// VanillaOdef_Run — execute the ODEF bytecode blob and spawn its entities.
// ============================================================================
//   stream   - engine file handle (as opened by FUN_00539e30). The odef blob
//              has ALREADY been seeked to (the caller did `SEEK header[0];
//              READ 4 -> odefSize`); this function reads odefSize bytes from
//              the current cursor and interprets them.
//   blobSize - byte length of the odef blob (the u32 read at the section head).
//
// Faithfully emulates the vanilla dispatcher at 0x4b809d:
//   * reads the blob into an in-memory buffer (the vanilla allocator at 0x4b7ea0
//     mallocs 0x1c9 bytes; we bound to blobSize),
//   * skips the two NUL-terminated header strings,
//   * walks the bytecode, dispatching each opcode,
//   * on SPAWN opcodes (0x2a / 0x46): allocates an EntityObject via FUN_0049c190,
//     writes the placement fields (position/angles), head-inserts into
//     g_PlacedObjectList, and logs the spawn.
// Non-spawn opcodes are advanced by their disassembly-confirmed sizes; their
// engine-state writes are skipped (logged at trace level) because those engine
// subsystems (materials, lights, paths) are not yet ported.
void VanillaOdef_Run(uint32_t stream, uint32_t blobSize);

#ifdef __cplusplus
} // extern "C"
#endif

namespace VanillaOdef {
// Self-test: loads Bin\w_intro_island.bin, parses the .BIN header to locate the
// odef section, then runs VanillaOdef_Run on it. Returns the number of entities
// spawned (expected: 2 — the two "mission1" placements). Logs to stdout.
int SelfTest();
} // namespace VanillaOdef
