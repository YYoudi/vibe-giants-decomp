// Giants Engine - Trace Log global definition
//
// g_traceLog is referenced across the engine (EngineInit, GameLoop, GameLogic,
// RendererLoader) and by the standalone exe. Defining it here in the static lib
// means BOTH the GiantsMain exe and the gg_dx9r proxy DLL link cleanly without
// each needing their own copy. TraceLog.h declares it `extern`.

#include "TraceLog.h"

namespace Giants {

// Global trace log file — opened once at startup (TraceInit), flushed per entry.
FILE* g_traceLog = nullptr;

} // namespace Giants
