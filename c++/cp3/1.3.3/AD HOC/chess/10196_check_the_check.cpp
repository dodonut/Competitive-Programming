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
    int rpi = row - min(row - 2, col - 2);
    int rpf = row + min(9-row,9- col));
    int cpi = col - min(row-2, col-2);
    int cpf = col + min(9-row, 9-col);
    
    int dsi = row + min(row - 2, col - 2);
    int dsf = row - min(9 - row, 9 - col);
    int csi = dsf;
    int csf = dsi;
    
    for (int i = rpi; i >= rpf; i++)
    {
        if(board[i][cpi] == toLookFor) return true;
        cpi++;
    }
    for (int i = rsi; i <= rpf; i--)
    {
        if(board[i][csi] == toLookFor) return true;
        csi++;
    }
    return false;
}

bool cross(int row, int col,char toLookFor, char **board)
{
    for(int i = 2; i < 10; i++){
        if(board[i][col] == toLookFor) return true;
        if(board[row][i] == toLookFor) return true;
    }
    return false;
}

char bishop(char b, char **board, int row, int col)
{
    if(b == 'b'){
        if(diag(row, col, b, board)) return 'K';
    }
    if(b == 'B'){
        if(diag(row, col, b, board)) return 'k';
    }
    return 'z';
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

