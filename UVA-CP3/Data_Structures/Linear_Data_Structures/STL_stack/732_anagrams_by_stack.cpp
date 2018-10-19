#include <iostream>
#include <stack>
#include <algorithm>

std::string source, target;
int len;

bool possible(std::string a, std::string b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return a == b;
}

void printPop(std::stack<char> m)
{
    int count = 0;
    std::stack<char> p;
    while (!m.empty())
    {
        p.push(m.top());
        m.pop();
    }
    while (!p.empty())
    {
        if (count++)
            std::cout << ' ';
        std::cout << p.top();
        p.pop();
    }
    std::cout << '\n';
}

void anagram(int i, int o, std::stack<char> s, std::string m, std::stack<char> poppush)
{
    if (i == len && o == len)
        printPop(poppush);
    else
    {
        if (i < len)
        {
            s.push(source[i]);
            poppush.push('i');
            anagram(i + 1, o, s, m, poppush);
            poppush.pop();
            s.pop();
        }
        if (!s.empty() && s.top() == target[o])
        {
            s.pop();
            poppush.push('o');
            anagram(i, o + 1, s, m, poppush);
        }
    }
}

int main()
{
    std::stack<char> push, pop;
    while (std::cin >> source >> target)
    {
        printf("[\n");
        len = source.size();
        if (possible(source, target))
            anagram(0, 0, push, "", pop);
        printf("]\n");
    }
}