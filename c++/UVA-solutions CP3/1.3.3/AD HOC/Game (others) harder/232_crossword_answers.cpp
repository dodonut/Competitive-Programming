#include <iostream>

char chart[12][12] = {'*'};
char elligible[12][12] = {'b'};
int r, c;

bool isElligible(int row, int col)
{
    if (chart[row - 1][col] == '*' || chart[row][col - 1] == '*')
        return true;
    return false;
}

void mountElligible()
{
    int cont = 0;
    int i = 1, j = 1;
    for (; i < r; i++)
        for (; j < c; j++)
        {
            if (isElligible(i, j))
                elligible[i][j] = cont + '0';
        }
}

void printAcross()
{
    int i = 1, j = 1;
    for (; i < r; i++)
    {
        for (; j < c; j++)
        {
            if (elligible[i][j] != 'b')
                printf("%c.", elligible[i][j]);
            if (chart[i][j] == '*')
                break;
            else
                printf("%c", chart[i][j]);
        }
        printf("\n");
    }
}

void printDown()
{
    int i = 1, j = 1;
    for (; i < c; i++)
    {
        for (; j < r; j++)
        {
            if (elligible[j][i] != 'b')
                printf("%3c.", elligible[j][i]);
            if (chart[j][i] == '*')
                break;
            else
                printf("%c", chart[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, cont = 0;
    char ch[12];
    while (true)
    {
        r = getchar();
        if (r == 0)
            break;
        c = getchar();
        if (cont > 0)
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