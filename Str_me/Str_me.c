
#include "Str_me.h"

/**
 * @brief Calculate the length of a string.
 * @param str The input string.
 * @return The length of the string.
 */
int Str_len(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

/**
 * @brief Concatenate two strings.
 * @param str1 The first input string.
 * @param str2 The second input string.
 * @return A new dynamically allocated string containing the concatenated result.
 *         The caller is responsible for freeing the allocated memory.
 *         Returns NULL if memory allocation fails.
 */
char *Str_concatenate(const char *str1, const char *str2) {
    // Allocate memory for the concatenated string
    char *New_Str = (char *) malloc((Str_len(str1) + Str_len(str2) + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (New_Str == NULL) {
        // Handle memory allocation failure, for example, by returning NULL
        return NULL;
    }

    // Copy the characters from str1 to New_Str
    for (int i = 0; i < Str_len(str1); ++i) {
        New_Str[i] = str1[i];
    }

    // Copy the characters from str2 to New_Str
    for (int i = 0; i < Str_len(str2); ++i) {
        New_Str[Str_len(str1) + i] = str2[i];
    }

    // Add the null-terminator to the end of the concatenated string
    New_Str[Str_len(str1) + Str_len(str2)] = '\0';

    return New_Str;
}


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
char *Str_copy(const char *Father, char *Child) {
    // Allocate memory for Child, including space for the null-terminator
    Child = (char *) malloc((Str_len(Father) + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (Child == NULL) {
        // Handle memory allocation failure, for example, by returning NULL
        return NULL;
    } else {
        // Copy the characters from Father to Child
        for (int i = 0; i <= Str_len(Father); ++i) {
            Child[i] = Father[i];
        }

        return Child;
    }
}

/**
 * Str_copy_n - Copy up to 'n' characters from the source string to the destination string.
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
char *Str_copy_n(const char *Father, char *Child, int n) {
    // Check if 'Child' is NULL
    if (Child == NULL) {
        return NULL;
    }

    // Allocate memory for 'Child' with space for 'n' characters and null-terminator
    Child = (char *) malloc(sizeof(char) * (n + 1));

    // Check if memory allocation fails
    if (Child == NULL) {
        return NULL;
    }

    // Copy characters from 'Father' to 'Child'
    int i = 0;
    for (; i < n; ++i) {
        Child[i] = Father[i];

        // Check for the null terminator in 'Father' and terminate the loop
        if (Father[i] == '\0') {
            return Child;
        }
    }

    // Ensure the destination string is null-terminated
    Child[i] = '\0';

    // Return a pointer to the destination string 'Child'
    return Child;
}


/**
 * Compare two strings.
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
int Str_compare(const char *str1, const char *str2) {
    // Check for NULL pointers
    if (str1 == NULL || str2 == NULL) {
        return INT_MIN;  // Indicate that at least one string is NULL
    } else {
        // Iterate through both strings
        while (*str1 && *str2) {
            // Compare characters at the current position
            if (*str1 != *str2) {
                // Return the difference between ASCII values
                return *str2 - *str1;
            }
            // Move to the next characters in both strings
            str1++;
            str2++;
        }
        // If both strings are equal up to the length of the shorter string,
        // compare the last characters in each string based on ASCII values
        return str2[Str_len(str2) - 1] - str1[Str_len(str1) - 1];
    }
}

/**
 * Str_memchr - Search for a character in a block of memory.
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
void *Str_memchr(const void *str, int c, int len) {
    // Check if the input pointer is NULL
    if (str == NULL) {
        return NULL;
    } else {
        // Cast the input pointer to a char pointer for byte-wise access
        char *target = (char *) str;

        // Iterate through the first 'len' bytes of the memory block
        for (int i = 0; i < len; ++i) {
            // Check if the current byte matches the target character 'c'
            if (*target == c) {
                // Return a pointer to the first occurrence of 'c'
                return (void *) target;
            }
            // Move to the next byte in the memory block
            target++;
        }
    }

    // If 'c' is not found in the first 'len' bytes, return NULL
    return NULL;
}

/**
 * Str_concatenate_n - Concatenate the first 'n' characters of str1 to str2.
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
char *Str_concatenate_n(const char *str1, char *str2, int n) {
    // Check if 'str1' or 'str2' is NULL
    if (str1 == NULL || str2 == NULL)
        return NULL;

    // Allocate memory for a temporary string
    char *temp = (char *) malloc((Str_len(str1) + n + 1) * sizeof(char));

    // Check if memory allocation fails
    if (temp == NULL) {
        return NULL;
    }

    // Copy the contents of 'str2' to the temporary string
    temp = Str_copy(str2, temp);

    int i = 0;
    for (; i < n; ++i) {
        // Concatenate the first 'n' characters of 'str1' to the temporary string
        temp[i + Str_len(str2)] = str1[i];

        // Check for the null terminator in 'str1' and terminate the loop
        if (str1[i] == '\0') {
            // Update 'str2' with the concatenated string
            Str_copy(temp, str2);
            return Str_copy(temp, str2);
        }
    }

    // Ensure the temporary string is null-terminated
    temp[i + Str_len(str2)] = '\0';

    // Update 'str2' with the concatenated string
    Str_copy(temp, str2);

    // Return a pointer to the destination string 'str2'
    return Str_copy(temp, str2);
}

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
void Str_swap(char *str1, char *str2) {
    // Check for NULL pointers or allocate memory for temporary strings
    if (str1 == NULL || str2 == NULL) {
        return;
    }

    // Allocate memory for a temporary string and copy contents of str1
    char *temp = Str_copy(str1, NULL);

    // Copy contents of str2 to str1
    Str_copy(str2, str1);

    // Copy contents of temp to str2
    Str_copy(temp, str2);

    // Free memory allocated for temporary string
    free(temp);
}

/**
 * Converts a string representation of an integer to a long integer with a specified base.
 *
 * @param str The input string to be converted.
 * @param base The base of the number system used in the input string. Must be greater than 1.
 * @return The converted long integer. Returns 0 if the input string is NULL or if the base is invalid.
 */
long Str_string_to_integer(char *str, int base) {
    // Check if the input string is NULL
    if (str == NULL) {
        return 0;
    }

    // Check if the base is valid
    if (base < 2) {
        return 0;
    }

    // Initialize sign and length variables
    int sign = 1;  // 1 for positive, 0 for negative
    int Len = Str_len(str);  // Assuming Str_len is a function that returns the length of the string

    // Check if the number is negative, update sign and length accordingly
    if (*str == '-') {
        sign = 0;
        Len--;
        str++;
    }

    // Initialize a variable to store the resulting number
    long num = 0;

    // Iterate through each digit of the string and convert to a long integer
    for (int i = 0; i < Len; ++i) {
        // Convert each digit character to its corresponding integer value and accumulate
        num += (long) pow(base, Len - i - 1) * (str[i] - '0');
    }

    // Apply the sign to the resulting number if it is negative
    if (!sign) {
        num = -num;
    }

    // Return the converted long integer
    return num;
}

/**
 * Reverses a string and returns the reversed string.
 *
 * @param str The input string to be reversed.
 * @return A pointer to the reversed string. Returns NULL if the input string is NULL.
 *         The returned string is dynamically allocated and should be freed by the caller.
 */
char *Str_Revers_String(const char *str) {
    // Check if the input string is NULL
    if (str == NULL) {
        return NULL;
    }

    // Allocate memory for the reversed string
    char *reversedStr = (char *) malloc((Str_len(str) + 1) * sizeof(char));

    // Check if memory allocation is successful
    if (reversedStr == NULL) {
        return NULL;  // Memory allocation failed
    }

    // Reverse the string
    int len = Str_len(str);
    for (int i = 0; i < len; ++i) {
        reversedStr[i] = str[len - i - 1];
    }
    reversedStr[len] = '\0';  // Null-terminate the reversed string

    // Optionally, copy the reversed string to the original string
    Str_copy(str, reversedStr);

    return reversedStr;
}
