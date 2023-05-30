#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include "mapset.hpp"

std::string to_lowercase(const std::string& str)
{
    std::string lower {str};
    std::transform(lower.begin(), lower.end(), lower.begin(), 
                   [](char c){return std::tolower(c);});
    return lower; 
}

std::set<std::string> load_stopwords(std::istream& stopwords)
{
    std::set<std::string> words;
    words.insert(std::istream_iterator<std::string>(stopwords),
                 std::istream_iterator<std::string>());

    std::set<std::string> lower_words;
    std::transform(words.begin(), words.end(), std::inserter(lower_words,
                   lower_words.begin()), [](std::string str)
                   {return to_lowercase(str);});
    return lower_words;
}

std::map<std::string, int> count_words(std::istream& document,
                           const std::set<std::string>& stopwords)
{
    std::map<std::string, int> counts;
    std::for_each(std::istream_iterator<std::string>(document),
                  std::istream_iterator<std::string>(),
                  [stopwords, &counts](std::string word){
            if(stopwords.find(to_lowercase(word)) == stopwords.end())
                ++counts[to_lowercase(word)];});
    return counts;
}

void output_word_counts(const std::map<std::string, int>& word_counts,
                        std::ostream& output)
{
    for(auto [key, value] : word_counts)
        output << key << " " << value << "\n";
}
