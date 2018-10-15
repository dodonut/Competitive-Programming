#include <iostream>

#define FLIP(x, y) (x ^ (1 << y))

int main()
{
    unsigned int N, n, k, t, x[1 << 31], count, pos, val;
    bool one, inc;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d %d", &n, &k);
        t = 1;
        while ((1 << t) < k)
            t++;
        pos = (1 << t);
        val = pos >> 1;
        one = true;
        inc = true;
        while (pos > k)
        {
            if (one)
        }
    }
}