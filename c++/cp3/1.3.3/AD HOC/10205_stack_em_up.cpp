#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <limits>
#define iter(a, b, c, d) for (a = b; a < c; a += d)
#define ited(a, b, c, d) for (a = b; a > c; a -= d)
#define li long int
#define uli unsigned li
#define ll long li
#define ull unsigned ll
#define si(a) scanf("%d", &a)
#define sli(a) scanf("%ld", &a)
#define sll(a) scanf("%lld", &a)
#define slu(a) scanf("%llu", &a)
#define sf(a) scanf("%f", &a)
#define slf(a) scanf("%lf", &a)
#define PI 3.1415926
using namespace std;

map<int, string> mountDeck()
{
  string suits[]{"C", "D", "H", "S"};
  string numbers[]{"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};

  map<int, string> deck;
  int i, j, counter = 1;
  string card;
  iter(i, 0, 4, 1)
  {
    iter(j, 0, 13, 1)
    {
      card += suits[i] + numbers[j];
      deck[counter++] = card;
      card = "";
    }
  }
  return deck;
}

string nameCard(char val)
{
  if (val == '2')
    return "2";
  if (val == '3')
    return "3";
  if (val == '4')
    return "4";
  if (val == '5')
    return "5";
  if (val == '6')
    return "6";
  if (val == '7')
    return "7";
  if (val == '8')
    return "8";
  if (val == '9')
    return "9";
  if (val == 'T')
    return "10";
  if (val == 'J')
    return "Jack";
  if (val == 'Q')
    return "Queen";
  if (val == 'K')
    return "King";
  if (val == 'A')
    return "Ace";
}

string nameSuit(char val)
{
  if (val == 'H')
    return "Hearts";
  if (val == 'S')
    return "Spades";
  if (val == 'D')
    return "Diamonds";
  if (val == 'C')
    return "Clubs";
}

vector<int> doShuffles(vector<int> s, vector<vector<int>> &sh)
{
  vector<int> ans(52), now;
  int i, j, k, pos, shuff, card;
  iter(i, 0, 52, 1)
      now.push_back(i + 1);

  cout << "here" << endl;
  iter(i, 0, s.size(), 1)
  {
    shuff = s[i];
    iter(j, 0, 52, 1)
    {
      card = sh.at(shuff - 1).at(j);
      ans.at(j) = card;
    }
    iter(k, 0, 52, 1)
    {
      //cout << now.at(k) << ' ';
      //pos = now.at(k);
      now.at(k) = ans.at(now.at(k) - 1);
      //cout << now.at(k) << ' ';
      //cout << ans.at(k) << endl;
    }
    //ans.clear();
  }
  return now;
}

int main()
{
  map<int, string> deckMap = mountDeck();
  vector<int> ans, now;

  int testCases;
  int card, i;

  cin >> testCases;
  while (testCases--)
  {
    int shf;
    cin >> shf;
    vector<vector<int>> shuffles;

    int c = shf;
    while (c--)
    {
      iter(i, 0, 52, 1)
      {
        cin >> card;
        ans.push_back(card);
      }
      shuffles.push_back(ans);
      ans.clear();
    }
    vector<int> shufSeq;
    string linha;
    i = 0;
    while (getline(cin, linha) && !linha.empty())
      shufSeq.push_back(stoi(linha));

    cout << "here" << endl;
    now = doShuffles(shufSeq, shuffles);

    string card;
    iter(i, 0, 52, 1)
    {
      card = deckMap[now[i]];
      printf("%s of %s\n", nameCard(card[1]).c_str(), nameSuit(card[0]).c_str());
    }
    cout << endl;
    iter(i, 0, shuffles.size(), 1) shuffles[i].clear();
    shuffles.clear();
  }
}
