// Giants Engine - Entity Sound Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntitySoundDispatch.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_0066bfc8;
extern uint32_t DAT_0066bf2c;  // 1.0f
extern uint32_t DAT_0066be20;
extern void SoundPlayEffect();  // FUN_00483140

int EntitySoundDispatch(int param_1, int param_2, int param_3)
{
    int count = 0;
    int maxSlots = 2;
    int slot = 0;
    int localFlag = 2;

    uint32_t* outPtr = reinterpret_cast<uint32_t*>(param_3 + 0x14);
    float* slotData = reinterpret_cast<float*>(param_1 + 0x7C);

    do {
        // Check if slot has valid sound index (not ~3.5593e-43 which is a tag value)
        if (slotData[-7] != 3.5593e-43f) {
            int idx = static_cast<int>(slotData[-7]);
            int soundIdx = *reinterpret_cast<int*>(idx * 4 + 8 +
                *reinterpret_cast<int*>(param_1 + 8));
            if (soundIdx != 0) {
                // Store sound reference
                outPtr[-5] = soundIdx;

                // Get sound data pointer and link back to entity
                int* soundData = *reinterpret_cast<int**>(soundIdx + 0x28);
                *soundData = param_1;

                // Read volume from sound slot if flag not set
                if ((*reinterpret_cast<uint8_t*>(soundIdx + 8) & 1) == 0) {
                    outPtr[-4] = *reinterpret_cast<uint32_t*>(
                        soundIdx + 0x2C + param_2 * 4);
                }

                // Compute pitch: data[6] * scale * data[7] + data[4]
                outPtr[-1] = static_cast<int>(
                    static_cast<float>(soundData[6]) * slotData[-6] *
                    static_cast<float>(soundData[7])) + soundData[4];

                if (slot < 2) {
                    *outPtr = 0;
                    float fVar8 = *slotData * *reinterpret_cast<float*>(&DAT_0066bfc8);
                    SoundPlayEffect();
                    fVar8 = (*reinterpret_cast<float*>(&DAT_0066bf2c) - fVar8) *
                            *reinterpret_cast<float*>(&DAT_0066be20);
                    outPtr[1] = fVar8;
                    if (fVar8 != 0.0f) {
                        localFlag = 4;
                    }
                } else {
                    *outPtr = 1;
                }

                count++;
                outPtr += 7;
                maxSlots = localFlag;
            }
        }
        slot++;
        slotData += 9;
    } while (slot < maxSlots);

    return count;
}
} // namespace Giants
