#include <cstring>
#include <iostream>
#include <queue>

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int c, l, m, size_car, total_remaining, travel_times;
    bool left_flag;
    char arrive_bank[10];
    scanf("%d", &c);
    while (c--)
    {
        travel_times = 0;
        scanf("%d %d", &l, &m);
        l *= 100;
        std::queue<int> left, right;
        while (m--)
        {
            scanf("%d %s", &size_car, arrive_bank);
            if (strcmp("left", arrive_bank) == 0)
                left.push(size_car);
            else
                right.push(size_car);
        }
        left_flag = true;
        total_remaining = l;
        while (!(left.empty() && right.empty()))
        {
            if (left_flag)
            {
                auto x = left.front();
                while (!left.empty() && total_remaining - left.front() > 0)
                {
                    total_remaining -= left.front();
                    left.pop();
                }
            }
            else
            {
                while (!right.empty() && total_remaining - right.front() > 0)
                {
                    total_remaining -= right.front();
                    right.pop();
                }
            }
            left_flag = !left_flag;
            total_remaining = l;
            travel_times++;
        }
        printf("%d\n", travel_times);
    }
}