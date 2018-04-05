#include <iostream>
#include <set>

char **board;
std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> list;
std::set<std::pair<int, int>> setPairs;

void displayBoard()
{
  int i, j;
  for (i = 1; i < 9; i++)
  {
    for (j = 1; j < 9; j++)
    {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

void displayAllMoves(int cont)
{
  if (!list.empty())
  {
    setPairs.clear();
    for (auto &&xx : list)
      setPairs.insert(xx.first);
    for (auto &&x : setPairs)
    {
      if (cont > 0)
        printf(" ");
      cont++;
      printf("(%d,%d)", x.first, x.second);
    }
  }
  else
    printf("No legal move.");
}

void validBracket(int row, int col, int dirr, int dirc, char playerPiece)
{
  char toLookFor = playerPiece == 'B' ? 'W' : 'B';
  int i = row + dirr, j = col + dirc;
  bool foundLookingFor = false;
  int lastPosX = -1, lastPosY = -1;

  if (board[i][j] == toLookFor)
    foundLookingFor = true;

  while (i >= 1 && i < 9 && j >= 1 && j < 9 &&
         foundLookingFor)
  { // inside board
    if (board[i][j] == playerPiece)
    {
      lastPosX = i;
      lastPosY = j;
    }
    else if (board[i][j] == '-')
      break;
    i += dirr;
    j += dirc;
  }
  if (lastPosX != -1)
    list.insert(std::make_pair(std::make_pair(row, col),
                               std::make_pair(lastPosX, lastPosY)));
}

void getAllMoves(char playerPiece)
{
  list.clear();
  int i, j;
  for (i = 1; i < 9; i++)
  {
    for (j = 1; j < 9; j++)
    {
      if (board[i][j] == '-')
      {
        validBracket(i, j, 1, 0, playerPiece);   // vert down
        validBracket(i, j, -1, 0, playerPiece);  // vert up
        validBracket(i, j, 0, 1, playerPiece);   // hor right
        validBracket(i, j, 0, -1, playerPiece);  // hor left
        validBracket(i, j, 1, 1, playerPiece);   // diag right down
        validBracket(i, j, 1, -1, playerPiece);  // diag left down
        validBracket(i, j, -1, -1, playerPiece); // diag left up
        validBracket(i, j, -1, 1, playerPiece);  // diag right up
      }
    }
  }
}

std::pair<int, int> loopTo(std::pair<int, int> from, std::pair<int, int> to)
{
  std::pair<int, int> dir;
  int d = abs(from.first - to.first);
  int d2 = abs(from.second - to.second);
  if (d == d2)
  {
    if (from.first < to.first)
      dir.first = 1;
    else
      dir.first = -1;
    if (from.second < to.second)
      dir.second = 1;
    else
      dir.second = -1;
  }
  else if (from.first == to.first)
  {
    dir.first = 0;
    if (from.second < to.second)
      dir.second = 1;
    else
      dir.second = -1;
  }
  else
  {
    dir.second = 0;
    if (from.first < to.first)
      dir.first = 1;
    else
      dir.first = -1;
  }
  return dir;
}

void bracket(char pp, std::pair<int, int> from, std::pair<int, int> to)
{
  std::pair<int, int> dir = loopTo(from, to);
  int i = dir.first, j = dir.second;
  int row = from.first, col = from.second;
  while (row != to.first || col != to.second)
  {
    board[row][col] = pp;
    row += i;
    col += j;
  }
  board[row][col] = pp;
}

int makeMove(int x, int y, char pp)
{
  getAllMoves(pp);
  bool validMove = list.size() == 0 ? false : true;
  for (auto &&i : list)
  {
    if (i.first.first == x && i.first.second == y)
    {
      bracket(pp, i.first, i.second);
    }
  }
  if (!validMove)
    return 0;
  return 1;
}

std::pair<int, int> howMany()
{
  int i, j;
  std::pair<int, int> pieces;
  for (i = 1; i < 9; i++)
  {
    for (j = 1; j < 9; j++)
    {
      if (board[i][j] == 'B')
        pieces.first++;
      else if (board[i][j] == 'W')
        pieces.second++;
    }
  }
  return pieces;
}

char switchPlayer(char actualPlayer) { return actualPlayer == 'B' ? 'W' : 'B'; }

int main()
{
  int N, i, j, cont, k = 0;
  char cmd;
  std::pair<int, int> pieces;
  board = new char *[10];
  for (i = 0; i < 10; i++)
    board[i] = new char[10];
  char playerPiece;
  scanf("%d", &N);
  while (N--)
  {
    if (k > 0)
      printf("\n");

    for (i = 1; i < 9; i++)
      for (j = 1; j < 9; j++)
        scanf(" %c", &board[i][j]);

    scanf(" %c", &playerPiece);
    while (scanf(" %c", &cmd))
    {
      cont = 0;
      if (cmd == 'L')
      {
        getAllMoves(playerPiece);
        displayAllMoves(cont);
      }

      else if (cmd == 'M')
      {
        char r, c;
        int ans;
        scanf(" %c %c", &r, &c);
        ans = makeMove(r - '0', c - '0', playerPiece);
        if (!ans)
        { // movement not allowed
          playerPiece = switchPlayer(playerPiece);
          makeMove(r - '0', c - '0', playerPiece);
        }
        board[r - '0'][c - '0'] = playerPiece;
        playerPiece = switchPlayer(playerPiece);
        pieces = howMany();
        printf("Black - %2d White - %2d", pieces.first, pieces.second);
      }

      else
      {
        displayBoard();
        break;
      }
      printf("\n");
    }
    k++;
  }
}