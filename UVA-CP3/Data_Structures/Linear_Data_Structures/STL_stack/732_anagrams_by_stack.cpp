#include <iostream>
#include <stack>

void printPop(std::string &m)
{
    for (int i = 0; i < m.size(); i++)
        std::cout << m[i] << ' ';
    std::cout << '\n';
}

void anagram(int index, std::string source, std::string target, std::stack<char> s, std::string m, std::string poppush)
{
    if (m == target)
        printPop(poppush);
    else
    {
        if (index < source.size())
        {
            s.push(source[index]);
            poppush += 'i';
            anagram(index + 1, source, target, s, m, poppush);
        }
        if (!s.empty())
        {
            m += s.top();
            s.pop();
            poppush += 'o';
            anagram(index + 1, source, target, s, m, poppush);
        }
    }
}

int main()
{
    std::string source, target;
    std::stack<char> push;
    while (std::cin >> source >> target)
    {
        printf("[\n");
        anagram(0, source, target, push, "", "");
        printf("]\n");
    }
}