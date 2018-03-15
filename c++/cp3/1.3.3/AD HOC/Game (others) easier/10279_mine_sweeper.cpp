#include <iostream>
void add(char field[][12], int D[][2], int x, int y)
{
  for (int i = 0; i < 8; i++)
  {
    int k = D[i][0], l = D[i][1];
    if (field[x + k][y + l] >= '0' && field[x + k][y + l] <= '9')
      field[x + k][y + l] += 1;
  }
}

int main()
{
  int T, n, i, j, cont = 0;
  bool touchmine;
  char field[12][12], touched[12][12], temp;
  int D[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
  scanf("%d", &T);
  while (T--)
  {
    if(cont > 0)
      printf("\n");
    touchmine = false;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        scanf(" %c", &field[i][j]);
      }
    }
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        scanf(" %c", &touched[i][j]);
        if (touched[i][j] == 'x')
          touched[i][j] = '0';
      }
    }
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        if (field[i][j] == '*')
        {
          if (touched[i][j] >= '0' && touched[i][j] <= '9')
            touchmine = true;
          add(touched, D, i, j);
        }
      }
    }
    if (touchmine)
    {
      for (i = 1; i <= n; i++)
      {
        for (j = 1; j <= n; j++)
        {
          if (field[i][j] == '*')
            touched[i][j] = '*';
        }
      }
    }
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        printf("%c", touched[i][j]);
      }
      printf("\n");
    }
    cont++;
  }
}