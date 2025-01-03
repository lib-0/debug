#define G_THIS
#include "-0_debug.h"
#undef G_THIS

#include <stdio.h>
#include <stdlib.h>

#define G_THIS
#include "-0_common.h"
#undef G_THIS

G_EXPORT void
g_0_debug_die(G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE const char *message) {
  G_0_DEBUG_FUNCTION_BODY_PRELUDE;

#ifdef NDEBUG

  if (message) {
    fprintf(stderr, "%s\n", message);
  }
  abort();

#else

  if (message) {
    fprintf(stderr, "Aborted: %s\n\nStacktrace:\n", message);
  } else {
    fprintf(stderr, "Aborted.\n\nStacktrace:\n");
  }

  const g_0_debug_stacktrace_node_t *now =
      &g_0_reserved_internal_current_stacktrace_node;
  while (now) {
    fprintf(stderr, "%s (%s:%llu)\n", now->function_name, now->file_name,
            now->line);
    now = now->previous;
  }

  abort();

#endif
}
