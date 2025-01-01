#include "-0_debug.h"

#include <stddef.h>
#include <stdlib.h>

void assert_even(G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE char *number_str) {
  G_0_DEBUG_FUNCTION_BODY_PRELUDE;

  const int number = atoi(number_str);
  if (number % 2 != 0) {
    g_0_debug_die(G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE
                  "Given number is not a even number");
  }
}

void do_something(G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE char *const *args,
                  size_t args_length) {
  G_0_DEBUG_FUNCTION_BODY_PRELUDE;

  for (size_t i = 0; i < args_length; i++) {
    assert_even(G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE args[i]);
  }
}

int main(int argc, char **argv) {
  G_0_DEBUG_ROOT_FUNCTION_BODY_PRELUDE;
  G_0_DEBUG_FUNCTION_BODY_PRELUDE;

  do_something(G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE argv + 1, (size_t)argc - 1);
}
