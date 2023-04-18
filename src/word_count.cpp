#include <istream>
#include <cctype>
#include "word_count.h";

#include <iostream>

void to_lowercase(std::string& str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        str[i] = tolower(str[i]);
    }
}

std::set<std::string> load_stopwords(std::istream& stopwords)
{
    std::string word;
    std::set<std::string> stops;

    while(std::getline(stopwords, word))
    {
        to_lowercase(word);
        stops.insert(word);
    }

    return stops;
}

std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords)
{
    std::map<std::string, int> count;
    std::string word;

    while (document >> word)
    {
        if (!stopwords.count(word))
        {
            count[word] += 1;
        }
    }

    return count;
}

void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output)
{
    for (auto e: word_counts)
    {
        output << e.first << " " << e.second << std::endl;
    }
}
