*This activity has been created as part of the 42 curriculum by batokarz.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the standard C `printf` function, built as a static library (`libftprintf.a`).

**Goal:** learn how to write a variadic function in C (a function taking a variable number of arguments), and how to parse a format string and dispatch each conversion to the right handler.

**Overview:** the function reads the format string character by character. Ordinary characters are written as-is to standard output. When a `%` is found, the next character selects the conversion, and the matching argument is fetched from the argument list and printed. The function returns the total number of characters written, like the original `printf`.

Supported conversions:

| Specifier | Output |
|-----------|--------|
| `%c` | a single character |
| `%s` | a string |
| `%p` | a pointer address in hexadecimal |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | an unsigned hexadecimal integer (lower / upper case) |
| `%%` | a literal percent sign |

## Instructions

**Compilation**

The project is compiled with `cc -Wall -Wextra -Werror`.

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # fclean + make
```

**Usage**

Include the header and link the library `libftprintf.a` when compiling your own program:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old\n", "42", 10);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c lftprintf -o test
./test
```

## Algorithm and data structures

**Variadic arguments.** The function relies on the `<stdarg.h>` macros: `va_start` initializes the argument list from the last named parameter (the format string), `va_arg` fetches the next argument with the type expected by the current conversion, and `va_end` cleans up at the end.

**Parsing.** The format string is traversed once, from left to right, in a single loop, so the complexity is O(n) in the length of the format string. No intermediate data structure is needed: the only state is the current position in the string, the `va_list`, and a running counter of printed characters.

**Dispatch.** When a `%` is encountered, the following character is passed to a dispatch function that calls the matching handler (one for characters, strings, signed integers, unsigned integers, hexadecimal values and pointers). Each handler returns the number of characters it wrote, and this value is added to the total returned by `ft_printf`.

**Number conversion.** Integers and hexadecimal values are printed recursively: the number is divided by the base, the higher digits are printed first, then the current digit. This avoids allocating a buffer and prevents having to reverse a string. Edge cases are handled explicitly: `INT_MIN`, `0`, `NULL` strings (printed as `(null)`) and `NULL` pointers (printed as `(nil)`).

**Why this design.** Writing directly with `write` while counting characters keeps the code simple and uses no dynamic memory allocation, so there is nothing to free and no risk of memory leaks. The trade-off is a higher number of system calls compared with a buffered approach, which is acceptable for the scope of this project.

## Resources

**References**

- [Les fonctions à nombre variable d'arguments (Zeste de Savoir)](https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/les-fonctions-a-nombre-variable-darguments/)
- [x0r.fr, blog article 31](https://x0r.fr/blog/31)
- [C printf (CommentCoder)](https://www.commentcoder.com/blog/c-printf)
- [Video tutorial on variadic functions and printf (1)](https://www.youtube.com/watch?v=oDC208zvsdg)
- [Video tutorial on variadic functions and printf (2)](https://www.youtube.com/watch?v=Hb2m7htiKWM)
- `man 3 printf` and `man 3 stdarg`

**Use of AI**

AI (Claude) was used for the following tasks:

- Understanding variadic functions (`<stdarg.h>`: `va_start`, `va_arg`, `va_end`) and how `printf` conversions work.
- Understanding how to build and link the static library `libftprintf.a`, which is used in the "Usage" part of this README.
- Drafting and structuring this README file (the Usage section included).

The code of the project itself was written, tested and understood by me.