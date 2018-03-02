#include <iostream>
using namespace std;
char pawn(char p, char **board, int row, int col)
{
    if (p == 'p')
    {
        if (board[row + 1][col - 1] == 'K')
            return 'K';
        if (board[row + 1][col + 1] == 'K')
            return 'K';
    }
    else
    {
        if (board[row - 1][col - 1] == 'k')
            return 'k';
        if (board[row - 1][col + 1] == 'k')
            return 'k';
    }
    return 'z';
}

char knight(char n, char **board, int row, int col)
{
    if (n == 'n')
    {
        if (board[row - 2][col - 1] == 'K' ||
            board[row - 2][col + 1] == 'K' ||
            board[row - 1][col - 2] == 'K' ||
            board[row + 1][col - 2] == 'K' ||
            board[row + 2][col - 1] == 'K' ||
            board[row + 2][col + 1] == 'K' ||
            board[row + 1][col + 2] == 'K' ||
            board[row - 1][col + 2] == 'K')
            return 'K';
    }
    else
    {
        if (board[row - 2][col - 1] == 'k' ||
            board[row - 2][col + 1] == 'k' ||
            board[row - 1][col - 2] == 'k' ||
            board[row + 1][col - 2] == 'k' ||
            board[row + 2][col - 1] == 'k' ||
            board[row + 2][col + 1] == 'k' ||
            board[row + 1][col + 2] == 'k' ||
            board[row - 1][col + 2] == 'k')
            return 'k';
    }
    return 'z';
}

bool diag(int row, int col, char toLookFor, char **board)
{
    int diag = 1;
    int diagright;
    int diagleft;
    for (int i = row - 1; i >= 2; i--)
    {
        diagleft = col - diag;
        diagright = col + diag;
        if (diagleft > 1)
        {
            if (board[i][diagleft] == toLookFor)
                return true;
        }
        if (diagright > 1)
        {
            if (board[i][diagright] == toLookFor)
                return true;
        }
        diag++;
    }
    diag = 1;
    for (int i = row + 1; i >= 9; i++)
    {
        diagleft = col - diag;
        diagright = col + diag;
        if (diagleft < 9)
        {
            if (board[i][diagleft] == toLookFor)
                return true;
        }
        if (diagright < 9)
        {
            if (board[i][diagright] == toLookFor)
                return true;
        }
        diag++;
    }
    return false;
}

char bishop(char b, char **board, int row, int col)
{
}

int main()
{
    char **board = new char[12];
    for (int i = 0; i < 12; i++)
        board[i] = new char[12];
    int i = 2, j = 2;
    char temp;
    char check;
    while (cin >> temp)
    {
        board[i][j] = temp;
        j++;
        if (j == 10)
            i++;
        if (i == 10)
        {
            i = 2;
            j = 2;
            for (int k = 2; k < 10; k++)
            {
                for (int l = 2; l < 10; l++)
                {
                    if (board[i][j] != '.')
                }
            }
        }
    }
}