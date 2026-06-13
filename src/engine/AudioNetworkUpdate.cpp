// Giants Engine - Audio Network Update Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "AudioNetworkUpdate.h"
#include <cstdint>
namespace Giants {
extern uint8_t* DAT_00701ce8;  // Audio/network object
extern void FUN_004d9920(void* out1, void* out2);  // Audio preprocess
extern void FUN_004e19a0(void* ctx);               // Audio post-process
extern void FUN_004e0b70();                        // Audio cleanup

void AudioNetworkUpdate()
{
    uint8_t localBuf1[24];
    uint8_t localBuf2[76];

    // Pre-process audio data
    FUN_004d9920(localBuf2, localBuf1);

    // If audio object active (bit 0 set), call vtable functions
    uint8_t* audioObj = DAT_00701ce8;
    if ((*audioObj & 1) != 0) {
        // vtable+4: init with (0, 5)
        int vtable = *reinterpret_cast<int*>(*reinterpret_cast<int*>(audioObj + 0x30));
        reinterpret_cast<void(*)(int, int)>(vtable + 4)(0, 5);

        // vtable+8: get buffer → store at +0x10
        int objPtr = *reinterpret_cast<int*>(audioObj + 0x30);
        uint32_t buf = reinterpret_cast<uint32_t(*)(int, uint32_t)>(
            *reinterpret_cast<int*>(objPtr) + 8)(objPtr, *reinterpret_cast<uint32_t*>(audioObj + 0xC));
        *reinterpret_cast<uint32_t*>(audioObj + 0x10) = buf;
    }

    // Post-process
    FUN_004e19a0(localBuf1);

    // Cleanup if active
    audioObj = DAT_00701ce8;
    if ((*audioObj & 1) != 0) {
        FUN_004e0b70();

        int vtablePtr = *reinterpret_cast<int*>(audioObj + 0x30);
        // vtable+0x24: shutdown
        reinterpret_cast<void(*)(int)>(*reinterpret_cast<int*>(vtablePtr) + 0x24)(vtablePtr);
        // vtable+4: release
        reinterpret_cast<void(*)(int)>(*reinterpret_cast<int*>(vtablePtr) + 4)(vtablePtr);
    }
}
} // namespace Giants
