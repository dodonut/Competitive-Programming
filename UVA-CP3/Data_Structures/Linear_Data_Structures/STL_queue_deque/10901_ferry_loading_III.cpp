#include <cstring>
#include <iostream>
#include <queue>

#define RIGHT 0
#define LEFT 1
struct Car
{
    int time, in;
    Car(int t, int i) : time(t), in(i) {}
};

int main()
{
    int n, t, m, T, ferry_time, ti, side, cont;
    int order[10005];
    scanf("%d", &T);
    bool move;
    char s[10];
    while (T--)
    {
        ferry_time = 0;
        side = LEFT;
        scanf("%d%d%d", &n, &t, &m);
        std::queue<Car> cars_queue[2];
        for (int i = 0; i < m; i++)
            order[i] = 0;

        for (int i = 0; i < m; i++)
        {
            scanf("%d %s ", &ti, s);
            if (strcmp("right", s) == 0)
                cars_queue[RIGHT].push(Car(ti, i));
            else
                cars_queue[LEFT].push(Car(ti, i));
        }

        while (!(cars_queue[RIGHT].empty() && cars_queue[LEFT].empty()))
        {
            move = false;
            if (!cars_queue[side].empty() && cars_queue[side].front().time <= ferry_time)
            {
                move = true;
                cont = 0;
                while (!cars_queue[side].empty() && cars_queue[side].front().time <= ferry_time && cont < n)
                {
                    cont++;
                    order[cars_queue[side].front().in] = ferry_time + t;
                    cars_queue[side].pop();
                }
            }
            if (move || (!cars_queue[!side].empty() && cars_queue[!side].front().time <= ferry_time))
            {
                ferry_time += t;
                side = !side;
            }
            else
                ferry_time += 1;
        }
        for (int i = 0; i < m; i++)
            printf("%d\n", order[i]);

        if (T)
            printf("\n");
    }
}