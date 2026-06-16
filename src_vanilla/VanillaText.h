// Giants Vanilla-Native Recomp — localized-text lookup (UpCalls callback[11] GetLocalizedString).
// Loads GText<Lang>.bin (header 12B [count][keySize][valSize] + count*8 offset table
// {keyOff,valOff} + null-separated key region + null-separated value region) and looks
// up a key (e.g. "$IDnew") → localized value ("Enter New ID"). The renderer/menus call
// callback[11] to resolve UI string IDs.
#pragma once
#include <cstdint>
#include <string>

namespace VanillaText {
// Load GText<lang>.bin (lang="English"/"French"/...). Returns true on success.
bool Load(const char* lang);
// Look up a key → value (returns "" if not found / not loaded).
const char* Lookup(const char* key);
} // namespace VanillaText
