#include <iostream>

char board[3][3];

bool won(char c)
{
    int i;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return true;
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
            return true;
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return true;
    if (board[2][0] == c && board[1][1] == c && board[0][2] == c)
        return true;
    return false;
}

int main()
{
    int N, i, j, x_count = 0, o_count = 0, dot_count = 0;
    char c;
    scanf("%d", &N);
    while (N--)
    {
        x_count = 0;
        o_count = 0;
        dot_count = 0;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                scanf(" %c", &c);
                board[i][j] = c;
                if (c == 'X')
                    x_count++;
                else if (c == 'O')
                    o_count++;
                else
                    dot_count++;
            }
        }
        auto neitherWon = (!won('X') && !won('O'));
        auto x_won = won('X');
        auto o_won = won('O');
        if (x_count - o_count == 1)
        {
            if ((x_won && !o_won) || neitherWon)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if (o_count == x_count)
        {
            if ((o_won && !x_won) || neitherWon)
                printf("yes\n");
            else
                printf("no\n");
        }
        else
            printf("no\n");
    }
}