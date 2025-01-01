#include "-0_debug.h"

#include <stddef.h>
#include <stdlib.h>

void assert_even(G_P char *number_str) {
  G_B;

  const int number = atoi(number_str);
  if (number % 2 != 0) {
    g_0_debug_die(G_A "Given number is not a even number");
  }
}

void do_something(G_P char *const *args, size_t args_length) {
  G_B;

  for (size_t i = 0; i < args_length; i++) {
    assert_even(G_A args[i]);
  }
}

int main(int argc, char **argv) {
  G_RB;
  G_B;

  do_something(G_A argv + 1, (size_t)argc - 1);
}
