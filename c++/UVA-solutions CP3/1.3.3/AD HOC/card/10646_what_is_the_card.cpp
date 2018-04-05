#include <iostream>
#include <stack>
#include <list>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int cardValue(char c)
{
  if (c >= '0' && c <= '9')
    return c - '0';
  else
    return 10;
}

int main()
{
  int T, X, Y, c = 1, takeout;
  string card;
  std::list<string> pile, tempPile, discard;
  std::list<string>::iterator it;
  cin >> T;
  while (T--)
  {
    Y = 0;
    for (int i = 0; i < 52; i++)
    {
      cin >> card;
      pile.insert(pile.begin(), card);
    }
    it = pile.begin();
    std::advance(it, 25);
    tempPile.splice(tempPile.begin(), pile, pile.begin(), it);
    for (int i = 0; i < 3; i++)
    {
      card = pile.front();
      tempPile.pop_front();

      X = cardValue(card[0]);
      it = pile.begin();
      std::advance(it, 11 - X);

      Y += X;
      discard.splice(discard.begin(), pile, pile.begin(), it);
      //pile.reverse();
      //pile.insert(pile.begin(), card);
    }

    pile.splice(pile.begin(), tempPile, tempPile.begin(), tempPile.end());
    it = pile.begin();
    std::advance(it, pile.size() - Y);

    printf("Case %d: %s\n", c++, (*it).c_str());

    Y = 0;
    pile.clear();
    pile.clear();
  }
}