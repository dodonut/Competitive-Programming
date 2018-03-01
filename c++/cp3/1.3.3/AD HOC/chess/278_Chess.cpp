#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int rooks(int rows, int col)
{
  return min(rows, col);
}

int knights(int rows, int col)
{
  return ceil((float)(rows * col) / 2);
}

int queens(int rows, int col)
{
  return min(rows, col);
}

int kings(int rows, int col)
{
  int f = ceil((float)rows / 2);
  int c = ceil((float)col / 2);
  return f * c;
}

int main()
{
  char type;
  float rows, col, N, res;
  cin >> N;
  while (N--)
  {
    cin >> type >> rows >> col;
    switch (type)
    {
    case 'r':
      res = rooks(rows, col);
      break;
    case 'k':
      res = knights(rows, col);
      break;
    case 'Q':
      res = queens(rows, col);
      break;
    case 'K':
      res = kings(rows, col);
      break;
    }
    cout << res << endl;
  }
}