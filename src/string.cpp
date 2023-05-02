#include <iostream>
#include <utility>
#include "string.hpp";


String::String(const char *s) : buf(strdup(s)) {}

String::String(const String &s) : buf(strdup(s.buf)) {}

String::String(String &&s) : buf(strdup(s.buf)) 
{
    s.buf = nullptr;
}

void String::swap(String &s)
{
    std::swap(buf, s.buf);
}

String &String::operator=(const String &s)
{
    if(&s != this)
    {
        delete[] buf;
        buf = strdup(s.buf);
    }
    return *this;
}

String &String::operator=(String &&s)
{
    if(&s != this)
    {
        delete[] buf;
        swap(s);
    }
    return *this;
}

char &String::operator[](int index)
{
    if (!in_bounds(index))
    {
        std::cout << "ERROR: Index Out Of Bounds";
        return *buf;
    }

    return *(buf + index); 
}

const char &String::operator[](int index) const
{
    if (!in_bounds(index))
    {
        std::cout << "ERROR: Index Out Of Bounds";
        return buf[0];
    }

    return buf[index];
}

int String::size() const
{
    return strlen(buf);
}

String String::reverse() const
{
    String temp = String(strlen(buf));
    reverse_cpy(temp.buf, buf);
    return temp;
}

int String::indexOf(char c) const
{
    if(strchr(buf, c) == nullptr)
    {
        return -1;
    }
    return strchr(buf, c) - buf;
}

int String::indexOf(const String &s) const
{
    if(strchr(buf, *s.buf) == nullptr)
    {
        return -1;
    }
    return strchr(buf, *s.buf) - buf; 
}

bool String::operator==(const String &s) const
{
    int result = strcmp(buf, s.buf);
    return result == 0;
}

bool String::operator!=(const String &s) const
{
    int result = strcmp(buf, s.buf);
    return result != 0;
}

bool String::operator>(const String &s) const
{
    int result = strcmp(buf, s.buf);
    return result > 0;
}

bool String::operator<(const String &s) const
{
    int result = strcmp(buf, s.buf);
    return result < 0;
}

bool String::operator<=(const String &s) const
{
    int result = strcmp(buf, s.buf);
    return result <= 0;
}

bool String::operator>=(const String &s) const
{
    int result = strcmp(buf, s.buf);
    return result >= 0;
}

String String::operator+(const String &s) const
{
    String temp = String(strlen(buf) + strlen(s.buf));
    strcpy(temp.buf, buf);
    strcat(temp.buf, s.buf);
    return temp;
}

String &String::operator+=(const String &s)
{
    String temp = String(strlen(buf) + strlen(s.buf));
    strcpy(temp.buf, buf);
    if(s != *this)
    {
        delete[] buf;
    }
    strcat(temp.buf, s.buf);
    buf = strdup(temp.buf);
    return *this;
}

void String::print(std::ostream &out) const
{
    out << buf;
}

void String::read(std::istream &in)
{
    delete[] buf;
    char temp[1024];
    in >> temp;
    buf = strdup(temp);
}

String::String(int length) : buf(new char[length + 1]) {}

String::~String()
{
    
    if(buf != nullptr)
    {
        std::cout << "String " << buf << " is destructing" << std::endl;
    }
    else
    {
        std::cout << "String is destructing" << std::endl; 
    }
    delete[] buf;
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

char *String::strdup(const char *src)
{    
    char *p = new char[strlen(src) + 1];

    strcpy(p, src); 
    return p;
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

std::ostream &operator<<(std::ostream &out, String s)
{
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s)
{
    s.read(in);
    return in;
}
