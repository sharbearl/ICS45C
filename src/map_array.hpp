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
    using value_type = std::pair<Key, Value>;
    class ArrayIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = MapArray::value_type;
        using difference_type = std::ptrdiff_t;
        using pointer = MapArray::value_type*;
        using reference = MapArray::value_type&;

        explicit ArrayIterator(std::pair<Key, Value>* ptr = nullptr)
            : ptr(ptr) {}

        ArrayIterator& operator++()
        {
           ++ptr;
           return *this;
        }

        ArrayIterator& operator--()
        {
            --ptr;
            return *this;
        }

        ArrayIterator operator++(int)
        {
            auto cpy = *this;
            ptr++;
            return cpy;
        }

        ArrayIterator operator--(int)
        {
            auto cpy = *this;
            ptr++;
            return cpy;
        }

        ArrayIterator& operator+=(difference_type d);

        ArrayIterator& operator-=(difference_type d);

        friend ArrayIterator operator+(ArrayIterator it, difference_type d);
        
        friend ArrayIterator operator+(difference_type d, ArrayIterator it);
        
        friend ArrayIterator operator-(ArrayIterator it, difference_type d);
        
        friend difference_type operator-(ArrayIterator lhs, 
                                         ArrayIterator rhs);
        
        auto operator<=>(const ArrayIterator& other) const = default;

        std::pair<Key, Value>& operator*() const
        {
            return *ptr;
        }

        std::pair<Key, Value>* operator->() const
        {
            return ptr;
        }

        std::pair<Key, Value>& operator[](difference_type d) const;
    private:
        std::pair<Key, Value>* ptr;
    };
    using iterator = ArrayIterator;
    ArrayIterator begin()
    {
        return ArrayIterator(data.begin());
    }

    ArrayIterator end()
    {
        return ArrayIterator(data.end());
    }

    Value& operator[](const Key& key);
private:
    std::vector<std::pair<Key, Value>> data;
    static_assert(std::random_access_iterator<iterator>);
};

#endif
