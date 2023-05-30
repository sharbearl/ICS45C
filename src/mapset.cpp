#include <algorithm>
#include "mapset.hpp"

std::string to_lowercase(const std::string& str)
{
    std::string lower {str};
    std::transform(lower.begin(), lower.end(), lower.begin(), 
                   [](char c){return std::tolower(c);});
    return lower; 
}
/*
std::set<std::string> load_stopwords(std::istream& stopwords);

std::map<std::string, int> count_word(std::istream& document,
                           const std::set<std::string>& stopwords);

void output_word_counts(const std::map<std::string, int>& word_counts
                        std::ostream& output);*/
