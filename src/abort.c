#define G_THIS
#include "-0_debug.h"
#undef G_THIS

#include <stddef.h>

#define G_THIS
#include "-0_common.h"
#undef G_THIS

G_EXPORT void g_0_debug_abort(G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE0) {
  G_0_DEBUG_FUNCTION_BODY_PRELUDE;
  g_0_debug_die(G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE NULL);
}
