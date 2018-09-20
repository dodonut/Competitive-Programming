#include <iostream>

int main()
{
    int N, h[101], sum, set = 1;

    while (scanf("%d", &N), N)
    {
        sum = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &h[i]);
            sum += h[i];
        }
        int totHeight = sum / N;
        int totMoves = 0;
        for (int i = 0; i < N; i++)
        {
            if (h[i] > totHeight)
                totMoves++;
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", set++, totMoves);
    }
}