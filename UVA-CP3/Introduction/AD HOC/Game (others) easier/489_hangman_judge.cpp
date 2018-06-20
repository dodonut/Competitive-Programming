#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
  int section, wrongGuess;
  string word;
  string guess;
  set<char> wordHash, repeated;

  while (cin >> section && section != -1)
  {
    cin >> word >> guess;
    wrongGuess = 0;
    for (int i = 0; i < word.size(); i++)
      wordHash.insert(word[i]);

    for (auto &&x : guess)
    {
      if (repeated.find(x) == repeated.end())
      {
        repeated.insert(x);
        if (wordHash.find(x) != wordHash.end())
        {
          wordHash.erase(x);
          if (wordHash.size() == 0)
            break;
        }
        else
        {
          wrongGuess++;
          if (wrongGuess == 7)
            break;
        }
      }
    }
    printf("Round %d\n", section);
    if (wrongGuess == 7)
      printf("You lose.");
    else if (wordHash.size() > 0)
      printf("You chickened out.");
    else
      printf("You win.");
    cout << endl;
    wordHash.clear();
    repeated.clear();
  }
}