#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>

int f[1500];
std::vector<std::vector<int>> ff;
int levels;
int n;
int len;

void factors(int number)
{
    std::vector<int> s;
    int i;
    int count = 0;
    for (i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            f[count++] = i;
            s.push_back(number / i);
        }
    }
    for (int j = s.size() - 1; j >= 0; j--)
        f[count++] = s[j];

    len = count;
}

void factorizations(int index, int currentVal, std::vector<int> s)
{
    unsigned long long val;
    for (int i = index; i < len; i++)
    {
        val = currentVal * f[i];
        if (val < n)
        {
            s.push_back(f[i]);
            factorizations(i, val, s);
            s.pop_back();
        }
        else if (val == n)
        {
            s.push_back(f[i]);
            ff.push_back(s);
            levels++;
            return;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    int T, c;
    while (scanf("%d", &n), n)
    {
        for (auto &i : ff)
            i.clear();
        ff.clear();
        levels = 0;
        std::vector<int> a;

        factors(n);
        factorizations(0, 1, a);
        printf("%d\n", levels);
        if (levels)
        {
            for (auto &t : ff)
            {
                c = 0;
                for (auto &k : t)
                {
                    if (c++)
                        putchar(' ');
                    printf("%d", k);
                }
                puts("");
            }
        }
    }
}