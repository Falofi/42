*This project has been created as part of the 42 curriculum by tomperei.*

## Description

`get_next_line` reads a line from a file descriptor.

```c
char *get_next_line(int fd);
```

Repeated calls read the text one line at a time. The returned line includes the terminating `\n`, except when the end of the file is reached and the file does not end with a `\n`. If there is nothing left to read, or if an error occurs, the function returns `NULL`.

The function has to work when reading a file and when reading from the standard input. `BUFFER_SIZE` is the size passed to `read`. Peer evaluators and the Moulinette change this value. Each call reads as little as possible: once a newline is found, the current line is returned. The whole file is not read first to be split afterwards.

The behavior is undefined if the file behind the descriptor is modified after the last call, while `read` has not reached the end of the file. Reading a binary file is also undefined behavior.

Allowed external functions: `read`, `malloc`, `free`. The libft is forbidden. `lseek` is forbidden. Global variables are forbidden.

Files turned in at the root: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`. Helper functions go in `get_next_line_utils.c`. The header contains at least the prototype of `get_next_line`. The subject points to a static variable as a starting point for keeping data between calls.

## Instructions

The subject compiles the project with `cc`, `-Wall`, `-Wextra` and `-Werror`. A buffer size of 42 is the example used in the subject:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

The same files also compile without `-D BUFFER_SIZE`. `get_next_line.h` then sets `BUFFER_SIZE` to 42.

The Makefile compiles the two source files into object files. The subject does not ask for a program, so `make` produces no executable and no archive. Another buffer size recompiles the objects:

```sh
make
make re BUFFER_SIZE=1
```

Rules: `all`, `clean`, `fclean`, `re`.

## Algorithm

The subject requires one line per call, read from `fd` with `read` and a buffer of `BUFFER_SIZE` bytes. A line that contains a newline is returned with that newline as soon as it is found. The call reads only what that line needs.

`read` returns a block of `BUFFER_SIZE` bytes, which does not stop at the end of a line. It can end in the middle of a line or contain several lines. What was read but not returned yet has to survive between two calls, so `get_next_line` keeps it in a `static` pointer called `stash`. A static variable keeps its value from one call to the next, and it is not a global variable.

Each call has three steps:

1. **Read.** `read_to_stash` appends blocks of `BUFFER_SIZE` bytes to `stash` (with `ft_strjoin`) until `stash` contains a `\n` or `read` returns `0`. The call reads only what one line needs.
2. **Cut.** `ft_strchr` finds the first `\n` in `stash`. `ft_substr` copies everything up to that `\n` (included) into the returned line, and a second `ft_substr` copies what follows into a new `stash`. The old block is freed. If there is no `\n`, the line is the whole `stash`, which is the last line of a file that does not end with a newline.
3. **End.** When `stash` is empty, there is nothing left: it is freed, set to `NULL`, and the function returns `NULL`. The next call starts again from scratch.

**Data structure.** A single C string, `stash`, kept in a `static` pointer. A linked list of buffers would avoid copying the remainder, but it needs more code and more `malloc`, and the string is enough here.

**Memory.** The returned line belongs to the caller, who frees it. The old `stash` is freed each time it is replaced, and the read buffer is freed at the end of each read. If `read` or a `malloc` fails, the buffer and the current `stash` are freed, and the function returns `NULL`: `ft_strjoin` frees its first argument even when it fails, and `free_both` frees the two blocks and returns `NULL`. The code was tested with every `BUFFER_SIZE` from `1` to `10000000`, with files that end or not with a newline, with the standard input, and with `read` and `malloc` made to fail on purpose.

Helper functions: `ft_strlen`, `ft_strjoin` (it frees its first argument, the old `stash`, on success and on failure), `ft_strchr` and `ft_substr` are in `get_next_line_utils.c`. `read_to_stash` and `free_both` are `static` in `get_next_line.c`.

The bonus part is not implemented.

## Resources

- `man 2 read`
- `man 3 malloc`
- `man 3 free`
- The get_next_line subject and the 42 Norm

AI usage: an AI assistant was used mainly as a teacher, to help understand some functions and new notions, such as static variables and `read`.
