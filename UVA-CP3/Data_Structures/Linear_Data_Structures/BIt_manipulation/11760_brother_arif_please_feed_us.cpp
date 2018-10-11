#include <iostream>

bool R[10002] = {true}, C[10002] = {true};
int r, c, n;

bool escaped(int a, int b)
{
    int rl = a - 1,
        rm = a + 1,
        cl = b - 1,
        cm = b + 1;
    return (C[b] && (R[a] || R[rl] || R[rm])) || (R[a] && (C[b] || C[cl] || C[cm]));
}

int main()
{
    int x, y, count = 1;
    R[0] = C[0] = 0;
    while (scanf("%d %d %d", &r, &c, &n), (r || c || n))
    {
        std::fill_n(R + 1, r + 1, 1);
        std::fill_n(C + 1, c + 1, 1);
        R[r + 1] = C[c + 1] = 0;
        while (n--)
        {
            scanf("%d %d", &x, &y);
            R[++x] = 0;
            C[++y] = 0;
        }

        scanf("%d %d", &x, &y);
        printf("Case %d: %s\n", count++, escaped(++x, ++y) ? "Escaped again! More 2D grid problems!" : "Party time! Let's find a restaurant!");
    }
}