# Debug

Stacktrace support for any platform that supports the C99 standard

## Why archive?

It seems useless because most debuggers support this functionality

## Result example

```sh
# build test executable
sh example/usage.sh

example/out_self_debug/bin/example 1

# Aborted: Given number is not a even number
#
# Stacktrace:
# g_0_debug_die (/Users/user/workspace/lib-0/debug/src/die.c:14)
# assert_even (/Users/user/workspace/lib-0/debug/example/main.c:7)
# do_something (/Users/user/workspace/lib-0/debug/example/main.c:16)
# main (/Users/user/workspace/lib-0/debug/example/main.c:25)
# zsh: abort      example/out_self_debug/bin/example 1

example/out_self_release/bin/example 1

# Given number is not a even number
# zsh: abort      example/out_self_release/bin/example 1
```

## Usage

```c
// G_P before the first parameter, or G_P0 if there are no parameters
void do_something(G_P char *const *args, size_t args_length) {
  // G_B; before the function body, G_RB; G_B; before the root function body
  G_B;

  for (size_t i = 0; i < args_length; i++) {
    // G_A before the first argument, or G_A0 if there are no parameters
    assert_even(G_A args[i]);
  }
}
```
