#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#define ii std::pair<std::string, std::string>
#define vii std::vector<ii>

vii shelve, borrowed, returned;

bool compare(const ii &a, const ii &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

bool comp(const ii &a, const ii &b)
{
    return a.first < b.first;
}

int bin_search(vii &t, int i, int f, std::string k)
{
    if (i == f)
        return f;
    int m = (i + f) / 2;
    if (t[m].first < k)
        return bin_search(t, m + 1, f, k);
    return bin_search(t, i, m - 1, k);
}

void shelveSort()
{
    for (auto &&it = returned.begin(); it != returned.end(); ++it)
    {
        returned.erase(it);
        auto lowerbound = bin_search(shelve, 0, shelve.size(), (*it).first);
        if (lowerbound == 0)
        {
            printf("Put %s first\n", (*it).first.c_str());
        }
        else
        {
            printf("Put %s after %s\n", (*it).first.c_str(), (*(--it)).first.c_str());
        }
        shelve.insert(std::advance(shelve.begin(),lowerbound),(*it));
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
                borrowed.erase(std::find(borrowed.begin(), borrowed.end(), title_author));
                returned.push_back(title_author);
            }
        }
    }
}