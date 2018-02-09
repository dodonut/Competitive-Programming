#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

bool myfunction(int i, int j) { return (i > j); }

int worstCase(int *cards)
{
  int result = 0;
  for (int i = 1; i < 3; i++)
  {
    for (int j = 3; j < 5; j++)
    {
      if (cards[i] > cards[j])
        result--;
      else
        result++;
    }
  }
  if (result < 0)
    return -1;
  return cards[1] + 1;
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