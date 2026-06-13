// Giants Engine - Render Entity Setup Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderEntitySetup.h"
#include <cstdint>
namespace Giants {
extern void FUN_0048f2f0(int, int, int, int, float);

void SetupRenderEntity(uint32_t param_1, int entityIndex)
{
    if (entityIndex != 0xFE) {
        // Render the specific entity
        FUN_0048f2f0(entityIndex, 0x20, 0, 0, 0.33333334f);  // 0x3E2AAAAB
        // Then render default fallback
        FUN_0048f2f0(0xFE, 0, 0, 0, 0.33333334f);
    }
}
} // namespace Giants
