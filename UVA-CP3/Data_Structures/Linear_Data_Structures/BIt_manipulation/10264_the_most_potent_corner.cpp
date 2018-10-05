#include <iostream>
#include <cstdio>

#define FLIP(x, y) (x ^ (1 << y))

int main()
{
    int arr[1 << 14 + 1] = {0}, N, sum1, sum2, s, stot, sums[1 << 14 + 1] = {0};

    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < (1 << N); i++)
        {
            scanf("%d", &arr[i]);
        }

        sum1 = -1;
        sum2 = -1;
        stot = 0;
        for (int i = 0; i < (1 << N); i++)
        {
            s = 0;
            for (int j = 0; j < N; j++)
            {
                int k = FLIP(i, j);
                s += arr[k];
            }
            sums[i] = s;
        }
        for (int i = 0; i < (1 << N); i++)
        {
            for (int j = 0; j < N; j++)
            {
                int k = FLIP(i, j);
                sum2 = sum1;
                sum1 = sums[k];
                printf("sum2:%d sum1:%d stot:%d\n", sum2, sum1, stot);
                if (sum1 + sum2 > stot)
                    stot = sum1 + sum2;
            }
        }
        printf("%d\n", stot);
    }
}