#include <iostream>
#include <stack>
#include <algorithm>

std::string source, target;

bool possible(std::string a, std::string b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return a == b;
}

void printPop(std::stack<char> m)
{
    while (!m.empty)
    {
        std::cout << m.top() << ' ';
        m.pop();
    }
    std::cout << '\n';
}

void anagram(int i, int o, std::stack<char> s, std::string m, std::stack<char> poppush)
{
    if (m == target)
        printPop(poppush);
    else
    {
        if (i < source.size())
        {
            s.push(source[i]);
            poppush.push('i');
            anagram(i + 1, o, s, m, poppush);
            poppush.pop();
            s.pop();
        }
        if (!s.empty() && s.top() == target[o])
        {
            m += s.top();
            s.pop();
            poppush.push('o');
            anagram(i, o + 1, s, m, poppush);
        }
    }
}

int main()
{
    std::stack<char> push;
    while (std::cin >> source >> target)
    {
        printf("[\n");
        if (possible(source, target))
            anagram(0, 0, push, "", "");
        printf("]\n");
    }
}