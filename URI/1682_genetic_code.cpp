#include <iostream>
using namespace std;

char genome[] = {'N', 'O', 'P'};

//create thue_sequence helper to deal with n = 1 and 2

string thue_sequence(string curr_word, int n, int pos)
{
    int _s = curr_word.size();
    string to_search;
    if (_s == n)
        return curr_word;
    for (int i = 0; i < 3; i++)
    {
        if (_s <= 1)
            return thue_sequence(curr_word + genome[pos], n, pos + 1);
        else
        {
            to_search = curr_word[_s - 1] + genome[pos];
            if (curr_word.find(to_search) + 2 == curr_word.rfind(to_search))
                return thue_sequence(curr_word + genome[pos], n, i);
            return thue_sequence(curr_word, n, i + 1);
        }
    }
    return nullptr;
}

int main()
{
    int n;
    string s = "";
    while (scanf("%d", &n), n)
    {
        cout << thue_sequence(s, n, 0) << '\n';
    }
}