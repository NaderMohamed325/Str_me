#ifndef STR_ME_H
#define STR_ME_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/**
 * @file Str_me.h
 * @brief Header file for string manipulation functions.
 */

/**
 * @brief Calculate the length of a string.
 * @param str The input string.
 * @return The length of the string.
 */
int Str_len(const char *str);

/**
 * @brief Concatenate two strings.
 * @param str1 The first input string.
 * @param str2 The second input string.
 * @return A new dynamically allocated string containing the concatenated result.
 *         The caller is responsible for freeing the allocated memory.
 *         Returns NULL if memory allocation fails.
 */
char *Str_concatenate(const char *str1, const char *str2);

/**
 * @brief Copy a string to another.
 *
 * This function copies the content of the source string (`Father`) to the
 * destination string (`Child`). If `Child` is NULL, it allocates memory to
 * store the copy. If `Child` is not NULL, it should point to a valid memory
 * block with enough space for the copy.
 *
 * @param Father The source string to be copied.
 * @param Child The destination string where the copy will be stored.
 *              If NULL, memory will be allocated.
 *              If not NULL, it should point to a valid memory block.
 *
 * @return The destination string (`Child`). Returns NULL if memory allocation fails.
 *         Note: The caller is responsible for freeing the allocated memory.
 */
char *Str_copy(const char *Father, char *Child);

/**
 * @brief Copy up to 'n' characters from the source string to the destination string.
 *
 * This function attempts to copy up to 'n' characters from the source string 'Father' to the
 * destination string 'Child'. It allocates memory for 'Child' and ensures that the destination
 * string is null-terminated.
 *
 * @param Father  Pointer to the source string to be copied.
 * @param Child   Pointer to the destination string where the copy will be stored.
 * @param n       Maximum number of characters to copy.
 *
 * @return        A pointer to the destination string 'Child'.
 *                If 'Child' is NULL or memory allocation fails, returns NULL.
 */
char *Str_copy_n(const char *Father, char *Child, int n);

/**
 * @brief Compare two strings.
 *
 * This function compares two strings, `str1` and `str2`, lexicographically.
 *
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 *
 * @return If either `str1` or `str2` is NULL, returns INT_MIN. If both strings are equal, returns 0.
 *         If the first differing character in `str1` has a greater ASCII value than the corresponding
 *         character in `str2`, returns a positive value. If the first differing character in `str1` has
 *         a smaller ASCII value than the corresponding character in `str2`, returns a negative value.
 */
int Str_compare(const char *str1, const char *str2);

/**
 * @brief Search for a character in a block of memory.
 *
 * This function searches for the first occurrence of the character 'c' in the first 'len' bytes
 * of the memory block pointed to by 'str'.
 *
 * @param str   Pointer to the memory block to be searched.
 * @param c     Character to be located.
 * @param len   Number of bytes to search within the memory block.
 *
 * @return      A pointer to the first occurrence of 'c' in the memory block, or NULL if 'c' is
 *              not found in the first 'len' bytes.
 */
void *Str_memchr(const void *str, int c, int len);

/**
 * @brief Concatenate the first 'n' characters of str1 to str2.
 *
 * This function concatenates the first 'n' characters of the source string 'str1' to
 * the destination string 'str2'. It allocates memory for a temporary string, performs the
 * concatenation, and updates the destination string 'str2'.
 *
 * @param str1  Pointer to the source string to be concatenated.
 * @param str2  Pointer to the destination string where the concatenation will be stored.
 * @param n     Number of characters from 'str1' to concatenate to 'str2'.
 *
 * @return      A pointer to the destination string 'str2'.
 *              If 'str1' or 'str2' is NULL or memory allocation fails, returns NULL.
 */
char *Str_concatenate_n(const char *str1, char *str2, int n);

/**
 * @brief Swap the contents of two strings.
 *
 * This function swaps the contents of two strings by modifying the pointers to the strings.
 * It allocates memory for temporary strings, performs the swap, and frees the memory.
 *
 * @param str1  Pointer to the first string. Will be updated to point to the second string.
 * @param str2  Pointer to the second string. Will be updated to point to the first string.
 *
 * @note The caller is responsible for freeing the memory of the swapped strings.
 *
 * @return None.
 */
void Str_swap(char *str1, char *str2);

/**
 * @brief Converts a string representation of an integer to a long integer with a specified base.
 *
 * @param str The input string to be converted.
 * @param base The base of the number system used in the input string. Must be greater than 1.
 * @return The converted long integer. Returns 0 if the input string is NULL or if the base is invalid.
 */
long Str_string_to_integer(char *str, int base);

/**
 * @brief Reverses a string and returns the reversed string.
 *
 * @param str The input string to be reversed.
 * @return A pointer to the reversed string. Returns NULL if the input string is NULL.
 *         The returned string is dynamically allocated and should be freed by the caller.
 */
char *Str_Revers_String(const char *str);

#endif /* STR_ME_H */
