#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

bool myfunction(int i, int j) { return (i > j); }

int worstCase(int *cards)
{
  int temp = 0;
  if (cards[1] < cards[3])
  {
    if (cards[0] < cards[3])
      temp = 1;
    else
      temp = cards[1] + 1;
  }
  else
  {
    if (cards[0] > cards[4])
      temp = -1;
    else
      temp = cards[0] + 1;
  }
  while (temp == cards[3] || temp == cards[4] || temp == cards[0] || temp == cards[1] || temp == cards[2])
    temp++;
  if (temp == 53)
    temp = -1;
  return temp;
}

int main()
{
  int cards[5] = {0};
  int i = 0;
  while (cin >> cards[i], cards[i])
  {
    i++;
    if (i == 5)
    {
      std::sort(cards, cards + 3, myfunction);
      std::sort(cards + 3, cards + 5);

      cout << worstCase(cards) << endl;
      i = 0;
    }
  }
}