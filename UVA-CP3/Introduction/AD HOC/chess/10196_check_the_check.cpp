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

bool diag(int row, int col, char piece, char **board)
{
    char toLookFor = tolower(piece) == piece ? 'K' : 'k';
    int i = row - 1, j = col - 1;
    for (; i >= 2 && j >= 2; i--, j--)
    {
        if (board[i][j] == toLookFor)
            return true;
        if (board[i][j] != '.')
            break;
    }
    i = row + 1;
    j = col + 1;
    for (; i <= 9 && j <= 9; i++, j++)
    {
        if (board[i][j] == toLookFor)
            return true;
        if (board[i][j] != '.')
            break;
    }
    i = row + 1;
    j = col - 1;
    for (; i <= 9 && j >= 2; i++, j--)
    {
        if (board[i][j] == toLookFor)
            return true;
        if (board[i][j] != '.')
            break;
    }
    i = row - 1;
    j = col + 1;
    for (; i >= 2 && j <= 9; i--, j++)
    {
        if (board[i][j] == toLookFor)
            return true;
        if (board[i][j] != '.')
            break;
    }
    return false;
}

bool cross(int row, int col, char piece, char **board)
{
    char toLookFor = tolower(piece) == piece ? 'K' : 'k';
    for (int i = col - 1; i >= 2; i--)
    {
        if (board[row][i] == toLookFor)
            return true;
        if (board[row][i] != '.')
            break;
    }
    for (int i = col + 1; i <= 9; i++)
    {
        if (board[row][i] == toLookFor)
            return true;
        if (board[row][i] != '.')
            break;
    }
    for (int i = row - 1; i >= 2; i--)
    {
        if (board[i][col] == toLookFor)
            return true;
        if (board[i][col] != '.')
            break;
    }
    for (int i = row + 1; i <= 9; i++)
    {
        if (board[i][col] == toLookFor)
            return true;
        if (board[i][col] != '.')
            break;
    }
    return false;
}

char bishop(char b, char **board, int row, int col)
{

    if (diag(row, col, b, board))
        return b == 'b' ? 'K' : 'k';
    return 'z';
}

char rook(char r, char **board, int row, int col)
{
    if (cross(row, col, r, board))
        return r == 'r' ? 'K' : 'k';
    return 'z';
}

char queen(char q, char **board, int row, int col)
{
    if (diag(row, col, q, board) || cross(row, col, q, board))
        return q == 'q' ? 'K' : 'k';
    return 'z';
}

char which(char piece, char **board, int row, int col)
{
    switch (piece)
    {
    case 'p':
    case 'P':
        return pawn(piece, board, row, col);
    case 'b':
    case 'B':
        return bishop(piece, board, row, col);
    case 'r':
    case 'R':
        return rook(piece, board, row, col);
    case 'n':
    case 'N':
        return knight(piece, board, row, col);
    case 'q':
    case 'Q':
        return queen(piece, board, row, col);
    case 'k':
    case 'K':
        return 'z';
    }
}

int main()
{
    char **board = new char *[12];
    for (int i = 0; i < 12; i++)
        board[i] = new char[12];
    int i = 2, j = 2, cont = 1;
    char temp;
    char check;
    bool wcheck, bcheck;
    while (cin >> temp)
    {
        board[i][j] = temp;
        j++;
        if (j == 10)
        {
            i++;
            j = 2;
        }
        if (i == 10)
        {
            wcheck = false;
            bcheck = false;
            i = 2;
            j = 2;
            temp = 'a';
            for (int k = 2; k < 10; k++)
            {
                for (int l = 2; l < 10; l++)
                {
                    if (board[k][l] != '.')
                    {
                        temp = which(board[k][l], board, k, l);
                        if (temp == 'k')
                            bcheck = true;
                        else if (temp == 'K')
                            wcheck = true;
                    }
                }
            }
            if (temp != 'a')
            {
                printf("Game #%d: ", cont++);
                if (wcheck)
                    printf("white");
                else if (bcheck)
                    printf("black");
                else
                    printf("no");
                printf(" king is in check.\n");
            }
        }
    }
}