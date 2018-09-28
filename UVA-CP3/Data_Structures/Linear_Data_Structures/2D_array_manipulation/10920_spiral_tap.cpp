#include <iostream>

int binary_search(int i, int f, int v)
{
    int m, tmp_i = i;
    do
    {
        m = (i + f) / 2;
        if (m < v)
            i = m;
        else
            f = m;
    } while (m != v);
    return m - tmp_i;
}

int main()
{
    int sz, p, r, c, count, s, f, m, lim_inf, lim_sup;
    long long n;
    while (scanf("%d%d", &sz, &p), sz || p)
    {
        count = 1;
        n = 1;
        while (p > n)
            d count += 2;

        lim_inf = (sz / 2) - (n / 2);
        lim_sup = (sz / 2) + (n / 2);
        f = n * n;
        s = f - n + 1;
        count = 0;
        while (s > p)
        {
            f = s;
            s = f - n + 1;
            count++;
        }
        switch (count)
        {
        case 0:
            c = lim_sup;
            r = binary_search(s, f, p) + lim_inf;
            break;
        case 1:
            r = lim_inf;
            c = binary_search(s, f, p) + lim_inf;
            break;
        case 2:
            c = lim_inf;
            r = binary_search(s, f, p) + lim_inf;
            break;
        case 3:
            r = lim_sup;
            c = binary_search(s, f, p) + lim_inf;
        }

        printf("Line = %d, column = %d.\n", r, c);
    }
}