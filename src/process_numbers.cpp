#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>
#include "process_numbers.hpp"

void split_odd_even(std::istream& numbers, 
                    std::ostream& odds, std::ostream& evens)
{
    std::vector<int> nums;
    std::copy(std::istream_iterator<int>(numbers), 
              std::istream_iterator<int>(), back_inserter(nums));
    std::sort(nums.begin(), nums.end());

    std::copy_if(nums.begin(), nums.end(), 
                 std::ostream_iterator<int>(odds, " "),
                 [](int x){return x % 2 == 1;});
    odds << "\n";

    std::copy_if(nums.begin(), nums.end(), 
                 std::ostream_iterator<int>(evens, "\n"),
                 [](int x){return x % 2 == 0;});
}
