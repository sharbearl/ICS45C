#include <iostream>
#include "letter_count.h"

constexpr int N_CHARS = ('Z'-'A'+1);

int main()
{
    string line;
    int counts[N_CHARS] = {0};
    while (getline(cin, line))
    {
        count(line, counts);
    }
    print_count(counts, N_CHARS);
    return 0;
}
