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
  std::list<string> deck, pile;
  std::list<string>::iterator it;
  cin >> T;
  while (T--)
  {
    Y = 0;
    for (int i = 0; i < 52; i++)
    {
      cin >> card;
      deck.insert(deck.begin(), card);
    }
    for (int i = 0; i < 3; i++)
    {
      card = deck.front();
      deck.pop_front();

      X = cardValue(card[0]);
      it = deck.begin();
      std::advance(it, 10 - X);

      Y += X;
      pile.splice(pile.begin(), deck, deck.begin(), it);
      //pile.reverse();
      //pile.insert(pile.begin(), card);
    }
    cout << "Y: " << Y << endl;
    for (it = deck.begin(); it != deck.end(); ++it)
      cout << *it << ' ';
    it = deck.begin();
    std::advance(it, Y);
    printf("Case %d: %s\n", c++, (*it).c_str());

    Y = 0;
    deck.clear();
    pile.clear();
  }
}