#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

std::vector<int> left(100005), right(100005);

int main()
{
    int S, B, l, r;
    while (scanf("%d %d", &S, &B), S || B)
    {
        std::iota(left.begin(), left.begin() + S, 0);
        std::iota(right.begin(), right.begin() + S, 1);
        right[S] = 0;

        for (int i = 0; i < B; i++)
        {
            scanf("%d %d", &l, &r);

            right[left[l]] = right[r];
            left[right[r]] = left[l];

            if (left[l] == 0)
                printf("* ");
            else
                printf("%d ", left[right[r]]);

            if (right[r] == 0)
                printf("*");
            else
                printf("%d", right[left[l]]);
            printf("\n");
        }
        printf("-\n");
    }
}