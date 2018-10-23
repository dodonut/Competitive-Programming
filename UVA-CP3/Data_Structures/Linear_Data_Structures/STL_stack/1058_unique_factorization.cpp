#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>

int f[1500];
std::vector<std::stack<int>> ff;
int levels;
int len;

void factors(int number)
{
    std::vector<int> s;
    int i;
    for (i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            f[i] = i;
            s.push_back(number / i);
        }
    }
    for (int j = 0; j < s.size(); j++)
        f[i++] = s[j];

    len = i;
}

void factorizations(int currentVal, int number, std::stack<int> s)
{
    int val;
    for (int i = 1; i <= len; i++)
    {
        val = currentVal * f[i];
        if (val < number)
        {
            s.push(f[i]);
            factorizations(val, number, s);
            s.pop();
        }
        else if (val == number)
        {
            s.push(f[i]);
            ff.push_back(s);
            levels++;
        }
        return;
    }
}

int main()
{
    int T, n;

    while (scanf("%d", &n), n)
    {
        for (auto &i : ff)
        {
            while (!i.empty())
                i.pop();
        }
        ff.clear();
        levels = 0;
        std::stack<int> a;

        factors(n);
        factorizations(0, n, a);
        printf("%d", levels);
    }
}