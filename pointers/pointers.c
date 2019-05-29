#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int i = 0;
    while (*y != '\0')
    {
        x[i] = *y;
        i++;
        y++;
    }
    x[i] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{

    while (*str != '\0')
    {
        if (*str == c)
        {
            return str;
        }
        else
        {
            str++;
        }
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
int string_length(char *string)
{
    int length = 0;
    while (*string != '\0')
    {
        length++;
        string++;
    }
    return length;
}
char *find_string(char *haystack, char *needle)
{
    int length = string_length(needle);

    while (*haystack != '\0')
    {
        if (*haystack == needle[0])
        {
            char *firstIndex = haystack;

            for (int i = 0; i < length; i++)
            {
                if (firstIndex[i] != needle[i])
                {
                    return NULL;
                }
            }
            return firstIndex;
        }
        haystack++;
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
