#include <algorithm>
#include <iostream>
#include <cstdio>
#include <numeric>
#include <vector>

std::vector<int> left(100001), right(100001);

int main()
{
    int S, B, l, r;
    while (scanf("%d %d", &S, &B), S || B)
    {
        std::iota(left.begin(), left.begin() + S + 1, 0);
        std::iota(right.begin(), right.begin() + S + 1, 1);
        right[S] = 0;

        while (B--)
        {
            scanf("%d %d", &l, &r);

            if (left[l] == 0)
                printf("* ");
            else
                printf("%d ", left[l]);
            left[right[r]] = left[l];

            if (right[r] == 0)
                printf("*");
            else
                printf("%d", right[r]);
            right[left[l]] = right[r];

            printf("\n");
        }
        printf("-\n");
    }
}