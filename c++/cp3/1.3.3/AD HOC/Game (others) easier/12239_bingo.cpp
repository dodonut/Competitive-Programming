#include <iostream>
#include <cmath>
int main()
{
  int a, b;
  bool won;
  while (scanf("%d %d", &a, &b), a)
  {
    won = true;
    int *num = new int[a + 1];
    int *match = new int[a + 1];
    for (int i = 0; i < b; i++)
      scanf("%d", &num[i]);
    for (int i = 0; i <= a; i++)
      printf("%d\n", match[i]);
    for (int i = 0; i < a; i++)
    {
      for (int j = i + 1; j < a; j++)
      {
        match[abs(num[i] - num[j])] = 1;
      }
    }
    for (int i = 1; i <= a; i++)
    {
      if (match[i] == 0)
        won = false;
      int aux = match[i];
      int p = 0;
    }
    if (won)
      printf("Y\n");
    else
      printf("N\n");
    delete[] match;
    delete[] num;
  }
}