*This project has been created as part of the 42 curriculum by tomperei.*

## Description

Libft is a static C library that reimplements a set of libc functions and adds
utility functions for strings, memory, output and linked lists. The goal is to
understand how the standard functions work by writing them from scratch, and to
build a reusable foundation for the following 42 projects.

The library contains 43 functions split in three parts:

- **Part 1 (libc)** — 23 reimplementations of standard functions. They have the
  same prototypes and the same behaviour as the originals; only the `ft_` prefix
  differs.
- **Part 2 (additional)** — 11 functions that are not in the libc, or exist in a
  different form: allocation, string transformation and output to a file
  descriptor.
- **Part 3 (linked lists)** — 9 functions built on the `t_list` structure.

Only `malloc`, `free` and `write` are used from outside the library; everything
else is implemented here, and helper functions are `static` to keep their scope
inside their file.

## Instructions

Compilation, from the root of the repository:

```sh
make
```

This creates `libft.a` at the root. The Makefile uses `cc` with the flags
`-Wall -Wextra -Werror`, creates the library with `ar`, and provides the rules
`all`, `clean`, `fclean` (object files and library) and `re` (full rebuild).

## Library

### Part 1 — libc functions

**Character classification** — `ft_isalpha`, `ft_isdigit`, `ft_isalnum`,
`ft_isascii`, `ft_isprint` return `1` if the character belongs to the tested
class, `0` otherwise.

**Case conversion** — `ft_toupper` and `ft_tolower` return the character
unchanged when it is not a letter.

**Strings** — `ft_strlen`; `ft_strlcpy` and `ft_strlcat` copy at most `size`
bytes, always terminate the destination with `'\0'` and return the length they
tried to create; `ft_strchr` and `ft_strrchr` return a pointer to the first or
last occurrence of a character (the terminating `'\0'` included); `ft_strncmp`
compares at most `n` characters; `ft_strnstr` looks for a substring inside the
first `len` characters; `ft_strdup` allocates a copy; `ft_atoi` skips
whitespaces, accepts one sign and stops at the first character that is not a
digit.

**Memory** — these functions work on untyped memory (`void *`), byte by byte,
with lengths in `size_t`: `ft_memset`, `ft_bzero`, `ft_memcpy`,
`ft_memmove` (copies backwards when the areas overlap), `ft_memchr` and
`ft_memcmp` (both cross `'\0'` without stopping). `ft_calloc` allocates and
zeroes; a multiplication that would overflow `size_t` returns `NULL`, and a
`nmemb` or `size` of `0` still returns a unique pointer that can be freed.

### Part 2 — additional functions

`ft_substr`, `ft_strjoin` and `ft_strtrim` allocate new strings from existing
ones: a range of characters, a concatenation, and a copy with the characters of
`set` removed from both ends. `ft_split` returns a `NULL`-terminated array of
strings cut on a delimiter, each string allocated independently (free every
string, then the array itself). `ft_itoa` converts an `int` to a string, negative
values included (`INT_MIN` handled). `ft_strmapi` builds a new string from the
successive results of `f(index, character)`, while `ft_striteri` applies
`f(index, &character)` in place, so the character can be modified.
`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd` and `ft_putnbr_fd` write to a
file descriptor using `write` (`ft_putendl_fd` adds a newline).

### Part 3 — linked lists

The structure is declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

`content` can hold any kind of data thanks to `void *`; `next` is the address of
the next node, or `NULL` for the last one.

`ft_lstnew` allocates a node initialised with its content and a `NULL` `next`.
`ft_lstadd_front` and `ft_lstadd_back` insert a node at the beginning or at the
end of a list; both take a `t_list **` so they can change the pointer of the
caller. `ft_lstsize` counts the nodes and `ft_lstlast` returns the last one.
`ft_lstdelone` frees the content with `del` and then the node itself, without
touching `next`; `ft_lstclear` deletes a node and all its successors, then sets
the list pointer to `NULL`. `ft_lstiter` applies `f` to the content of every
node, and `ft_lstmap` builds a new list from the results of `f`, deleting the
content already created with `del` if an allocation fails.

## Usage

Include the header of the library and link it with `-L. -lft`:

```c
#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	char	*joined;

	joined = ft_strjoin("Hello ", "42");
	if (!joined)
		return (1);
	ft_putendl_fd(joined, 1);
	free(joined);
	return (0);
}
```

```sh
cc main.c -L. -lft -o program
```

## Resources

- `man 3` pages of the reimplemented libc functions, and `write(2)`.
- The 42 Libft subject and the 42 Norm.
- cppreference.com for the C library reference.
- AI usage: AI tools were used to (1) adapt implementations written during the
  piscine to the Libft prototypes, (2) explain and help write the functions that
  were new (the Part 1 memory functions, `ft_calloc`, `ft_itoa`, `ft_strmapi`,
  and all of Part 3), (3) generate test programs for the functions and run
  Norminette. Every function was reviewed and tested before being kept.
