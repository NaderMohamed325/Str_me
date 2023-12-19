# String Manipulation Library

This library provides a set of functions for manipulating strings in C. It includes functions for string length calculation, concatenation, copying, comparison, memory searching, and more.

## Table of Contents

- [Functions](#functions)
- [Usage](#usage)
- [Contributing](#contributing)


## Functions

### `int Str_len(const char *str)`

Calculate the length of a string.

### `char *Str_concatenate(const char *str1, const char *str2)`

Concatenate two strings.

### `char *Str_copy(const char *Father, char *Child)`

Copy a string to another.

### `char *Str_copy_n(const char *Father, char *Child, int n)`

Copy up to 'n' characters from the source string to the destination string.

### `int Str_compare(const char *str1, const char *str2)`

Compare two strings.

### `void *Str_memchr(const void *str, int c, int len)`

Search for a character in a block of memory.

### `char *Str_concatenate_n(const char *str1, char *str2, int n)`

Concatenate the first 'n' characters of str1 to str2.

### `void Str_swap(char *str1, char *str2)`

Swap the contents of two strings.

### `long Str_string_to_integer(char *str, int base)`

Converts a string representation of an integer to a long integer with a specified base.

### `char* Str_Revers_String(const char *str)`

Reverses a string and returns the reversed string.

## Usage

To use this library in your C project, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/NaderMohamed325/Str_me
