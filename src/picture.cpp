#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture() : head(nullptr), tail(nullptr){}

void Picture::add(const Shape& shape)
{
    head = new ListNode{shape, nullptr, tail};
    if(!tail)
        tail = head;
    else
        tail->prev = head;
}

void Picture::print_all(std::ostream& out) const
{
    for (ListNode* p = head; p != nullptr; p = p->next)
        p->shape.print();
}
