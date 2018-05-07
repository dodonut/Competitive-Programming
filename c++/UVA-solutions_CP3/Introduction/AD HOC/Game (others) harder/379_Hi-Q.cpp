#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using std::map;
using std::vector;

struct Pos
{
    int x, y;
    Pos() : x(0), y(0){};
    Pos(int x, int y) : x(x), y(y) {}
};

int D[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int xsize = 9, ysize = 9;
vector<vector<int>> score(xsize, vector<int>(ysize));
vector<Pos> posMatrix(1);

bool sourceTargetSort(std::pair<Pos, Pos> p1, std::pair<Pos, Pos> p2)
{
    if (p1.second.x == p2.second.x && p1.second.y == p2.second.y)
        return score[p1.first.x][p1.first.y] > score[p2.first.x][p2.first.y];
    return score[p1.second.x][p1.second.y] > score[p2.second.x][p2.second.y];
}

Pos greaterTarget(Pos source, vector<vector<bool>> &p)
{
    int i, dx, dy;
    Pos target;
    int initScore = 0;
    for (i = 0; i < 4; i++)
    {
        dx = D[i][0];
        dy = D[i][1];
        if (p[source.x + dx][source.y + dy] && !p[source.x + dx * 2][source.y + dy * 2])
        {
            if (score[source.x + dx * 2][source.y + dy * 2] > initScore)
                initScore = score[source.x + dx * 2][source.y + dy * 2];
        }
    }
    target.x = posMatrix[initScore].x;
    target.y = posMatrix[initScore].y;
    return target;
}

std::pair<Pos, Pos> bestSourceTarget(vector<Pos> sources, vector<vector<bool>> &p)
{
    int i;
    vector<std::pair<Pos, Pos>> all;
    for (i = 0; i < sources.size(); i++)
        all.push_back(std::make_pair(sources[i], greaterTarget(sources[i], p)));

    sort(all.begin(), all.end(), sourceTargetSort);
    return all[0];
}

bool validPeg(vector<vector<bool>> p, int x, int y)
{
    int i, dx, dy, newx, newy;
    for (i = 0; i < 4; i++)
    {
        dx = D[i][0];
        dy = D[i][1];
        newx = x + dx * 2;
        newy = y + dy * 2;
        if ((newx < 3 || newx > 5) && (newy < 3 || newy > 5))
            continue;
        if (newx < 1 || newx > 7 || newy < 1 || newy > 7) //out of the board
            continue;
        if (p[x + dx][y + dy] && !p[x + dx * 2][y + dy * 2])
            return true;
    }
    return false;
}

std::pair<Pos, Pos> pickPeg(vector<vector<bool>> &p)
{
    int i, j, x, y;
    vector<Pos> sources;
    vector<Pos> target;
    for (i = 1; i <= 33; i++)
    {
        x = posMatrix[i].x;
        y = posMatrix[i].y;
        if (p[x][y] && validPeg(p, x, y))
            sources.push_back(posMatrix[i]);
    }
    if (sources.empty())
        return std::make_pair(Pos(0, 0), Pos(0, 0));

    return bestSourceTarget(sources, p);
}

Pos median(Pos p1, Pos p2)
{
    return Pos((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

int countRemaining(vector<vector<bool>> p)
{
    int i, j, cont = 0;
    for (i = 1; i <= 7; i++)
        for (j = 1; j <= 7; j++)
            if (p[i][j])
                cont += score[i][j];

    return cont;
}

int main()
{
    int N, i, j, cont = 1, val;
    std::pair<Pos, Pos> toMove(Pos(0, 0), Pos(0, 0));
    Pos med(0, 0);
    scanf("%d", &N);
    for (i = 1; i <= 7; i++)
    {
        for (j = 1; j <= 7; j++)
        {
            if (!((i < 3 || i > 5) && (j < 3 || j > 5)))
            {
                posMatrix.push_back(Pos(i, j));
                score[i][j] = cont++;
            }
        }
    }

    printf("HI Q OUTPUT\n");
    while (N--)
    {
        vector<vector<bool>> pegs(xsize, vector<bool>(ysize, false));
        vector<int> valEntered;
        while (scanf("%d", &val), val)
        {
            pegs[posMatrix[val].x][posMatrix[val].y] = true;
            valEntered.push_back(val);
        }

        toMove = pickPeg(pegs);
        auto s = score[toMove.first.x][toMove.first.y];
        auto t = score[toMove.second.x][toMove.second.y];
        while (toMove.first.x != 0)
        {
            pegs[toMove.first.x][toMove.first.y] = false;
            med = median(toMove.first, toMove.second);
            pegs[med.x][med.y] = false;
            pegs[toMove.second.x][toMove.second.y] = true;
            toMove = pickPeg(pegs);
            s = score[toMove.first.x][toMove.first.y];
            t = score[toMove.second.x][toMove.second.y];
        }
        printf("%d\n", countRemaining(pegs));
    }
    printf("END OF OUTPUT\n");
}