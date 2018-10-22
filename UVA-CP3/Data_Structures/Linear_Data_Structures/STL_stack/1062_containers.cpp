#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

int main()
{
    char stack[1005];
    std::map<char, int> map;
    int len, count, Case = 1;
    while (fgets(stack, 1005, stdin) && strcmp(stack, "end\n"))
    {
        //printf("string %s -> ", stack);
        len = strlen(stack);
        count = 1;
        for (int i = len - 2; i > 0; i--)
        {
            if (stack[i] > stack[i - 1])
                count++;

            map[stack[i]] = 1;
        }
        map[stack[0]] = 1;
        printf("%d %d\n", count, (int)map.size());
        printf("Case %d: %d\n", Case++, std::min(count, (int)map.size()));
    }
}