#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

#define ii std::pair<std::string, std::string>
#define vii std::vector<ii>

vii shelve, borrowed, returned;

bool compare(const ii &a, const ii &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

std::pair<std::string, std::string> find_pair_by_title(const std::string &title)
{
    auto lower_bound = std::lower_bound(shelve.begin(), shelve.end(), title,
                                        [](const ii &a, const ii &b) { return a.first < b.first; });
    return (*lower_bound);
}

void shelveSort()
{
    for (auto &&it = returned.begin(); it != returned.end(); ++it)
    {
        returned.erase(it);
        auto lowerbound = std::lower_bound(shelve.begin(), shelve.end(), *it, compare);
        auto a = std::distance(shelve.begin(), lowerbound);
        if (a == 0)
        {
            printf("Put %s first\n", (*it).first.c_str());
        }
        else
        {
            printf("Put %s after %s\n", (*it).first.c_str(), (*(--it)).first.c_str());
        }
        shelve.insert(lowerbound, *it);
    }
}

int main()
{
    char title[81], author[81], status[10];
    std::string line;

    while (getline(std::cin, line))
    {
        if (line == "END")
            break;
        sscanf(line.c_str(), " \"%[^\"]\" by %[^\"]", title, author);
        shelve.push_back(std::make_pair(title, author));
    }
    std::sort(shelve.begin(), shelve.end(), compare);

    while (getline(std::cin, line))
    {
        if (line == "END")
            break;
        if (line == "SHELVE")
        {
            std::sort(returned.begin(), returned.end(), compare);
            shelveSort();
        }
        else
        {
            sscanf(line.c_str(), "%s \"%[^\"]\"", status, title);
            auto title_author = find_pair_by_title(title);
            if (strcmp(status, "BORROW") == 0)
            {
                shelve.erase(std::find(shelve.begin(), shelve.end(), title_author));
                borrowed.push_back(title_author);
            }
            else
            {
                borrowed.erase(std::find(borrowed.begin(), borrowed.end(), title_author);
                returned.push_back(title_author);
            }
        }
    }
}