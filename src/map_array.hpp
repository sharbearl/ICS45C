#ifndef MAP_ARRAY_HPP
#define MAP_ARRAY_HPP

#include <algorithm>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>

template <typename Key, typename Value>
class MapArray {
public:
    using value_type = ???;
    class ArrayIterator {
    public:
        using iterator_category = ???;
        using value_type = ???;
        using difference_type = ???;
        using pointer = ???;
        using reference = ???;

        explicit ArrayIterator(std::pair<Key, Value>* ptr = nullptr);
        ArrayIterator& operator++();
        ArrayIterator& operator--();
        ArrayIterator operator++(int);
        ArrayIterator operator--(int);
        ArrayIterator& operator+=(difference_type d);
        ArrayIterator& operator-=(difference_type d);
        friend ArrayIterator operator+(ArrayIterator it, difference_type d);
        friend ArrayIterator operator+(difference_type d, ArrayIterator it);
        friend ArrayIterator operator-(ArrayIterator it, difference_type d);
        friend difference_type operator-(ArrayIterator lhs, 
                                         ArrayIterator rhs);
        auto operator<=>(const ArrayIterator& other) const = default;
        std::pair<Key, Value>& operator*() const;
        std::pair<Key, Value>* operator->() const;
        std::pair<Key, Value>& operator[](difference_type d) const;
    private:
        std::pair<Key, Value>* ptr;
    };
    using iterator = ArrayIterator;
    ArrayIterator begin();
    ArrayIterator end();
    Value& operator[](const Key& key);
private:
    std::vector<std::pair<Key, Value>> data;
    static_assert(std::random_access_iterator<iterator>);
};

#endif
