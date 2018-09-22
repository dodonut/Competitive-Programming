#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> army;

void dead(int from, int to)
{
    std::fill(army.begin() + from, army.begin() + to, 0);
    bool fromBuddieFound = false, toBuddieFound = false;
    while (from-- >= 0)
    {
        if (army[from] != 0)
        {
            fromBuddieFound = true;
            break;
        }
    }
    while (to++ < army.size())
    {
        if (army[to] != 0)
        {
            toBuddieFound = true;
            break;
        }
    }
    if (fromBuddieFound)
        printf("%d ", army[from]);
    else
        printf("* ");

    if (toBuddieFound)
        printf("%d", army[to]);
    else
        printf("*");
}

int main()
{
    int S, B, from, to;
    while (scanf("%d %d", &S, &B), S || B)
    {
        army.clear();
        army.resize(S);
        std::iota(army.begin(), army.end(), 1);

        for (int i = 0; i < B; i++)
        {
            scanf("%d %d", &from, &to);
            dead(from - 1, to);
            printf("\n");
        }
        printf("-\n");
    }
}