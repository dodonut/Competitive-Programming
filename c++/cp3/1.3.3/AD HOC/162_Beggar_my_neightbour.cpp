#include <iostream>
#include <stack>
#include <vector>

using namespace std;
//return true if is a face, false otherwise
bool isFace(const string& card) {
  if (card[1] == 'A' || card[1] == 'J' || card[1] == 'Q' || card[1] == 'K') {
    return true;
  }
  return false;
}
//return a face if it was founded when covering, blank string otherwise
string coverUntilFindsFaceOrDone(stack<string>& heap, stack<string>& deck_covering, const int iter) {
  string temp;
  for (int i = 0; i < iter; i++) {
    temp = deck_covering.top();
    deck_covering.pop();
    heap.push(temp);
    if (isFace(temp)) {
      return temp;
    }
  }
  return "";
}
//return pair(coverUntilFindsFaceOrDone, caller)
std::pair<string, int> cover(stack<string>& heap, stack<string>& deck_covering,const int faceCaller, const string& faceCallerCard) {
  int a;
  switch (faceCallerCard[1]) {
    case 'J':
      a = 1;
      break;
    case 'Q':
      a = 2;
      break;
    case 'K':
      a = 3;
      break;
    case 'A':
      a = 4;
      break;

  }
  return make_pair(coverUntilFindsFaceOrDone(heap, deck_covering, a), faceCaller);
}
//deal cards from the heap to the players
void dealCards(stack<string>& heap, stack<string>& d_hand, stack<string>& nd_hand ) {
  int s = heap.size();
  for (unsigned long i = 0; i < s; i++) {
    if (i%2 == 0) {
      nd_hand.push(heap.top());
    }
    else {
      d_hand.push(heap.top());
    }
    heap.pop();
  }
}
//return a std::pair<string, int> with the face and the player who's belong, blank string and -1 otherwise
std::pair<string, int> dealUntilFindsFace(stack<string>& heap, stack<string>& d_hand, stack<string>& nd_hand ) {
  std::cout << "here" << std::endl;
  vector<stack<string>> vss {&d_hand, &nd_hand};
  int playerturn = 1;
  std::cout << "here" << std::endl;
  while (!d_hand.empty() || !nd_hand.empty()) {
    string temp = vss[playerturn].top();
    vss[playerturn].pop();
    heap.push(temp);
    playerturn = (playerturn + 1) % 2;
    if (isFace(temp)) {
      return std::make_pair(temp, playerturn);
    }
  }
  return std::make_pair("", -1);
}
//add the heap to the winnerOfTheHeap top deck without changing the heap order
void takeTheHeap(stack<string>& heap, stack<string>& winnerOfTheHeap) {
  stack<string> temp;
  while (!heap.empty()) {
    temp.push(heap.top());
    heap.pop();
  }
  while (!temp.empty()) {
    winnerOfTheHeap.push(temp.top());
    temp.pop();
  }
}
//flow of the game
void Game(stack<string>& heap,stack<string>& player1,stack<string>& player2 ) {
  string card;
  string input;
  while (cin >> input && input != "#") {
    heap.push(input);
    for (int i = 0; i < 51; i++) {
      cin >> card;
      // printf("%s ", card.c_str());
      heap.push(card);
    }
    //initial deal of 26 cards
    // std::cout << "here" << std::endl;
    dealCards(heap, player1, player2);
    std::pair<string, int> pair;
    //put cards on the heap until one of the players takes a face card
    //default value to start the loop
    //games on until one of players loses by emptying their hands
    while(!player1.empty() || !player2.empty()){
      pair = dealUntilFindsFace(heap, player1, player2);
      std::cout << "here" << std::endl;
      while (pair.first != "") {
        if(pair.second == -1){
          //game finished over normal dealing
          return;
        }
        do {
          pair = pair.second == 0 ? cover(heap, player2, 1, pair.first) :
            cover(heap, player1, 2, pair.first);
          //returned a face?
          if (!pair.first.empty()) {
            pair.second = (pair.second + 1) % 2;
          }
        } while (!pair.first.empty());
      }
      pair.second == 0 ? takeTheHeap(heap, player1) : takeTheHeap(heap, player2);
    }
  }
}

int main()
{
  stack<string> player1, player2, heap;
  Game(heap, player1, player2);
  if (player1.empty()) {
    printf("%d %d", 2, player2.size());
  }
  else {
    printf("%d %d", 1, player1.size());
  }
  return 0;
}
