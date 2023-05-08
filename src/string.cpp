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
/*
std::strong_ordering String::operator<=>(const String &s) const
{
}*/

void String::print(std::ostream &out) const
{
    list::print(out, head);
}

std::ostream &operator<<(std::ostream &out, const String &s)
{
    s.print(out);
    return out;
}

