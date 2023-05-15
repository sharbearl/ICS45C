#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture(): head(nullptr), tail(nullptr){}

void Picture::add(const Shape& shape)
{
    ListNode* temp = new ListNode{shape, tail, nullptr};
    
}

void Picture::print_all(std::ostream& out) const
{
    for (ListNode* p = head; p != nullptr; p = p->next)
        p->shape.print();
}
