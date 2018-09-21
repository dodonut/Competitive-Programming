#include <iostream>

int main()
{
    int n, i, next, before, N[3001];
    bool flag;

    while (scanf("%d", &n) != EOF)
    {
        flag = false;
        std::fill(N, N + n, 0);
        scanf("%d", &next);
        for (i = 0; i < n - 1; i++)
        {
            before = next;
            scanf("%d", &next);
            if (std::abs(before - next) < 3000)
                N[std::abs(before - next)] = 1;
        }
        for (i = 1; i < n - 1; i++)
            if (!N[i])
                break;

        if (N[i] || n == 1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
}