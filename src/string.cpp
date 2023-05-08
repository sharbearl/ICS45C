#include <iostream>
#include "string.hpp";

String::String(const char *s) : head(list::from_string(s)) {}

String::String(const String &s) : head(list::copy(s.head)) {}

int String::size() const
{
    return list::length(head);
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

void String::print(std::ostream &out) const
{
    list::print(out, head);
}

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

