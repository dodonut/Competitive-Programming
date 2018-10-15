#include <iostream>

#define FLIP(x, y) (x ^= (1 << y))

int main()
{
    unsigned int N, n, k, t, x[1 << 31], count, pos, val, tmp_pos;
    bool one, inc;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d %d", &n, &k);
        t = 1;
        ++k;
        while ((1 << t) < k)
            t++;
        pos = (1 << t);
        val = pos >> 1;
        one = true;
        inc = true;
        tmp_pos = 1;
        while (pos > k)
        {
            if (one)
                FLIP(val, 0);
            else
                FLIP(val, count);
            for (int i = 0; i < tmp_pos; i++)
        }
    }
}