#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int knights(int rows, int col)
{
  int Min = min(rows, col);
  int Max = max(rows, col);
  if (Min == 1)
    return Max;
  if (Min == 2)
  {
    int r = Max % 4;
    int d = Max / 4;
    switch (r)
    {
    case 1:
      return d * 4 + 2;
    case 2:
    case 3:
      return d * 4 + 4;
    }
  }
  return ceil((float)(rows * col) / 2);
}

int main()
{
  int rows, cols;
  while (cin >> rows >> cols && (rows || cols))
  {
    printf("%d knights may be placed on a %d row %d column board.\n", knights(rows, cols), rows, cols);
  }
}