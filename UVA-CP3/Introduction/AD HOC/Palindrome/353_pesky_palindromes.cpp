#include <iostream>
#include <map>

std::map<std::string, int> pal;

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

std::map<std::string, int> all_substrs(const std::string &word)
{
    std::map<std::string, int> substrs;
    for (int i = 0; i < word.size(); i++)
        for (int len = 1; len <= word.size() - i; len++)
            substrs[word.substr(i, len)] = 1;
    return substrs;
}

int main()
{
    int n_pals;
    std::string word;
    std::map<std::string, int> subsets;

    while (std::cin >> word)
    {
        n_pals = 0;
        subsets.clear();
        subsets = all_substrs(word);
        for (auto &&i : subsets)
        {
            if (is_pal(i.first))
                n_pals++;
                }
        printf("The string '%s' contains %d palindromes.\n", word.c_str(), n_pals);
    }
}