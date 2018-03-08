#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

bool hasPieces(char **board, int row, int col)
{
    if (board[row][col] == '.' || board[row][col] == '*')
        return false;
    return true;
}

void pawn(char p, char **board, int row, int col)
{
    if (p == 'p')
    {
        if (!hasPieces(board, row + 1, col - 1))
            board[row + 1][col - 1] = '*';
        if (!hasPieces(board, row + 1, col + 1))
            board[row + 1][col + 1] = '*';
    }
    else
    {
        if (!hasPieces(board, row - 1, col - 1))
            board[row - 1][col - 1] = '*';
        if (!hasPieces(board, row - 1, col + 1))
            board[row - 1][col + 1] = '*';
    }
}

void knight(char **board, int row, int col)
{
    if (!hasPieces(board, row - 2, col - 1))
        board[row - 2][col - 1] = '*';
    if (!hasPieces(board, row - 2, col + 1))
        board[row - 2][col + 1] = '*';
    if (!hasPieces(board, row - 1, col - 2))
        board[row - 1][col - 2] = '*';
    if (!hasPieces(board, row + 1, col - 2))
        board[row + 1][col - 2] = '*';
    if (!hasPieces(board, row + 2, col - 1))
        board[row + 2][col - 1] = '*';
    if (!hasPieces(board, row + 2, col + 1))
        board[row + 2][col + 1] = '*';
    if (!hasPieces(board, row + 1, col + 2))
        board[row + 1][col + 2] = '*';
    if (!hasPieces(board, row - 1, col + 2))
        board[row - 1][col + 2] = '*';
}

void diag(char **board, int row, int col)
{
    int i = row - 1, j = col - 1;
    for (; i >= 2 && j >= 2; i--, j--)
    {
        if (hasPieces(board, i, j))
            break;
        board[i][j] = '*';
    }
    i = row + 1;
    j = col + 1;
    for (; i <= 9 && j <= 9; i++, j++)
    {
        if (hasPieces(board, i, j))
            break;
        board[i][j] = '*';
    }
    i = row + 1;
    j = col - 1;
    for (; i <= 9 && j >= 2; i++, j--)
    {
        if (hasPieces(board, i, j))
            break;
        board[i][j] = '*';
    }
    i = row - 1;
    j = col + 1;
    for (; i >= 2 && j <= 9; i--, j++)
    {
        if (hasPieces(board, i, j))
            break;
        board[i][j] = '*';
    }
}

bool cross(char **board, int row, int col)
{
    for (int i = col - 1; i >= 2; i--)
    {
        if (hasPieces(board, row, i))
            break;
        board[row][i] = '*';
    }
    for (int i = col + 1; i <= 9; i++)
    {
        if (hasPieces(board, row, i))
            break;
        board[row][i] = '*';
    }
    for (int i = row - 1; i >= 2; i--)
    {
        if (hasPieces(board, i, col))
            break;
        board[i][col] = '*';
    }
    for (int i = row + 1; i <= 9; i++)
    {
        if (hasPieces(board, i, col))
            break;
        board[i][col] = '*';
    }
}

void completeWhiteSpaces(char **board, int row, int col, int spaces)
{
    for (int i = col; i < col + spaces; i++)
    {
        board[row][i] = '.';
    }
}

int countNotAttacked(char **board)
{
    int count = 0;
    for (int i = 2; i < 10; i++)
    {
        for (int j = 2; j < 10; j++)
        {
            if (board[i][j] == '.')
                count++;
        }
    }
    return count;
}

void bishop(char **board, int row, int col)
{
    diag(board, row, col);
}

void rook(char **board, int row, int col)
{
    cross(board, row, col);
}

void queen(char **board, int row, int col)
{
    diag(board, row, col);
    cross(board, row, col);
}
void king(char **board, int row, int col)
{
    if (!hasPieces(board, row - 1, col))
        board[row - 1][col] = '*';
    if (!hasPieces(board, row - 1, col - 1))
        board[row - 1][col - 1] = '*';
    if (!hasPieces(board, row, col - 1))
        board[row][col - 1] = '*';
    if (!hasPieces(board, row + 1, col - 1))
        board[row + 1][col - 1] = '*';
    if (!hasPieces(board, row + 1, col))
        board[row + 1][col] = '*';
    if (!hasPieces(board, row + 1, col + 1))
        board[row + 1][col + 1] = '*';
    if (!hasPieces(board, row, col + 1))
        board[row][col + 1] = '*';
    if (!hasPieces(board, row - 1, col + 1))
        board[row - 1][col + 1] = '*';
}

void which(char piece, char **board, int row, int col)
{
    switch (piece)
    {
    case 'p':
    case 'P':
        pawn(piece, board, row, col);
        break;
    case 'b':
    case 'B':
        bishop(board, row, col);
        break;
    case 'r':
    case 'R':
        rook(board, row, col);
        break;
    case 'n':
    case 'N':
        knight(board, row, col);
        break;
    case 'q':
    case 'Q':
        queen(board, row, col);
        break;
    case 'k':
    case 'K':
        king(board, row, col);
        break;
    }
}
void printboard(char **board)
{
    for (int k = 2; k < 10; k++)
    {
        for (int l = 2; l < 10; l++)
        {
            cout << board[k][l];
        }
        cout << endl;
    }
}

void startBoard(char **board)
{
    for (int i = 2; i < 10; i++)
    {
        for (int j = 2; j < 10; j++)
        {
            board[i][j] = '.';
        }
    }
}

int main()
{
    char **board = new char *[12];
    for (int i = 0; i < 12; i++)
        board[i] = new char[12];

    char temp;
    int i = 2, j = 2;
    string line;
    startBoard(board);
    while (getline(cin, line))
    {
        for (int c = 0; c < line.size(); c++)
        {
            if (line[c] == '/')
            {
                i++;
                j = 2;
            }
            else if (isdigit(line[c]))
            {
                completeWhiteSpaces(board, i, j, line[c] - '0');
                j += (line[c] - '0');
            }
            else
            {
                board[i][j] = line[c];
                j++;
            }
        }

        i = 2;
        j = 2;
        for (int k = 2; k < 10; k++)
        {
            for (int l = 2; l < 10; l++)
            {
                which(board[k][l], board, k, l);
            }
        }
        cout << countNotAttacked(board) << endl;
        startBoard(board);
    }
}