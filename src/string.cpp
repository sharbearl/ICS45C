#include <iostream>
#include "string.hpp";

String::String(const char *s) : head(list::from_string(s)) {}

String::String(const String &s) : head(list::copy(s.head)) {}

int String::size() const
{
    return list::length(head);
}
