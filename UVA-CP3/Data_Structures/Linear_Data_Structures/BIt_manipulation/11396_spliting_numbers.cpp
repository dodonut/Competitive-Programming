#include <iostream>
#include <bitset>
#include <cstdio>

int main()
{
    unsigned long n, a, b;
    int i;
    while (scanf("%lu", &n), n)
    {
        i = 0;
        a = 0;
        b = 0;
        bool odd = false;
        while ((1 << i) <= n)
        {
            if (n & (1 << i))
            {
                if (odd)
                    b |= (1 << i);
                else
                    a |= (1 << i);
                odd = !odd;
            }
            i++;
        }
        printf("%lu %lu\n", a, b);
    }
}