#include <iostream>
#include <vector>

int CanCompleteLap(std::vector<int> &F, std::vector<int> &S)
{
    int i, j, fuel;
    bool enoughFuel;
    for (i = 0; i < F.size(); i++)
    {
        j = i;
        enoughFuel = true;
        do
        {
            fuel += F[j] - S[j];
            j = (j + 1) % F.size();
        } while (j != i && fuel >= 0);
        if (enoughFuel)
        {
            printf("Enough Fuel: %d", fuel);
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    int T, N, tmp, count = 1;
    std::vector<int> F, S;
    scanf("%d", &T);
    while (T--)
    {
        F.clear();
        S.clear();
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &tmp);
            F.push_back(tmp);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &tmp);
            S.push_back(tmp);
        }
        int c = CanCompleteLap(F, S);
        printf("Case %d: ", count++);
        if (c > 0)
            printf("Possible from station %d\n", c);
        else
            printf("Not possible\n");
    }
}