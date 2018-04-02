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

void makeMove()

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
    while (scanf(" %c", &cmd) && cmd != 'Q') {
      cont = 0;
      getAllMoves(playerPiece);
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
        list.clear();
        setPairs.clear();
      }
    }
  }
  printf("Quiting....");
}