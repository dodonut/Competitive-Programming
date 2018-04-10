#include <iostream>

char chart[12][12];
int elligible[12][12];
int r, c;

bool isElligible(int row, int col)
{
    if (chart[row - 1][col] == '*' || chart[row][col - 1] == '*')
        return true;
    return false;
}

void mountElligible()
{
    int cont = 1;
    int i = 1, j = 1;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (chart[i][j] != '*' && isElligible(i, j))
            {
                elligible[i][j] = cont++;
            }
        }
    }
}

void printAcross()
{
    int i, j, cont = 1;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (chart[i][j] != '*' && elligible[i][j] != 0)
            {
                printf("%3d.", elligible[i][j]);
                while (chart[i][j] != '*')
                {
                    printf("%c", chart[i][j]);
                    j++;
                }
                printf("\n");
            }
        }
    }
}

void printDown()
{
    int i, j, cont = 1, tempi;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (chart[i][j] != '*' && elligible[i][j] != 0)
            {
                printf("%3d.", elligible[i][j]);
                tempi = i;
                while (chart[tempi][j] != '*')
                {
                    printf("%c", chart[tempi][j]);
                    tempi++;
                    elligible[tempi][j] = 0;
                }
                printf("\n");
            }
        }
    }
}

void printMatrix(int m[][12])
{
    int i, j;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, cont = 1;
    char ch[12];
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            chart[i][j] = '*';
            elligible[i][j] = 0;
        }
    }

    while (true)
    {
        scanf("%d", &r);
        if (r == 0)
            break;
        scanf("%d", &c);
        if (cont > 1)
            printf("\n");
        for (i = 0; i < r; i++)
        {
            scanf(" %s", &ch);
            for (j = 0; j < c; j++)
                chart[i + 1][j + 1] = ch[j];
        }
        mountElligible();
        printf("puzzle #%d:\n", cont++);
        printf("Across\n");
        printAcross();
        printf("Down\n");
        printDown();
    }
}