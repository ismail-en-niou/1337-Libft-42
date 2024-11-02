#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Advanced tests for ft_strlen
void test_strlen() {
    printf("Testing ft_strlen with edge cases:\n");
    printf("Long String - Expected: 1000, Got: %zu\n", ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua." "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua." "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."));
    printf("Unicode Characters - Expected: 5, Got: %zu\n", ft_strlen("안녕하세요"));
    printf("Special Characters - Expected: 10, Got: %zu\n", ft_strlen("!@#$%^&*()"));
}

// Advanced tests for ft_strcpy
void test_strcpy() {
    printf("\nTesting ft_strcpy with edge cases:\n");
    char dest[100];
    printf("Copy Long String - Expected: Lorem... Got: %s\n", ft_strcpy(dest, "Lorem ipsum dolor sit amet, consectetur adipiscing elit."));
    printf("Copy Special Characters - Expected: !@#... Got: %s\n", ft_strcpy(dest, "!@#$%^&*()"));
}

// Advanced tests for ft_strdup
void test_strdup() {
    printf("\nTesting ft_strdup with edge cases:\n");
    char *dup = ft_strdup("Complex string with newline\n and tab\t characters");
    printf("Special Characters Test - Expected: Complex... Got: %s\n", dup);
    free(dup);

    dup = ft_strdup("String with Null-terminator\0hidden text");
    printf("Embedded Null Test - Expected: String... Got: %s\n", dup);
    free(dup);
}

// Advanced tests for ft_strjoin
void test_strjoin() {
    printf("\nTesting ft_strjoin with edge cases:\n");
    char *joined = ft_strjoin("String with special chars: ", "!@#$%^&*()");
    printf("Special Characters Join - Expected: String with special chars... Got: %s\n", joined);
    free(joined);

    joined = ft_strjoin(NULL, "String with NULL");
    printf("NULL Prefix Test - Expected: String with NULL, Got: %s\n", joined);
    free(joined);

    joined = ft_strjoin("String with NULL", NULL);
    printf("NULL Suffix Test - Expected: String with NULL, Got: %s\n", joined);
    free(joined);
}

// Advanced tests for ft_memcpy
void test_memcpy() {
    printf("\nTesting ft_memcpy with edge cases:\n");
    char dest[50] = "Initial text in destination buffer";
    printf("Overlapping Memory - Expected: text in destination buffer, Got: %s\n", (char *)ft_memcpy(dest + 7, dest, 24));

    char src[10] = "123456789";
    printf("Copy with Smaller Size - Expected: 12345, Got: %s\n", (char *)ft_memcpy(dest, src, 5));
}

// Advanced tests for ft_atoi
void test_atoi() {
    printf("\nTesting ft_atoi with edge cases:\n");
    printf("Leading Zeros - Expected: 42, Got: %d\n", ft_atoi("00042"));
    printf("Negative Leading Zeros - Expected: -42, Got: %d\n", ft_atoi("-00042"));
    printf("Overflow Test - Expected: 2147483647, Got: %d\n", ft_atoi("2147483647"));
    printf("Underflow Test - Expected: -2147483648, Got: %d\n", ft_atoi("-2147483648"));
    printf("Beyond Range - Expected: 0, Got: %d\n", ft_atoi("9999999999999999999999999"));
    printf("Mixed Characters - Expected: 0, Got: %d\n", ft_atoi("42abc"));
}

// Advanced tests for ft_isalpha
void test_isalpha() {
    printf("\nTesting ft_isalpha with edge cases:\n");
    printf("Uppercase A - Expected: 1, Got: %d\n", ft_isalpha('A'));
    printf("Lowercase z - Expected: 1, Got: %d\n", ft_isalpha('z'));
    printf("Digit - Expected: 0, Got: %d\n", ft_isalpha('5'));
    printf("Special Character - Expected: 0, Got: %d\n", ft_isalpha('#'));
    printf("Extended ASCII - Expected: 0, Got: %d\n", ft_isalpha(128));  // Check behavior on non-ASCII characters
}

// Advanced tests for ft_isdigit
void test_isdigit() {
    printf("\nTesting ft_isdigit with edge cases:\n");
    printf("Digit 0 - Expected: 1, Got: %d\n", ft_isdigit('0'));
    printf("Digit 9 - Expected: 1, Got: %d\n", ft_isdigit('9'));
    printf("Non-digit character - Expected: 0, Got: %d\n", ft_isdigit('a'));
    printf("Special Character - Expected: 0, Got: %d\n", ft_isdigit('@'));
}

// Advanced tests for ft_tolower
void test_tolower() {
    printf("\nTesting ft_tolower with edge cases:\n");
    printf("Uppercase to Lowercase - Expected: b, Got: %c\n", ft_tolower('B'));
    printf("Lowercase Input - Expected: z, Got: %c\n", ft_tolower('z'));
    printf("Non-alpha character - Expected: 5, Got: %c\n", ft_tolower('5'));
    printf("Extended ASCII - Expected: 128, Got: %c\n", ft_tolower(128));  // Non-ASCII input
}

// Advanced tests for ft_toupper
void test_toupper() {
    printf("\nTesting ft_toupper with edge cases:\n");
    printf("Lowercase to Uppercase - Expected: C, Got: %c\n", ft_toupper('c'));
    printf("Uppercase Input - Expected: Z, Got: %c\n", ft_toupper('Z'));
    printf("Non-alpha character - Expected: 3, Got: %c\n", ft_toupper('3'));
    printf("Extended ASCII - Expected: 130, Got: %c\n", ft_toupper(130));  // Non-ASCII input
}

int main() {
    test_strlen();
    test_strcpy();
    test_strdup();
    test_strjoin();
    test_memcpy();
    test_atoi();
    test_isalpha();
    test_isdigit();
    test_tolower();
    test_toupper();

    return 0;
}
