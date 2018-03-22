#include <cstdio>
#include <vector>
/*
  Found a bug on the problem statement, the rebound turn 90 degrees LEFT, not right
  according to the input/output example and udebug tests
*/

int main()
{
  bool hasBumber[55][55];
  int xChange[]{1, 0, -1, 0};
  int yChange[]{0, 1, -1, 0};

  int bumpScore[55][55];
  int bumpCost[55][55];
  for (int i = 0; i < 55; i++)
    for (int j = 0; j < 55; j++)
      hasBumber[i][j] = false;

  int m, n, wallcost, p, tp, i;
  scanf("%d %d %d %d", &m, &n, &wallcost, &p);
  int x, y, score, cost, lifetime, dir;
  for (i = 0; i < p; i++)
  {
    scanf("%d %d %d %d", &x, &y, &score, &cost);
    hasBumber[x][y] = true;
    bumpScore[x][y] = score;
    bumpCost[x][y] = cost;
  }

  int ballPoints = 0;
  int totalPoints = 0;
  int newx, newy;
  while (scanf("%d %d %d %d", &x, &y, &dir, &lifetime) == 4)
  {
    ballPoints = 0;
    while (--lifetime > 0)
    {
      newx = x + xChange[dir];
      newy = y + yChange[dir];
      if (newx <= 1 || newx >= m || newy <= 1 || newy >= n)
      {
        lifetime -= wallcost;
        dir = (dir + 3) % 4;
      }
      else if (hasBumber[newx][newy])
      {
        lifetime -= bumpCost[newx][newy];
        ballPoints += bumpScore[newx][newy];
        dir = (dir + 3) % 4;
      }
      else
      {
        x = newx;
        y = newy;
      }
    }
    printf("%d\n", ballPoints);
    totalPoints += ballPoints;
  }
  printf("%d", totalPoints);
}
