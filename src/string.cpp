#include <iostream>
#include <utility>
#include "string.hpp";

String::String(const char *s) : head(list::from_string(s)) {}

String::String(const String &s) : head(list::copy(s.head)) {}

String::String(String &&s) : head(s.head)
{
    s.head = nullptr;
}

void String::swap(String &s)
{
    std::swap(head, s.head);
}

String &String::operator=(const String &s)
{
    if(&s != this)
    {
        list::free(head);
        head = list::copy(s.head);
    }
    return *this;
}

String &String::operator=(String &&s)
{
    swap(s);
    return *this;
}

bool String::in_bounds(int index) const
{
    return index >= 0 && index < list::length(head);
}

char String::operator[](int index) const
{
    if(head == nullptr)
    {
        return '@';
    }
    else if(!in_bounds(index))
    {
        std::cout << "ERROR: Index Out Of Bounds";
        return head->data;
    }
    return list::nth(head, index)->data;
}

int String::size() const
{
    return list::length(head);
}

String String::reverse() const
{
    return String(list::reverse(head));
}

int String::indexOf(char c) const
{
    list::Node* search = list::find_char(head, c);
    if(search == nullptr)
    {
        return -1;
    }
    return list::index(head, search);
}

int String::indexOf(const String &s) const
{
    list::Node* search = list::find_list(head, s.head);
    if(search == nullptr)
    {
        return -1;
    }
    return list::index(head, search);
}

bool String::operator==(const String &s) const
{
    int result = list::compare(head, s.head);
    return result == 0;
}

std::strong_ordering String::operator<=>(const String &s) const
{
    return list::compare(head, s.head) <=> 0;
}

String String::operator+(const String &s) const
{
    String temp = String(list::append(head, s.head));
    return temp;

}

String &String::operator+=(const String &s)
{
    String temp = String(list::append(head, s.head));
    swap(temp);
    return *this;
}

void String::print(std::ostream &out) const
{
    list::print(out, head);
}

void String::read(std::istream &in)
{
    list::free(head);
    char temp[1024];
    in >> temp;
    head = list::from_string(temp);
}

String::String(list::Node* head) : head(head) {}

String::~String()
{
    if(head != nullptr)
    {
        std::cout << "String ";
        list::print(std::cout, head);
        std::cout << " is destructing" << std::endl;
    }
    else
    {
        std::cout << "String is destructing" << std::endl;
    }
    list::free(head);
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
