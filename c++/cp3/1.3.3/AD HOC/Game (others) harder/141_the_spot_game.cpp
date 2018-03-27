#include <iostream>
#include <bitset>

std::bitset<50 * 50> left[103], no[103], right[103], down[103];

bool cmpM(int current)
{
    for (int i = 0; i < current - 1; i++)
        if (left[i] == left[current] || right[i] == right[current] || no[i] == no[current] || down[i] == down[current] || left[i] == no[current] || right[i] == no[current] || down[i] == no[current])
            return true;

    return false;
}

int main()
{

    int N, x, y;
    int xl, yl, xr, yr, xd, yd, player, winner, winMove;
    char ch;
    while (scanf("%d", &N), N)
    {
        player = 0;
        winner = -1;
        for (int i = 0; i < 2 * N; i++)
        {
            scanf("%d %d %c", &x, &y, &ch);
            x--;
            y--;
            xl = y;
            yl = N - x - 1;
            xr = N - y - 1;
            yr = x;
            xd = yl;
            yd = xr;
            left[i].flip(xl * N + yl);
            no[i].flip(x * N + y);
            right[i].flip(xr * N + yr);
            down[i].flip(xd * N + yd);
            if (winner == -1 && cmpM(i))
            {
                winner = 1 + (player + 1) % 2;
                winMove = i + 1;
            }
            left[i + 1] = left[i];
            right[i + 1] = right[i];
            no[i + 1] = no[i];
            down[i + 1] = down[i];
            player = (player + 1) % 2;
        }
        for (int i = 0; i < 2 * N; i++)
        {
            left[i].reset();
            right[i].reset();
            down[i].reset();
            no[i].reset();
        }
        if (winner == -1)
            printf("Draw\n");
        else
            printf("Player %d wins on move %d\n", winner, winMove);
    }
}