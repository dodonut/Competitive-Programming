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
    return m - tmp_i + 1;
}

int main()
{
    int sz, p, r, c, count, s, f, m;
    bool decRow, decCol;
    long long n;
    while (scanf("%d%d", &sz, &p), sz || p)
    {
        count = 1;
        n = 1;
        while (p > n)
        {
            count += 2;
            n = count * count;
        }
        f = n * n;
        s = f - n + 1;
        count = 0;
        bool foundRange = false;
        while (s > p)
        {
            f = s;
            s = f - n + 1;
            count++;
        }
        switch (count)
        {
        case 0:
            c = n;
            r = binary_search(s, f, p);
            break;
        case 1:
        }

        printf("Line = %d, column = %d.\n", r, c);
    }
}