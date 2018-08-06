#include <iostream>
#include <map>

std::map<char, char> reverseTable;

void makeTable(std::map<char, char> &table)
{
    table['A'] = 'A';
    table['E'] = '3';
    table['H'] = 'H';
    table['J'] = 'L';
    table['L'] = 'J';
    table['M'] = 'M';
    table['O'] = 'O';
    table['S'] = '2';
    table['T'] = 'T';
    table['U'] = 'U';
    table['V'] = 'V';
    table['W'] = 'W';
    table['X'] = 'X';
    table['Y'] = 'Y';
    table['Z'] = '5';
    table['1'] = '1';
    table['2'] = 'S';
    table['3'] = 'E';
    table['5'] = '5';
    table['8'] = '8';
}

bool is_mirrored(const std::string &word)
{
    int i, j;
    for (i = 0; i < word.size(); i++)
    {
        auto c = reverseTable.find(word[i]);
        if (c != reverseTable.end())
        {
            if (c->second != (word[word.size() - 1 - i]))
                return false;
        }
        else
            return false;
    }
    return true;
}

bool is_pal(const std::string &word)
{
    int size = word.size(), i;
    for (i = 0; i < size / 2; i++)
    {
        if (word[i] != word[size - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    std::string word;
    makeTable(reverseTable);
    while (std::cin >> word)
    {
        if (is_pal(word) && is_mirrored(word))
            printf("%s -- is a mirrored palindrome.\n\n", word.c_str());
        else if (is_mirrored(word))
            printf("%s -- is a mirrored string.\n\n", word.c_str());
        else if (is_pal(word))
            printf("%s -- is a regular palindrome.\n\n", word.c_str());
        else
            printf("%s -- is not a palindrome.\n\n", word.c_str());
    }
}