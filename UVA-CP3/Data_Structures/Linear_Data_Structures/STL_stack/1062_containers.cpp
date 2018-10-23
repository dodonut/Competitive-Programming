#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

int main()
{
    char stack[1005];
    std::vector<std::vector<char>> stks;
    int len, count, Case = 1;
    bool fit;
    while (fgets(stack, 1005, stdin) && strcmp(stack, "end\n"))
    {
        //printf("string %s -> ", stack);
        for (auto k : stks)
            k.clear();
        stks.clear();

        len = strlen(stack);
        for (int i = 0; i < len - 2; i++)
        {
            fit = false;
            for (int j = 0; j < stks.size() && !fit; i++)
            {
                if (stack[i] <= stks[j].back())
                {
                    stks[j].push_back(stack[i]);
                    fit = true;
                }
            }
            if (!fit)
            {
                std::vector<char> k;
                k.push_back(stack[i]);
                stks.push_back(k);
            }
        }
        printf("Case %d: %d\n", Case++, stks.size());
    }
}