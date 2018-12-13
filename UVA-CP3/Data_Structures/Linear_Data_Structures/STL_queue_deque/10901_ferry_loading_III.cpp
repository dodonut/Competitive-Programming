#include <iostream>
#include <queue>
#include <cstring>

#define RIGHT 0
#define LEFT 1

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, t, m, T, ferry_time, ti, side, cont;
    scanf("%d", &T);
    bool move;
    char s[10];
    while (T--)
    {
        ferry_time = 0;
        side = LEFT;
        scanf("%d%d%d", &n, &t, &m);
        std::queue<int> cars_queue[2];
        while (m--)
        {
            scanf("%d %s ", &ti, s);
            if (strcmp("right", s) == 0)
                cars_queue[RIGHT].push(ti);
            else
                cars_queue[LEFT].push(ti);
        }
        while (!(cars_queue[RIGHT].empty() && cars_queue[LEFT].empty()))
        {
            move = false;
            if (!cars_queue[side].empty() && cars_queue[side].front() <= ferry_time)
            {
                move = true;
                cont = 0;
                while (!cars_queue[side].empty() && cars_queue[side].front() <= ferry_time && cont < n)
                {
                    cont++;
                    cars_queue[side].pop();
                    printf("%d\n", ferry_time + t);
                }
            }
            if (move || cars_queue[!side].front() <= ferry_time)
                side = !side;

            ferry_time += t;
        }
        if (T)
            printf("\n");
    }
}