#include <iostream>
#include <string>

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
    std::string tmp;

    while (getline(std::cin, tmp) && tmp != "DONE")
    {
        tmp.erase(std::remove(tmp.begin(), tmp.end(), [](unsigned char x) { return std::ispunct(x); }), tmp.end());
        if (is_pal(tmp))
            printf("You won't be eaten!");
        else
            printf("Uh oh..");
    }
}