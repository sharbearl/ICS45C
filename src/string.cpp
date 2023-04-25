#include <iostream>
#include "string.hpp";

String::String(const char *s)
{
    strncpy(buf, s, MAXLEN - 1);
}

String &String::operator=(const String &s)
{
    strncpy(buf, s.buf, MAXLEN - 1);
    return *this;
}

char &String::operator[](int index)
{
    return buf[index];
}

String::String(const String &s)
{
    strncpy(buf, s.buf, MAXLEN - 1);
}

int String::size()
{
    return strlen(buf);
}

bool String::operator==(const String &s) const
{
    int result = strncmp(buf, s.buf, MAXLEN - 1);
    if (result == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool String::operator!=(const String &s) const
{
    int result = strncmp(buf, s.buf, MAXLEN - 1);
    if (result != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool String::operator>(const String &s) const
{
    int result = strncmp(buf, s.buf, MAXLEN - 1);
    if (result == 1)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

bool String::operator<(const String &s) const
{
    int result = strncmp(buf, s.buf, MAXLEN - 1);
    if (result == -1)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

bool String::operator<=(const String &s) const
{
    int result = strncmp(buf, s.buf, MAXLEN - 1);
    if (result <= 0)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

bool String::operator>=(const String &s) const
{
    int result = strncmp(buf, s.buf, MAXLEN - 1);
    if (result >= 0)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

String String::operator+(const String &s)
{
    String temp(buf);
    strncat(temp.buf, s.buf, MAXLEN - 1);
    return temp;
}

String &String::operator+=(const String &s)
{
    strncat(buf, s.buf, MAXLEN - 1);
    return *this;
}

void String::print(std::ostream &out) const
{
    out << buf;
}
/*
String::~String()
{
    std::cout << "String " << buf << " is destructing" << std::endl;
}
*/
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
    int i;
    int len = strlen(dest);
    for(i = 0; src[i] != '\0' && i < MAXLEN - 1; ++i)
    {
        dest[i + len] = src[i];
    }
    dest[i + len] = '\0'; 
    return dest;
}

char *String::strncat(char *dest, const char *src, int n)
{
    int i;
    int len = strlen(dest);
    for(i = 0; src[i] != '\0' && i < MAXLEN - 1 && i < n; ++i)
    {
        dest[i + len] = src[i];
    }
    dest[i + len] = '\0'; 
    return dest;
}

int String::strcmp(const char *left, const char *right)
{
    int i;
    for(i = 0; left[i] != '\0' && right[i] != '\0'; ++i)
    {
        if (left[i] > right[i])
        {
            return 1;
        }
        else if (left[i] < right[i])
        {
            return -1;
        }
        else
        {
            continue;
        }
    }
    if (strlen(left) > strlen(right))
    {
        return 1;
    }
    else if (strlen(left) < strlen(right))
    {
        return -1;
    }
    else if (left[i] == right[i])
    {
        return 0;
    }
}

int String::strncmp(const char *left, const char *right, int n)
{
    int i;
    for(i = 0; left[i] != '\0' && right[i] != '\0' && i < n - 1; ++i)
    {
        if (left[i] > right[i])
        {
            return 1;
        }
        else if (left[i] < right[i])
        {
            return -1;
        }
        else
        {
            continue;
        }
    }
    if (left[i] == right[i])
    {
        return 0;
    }
    else if (strlen(left) < strlen(right))
    {
        return -1;
    }
    else if (strlen(left) > strlen(right))
    {
        return 1;
    } 
}

std::ostream &operator<<(std::ostream &out, const String &s)
{
    s.print(out);
    return out;
}


