#include <iostream>
#include <algorithm>

std::map<std::string, std::string> key_val, val_key;

int main()
{
    int N;
    std::string line, tmp;
    scanf("%d", &N);
    getline(std::cin, line);
    while (N--)
    {
        getline(std::cin, line);
        std::erase(std::remove_if(line.begin(), line.end(), [](char x) { return isspace(x); }), line.end());
        tmp = line;
        std::sort(tmp.begin(), tmp.end());
    }
}