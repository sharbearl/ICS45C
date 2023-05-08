#include <iostream>;
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

void list::print(std::ostream& out, Node* head)
{
    for(Node *p = head; p != nullptr; p = p->next)
    {
        out << p->data;
    }
}

Node* copy(Node* head)
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
