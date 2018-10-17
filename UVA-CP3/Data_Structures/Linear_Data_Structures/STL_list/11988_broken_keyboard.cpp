#include <iostream>
#include <list>
#include <sstream>

int main()
{
    char c;
    std::string line;
    std::list<char> lineList;
    std::list<char>::iterator pos;
    while (getline(std::cin, line))
    {
        std::stringstream ss(line);
        lineList.clear();
        pos = lineList.begin();
        while (ss >> c)
        {
            if (c == '[')
                pos = lineList.begin();
            else if (c == ']')
                pos = lineList.end();
            else
                lineList.insert(pos, c);
        }
        for (auto &&i : lineList)
            std::cout << i;
        std::cout << '\n';
    }
}