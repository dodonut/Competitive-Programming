#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#define ii std::pair<std::string, std::string>
#define vii std::vector<ii>

vii shelve, tmpStack;

bool compare(vii::iterator &a, vii::iterator &b)
{
    if ((*a).second == (*b).second)
        return (*a).first < (*b).first;
    return (*a).second < (*b).second;
}

void shelveSort()
{
    for (auto &&it = tmpStack.begin(); it != tmpStack.end(); ++it)
    {
        tmpStack.erase(it);
        auto lowerbound = std::lower_bound(shelve.begin(), shelve.end(), it, compare);
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
            std::sort(tmpStack.begin(), tmpStack.end(), compare);
            shelveSort();
        }
        else
        {
            sscanf(line.c_str(), "%s \"%[^\"]\"", status, title);
            tmpStack.push_back(std::make_pair(title, author));
        }
    }
}