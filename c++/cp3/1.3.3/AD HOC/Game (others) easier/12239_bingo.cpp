#include <iostream>
#include <cmath>
int main()
{
  int a, b;
  bool won;
  int *num, *match;
   while (scanf("%d %d", &a, &b) && a && b)
  {
    won = true;
    num = new int[a + 5];
    match = new int[a + 5];
    for (int i = 0; i <= a; i++)
      match[i] = 0;

    for (int i = 0; i < b; i++)
      scanf("%d", &num[i]);

    for (int i = 0; i < b; i++)
      for (int j = i + 1; j < b; j++)
        match[abs(num[i] - num[j])] = 1;

    for (int i = 1; i <= a; i++)
      if (match[i] == 0)
        won = false;

    if (won)
      printf("Y\n");
    else
      printf("N\n");

    delete[] match;
    delete[] num;
  }
  delete match;
  delete num;
}