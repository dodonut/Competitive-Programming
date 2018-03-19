#include <iostream>
#include <map>
int main()
{
  int T, a, b, c, tempPlayer = 0, move, lad1, lad2;
  int going;
  std::map<int, int> ladders;
  int *players;
  bool gameover;
  scanf("%d", &T);
  while (T--)
  {
    gameover = false;
    tempPlayer = 0;
    scanf("%d %d %d", &a, &b, &c);
    players = new int[a + 1];
    for (int i = 0; i < a; i++)
      players[i] = 1;
    for (int i = 0; i < b; i++)
    {
      scanf("%d %d", &lad1, &lad2);
      ladders[lad1] = lad2;
    }

    for (int i = 0; i < c; i++)
    {
      scanf("%d", &move);
      if (!gameover)
      {
        going = move + players[tempPlayer];
        if (ladders.find(going) != ladders.end())
          going = ladders[going];
        players[tempPlayer] = going;
        if (going >= 100)
        {
          players[tempPlayer] = 100;
          gameover = true;
        }
        tempPlayer = (tempPlayer + 1) % a;
      }
    }
    for (int i = 0; i < a; i++)
      printf("Position of player %d is %d.\n", i + 1, players[i]);

    delete[] players;
    ladders.clear();
  }
}