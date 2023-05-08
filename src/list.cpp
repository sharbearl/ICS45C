#include <iostream>
#include "list.hpp";
using namespace list;

Node* list::from_string(const char *s)
{
    Node *first = new Node{s[0], nullptr}; 
    Node *previous = first;

    if(s[0] != '\0')
    {
        for(int i = 1; s[i] != '\0'; ++i)
        {
            previous->next = new Node{s[i], nullptr};
            previous = previous->next;
        }
    }
    return first;
}

void list::free(Node* head)
{
    for(Node *p = head; p != nullptr;)
    {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
}

int list::compare(Node* lhs, Node* rhs)
{
    Node *l = lhs;
    Node *r = rhs;

    for(; l != nullptr && r != nullptr; l = l->next, r = r->next)
    {
        if(l->data != r->data)
        {
            return l->data - r->data;
        }
    }

    if(l == nullptr && r == nullptr)
    {
        return 0;
    }
    else if(l == nullptr)
    {
        return 0 - r->data;
    }
    else
    {
        return l->data - 0;
    }

    delete l;
    delete r;
}

int list::compare(Node* lhs, Node* rhs, int n)
{
    Node *l = lhs;
    Node *r = rhs;
    int i = 0;

    for(; l != nullptr && r != nullptr && i < n; l = l->next, r = r->next, ++i)
    {
        if(l->data != r->data)
        {
            return l->data - r->data;
        }
    }

    if(l == r || i == n)
    {
        return 0;
    }
    else if(l != nullptr && r != nullptr && l->data == r->data)
    {
        return 0;
    }
    else if(l == nullptr)
    {
        return 0 - r->data;
    }
    else
    {
        return l->data - 0;
    }

    delete l;
    delete r;
}

void list::print(std::ostream& out, Node* head)
{
    for(Node *p = head; p != nullptr; p = p->next)
    {
        out << p->data;
    }
}

Node* list::copy(Node* head)
{
    Node* p = new Node{head->data, head->next};
    return p;
}

int list::length(Node* head)
{
    int count = 0;
    for(Node *p = head; p != nullptr; p = p->next)
    {
        ++count;
    }
    return count;
}
/*
Node* list::reverse(Node* head)
{
    Node *last = head;
    Node *first;

    if(last != nullptr)
    {
        for(Node *p = head->next; p != nullptr; p = p->next)
        {
            first = p;
            first->next = last;
            last = first;
        }
    }
    return first;
}*/
