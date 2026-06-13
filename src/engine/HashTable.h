// Giants Engine - Hash Table Utility Functions
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FNV-1a hash table operations used by game and VFS code.

#pragma once

#include <cstdint>

namespace Giants {

// ─── HashTableLookup (FUN_0043dcd0) — FAIL ─────────────────────
// Searches linked-list bucket for key match by ID.
uint32_t HashTableLookup(int param1, int* param2, uint32_t param3, uint32_t* param4);  // FUN_0043dcd0

// ─── HashTableFindOrInsert (FUN_0043f360) — FAIL ──────────────
// FNV-1a hash, bucket lookup, creates node on miss.
int* HashTableFindOrInsert(int param1, uint32_t* param2);  // FUN_0043f360

// ─── InitDispatchHelper (FUN_00450d90) — PASS ─────────────────
// Thin wrapper calling FUN_00450b00.
void InitDispatchHelper();  // FUN_00450d90

// ─── FormattedLogOutput (FUN_00461e70) — FAIL ─────────────────
// Calls fmt::vformat then writes to error channel.
void FormattedLogOutput(uint32_t param1, uint32_t param2);  // FUN_00461e70

// ─── ConfigFileLoader (FUN_0042e110) — FAIL ───────────────────
// Checks default config existence, reads settings, throws on missing.
void ConfigFileLoader(int param1);  // FUN_0042e110

} // namespace Giants
