#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  std::unordered_set<int> aliceCards, bettyCards;
  int card, aliceTradeCards, bettyTradeCards;
  aliceCards.rehash(10000);
  bettyCards.rehash(10000);

  int numCardsAlice, numCardsBetty;
  while (cin >> numCardsAlice >> numCardsBetty, numCardsAlice)
  {
    aliceTradeCards = 0;
    bettyTradeCards = 0;
    while (numCardsAlice--)
    {
      cin >> card;
      aliceCards.insert(card);
    }
    while (numCardsBetty--)
    {
      cin >> card;
      bettyCards.insert(card);
    }

    for (const int &var : aliceCards)
    {
      if (bettyCards.count(var) == 0)
        aliceTradeCards++;
    }
    for (const int &var : bettyCards)
    {
      if (aliceCards.count(var) == 0)
        bettyTradeCards++;
    }

    cout << std::min(aliceTradeCards, bettyTradeCards) << endl;
    aliceCards.clear();
    bettyCards.clear();
  }
}