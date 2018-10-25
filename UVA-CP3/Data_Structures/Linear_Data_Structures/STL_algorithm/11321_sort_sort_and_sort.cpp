#include <cstdio>
#include <algorithm>
int N, M;
int vet[10005];

bool comp(int a, int b)
{
    if (a % M == b % M)
    {
        if (a % 2 == 0 && b % 2 == 0)
            return a < b;
        else if (a % 2 != 0 && b % 2 == 0)
            return abs((a % 2)) > (b % 2);
        else if (a % 2 != 0 && b % 2 != 0)
            return a > b;
    }
    return (a % M) < (b % M);
}

int main()
{
    while (scanf("%d %d", &N, &M), (N || M))
    {
        for (int i = 0; i < N; i++)
            scanf("%d", &vet[i]);

        std::sort(vet, vet + N, comp);

        printf("%d %d\n", N, M);
        for (int i = 0; i < N; i++)
            printf("%d\n", vet[i]);
    }
    printf("0 0\n");
}