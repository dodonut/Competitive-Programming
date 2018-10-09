#include <iostream>
#include <bitset>
#include <cstdio>

int main()
{
    unsigned int n, a, b;
    int i;
    while (scanf("%ud", &n), n)
    {
        i = 1;
        a = 0;
        b = 0;
        bool odd = false;
        while ((1 << i++) < n)
        {
            if (n & (1 << i))
            {
                if (odd)
                    b++;
                else
                    a++;
                odd = !odd;
            }
        }
        printf("%ul %ul\n", a, b);
    }
}