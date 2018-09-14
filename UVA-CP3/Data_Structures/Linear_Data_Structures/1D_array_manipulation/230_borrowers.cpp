#include <iostream>
#include <map>
#include <cstdio>
#include <set>
#include <cstring>

#define ii std::pair<std::string, std::string>
#define sii std::set<ii>

sii shelve, returned;
std::map<std::string, std::string> shelvemap, borrow;

void shelveSort()
{
    for (auto &&it : returned)
    {
        auto pos = shelve.insert(it);
        auto count = std::distance(shelve.begin(), pos.first);
        if (count == 0)
        {
            printf("Put \"%s\" first\n", it.second.c_str());
        }
        else
        {
            printf("Put \"%s\" after \"%s\"\n", it.second.c_str(), ((*(pos.first)).second.c_str()));
        }
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
        shelve.insert(std::make_pair(author, title));
    }

    while (getline(std::cin, line))
    {
        if (line == "END")
            break;

        if (line == "SHELVE")
        {
            shelveSort();
            printf("END\n");
            returned.clear();
        }

        else
        {
            sscanf(line.c_str(), "%s \"%[^\"]\"", status, title);
            if (strcmp(status, "BORROW") == 0)
            {
                shelve.erase(std::make_pair(shelvemap[title], title));
                borrow[title] = shelvemap[title];
            }
            else
            {
                returned.insert(std::make_pair(borrow[title], title));
                borrow.erase(title);
            }
        }
    }
}