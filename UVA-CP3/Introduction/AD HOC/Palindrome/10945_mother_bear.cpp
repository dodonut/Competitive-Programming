#include <iostream>
#include <string>
#include <algorithm>

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

std::string to_lower(const std::string &line)
{
    std::string tmp = line;
    for (auto &&i : tmp)
    {
        i = std::tolower(i);
    }
    return tmp;
}

int main()
{
    std::string tmp;
    while (getline(std::cin, tmp) && tmp != "DONE")
    {
        tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [](unsigned char x) { return std::ispunct(x) || std::isspace(x); }), tmp.end());
        if (is_pal(to_lower(tmp)))
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
}