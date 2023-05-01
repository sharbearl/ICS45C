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

int String::strcmp(const char *left, const char *right)
{
    int i;
    for(i = 0; left[i] != '\0' && right[i] != '\0'; ++i)
    {
        if(left[i] != right[i])
        {
            return left[i] - right[i];
        }
    }

    if(left[i] == right[i])
    {
        return 0;
    }
    else
    {
        return left[i] - right[i];
    }
}

int String::strncmp(const char *left, const char *right, int n)
{
    int i;
    for(i = 0; left[i] != '\0' && right[i] != '\0' && i < n - 1; ++i)
    {
        if(left[i] != right[i])
        {
            return left[i] - right[i];
        }
    }

    if(left[i] == right[i])
    {
        return 0;
    }
    else
    {
        return left[i] - right[i];
    }
}

void String::reverse_cpy(char *dest, const char *src)
{
    if(src[0] == '\0')
    {
        dest[0] = '\0';
        return;
    }

    int len = 0;
    for(int i = 0; src[i] != '\0'; ++i)
    {
        ++len;
    }

    char temp;
    int j = 0;

    for(int i = len - 1; i >= (len/2); --i)
    {
        temp = src[j];
        dest[j] = src[i];
        dest[i] = temp;
        ++j;
    }
    dest[len] = '\0';
}

const char *String::strchr(const char *str, char c)
{
    if(c == '\0')
    {
        return str + strlen(str);
    }

    for(int i = 0; str[i] != '\0'; ++i)
    {
        const char *p = &str[i];
        if(str[i] == c)
        {
            return p;
        }
    }
    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle)
{
    if(needle[0] == '\0')
    {
        return haystack;
    }

    int len = strlen(needle);

    for(const char *p = haystack; (p = strchr(p, needle[0])); ++p)
    {
        if (strncmp(p, needle, len) == 0)
        {
            return p;
        }
    }
    return nullptr;
}
