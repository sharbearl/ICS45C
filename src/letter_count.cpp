#include <iostream>
#include "letter_count.h"

constexpr int N_CHARS = ('Z'-'A'+1);

int main()
{
    string line;
    int counts[N_CHARS] = {};
    while (getline(cin, line))
    {
        count(line, counts);
    }

    return 0;
}
