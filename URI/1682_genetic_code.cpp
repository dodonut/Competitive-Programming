#include <iostream>
using namespace std;

char genome[] = {'N', 'O', 'P'};

bool is_thue(string curr_word)
{
    int s = curr_word.size();
    if (s <= 1)
        return true;
    if (s == 2)
        return curr_word[0] != curr_word[1];
    string search = curr_word.substr(s - 2);
    int k = curr_word.find(search);
    int t = curr_word.rfind(search);
    return curr_word.find(search) == curr_word.rfind(search);
}

string thue_sequence(string curr_word, int n)
{
    int _s = curr_word.size();
    if (_s == n)
    {
        return curr_word;
    }
    for (int i = 0; i < 3; i++)
    {
        if (is_thue(curr_word + genome[i]))
            return thue_sequence(curr_word + genome[i], n);
    }
}

int main()
{
    int n;
    string s = "N";
    while (scanf("%d", &n), n)
    {
        cout << thue_sequence(s, n) << '\n';
    }
}