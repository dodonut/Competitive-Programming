#include <iostream>
#include <map>
#include <cstring>

std::map<std::string, std::string> loser;
typedef std::pair<int, int> ii;

int win[101], loses[101];

int main()
{
    int fp, sp, n, k, count = 0, games, i, tot;
    char pfp[10], psp[10];
    std::string first_play, second_play;
    loser["rock"] = "paper";
    loser["scissors"] = "rock";
    loser["paper"] = "scissors";

    while (scanf("%d", &n), n)
    {
        scanf("%d", &k);
        if (count > 0)
            printf("\n");
        std::fill(win, win + 101, 0);
        std::fill(loses, loses + 101, 0);
        games = k * n * (n - 1) / 2;
        while (games--)
        {
            scanf("%d %s %d %s", &fp, pfp, &sp, psp);
            first_play = pfp;
            second_play = psp;
            if (loser[first_play] == second_play)
            {
                loses[fp] += 1;
                win[sp] += 1;
            }
            else if (loser[second_play] == first_play)
            {
                loses[sp] += 1;
                win[fp] += 1;
            }
        }
        for (i = 1; i <= n; i++)
        {
            tot = win[i] + loses[i];
            if (tot > 0)
                printf("%.3f\n", win[i] / (double)(tot));
            else
                printf("-\n");
        }
        count++;
    }
}