#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
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

int simpleEval(string var) {
  if(var[0] == 'A') return 4;
  if(var[0] == 'K') return 3;
  if(var[0] == 'Q') return 2;
  if(var[0] == 'J') return 1;
  return 0;

}

int findSuit(string *vet, char suit) {
  int i;
  int counter = 0;
  iter(i,0,13, 1){
    if(vet[i][1] == suit) counter++;
  }
  return counter;
}

int rule1(string *vet) {
  int counter = 0;
  int i;
  iter(i,0,13,1) {
    counter += simpleEval(vet[i]);
  }
  return counter;
}

int rule2(string *vet) {
  int i;
  int subtract = 0;
  iter(i,0,13,1) {
    if(vet[i][0] == 'K')
      //because the K* is a suit card
      if(findSuit(vet, vet[i][1]) == 1) subtract--;
  }
  return subtract;
}

int rule3(string *vet) {
  int i;
  int subtract = 0;
  iter(i,0,13,1) {
    if(vet[i][0] == 'Q')
      if(findSuit(vet, vet[i][1]) < 3) subtract--;
  }
  return subtract;

}

int rule4(string *vet) {
  int i;
  int subtract = 0;
  iter(i,0,13,1) {
    if(vet[i][0] == 'J')
      if(findSuit(vet, vet[i][1]) < 4) subtract--;
  }
  return subtract;
}

int rule5(string *vet) {
  int add = 0;
  if(findSuit(vet, 'S') == 2) add++;
  if(findSuit(vet, 'D') == 2) add++;
  if(findSuit(vet, 'H') == 2) add++;
  if(findSuit(vet, 'C') == 2) add++;
  return add;

}

int rule6(string *vet) {
  int add = 0;
  if(findSuit(vet, 'S') == 1) add+=2;
  if(findSuit(vet, 'D') == 1) add+=2;
  if(findSuit(vet, 'H') == 1) add+=2;
  if(findSuit(vet, 'C') == 1) add+=2;
  return add;
}

int rule7(string *vet) {
  int add = 0;
  if(findSuit(vet, 'S') == 0) add+=2;
  if(findSuit(vet, 'D') == 0) add+=2;
  if(findSuit(vet, 'H') == 0) add+=2;
  if(findSuit(vet, 'C') == 0) add+=2;
  return add;
}

char mostCard(string *vet) {
  int i;
  int s=0,h=0,d=0,c=0;
  iter(i,0,13,1){
    if(vet[i][1] == 'S') s++;
    else if(vet[i][1] == 'D') d++;
    else if(vet[i][1] == 'H') h++;
    else c++;
  }
  if(s >= d && s >= h && s >= c) return 'S';
  else if(h >= d && h >= c) return 'H';
  else if(d >= c) return 'D';
  else return 'C';
}

int whichSuit(char suit) {
  if(suit == 'S') return 1;
  if(suit == 'H') return 2;
  if(suit == 'D') return 3;
  if(suit == 'C') return 4;
}

bool allSuitStopped(string *vet) {
  int i;
  int s=0,c=0,h=0,d=0;
  iter(i,0,13,1){
    if(vet[i][0] == 'A'){
      if(whichSuit(vet[i][1]) == 1) s = 1;
      if(whichSuit(vet[i][1]) == 2) h = 1;
      if(whichSuit(vet[i][1]) == 3) d = 1;
      if(whichSuit(vet[i][1]) == 4) c = 1;
    }
    else if(vet[i][0] == 'K'){
      if(findSuit(vet, vet[i][1]) > 1){
        if(whichSuit(vet[i][1]) == 1) s = 1;
        if(whichSuit(vet[i][1]) == 2) h = 1;
        if(whichSuit(vet[i][1]) == 3) d = 1;
        if(whichSuit(vet[i][1]) == 4) c = 1;
      }
    }
    else if(vet[i][0] == 'Q'){
      if(findSuit(vet, vet[i][1]) > 2){
        if(whichSuit(vet[i][1]) == 1) s = 1;
        if(whichSuit(vet[i][1]) == 2) h = 1;
        if(whichSuit(vet[i][1]) == 3) d = 1;
        if(whichSuit(vet[i][1]) == 4) c = 1;
      }
    }
  }
  if(s && h && d && c) return true;
  return false;
}

string finalEvaluation(string *vet, int eval) {
  int r5 = rule5(vet);
  int r6 = rule6(vet);
  int r7 = rule7(vet);
  if(eval < 14) return "PASS";
  else if(allSuitStopped(vet) && (eval - r5 - r6 - r7 ) >= 16) return "BID NO-TRUMP";
  else {
    string r = "BID ";
    r += mostCard(vet);
    return r;
  };
}
int main()
{
  string x[14];
  int i = 0;
  while (cin >> x[i++]) {
    if(i == 13){
      i = 0;
      int eval = 0;
      //start evaluating
      eval += rule1(x);
      eval += rule2(x);
      eval += rule3(x);
      eval += rule4(x);
      eval += rule5(x);
      eval += rule6(x);
      eval += rule7(x);

      cout << finalEvaluation(x, eval) << endl;
    }
  }
}
