# ft_printf
This project is about recoding parts of `printf()`.
Its goal is to learn about and make use of variadic functions.

## Usage
- `make` - compiles the source files and creates the library **libftprintf.a**
- include **ft_printf.h** headerfile into .c files where you want to use `ft_printf()`
- compile your program with the **libftprintf** library (e.g. `gcc main.c -llibftprintf -L<path to libftprintf.a>`)

---

Function declaration:

` int ft_printf( const char *format, ... );`

Parameter *format* can include format specifiers:

` %[flags][width][.precision]specifier`

## Limitations
### Covered conversion specifiers are:
| specifier | description                              |
| --------- | ---------------------------------------- |
| c         | char                                     |
| s         | char * (string)                          |
| p         | void * (pointer address)                 |
| d         | signed decimal integer                   |
| i         | see \%d                                  |
| u         | unsigned decimal integer                 |
| x         | unsigned hexadecimal integer, lower case |
| X         | unsigned hexadecimal integer, upper case |
| %         | prints percentage sign                   |

### Covered sub-specifiers are:

| flag | description |
| --- | --- |
| \- | Left-justify within the given field width; Right justification is the default. |
| 0 | Left-pads the number with zeroes (0) instead of spaces when padding is specified. |
| \(space) | If no sign is going to be written, a blank space is inserted before the value. |
| \+ | Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign. |
| \# | Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. By default, if no digits follow, no decimal point is written. |

| width | description |
| --- | --- |
| (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| \* | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

| .precision | description |
| --- | --- |
| .(number) | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
| .* | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

More information on `printf()` click [here](https://cplusplus.com/reference/cstdio/printf/).
