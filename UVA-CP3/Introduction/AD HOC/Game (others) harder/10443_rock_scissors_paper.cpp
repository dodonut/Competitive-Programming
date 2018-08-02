#include <iostream>
#include <map>

int initial[102][102];
int end[102][102];
int D[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int N, r, c, n;

std::map<char, int> char_int;
std::map<int, char> int_char;
std::map<int, int> loser;

int stronger(int a, int b)
{
    if (loser[a] == b)
        return b;
    return a;
}

int change(int t, int i, int j)
{
    int k, dy, dx, value = t, pos;
    for (k = 0; k < 4; k++)
    {
        dx = D[k][0];
        dy = D[k][1];
        pos = initial[i + dx][j + dy];
        if (pos != 0)
        {
            value = stronger(initial[i + dx][j + dy], t);
            if (value != t)
                return value;
        }
    }
    return value;
}

void printGrid()
{
    int i, j;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            printf("%c", int_char[end[i][j]]);
        }
        printf("\n");
    }
}

void end_to_init()
{
    int i, j;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
            initial[i][j] = end[i][j];
    }
}

int main()
{
    char_int['R'] = 1;
    char_int['S'] = 2;
    char_int['P'] = 3;
    int_char[1] = 'R';
    int_char[2] = 'S';
    int_char[3] = 'P';
    loser[1] = 3;
    loser[2] = 1;
    loser[3] = 2;
    int i, j, count = 0;
    char ch;
    scanf("%d", &N);
    while (N--)
    {
        if (count > 0)
            printf("\n");
        scanf("%d %d %d", &r, &c, &n);
        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                scanf(" %c", &ch);
                initial[i][j] = char_int[ch];
            }
        }
        while (n--)
        {
            for (i = 1; i <= r; i++)
            {
                for (j = 1; j <= c; j++)
                {
                    end[i][j] = change(initial[i][j], i, j);
                }
            }
            end_to_init();
        }
        printGrid();
    }
}