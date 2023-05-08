#include <iostream>
#include "string.hpp";

String::String(const char *s) : head(list::from_string(s)) {}

String::String(const String &s) : head(list::copy(s.head)) {}

//String::String(String &&s)

//void swap(String &s)

String &String::operator=(const String &s)
{
    if(&s != this)
    {
        list::free(head);
        head = list::copy(s.head);
    }
    return *this;
}

//String &String::operator=(String &&s)

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

//int indexOf(char c) const

//int indexOf(const String &s) const

bool String::operator==(const String &s) const
{
    int result = list::compare(head, s.head);
    return result == 0;
}

std::strong_ordering String::operator<=>(const String &s) const
{
    return list::compare(head, s.head) <=> 0;
}

//String String::operator+(const String &s)

//String &String::operator+=(const String &s)

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
