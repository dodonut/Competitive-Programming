#include <iostream>

int main()
{
    int T, grid[5][5] = {0}, tmp_grid[5][5] = {0}, index, D[][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}}, Dx, Dy, sum, max;
    bool infinity;
    char c;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                scanf(" %c", &c);
                grid[i][j] = c - '0';
            }
        }

        index = -1;
        while (true)
        {
            for (int i = 1; i <= 3; i++)
                for (int j = 1; j <= 3; j++)
                    tmp_grid[i][j] = grid[i][j];
            max = 0;
            for (int i = 1; i <= 3; i++)
            {
                for (int j = 1; j <= 3; j++)
                {
                    sum = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        Dx = D[k][0];
                        Dy = D[k][1];
                        sum += tmp_grid[i + Dx][j + Dy];
                    }
                    grid[i][j] = sum % 2;
                    max = std::max(tmp_grid[i][j], max);
                }
            }
            if (!max)
                break;
            
            index++;
        }
        printf("%d\n", index);
    }
}