#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include "process_numbers.hpp"

void split_odd_even(std::istream& numbers, 
                    std::ostream& odds, std::ostream& evens)
{
    std::vector<std::string> V;
    std::copy(std::istream_iterator<std::string>(numbers), 
              std::istream_iterator<std::string>(), back_inserter(V));
    //std::sort(nums.begin(), nums.end());

    //std::copy_if(nums.begin(), nums.end(), 
    //             std::ostream_iterator<int>(odds, " "),
    //             [](int x){return x % 2 == 1;});
}
