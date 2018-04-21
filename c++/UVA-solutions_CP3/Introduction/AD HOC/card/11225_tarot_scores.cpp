#include <iostream>
#include <string>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  int T, cardsWon, pointsNeeded, numOudlers, c = 1;
  double totalPoints;
  string card, discard, statusGame;
  cin >> T;
  while (T--)
  {
    if (c > 1)
      cout << endl;
    totalPoints = 0;
    numOudlers = 0;
    cin >> cardsWon;
    while (cardsWon--)
    {
      cin >> card;
      if (card == "fool")
      {
        numOudlers++;
        totalPoints += 4.5;
      }
      else if (card == "twenty-one")
      {
        numOudlers++;
        totalPoints += 4.5;
        cin >> discard >> discard;
      }
      else if (card == "one")
      {
        cin >> discard >> discard;
        if (discard == "trumps")
        {
          numOudlers++;
          totalPoints += 4.5;
        }
        else
          totalPoints += 0.5;
      }
      else if (card == "king")
      {
        cin >> discard >> discard;
        totalPoints += 4.5;
      }
      else if (card == "queen")
      {
        cin >> discard >> discard;
        totalPoints += 3.5;
      }
      else if (card == "knight")
      {
        cin >> discard >> discard;
        totalPoints += 2.5;
      }
      else if (card == "jack")
      {
        cin >> discard >> discard;
        totalPoints += 1.5;
      }
      else
      {
        cin >> discard >> discard;
        totalPoints += 0.5;
      }
    }
    if (numOudlers == 3)
      pointsNeeded = 36;
    else if (numOudlers == 2)
      pointsNeeded = 41;
    else if (numOudlers == 1)
      pointsNeeded = 51;
    else
      pointsNeeded = 56;

    if (pointsNeeded - totalPoints <= 0)
      statusGame = "won";
    else
      statusGame = "lost";

    printf("Hand #%d\nGame %s by %d point(s).\n", c++, statusGame.c_str(), abs(pointsNeeded - totalPoints));
  }
}