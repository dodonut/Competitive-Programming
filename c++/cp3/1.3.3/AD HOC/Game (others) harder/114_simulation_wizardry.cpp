#include <cstdio>
#include <vector>
/*
  Found a bug on the problem statement, the rebound turn 90 degrees LEFT, not right
  according to the input/output example and udebug tests
*/
std::vector<std::vector<int>> bumpers;
void move(int &x, int &y, int dir)
{
  switch (dir)
  {
  case 0:
    x--;
    break;
  case 1:
    y++;
    break;
  case 2:
    x++;
    break;
  case 3:
    y--;
    break;
  }
}

int isbumper(int x, int y)
{
  for (int i = 0; i < bumpers.size(); i++)
  {
    int x = bumpers[i][0];
    int y = bumpers[i][1];
    if (bumpers[i][0] == x && bumpers[i][1] == y)
      return i;
  }
  return -1;
}

bool iswall(int x, int y, int m, int n)
{
  if (x == 1 || x == m || y == 1 || y == n)
    return true;
  return false;
}

int main()
{
  int m, n, wallcost, p, tp, i;
  scanf("%d %d %d %d", &m, &n, &wallcost, &p);
  std::vector<int> bumper(4);
  for (i = 0; i < p; i++)
  {
    scanf("%d %d %d %d", &bumper[0], &bumper[1], &bumper[2], &bumper[3]);
    bumpers.push_back(bumper);
  }

  int ball[4];
  int previous = 0;
  int ballPoints = 0;
  int bumpLoc = 0;
  int totalPoints = 0;
  while (scanf("%d %d %d %d", &ball[0], &ball[1], &ball[2], &ball[3]) == 4)
  {
    ballPoints = 0;
    while (ball[3] > 1)
    {
      int tempx = ball[0], tempy = ball[1];
      move(ball[0], ball[1], ball[2]);
      ball[3]--;
      ballPoints += previous;
      int bumpLoc = isbumper(ball[0], ball[1]);
      if (bumpLoc != -1)
      {
        ball[0] = tempx;
        ball[1] = tempy;
        ball[3] -= bumpers[bumpLoc][3];
        previous = bumpers[bumpLoc][2];
        ball[2] = (ball[2] + 3) % 4;
      }
      else if (iswall(ball[0], ball[1], m, n))
      {
        ball[0] = tempx;
        ball[1] = tempy;
        ball[3] -= wallcost;
        ball[2] = (ball[2] + 3) % 4;
      }
    }
    printf("%d\n", ballPoints);
    totalPoints += ballPoints;
  }
  printf("%d", totalPoints);
}
