#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture(): head(nullptr), tail(nullptr){}

Picture::Picture(const Picture& other) : head(nullptr), tail(nullptr)
{
    if (other.head != nullptr)
        head = new ListNode{other.head->shape->clone(), nullptr, tail};
    
    ListNode* prev = head;

    if (other.head->next != nullptr)
    {
        for (ListNode* p = other.head->next; p != nullptr; p = p->next)
        {
            ListNode* temp = new ListNode{p->shape->clone(), prev, nullptr};
            prev->next = temp;
            prev = temp;
        }
    }

    tail = prev;
}

Picture &Picture::operator=(const Picture& other)
{

}

void Picture::add(const Shape& shape)
{
    ListNode* temp = new ListNode{shape.clone(), tail, nullptr};

    if (head == nullptr)
        head = temp;
    if (tail == nullptr)
        tail = temp;
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void Picture::print_all(std::ostream& out) const
{
    if (head != nullptr)
    {
        for (ListNode* p = head; p != nullptr; p = p->next)
            (p->shape)->print(out);
    }
}

void Picture::draw_all(std::ostream& out) const
{
    if (head != nullptr)
    {
        for (ListNode* p = head; p != nullptr; p = p->next)
            (p->shape)->draw(out);
    }
}

double Picture::total_area() const
{
    double total = 0.0;

    if (head != nullptr)
    {
        for (ListNode* p = head; p != nullptr; p = p->next)
            total += (p->shape)->area();
    }

    return total;
}

Picture::~Picture()
{/*
    for(ListNode *p = head; p != nullptr;)
    {
        ListNode *temp = p;
        p = p->next;
        delete temp;
    }*/
}
