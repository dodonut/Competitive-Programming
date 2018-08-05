#include <iostream>
#include <map>
#include <vector>

typedef std::pair<int, int> ii;
typedef std::map<int, ii> mii;

bool called[5][5];
int all[76];
mii grid;

bool calledAllBingoNumbers()
{
    int i;
    for (i = 1; i < 76; i++)
        if (!all[i])
            return false;
    return true;
}

bool won()
{
    bool wv = true;
    bool wh = true;
    bool dp = true;
    bool ds = true;
    int i, j;
    for (i = 0; i < 5; i++)
    {
        wv = true;
        wh = true;
        for (j = 0; j < 5; j++)
        {
            if (!called[j][i])
            {
                wv = false;
            }
            if (!called[i][j])
                wh = false;
        }
        if (wv || wh)
            return true;
    }
    for (i = 0; i < 5; i++)
        if (!called[i][i])
            dp = false;

    for (i = 0, j = 4; i < 5 && j >= 0; i++, j--)
        if (!called[i][j])
            ds = false;

    return (dp || ds);
}

int main()
{
    int N, i, j, bingo_card, bingo_number, count;
    scanf("%d", &N);
    while (N--)
    {
        grid.clear();
        for (i = 0; i < 76; i++)
            all[i] = 0;
        for (i = 0; i < 5; i++)
            for (j = 0; j < 5; j++)
                called[i][j] = 0;

        count = 0;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (i == 2 && j == 2)
                {
                    called[i][j] = 1;
                    bingo_card = 0;
                }
                else
                {
                    scanf("%d", &bingo_card);
                }
                grid[bingo_card] = std::make_pair(i, j);
            }
        }
        while (!won() && count < 100)
        {
            scanf("%d", &bingo_number);
            all[bingo_number] = 1;
            auto tmp = grid.find(bingo_number);
            if (tmp != grid.end())
                called[tmp->second.first][tmp->second.second] = 1;
            count++;
        }
        while (!calledAllBingoNumbers())
        {
            scanf("%d", &bingo_number);
            all[bingo_number] = 1;
        }
        printf("BINGO after %d numbers announced\n", count);
    }
}