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
        using iterator_category = std::random_access_iterator_tag;
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

        ArrayIterator& operator+=(difference_type d)
        {
            ptr += d;
            return *this;
        }

        ArrayIterator& operator-=(difference_type d)
        {
            ptr -= d;
            return *this;
        }

        friend ArrayIterator operator+(ArrayIterator it, difference_type d)
        {
            return ArrayIterator(it.ptr + d);
        }
        
        friend ArrayIterator operator+(difference_type d, ArrayIterator it)
        {
            return ArrayIterator(it.ptr + d);
        }

        friend ArrayIterator operator-(ArrayIterator it, difference_type d)
        {
            return ArrayIterator(it.ptr - d);
        }
        
        friend difference_type operator-(ArrayIterator lhs, 
                                         ArrayIterator rhs)
        {
            return lhs.ptr - rhs.ptr;
        }
        
        auto operator<=>(const ArrayIterator& other) const = default;

        std::pair<Key, Value>& operator*() const
        {
            return *ptr;
        }

        std::pair<Key, Value>* operator->() const
        {
            return ptr;
        }

        std::pair<Key, Value>& operator[](difference_type d) const
        {           
            return *(ptr + d);
        }
    private:
        std::pair<Key, Value>* ptr;
    };
    using iterator = ArrayIterator;

    ArrayIterator begin()
    {
        return ArrayIterator(&data[0]);
    }

    ArrayIterator end()
    {
        return ArrayIterator(&data[data.size()]);
    }

    Value& operator[](const Key& key)
    {
        auto result = std::find_if(begin(), end(), 
            [key](std::pair<Key, Value> pair){return pair.first == key;});
        if(result != end())
        {
            return (*result).second;
        }
        else
        {
            result = std::find_if(begin(), end(), [key]
                (std::pair<Key, Value> pair){return key < pair.first;});
            std::pair<Key, Value> new_pair;
            pair.first = key;
            result = data.insert(result, std::move(new_pair));
            return *(pair.second);
        }
    }
private:
    std::vector<std::pair<Key, Value>> data;
    static_assert(std::random_access_iterator<iterator>);
};

#endif
