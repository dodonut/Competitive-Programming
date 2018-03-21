#include <cstdio>
#include <vector>
/*
  Found a bug on the problem statement, the rebound turn 90 degrees LEFT, not right
  according to the input/output example and udebug tests
*/

int main()
{
  int m, n, hw, p, tp, i;
  scanf("%d %d %d %d", &m, &n, &hw, &p);
  std::vector<std::vector<int>> balls;
  int **bumpers = new int *[p];
  for (i = 0; i < p; i++)
    *bumpers = new int[4];
  for (i = 0; i < p; i++)
    scanf("%d %d %d %d", bumpers[i][0], bumpers[i][1], bumpers[i][2], bumpers[i][3]);

  i = 0;
  while (scanf("%d %d %d %d", &balls[i][0], &balls[i][1], &balls[i][2], &balls[i][3]))
    i++;
}

/*
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<vector<int>> balls;
    vector<int> ball(4);
    int i = 0;
    scanf("%d %d %d %d", &ball[0],&ball[1],&ball[2],&ball[3]);
    balls.push_back(ball);
    printf("%d %d %d %d", balls[0][0], balls[0][1], balls[0][2], balls[0][3]);
}


*/