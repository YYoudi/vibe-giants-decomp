// Giants Engine - Sound Emitter Check Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "SoundEmitterCheck.h"
#include <cstdint>
namespace Giants {
extern int DAT_007028f4;  // Entity system pointer — EntitySystem.cpp
void CheckSoundEmitter(int entity)
{
    uint32_t flags = *reinterpret_cast<uint32_t*>(entity + 300);

    if ((flags & 0x200) == 0) {
        // Normal path: check entity type
        if (*reinterpret_cast<int*>(entity + 0x60) == 0x47) {
            return;  // Type 0x47: skip
        }
        // Check scene graph
        if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(entity + 8) + 0x124) == 0) {
            return;
        }
        float volume = *reinterpret_cast<float*>(DAT_007028f4 + 0xB38) *
                       *reinterpret_cast<float*>(entity + 0x370);
    } else {
        // Flagged path: alternate volume calculation
        float altVolume = *reinterpret_cast<float*>(entity + 0x370);
    }
}
} // namespace Giants
