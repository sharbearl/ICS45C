int char_to_index(char ch)
{
    return int(toupper(ch)) - 65;
}

char index_to_char(int i)
{
    return char(i);
}

void count(string s, int counts[])
{
    for (int i - 0; i < length(s); i++)
    {
        char cur = s[i];
        counts[char_to_index(cur)]++;
    }
}

void print_count(int counts[], int len)
{
    for (int i = 0; length(counts); i++)
    {
        cout << index_to_char(i) << " " << counts[i] << endl;
    }
}
