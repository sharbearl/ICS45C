#include <iostream>
#include "letter_count.h"

constexpr int N_CHARS = ('Z'-'A'+1);

int main()
{
    string line;
    int len;
    int counts[N_CHARS] = {0};
    while (getline(cin, line))
    {
        len = line.length();
        count(line, counts);
    }
    print_count(counts, len);
    return 0;
}
