#include "string.hpp";

String::String(const char *s)
{
    strncpy(buf, s, MAXLEN - 1);
}
/*
char &String::operator[](int index)
{
    return buf[index];
}

String::String(const String &s)
{
    
    strncpy(buf, s, MAXLEN - 1);
}
*/
int String::size()
{
    return strlen(buf);
}

int String::strlen(const char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        ++len;
    }
    return len;
}
/*
String::~String()
{
    std::cout << "String <buf> is destructing" << endl;
}
*/
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
