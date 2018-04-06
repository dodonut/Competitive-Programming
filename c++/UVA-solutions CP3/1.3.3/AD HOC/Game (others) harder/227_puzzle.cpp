#include <iostream>
#include <vector>

void makeMove(char **board, int &blankX, int &blankY, char move)
{
    if (move == 'A')
    {
        std::swap(board[blankX][blankY], board[blankX - 1][blankY]);
        blankX--;
    }
    else if (move == 'B')
    {
        std::swap(board[blankX][blankY], board[blankX + 1][blankY]);
        blankX++;
    }
    else if (move == 'L')
    {
        std::swap(board[blankX][blankY], board[blankX][blankY - 1]);
        blankY--;
    }
    else
    {
        std::swap(board[blankX][blankY], board[blankX][blankY + 1]);
        blankY++;
    }
}

bool legalMove(char **board, int blankX, int blankY, char move)
{
    char temp;
    if (move != 'A' && move != 'B' && move != 'L' && move != 'R')
        return false;

    if (move == 'A')
    {
        if (blankX == 1)
            return false;
    }

    else if (move == 'B')
    {
        if (blankX == 5)
            return false;
    }

    else if (move == 'L')
    {
        if (blankY == 1)
            return false;
    }

    else
    {
        if (blankY == 5)
            return false;
    }

    return true;
}

void printBoard(char **board)
{
    int i, j;
    for (i = 1; i < 6; i++)
    {
        for (j = 1; j < 6; j++)
        {
            if (j > 1)
                printf(" ");
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char move;
    bool il, illegal;
    char bconfig;
    int i = 1, j = 1, c = 1;
    int ib, jb;
    //vector<vector<char>> board(7, vector<char>(7));
    char **board = new char *[8];
    for (int x = 0; x < 8; x++)
        board[x] = new char[8];
    while (scanf("%c", &bconfig) && bconfig != 'Z')
    {
        if (bconfig == '\n')
            continue;
        if (isspace(bconfig))
        {
            ib = i;
            jb = j;
        }
        board[i][j++] = bconfig;
        if (j == 6)
        {
            j = 1;
            i++;
        }
        if (i == 6)
        { //board complete
            if (c > 1)
                printf("\n");
            i = 1;
            j = 1;
            il = false;
            illegal = false;
            while (scanf(" %c", &move) && move != '0')
            {
                if (legalMove(board, ib, jb, move))
                    makeMove(board, ib, jb, move);
                else
                    illegal = true;
            }
            printf("Puzzle #%d:\n", c);
            if (!illegal)
                printBoard(board);
            else
                printf("This puzzle has no final configuration.\n");

            c++;
            //board.clear();
        }
    }
}