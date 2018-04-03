#include <iostream>
#include <set>
#include <vector>

char **board;
std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> list;

bool ordering(std::pair<int, int> &a, std::pair<int, int> &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

void validBracket(int row, int col, int dirr, int dirc, char playerPiece) {
  char toLookFor = playerPiece == 'B' ? 'W' : 'B';
  int i = row + dirr, j = col + dirc;
  bool foundLookingFor = false, foundPlayerPiece = false;
  int lastPosX = -1, lastPosY = -1;
  while (i >= 0 && i < 8 && j >= 0 && j < 8) { // inside board
    if (board[i][j] == toLookFor)
      foundLookingFor = true;
    else if (board[i][j] == playerPiece && foundLookingFor) {
      foundPlayerPiece = true;
      lastPosX = i;
      lastPosY = j;
    } else if (board[i][j] == '-' && foundLookingFor && foundPlayerPiece)
      list.insert(std::make_pair(std::make_pair(row + 1, col + 1),
                                 std::make_pair(lastPosX + 1, lastPosY + 1)));
    else if (board[i][j] == '-')
      break;
    i += dirr;
    j += dirc;
  }
}

void getAllMoves(char playerPiece) {
  std::pair<std::pair<int, int>, std::pair<int, int>> ppair;
  int i, j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (board[i][j] == '-') {
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

std::pair<int, int> loopTo(std::pair<int, int> from, std::pair<int, int> to) {
  std::pair<int, int> dir;
  int d = abs(from.first - to.first);
  int d2 = abs(from.second - to.second);
  if (d == d2) {
    if (from.first < to.first)
      dir.first = 1;
    else
      dir.first = -1;
    if (from.second < to.second)
      dir.second = 1;
    else
      dir.second = -1;
  } else if (from.first == to.first) {
    dir.first = 0;
    dir.second = 1;
  } else {
    dir.first = 1;
    dir.second = 0;
  }
  return dir;
}

void bracket(char pp, std::pair<int, int> from, std::pair<int, int> to) {
  std::pair<int, int> dir = loopTo(from, to);
  int i = dir.first, j = dir.second;
  int row = from.first, col = from.second;
  while (row != to.first && col != to.second) {
    board[row][col] = pp;
    row += i;
    col += j;
  }
  board[row][col] = pp;
}

int makeMove(int x, int y, char pp) {
  bool validMove = false;
  for (auto &&i : list) {
    if (i.first.first == x && i.first.second == y) {
      bracket(pp, i.first, i.second);
      validMove = true;
    }
  }
  if (!validMove)
    return 0;
  return 1;
}

void displayBoard() {}

int main() {
  int N, i, j, cont, player;
  char cmd;
  std::set<std::pair<int, int>> setPairs;
  board = new char *[8];
  for (i = 0; i < 8; i++)
    board[i] = new char[8];
  char ch, playerPiece;
  scanf("%d", &N);
  while (N--) {
    for (i = 0; i < 8; i++)
      for (j = 0; j < 8; j++)
        scanf(" %c", &board[i][j]);

    scanf(" %c", &ch);
    player = ch == 'B' ? 0 : 1;
    getAllMoves(playerPiece);
    while (scanf(" %c", &cmd)) {
      cont = 0;
      playerPiece = player == 0 ? 'B' : 'W';
      if (cmd == 'L') {
        if (!list.empty()) {
          for (auto &&xx : list)
            setPairs.insert(xx.first);
          for (auto &&x : setPairs) {
            if (cont > 0)
              printf(" ");
            cont++;
            printf("(%d,%d)", x.first, x.second);
          }
        } else
          printf("No legal move.");
        printf("\n");
      } else if (cmd == 'M') {
        char r, c;
        int ans;
        scanf(" %c %c", &r, &c);
        ans = makeMove(r - '0', c - '0', playerPiece);
        if (!ans) { // movement not allowed
          player = (player + 1) % 2;
          playerPiece = player == 0 ? 'B' : 'W';
          getAllMoves(playerPiece);
          board[r - '0'][r - '0'] = playerPiece;
          makeMove(r - '0', c - '0', playerPiece);
        }
      } else {
        displayBoard();
        break;
      }
    }
    list.clear();
    setPairs.clear();
  }
  printf("Quiting....");
}