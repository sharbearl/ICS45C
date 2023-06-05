#ifndef SET_LIST_HPP
#define SET_LIST_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <memory>
#include <ranges>

template <typename T>
class SetList {
    struct ListNode {
        T data;
        std::shared_ptr<ListNode> next;
    };
public:
    using value_type = T;

    class ListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = SetList::value_type;
        using difference_type = std::ptrdiff_t;
        using pointer = ListNode*;
        using reference = ListNode&;

        explicit ListIterator(std::shared_ptr<ListNode> ptr = nullptr)
            : ptr(ptr) {}

        ListIterator& operator++()
        {
            if(ptr != nullptr)
            {
                ptr = ptr->next;
            }
            return *this;
        }

        ListIterator operator++(int)
        {
            ListIterator copy = *this;
            ptr = ptr->next;
            return copy;
        }

        T& operator*() const
        {
            return ptr->data;
        }

        T* operator->() const
        {
            return ptr;
        }

        bool operator ==(const ListIterator& other) const = default;
    private:
        std::shared_ptr<ListNode> ptr;
    };
    SetList() = default;
    template <std::ranges::input_range Rng>
    explicit SetList(Rng&& rng) {
        std::ranges::for_each(std::forward<Rng>(rng),
                              std::bind_front(&SetList::insert, this));
    }

    ListIterator begin()
    {
        return ListIterator(head);
    }

    ListIterator end()
    {
        return ListIterator(nullptr);
    }

    bool contains(T const& value)
    {
        auto result = std::find(begin(), end(), value);

        return result != end();
    }

    ListIterator insert(T value)
    {
        if(!contains(value))
        {
            auto new_head {std::make_shared<ListNode>(value, head)};
            head = new_head;
        }

        return ListIterator(head);
    }
private:
    using iterator = ListIterator;
    static_assert(std::forward_iterator<iterator>);
    std::shared_ptr<ListNode> head = nullptr;
};

#endif
