#include <iostream>
void add(char field[][102], int D[][2], int x, int y)
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
  int m, n, i, j, cont = 1;
  char field[102][102], temp;
  int D[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
  while (scanf("%d %d", &m, &n) && m)
  {
    if (cont > 1)
      printf("\n");
    for (i = 1; i <= m; i++)
    {
      for (j = 1; j <= n; j++)
      {
        scanf("%c", &field[i][j]);
        if (field[i][j] == '.')
          field[i][j] = '0';
      }
    }
    for (i = 1; i <= m; i++)
    {
      for (j = 1; j <= n; j++)
      {
        if (field[i][j] == '*')
          add(field, D, i, j);
      }
    }
    printf("Field #%d:\n", cont++);
    for (i = 1; i <= m; i++)
    {
      for (j = 1; j <= n; j++)
      {
        printf("%c", field[i][j]);
      }
      printf("\n");
    }
  }
}