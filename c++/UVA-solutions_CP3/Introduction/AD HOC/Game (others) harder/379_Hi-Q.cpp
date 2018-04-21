#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using std::map;
using std::vector;

struct Pos
{
    int x, y;
    Pos(){};
    Pos(int x, int y) : x(x), y(y) {}
};

int D[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int xsize = 9, ysize = 9;
vector<vector<int>> score(xsize, vector<int>(ysize));
vector<Pos> posMatrix(1);

bool sourceTargetSort(std::pair<Pos, Pos> p1, std::pair<Pos, Pos> p2)
{
    if (p1.second.x == p2.second.x && p1.second.y == p2.second.y)
        return score[p1.first.x][p1.first.y] < score[p2.first.x][p2.first.y];
    return score[p1.second.x][p1.second.y] < score[p2.second.x][p2.second.y];
}

Pos greaterTarget(vector<Pos> targets)
{
    Pos gtar = targets[0];
    int i;
    for (i = 0; i < targets.size(); i++)
    {
        if (targets[i].x < 1 || targets[i].x > 7 || targets[i].y < 1 || targets[i].y > 7)
            continue;
        if (score[gtar.x][gtar.y] < score[targets[i].x][targets[i].y])
            gtar = targets[i];
    }
    return gtar;
}

std::pair<Pos, Pos> bestSourceTarget(vector<Pos> source)
{
    vector<std::pair<Pos, Pos>> all;
    Pos gtar(0, 0);
    int i, j;
    for (i = 0; i < source.size(); i++)
    {
        gtar = greaterTarget({Pos(source[i].x - 2, source[i].y),
                              Pos(source[i].x + 2, source[i].y),
                              Pos(source[i].x, source[i].y - 2),
                              Pos(source[i].x, source[i].y + 2)});
        all.push_back(std::make_pair(source[i], gtar));
    }
    all.empty() ? all.push_back(std::make_pair(Pos(0, 0), Pos(0, 0))) : std::sort(all.begin(), all.end(), sourceTargetSort);
    return all[0];
}

bool validPeg(vector<vector<bool>> p, int x, int y)
{
    int i, dx, dy;
    for (i = 0; i < 4; i++)
    {
        dx = D[i][0];
        dy = D[i][1];
        if ((x + dx * 2 < 3 || x + dx * 2 > 5) && (y + dy * 2 < 3 || y + dy * 2 > 5))
            continue;
        if (p[x + dx][y + dy] && !p[x + dx * 2][y + dy * 2])
            return true;
    }
    return false;
}

std::pair<Pos, Pos> pickPeg(vector<vector<bool>> &p, vector<int> &vals)
{
    int i, j, x, y;
    vector<Pos> source;
    vector<Pos> target;
    for (i = 0; i < vals.size(); i++)
    {
        x = posMatrix[vals[i]].x;
        y = posMatrix[vals[i]].y;
        if (p[x][y] && validPeg(p, x, y))
            source.push_back(posMatrix[vals[i]]);
    }
    if (source.empty())
        return std::make_pair(Pos(0, 0), Pos(0, 0));

    return bestSourceTarget(source);
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

        toMove = pickPeg(pegs, valEntered);
        while (toMove.first.x != 0)
        {
            pegs[toMove.first.x][toMove.first.y] = false;
            med = median(toMove.first, toMove.second);
            pegs[med.x][med.y] = false;
            pegs[toMove.second.x][toMove.second.y] = true;
            toMove = pickPeg(pegs, valEntered);
        }
        printf("%d\n", countRemaining(pegs));
    }
    printf("END OF OUTPUT\n");
}