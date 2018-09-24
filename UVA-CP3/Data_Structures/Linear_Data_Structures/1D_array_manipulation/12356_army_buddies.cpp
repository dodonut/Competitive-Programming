#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

std::vector<int> army;

void dead(int from, int to)
{

    auto f = std::lower_bound(army.begin(), army.end(), from);
    auto t = std::upper_bound(army.begin(), army.end(), to);

    if (std::distance(army.begin(), f - 1) >= 0)
        printf("%d ", *(--f));
    else
        printf("* ");

    if (std::abs(std::distance(army.end(), t)) > 0)
        printf("%d", *t);
    else
        printf("*");

    army.erase(f, t);

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
            dead(from, to);
            printf("\n");
        }
        printf("-\n");
    }
}