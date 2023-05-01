#include <iostream>
#include "string.hpp";

int String::strlen(const char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        ++len;
    }
    return len;
}

char *String::strcpy(char *dest, const char *src)
{
    int i;
    for(i = 0; src[i] != '\0'; ++i)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *String::strncpy(char *dest, const char *src, int n)
{
    int i;
    for(i = 0; src[i] != '\0' && i < n; ++i)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
