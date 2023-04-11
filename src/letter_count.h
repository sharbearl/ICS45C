using namespace std;

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
    for (int i = 0; i < s.length(); i++)
    {
        char cur = s[i];
        counts[char_to_index(cur)]++;
    }
}

void print_count(int counts[], int len)
{
    for (int i = 0; i < 65; i++)
    {
        cout << index_to_char(i) << " " << counts[i] << endl;
    }
}
