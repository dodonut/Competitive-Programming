#include <iostream>

int binary_search(long long i, long long f, long long v)
{
    long long m, tmp_i = i;
    while (i != f)
    {
        m = (i + f) / 2;
        if (m < v)
            i = m + 1;
        else
            f = m;
    }
    return i - tmp_i;
}

int main()
{
    long long n, p, sz, r, c, count, s, f, m, lim_inf, lim_sup;
    while (scanf("%lld%lld", &sz, &p), sz || p)
    {
        n = 1;
        while (p > n * n)
            n += 2;

        lim_inf = (sz / 2) + 1 - (n / 2);
        lim_sup = (sz / 2) + 1 + (n / 2);
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
            c = binary_search(s, f - 1, p) + lim_inf;
            break;
        case 2:
            c = lim_inf;
            r = lim_sup - binary_search(s, f - 1, p);
            break;
        case 3:
            r = lim_sup;
            c = lim_sup - binary_search(s + 1, f - 1, p) - 1;
        }
        printf("Line = %d, column = %d.\n", r, c);
    }
}