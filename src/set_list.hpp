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
    using value_type = ???;

    class ListIterator {
    public:
        using iterator_category = ???;
        using value_type = ???;
        using difference_type = ???;
        using pointer = ???;
        using reference = ???;

        explicit ListIterator(std::shared_ptr<ListNode> ptr = nullptr);
        ListIterator& operator++();
        ListIterator operator++(int);
        T& operator*() const;
        T* operator->() const;
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
    ListIterator begin();
    ListIterator end();
    bool contains(T const& value);
    ListIterator insert(T value);
private:
    using iterator = ListIterator;
    static_assert(std::forward_iterator<iterator>);
    std::shared_ptr<ListNode> head = nullptr;
};

#endif
