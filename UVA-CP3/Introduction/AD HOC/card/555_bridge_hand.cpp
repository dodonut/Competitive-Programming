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
  if(cv == '2') return 2;
  if(cv == '3') return 3;
  if(cv == '4') return 4;
  if(cv == '5') return 5;
  if(cv == '6') return 6;
  if(cv == '7') return 7;
  if(cv == '8') return 8;
  if(cv == '9') return 9;
  if(cv == 'T') return 10;
  if(cv == 'J') return 11;
  if(cv == 'Q') return 12;
  if(cv == 'K') return 13;
  if(cv == 'A') return 14;
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
  while(!suits.empty()){
    if(suitIndex != -1){
      temp.push_back(vs.at(suitIndex));
      vs.erase(vs.begin() + suitIndex);
      suitIndex = findSuit(vs, suit);
    }
    else{
      suitSize.push_back(temp.size());
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
    for (int j = i+1; j < end; j++) {
      card1 = vs[i];
      card2 = vs[j];
      if(cardValue(vs[j][1]) < cardValue(vs[i][1]))
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
    sortNumber(vss[i], 0, suitsSize[0]);
    sortNumber(vss[i], suitsSize[0] , suitsSize[1]);
    sortNumber(vss[i], suitsSize[1] , suitsSize[2]);
    sortNumber(vss[i], suitsSize[2] , suitsSize[3]);
  }
}

void displayAllHands(const vector<vector<string>>& vss)
{
  displayHand(vss[0], 'S');
  displayHand(vss[1], 'W');
  displayHand(vss[2], 'N');
  displayHand(vss[3], 'E');
}

//second solution
void createMapping(map<string, int>& deck)
{
  string suits[] {"C", "D", "S", "H"};
  string numbers[] {"2","3","4","5","6","7","8","9","T","J","Q","K","A"};

  int i,j,counter = 0;
  string card;
  iter(i,0,4,1){
    iter(j,0,13,1){
      card += suits[i] + numbers[j];
      deck[card] = counter++;
      card = "";
    }
  }
}

vector<pair<string,int>> playersCard(map<string, int>& deck, const string& line, int& D)   
{
  int i;
  string card = "";
  vector<pair<string,int>> vss;
  iter(i,0,line.size(),1) {
    card += line[i];
    int value;
    value = deck[card];
    if(card.size() == 2) {
      vss[ D ].push_back(make_pair(card,value));
      card = "";
      D = (D+1) % 4;
    }
  }

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
    int i;
    iter(i,0,4,1) vss[i].clear();

  }

}
