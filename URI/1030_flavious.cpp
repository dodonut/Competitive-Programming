#include <iostream>

int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int nc, n, k, i = 1;
    scanf("%d", &nc);
    while (nc--)
    {
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i++, josephus(n, k));
    }
}