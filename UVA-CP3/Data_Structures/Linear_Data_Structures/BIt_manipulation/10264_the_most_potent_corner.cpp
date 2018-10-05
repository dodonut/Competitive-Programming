#include <cstdio>
#include <iostream>

#define FLIP(x, y) (x ^ (1 << y))

int main()
{
    int arr[1 << 14 + 1] = {0}, N, s, stot, sums[1 << 14 + 1] = {0};

    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < (1 << N); i++)
        {
            scanf("%d", &arr[i]);
        }

        stot = 0;
        for (int i = 0; i < (1 << N); i++)
        {
            s = 0;
            for (int j = 0; j < N; j++)
                s += arr[FLIP(i, j)];

            sums[i] = s;
        }
        for (int i = 0; i < (1 << N); i++)
        {
            for (int j = 0; j < N; j++)
            {
                int k = FLIP(i, j);
                if (sums[k] + sums[i] > stot)
                    stot = sums[k] + sums[i];
            }
        }
        printf("%d\n", stot);
    }
}