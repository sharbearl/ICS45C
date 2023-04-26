#include <iostream>
#include "string.hpp";

String::String(const char *s)
{
    if (strlen(s) >= MAXLEN)
    {
        std::cout << "ERROR: Index Out Of Bounds";
        strncpy(buf, "", MAXLEN - 1);
    } 
    strncpy(buf, s, MAXLEN - 1);
}

String &String::operator=(const String &s)
{
    strncpy(buf, s.buf, MAXLEN - 1);
    return *this;
}

char &String::operator[](int index)
{
    if (!in_bounds(index))
    {
        std::cout << "ERROR: Index Out Of Bounds";
        return buf[0];
    }
    
    return buf[index];
}

String::String(const String &s)
{
    strncpy(buf, s.buf, MAXLEN - 1);
}

int String::size() const
{
    return strlen(buf);
}

String String::reverse() const
{
    char c[MAXLEN];
    reverse_cpy(c, buf);
    return String(c);

}

int String::indexOf(char c) const
{
    if (strchr(buf, c) == nullptr)
    {
        return -1;
    }
    return strchr(buf, c) - buf; 
}

int String::indexOf(const String &s) const
{
    if (strstr(buf, s.buf) == nullptr)
    {
        return -1;
    } 
    return strstr(buf, s.buf) - buf; 
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

String String::operator+(const String &s) const
{
    if (strlen(buf) + strlen(s.buf) >= MAXLEN)
    {
        std::cout << "ERROR: Index Out Of Bounds";
        return *this;
    } 
    String temp(buf);
    strncat(temp.buf, s.buf, MAXLEN - 1);
    return temp;
}

String &String::operator+=(const String &s)
{
    if (strlen(buf) + strlen(s.buf) >= MAXLEN)
    {
        std::cout << "ERROR: Index Out Of Bounds";
        return *this;
    } 
    strncat(buf, s.buf, MAXLEN - 1);
    return *this;
}

void String::print(std::ostream &out) const
{
    out << buf;
}

void String::read(std::istream &in)
{
    char temp[MAXLEN];
    in >> temp;
    strncpy(buf, temp, MAXLEN - 1);
}

String::~String()
{
    std::cout << "String " << buf << " is destructing" << std::endl;
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
    char temp[strlen(src) + len + 1];
    strcpy(temp, dest);

    for(i = 0; src[i] != '\0'; ++i)
    {
        temp[i + len] = src[i];
    }
    temp[i + len] = '\0';
    strcpy(dest, temp);
    return dest; 
}

char *String::strncat(char *dest, const char *src, int n)
{
    int i;
    int len = strlen(dest);
    int temp_len = strlen(src) + len + 1; 
    char temp[temp_len];
    strcpy(temp, dest);

    for(i = 0; src[i] != '\0' && i < n; ++i)
    {
        temp[i + len] = src[i];
    }
    temp[i + len] = '\0'; 
    strcpy(dest, temp);
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
    else
    {
        return 0;
    }
}

int String::strncmp(const char *left, const char *right, int n)
{
    int i = 0;
    for(i = 0; left[i] != '\0' && right[i] != '\0' && i < n; ++i)
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
    if ((left[i] == '\0' && right[i] == '\0') || n == i)
    {
        return 0;
    }
    else if (strlen(left) > strlen(right))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void String::reverse_cpy(char *dest, const char *src)
{
    if (strlen(src) == 0)
    {
        dest[0] = '\0';
        return;
    }

    int len = strlen(src);
    int j = 0;
    const int temp_len = len + 1;
    char temp[temp_len];
    strcpy(temp, src);

    for(int i = len - 1; i >= 0; --i)
    {
        dest[j] = temp[i];
        ++j;
    }
    dest[j] = '\0';
}

const char *String::strchr(const char *str, char c)
{    
    if (c == '\0')
    {
        return str + strlen(str);
    }
    for(int i = 0; str[i] != '\0'; ++i)
    {
        const char *p = &str[i];
        if (str[i] == c)
        {
            return p;
        }
    }
    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle)
{
    if (strlen(needle) == 0)
    {
        return haystack;
    }

    int len = strlen(needle);

    for (const char *p = haystack; (p = strchr(p, needle[0])); ++p)
    {
        if (strncmp(p, needle, len) == 0)
        {
            return p;
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &out, const String &s)
{
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s)
{
    s.read(in);
    return in;
}
