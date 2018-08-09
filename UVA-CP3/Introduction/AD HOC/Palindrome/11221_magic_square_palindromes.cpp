#include <iostream>
#include <algorithm>
#include <cmath>

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
    int T, r, count = 1;
    std::string line;
    std::cin >> T;
    std::cin.ignore();
    while (T--)
    {
        getline(std::cin, line);

        line.erase(std::remove_if(line.begin(), line.end(), [](unsigned char x) { return std::ispunct(x) || std::isspace(x); }), line.end());
        printf("Case #%d:\n", count++);
        if (is_pal(to_lower(line)))
        {
            r = sqrt(line.size());
            if (pow(r, 2) == line.length())
                printf("%d\n", r);
            else
                printf("No magic :(\n");
        }
        else
            printf("No magic :(\n");
    }
}