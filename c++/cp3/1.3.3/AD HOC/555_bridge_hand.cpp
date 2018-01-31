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
#define iter(a,b,c,d) for(a = b; a < c; a+=d)
#define ited(a,b,c,d) for(a = b; a > c; a-=d)
#define li long int
#define uli unsigned li
#define ll long li
#define ull unsigned ll
#define si(a) scanf("%d",&a)
#define sli(a) scanf("%ld",&a)
#define sll(a) scanf("%lld",&a)
#define slu(a) scanf("%llu",&a)
#define sf(a) scanf("%f",&a)
#define slf(a) scanf("%lf",&a)
#define PI 3.1415926
using namespace std;

void displayHand(const vector<string>& vs, char person)
{
  int i;
  printf("%c:", person);
  iter(i,0,vs.size(),1){
    printf(" %s", vs[i].c_str());
  }
  cout << endl;
}

int dealer(char d)
{
  if(d == 'S') return 0;
  if(d == 'W') return 1;
  if(d == 'N') return 2;
  if(d == 'E') return 3;
}

int cardValue(char cv)
{
  if(cv == 'T') return 10;
  if(cv == 'J') return 11;
  if(cv == 'Q') return 12;
  if(cv == 'K') return 13;
  if(cv == 'A') return 14;
  return (int)cv;
}

void playersCard(vector<vector<string>> & vss,const string& line,  int& D)
{
  int i;
  string card = "";
  iter(i,0,line.size(),1) {
    card += line[i];
    if(card.size() == 2) {
      vss[ D ].push_back(card);
      card = "";
      D = (D+1) % 4;
    }
  }
}

int findSuit(vector<string>& vs, char suit)
{
  int i;
  iter(i,0,vs.size(), 1){
    if(vs[i][0] == suit) return i;
  }
  return -1;
}

vector<int> sortSuits(vector<string>& vs)
{
  vector<char> suits = {'C', 'D', 'S', 'H'};
  vector<string> temp;
  vector<int> suitSize;
  char suit = suits.at(0);
  int suitIndex = findSuit(vs, suit);
  int lastTempSize = 0;
  while(!suits.empty()){
    if(suitIndex != -1){
      temp.push_back(vs.at(suitIndex));
      vs.erase(vs.begin() + suitIndex);
      suitIndex = findSuit(vs, suit);
    }
    else{
      suitSize.push_back(temp.size() - lastTempSize);
      lastTempSize = temp.size();
      suits.erase(suits.begin());
      if(!suits.empty()){
        suit = suits.at(0);
        suitIndex = findSuit(vs, suit);
      }
    }
  }
  vs = temp;
  return suitSize;
}

void sortNumber(vector<string>& vs, int start, int end) 
{
  string card1, card2;
  for (int i = start; i < end - 1; i++) {
    for (int j = start+1; j < end; j++) {
      card1 = vs[i];
      card2 = vs[j];
      if(cardValue(card2[1]) < cardValue(card1[1])) 
        std::swap(vs[i],vs[j]);
    }
  }
}

void sortAll(vector<vector<string>>& vss)
{
  int i;
  vector<int> suitsSize;
  iter(i,0,vss.size(),1){
    suitsSize = sortSuits(vss[i]);
    sortNumber(vss[i], suitsSize[0], suitsSize[1]);
    sortNumber(vss[i], suitsSize[1]+1, suitsSize[2]);
    sortNumber(vss[i], suitsSize[2]+1, suitsSize[3]);
    sortNumber(vss[i], suitsSize[3]+1, suitsSize.size());
  }
}

void displayAllHands(const vector<vector<string>>& vss)
{
  displayHand(vss[0], 'S');
  displayHand(vss[1], 'W');
  displayHand(vss[2], 'N');
  displayHand(vss[3], 'E');
}

int main()
{
  string firstLine, secondLine;
  char dealerChar;
  vector<vector<string>> vss (4,vector<string>(0));
  int D;
  while(cin >> dealerChar && dealerChar != '#') {
    D = dealer(dealerChar);
    cin >> firstLine >> secondLine;
    D = (D + 1) % 4;
    playersCard(vss, firstLine, D);
    playersCard(vss, secondLine, D);

    sortAll(vss);

    displayAllHands(vss);
  }

}
