#include <iostream>

int m[15][45];
int M, N;

bool rm(int r, int c, int value)
{
    if (m[r][c] == value)
    {
        m[r][c] = -1;
        rm(r - 1, c, value);
        rm(r + 1, c, value);
        rm(r, c - 1, value);
        rm(r, c + 1, value);
        return true;
    }
    return false;
}

bool Remove(int r, int c, int value)
{
    if (m[r][c] != -1)
    {
        if (rm(r - 1, c, value) || rm(r + 1, c, value) || rm(r, c - 1, value) || rm(r, c + 1, value))
            return true;
    }
    return false;
}

void dropValues(int c)
{
    int i, count = 1;
    for (i = 1; i <= M; i++)
    {
        while (i <= M && m[i][c] == -1)
            i++;
        std::swap(m[count][c], m[i][c]);
        count++;
    }
}

void swapCol(int c1, int c2)
{
    int i;
    for (i = 1; i <= M; i++)
        std::swap(m[i][c1], m[i][c2]);
}

void removeEmptyCol()
{
    int i, count = 1;
    for (i = 1; i <= N; i++)
    {
        while (i <= N && m[1][i] == -1)
            i++;
        swapCol(i, count);
        count++;
    }
}

void print()
{
    int i, j;
    for (i = M; i >= 1; i--)
    {
        printf("   ");
        for (j = 1; j <= N; j++)
        {
            if (m[i][j] == -1)
                printf("  ");
            else
                printf(" %d", m[i][j]);
        }
        printf("\n");
    }
}

bool won()
{
    int i, j;
    for (i = 1; i <= M; i++)
        for (j = 1; j <= N; j++)
            if (m[i][j] != -1)
                return false;
    return true;
}

int main()
{
    int i, j, r, c, cont = 1;
    while (scanf("%d %d", &M, &N), M && N)
    {
        if (cont > 1)
            printf("\n");

        for (i = 0; i < 15; i++)
            for (j = 0; j < 45; j++)
                m[i][j] = -1;

        for (i = 1; i <= M; i++)
            for (j = 1; j <= N; j++)
                scanf("%d", &m[i][j]);

        while (scanf("%d %d", &r, &c), r)
        {
            if (r > M || r < 0 || c > N || c < 0)
                continue;
            if (Remove(r, c, m[r][c]))
            {
                for (i = 1; i <= N; i++)
                    dropValues(i);
                removeEmptyCol();
            }
        }
        printf("Grid %d.\n", cont++);
        if (won())
            printf("    Game Won\n");
        else
            print();
    }
}