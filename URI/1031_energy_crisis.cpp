#include <iostream>

int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int n, k, t;
    while (scanf("%d", &n), n)
    {
        k = 1;
        while (true)
        {
            t = josephus(n - 1, k) + 1;
            if (t == 13)
            {
                printf("%d\n", k);
                break;
            }
            k++;
        }
    }
}
