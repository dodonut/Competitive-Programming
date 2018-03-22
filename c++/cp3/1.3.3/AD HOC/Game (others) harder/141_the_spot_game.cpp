#include <iostream>
#include <bitset>
int main()
{
    std::bitset<50 * 50> left[101], no[101], right[101];
    int N, x, y;
    int xl, yl, xr, yr;
    char ch;
    while (scanf("%d", &N), N)
    {
        for (int i = 0; i < 2 * N; i++)
        {
            scanf("%d %d %c", &x, &y, &ch);
            xl = y;
            yl = N - x;
            yr = x;
            xr = N - y;
            left[i].flip(xl * N + yl);
            no[i].flip(x * N + y);
            right[i].flip(xr * N + yr);
            for (int j = 0; j < i; j++)
            {
            }
        }
    }
}