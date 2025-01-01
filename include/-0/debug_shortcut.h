#ifndef G_0_DEBUG_SHORTCUT_H
#define G_0_DEBUG_SHORTCUT_H

#include "debug_types.h"

#ifdef NDEBUG

#define G_P0 void
#define G_P

#define G_RB                                                                   \
  do {                                                                         \
  } while (0);
#define G_B                                                                    \
  do {                                                                         \
  } while (0)

#define G_A0
#define G_A

#else

#define G_P0                                                                   \
  const g_0_debug_stacktrace_node_t                                            \
      *g_0_reserved_internal_previous_stacktrace_node
#define G_P G_P0,

#define G_RB                                                                   \
  const g_0_debug_stacktrace_node_t                                            \
      *const g_0_reserved_internal_previous_stacktrace_node = NULL;
#define G_B                                                                    \
  (void)g_0_reserved_internal_previous_stacktrace_node;                        \
  const g_0_debug_stacktrace_node_t                                            \
      g_0_reserved_internal_current_stacktrace_node = {                        \
          .previous = g_0_reserved_internal_previous_stacktrace_node,          \
          .function_name = __func__,                                           \
          .file_name = __FILE__,                                               \
          .line = __LINE__,                                                    \
  };                                                                           \
  (void)g_0_reserved_internal_current_stacktrace_node

#define G_A0 &g_0_reserved_internal_current_stacktrace_node
#define G_A G_A0,

#endif

#endif
