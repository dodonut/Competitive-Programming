#include <iostream>
#include <set>
using namespace std;
int main()
{
  int N, temp;
  int code[1001], guess[1001];
  int strong, weak, cont = 1;
  multiset<int> guessHash, codeHash;
  while (cin >> N, N)
  {
    for (int i = 0; i < N; i++)
      cin >> code[i];

    printf("Game %d:\n", cont++);
    while (cin >> temp)
    {
      strong = 0;
      weak = 0;
      guess[0] = temp;
      for (int i = 1; i < N; i++)
        cin >> guess[i];
      if (guess[0] == 0)
        break;
      for (int i = 0; i < N; i++)
      {
        if (code[i] == guess[i])
          strong++;
        else
        {
          codeHash.insert(code[i]);
          guessHash.insert(guess[i]);
        }
      }
      for (int x : codeHash)
      {
        auto pos = guessHash.find(x);
        if (pos != guessHash.end())
        {
          weak++;
          guessHash.erase(pos);
        }
      }
      printf("    (%d,%d)\n", strong, weak);
      codeHash.clear();
      guessHash.clear();
    }
  }
}