*This project has been created as part of the 42 curriculum by tomperei.*

## Description

ft_printf is a library that contains `ft_printf`, a recreation of the libc `printf`. The goal is to use a variable number of arguments.

```c
int ft_printf(const char *, ...);
```

The function handles the conversions `cspdiuxX%`. Its result is compared with the original `printf`. Buffer management of the original `printf` is outside this project.

- `%c` prints a single character.
- `%s` prints a string (as defined by the common C convention).
- `%p` prints the `void *` pointer argument in hexadecimal format.
- `%d` prints a decimal (base 10) number.
- `%i` prints an integer in base 10.
- `%u` prints an unsigned decimal (base 10) number.
- `%x` prints a number in hexadecimal (base 16) lowercase format.
- `%X` prints a number in hexadecimal (base 16) uppercase format.
- `%%` prints a percent sign.

Allowed external functions: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`. The libft is authorized. Its sources and its Makefile are in `libft/`.

The delivered archive is `libftprintf.a`, at the root of the repository. It is created with `ar`. `libtool` is forbidden.

## Instructions

From the root of the repository:

```sh
make
```

The Makefile uses `cc` with `-Wall`, `-Wextra` and `-Werror`. It compiles the libft through the Makefile in `libft/`, then builds `libftprintf.a` with `ar`. The libft objects are included in that archive, so a program links with this file alone. Running `make` again does not relink when nothing has changed.

Rules: `all`, `clean`, `fclean`, `re`.

```sh
cc main.c libftprintf.a -o program
```

## Algorithm and data structure

`ft_printf` reads the format string once, from left to right, with an index `i`. A normal character is written as it is. A `%` followed by a letter is handed to `ft_convert`, which decides what to print from that letter. A `%` at the very end of the string is ignored, so nothing is read after the terminating `\0`.

The code is split in small functions:

- `ft_printf` calls `va_start`, then `ft_parse`, then `va_end`, and returns the result. It has a single exit, so `va_end` is always called, even after a write error.
- `ft_parse` is the loop over the format string. It adds up the number of characters written and returns `-1` at the first failure.
- `ft_convert` only dispatches. It reads the argument with `va_arg` and calls the right writing function.
- `ft_printf_utils.c` holds the writing functions: `ft_putchar`, `ft_putstr` (prints `(null)` for a `NULL` string), `ft_putnbr` (uses `ft_itoa` and frees it), `ft_putbase` and `ft_putptr` (prints `0x`, or `(nil)` for a `NULL` pointer).

**Data structure.** There is no custom structure. The state is a `va_list`, which works as a cursor on the arguments, and an integer counter.

- The `va_list` is passed by address (`va_list *`). A function that receives a copy would move its own cursor only, and the next conversion would read the same argument again. This was checked on a Windows build, where it gives wrong output.
- `ft_putbase` receives the digits of the base as a string (`"0123456789"`, `"0123456789abcdef"`, `"0123456789ABCDEF"`). The length of the string is the base. One recursive function writes `%u`, `%x`, `%X` and `%p` instead of four near-identical ones. The recursion writes the higher digits first, so the digits come out in the right order.

**Return value.** Every writing function returns the number of characters it wrote, or `-1` if `write` failed. The total is the sum of these values. A failing `write` (for example a closed output) or a failing `malloc` in `ft_itoa` gives `-1`, like the negative value of the original `printf`.

The algorithm is a single pass over the string, so its cost is linear in the length of the output. No buffer is used, as the subject asks.

The bonus part is not implemented.

## Resources

- `man 3 printf`
- `man 3 stdarg` (`va_start`, `va_arg`, `va_copy`, `va_end`)
- `man 2 write`
- `man 3 malloc`
- The ft_printf subject, version 12.1, and the 42 Norm

AI usage: an AI assistant was used mainly as a teacher, to help understand some functions and new notions, such as variadic arguments (`va_list`, `va_start`, `va_arg`, `va_end`).
