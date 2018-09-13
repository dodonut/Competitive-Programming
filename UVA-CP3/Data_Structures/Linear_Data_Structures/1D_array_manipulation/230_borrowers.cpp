#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>

#define ii std::pair<std::string, std::string>
#define vii std::vector<ii>

vii shelve, returned;
std::map<std::string, std::string> shelvemap, borrow;

bool compare(const ii &a, const ii &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void remove_by_title(const std::string &title)
{
    auto lowerbound = std::lower_bound(shelve.begin(), shelve.end(), title,
                                       [](const ii &a, std::string t) { return a.first < t; });
    shelve.erase(lowerbound);
}

void shelveSort()
{
    for (auto &&it : returned)
    {
        auto lower_bound = std::lower_bound(shelve.begin(), shelve.end(), it.first,
                                            [](const ii &a, std::string t) { return a.first < t; });

        auto count = std::distance(shelve.begin(), lower_bound);
        if (count == 0)
        {
            printf("Put %s first\n", it.first.c_str());
        }
        else
        {
            printf("Put %s after %s\n", it.first.c_str(), (*lower_bound).first.c_str());
        }
        shelve.insert(lower_bound, it);
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
        sscanf(line.c_str(), " \"%[^\"]\" by %[^\n\r]", title, author);
        shelvemap[title] = author;
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
            for (auto &&i : shelve)
                printf("shelve %s %s\n", i.first.c_str(), i.second.c_str());
            //shelveSort();
        }

        else
        {
            sscanf(line.c_str(), "%s \"%[^\"]\"", status, title);
            if (strcmp(status, "BORROW") == 0)
            {
                remove_by_title(title);
                borrow[title] = shelvemap[title];
            }
            else
            {
                returned.push_back(std::make_pair(title, borrow[title]));
                borrow.erase(title);
            }
        }
    }
}