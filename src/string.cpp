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

char *String::strcat(char *dest, const char *src)
{
    int i = 0;
    int d_len = 0;
    for(int j = 0; dest[j] != '\0'; ++j)
    {
        ++d_len;
    }
    
    if (src[i] != '\0')
    {
        for(i = 1; src[i] != '\0'; ++i)
        {
            dest[i + d_len] = src[i];
        }
    }
    dest[i + d_len] = '\0';
    dest[d_len] = src[0];
    return dest;
}

char *String::strncat(char *dest, const char *src, int n)
{
    int i = 0;
    int d_len = 0;
    for(int j = 0; dest[j] != '\0'; ++j)
    {
        ++d_len;
    }

    if (src[i] != '\0')
    {
        for(i = 1; src[i] != '\0' && i < n; ++i)
        {
            dest[i + d_len] = src[i];
        }
    }
    dest[i + d_len] = '\0';
    dest[d_len] = src[0];
    return dest;
}
