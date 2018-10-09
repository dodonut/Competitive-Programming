#include <iostream>
#include <bitset>
#include <cstdio>

int main()
{
    unsigned int n, a, b;
    int i;
    while (scanf("%ud", &n), n)
    {
        i = 0;
        a = 0;
        b = 0;
        bool odd = false;
        while ((1 << i++) < n)
        {
            if (n & (1 << i))
            {
                if (odd)
                    b |= (i << i);
                else
                    a |= (i << i);
                odd = !odd;
            }
        }
        printf("%ul %ul\n", a, b);
    }
}