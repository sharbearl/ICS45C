#include <algorithm>
#include <iostream>
#include <iterator>
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
/*
std::map<std::string, int> count_word(std::istream& document,
                           const std::set<std::string>& stopwords);

void output_word_counts(const std::map<std::string, int>& word_counts
                        std::ostream& output);*/
