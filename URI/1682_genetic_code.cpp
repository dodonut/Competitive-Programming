#include <iostream>
using namespace std;

char genome[] = {'N', 'O', 'P'};

bool thue_for3(string curr_word)
{
    return curr_word[0] != curr_word[1] && curr_word[1] != curr_word[2];
}

bool thue_for4(string curr_word)
{
    return curr_word[3] != curr_word[2] && curr_word.substr(0, 2) != curr_word.substr(2);
}

bool is_thue(string curr_word)
{
    int s = curr_word.size();
    if (s <= 1)
        return true;
    if (s == 2)
        return curr_word[0] != curr_word[1];
    if (s == 3)
        return thue_for3(curr_word.substr(s - 3));
    return thue_for3(curr_word.substr(s - 3)) && thue_for4(curr_word.substr(s - 4));
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
    return "erro";
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