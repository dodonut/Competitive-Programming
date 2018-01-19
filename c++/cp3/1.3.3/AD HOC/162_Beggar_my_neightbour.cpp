#include <iostream>
#include <stack>

using namespace std;

bool isFace(const string& card) {
  if (card[1] == 'A' || card[1] == 'J' || card[1] == 'Q' || card[1] == 'K') {
    return true;
  }
  return false;
}

bool cover(stack<string>& heap, stack<string>& ss, const string& otherPlayerCard) {
  int a;
  switch (otherPlayerCard[1]) {
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
  string temp;
  for (int i = 0; i < a; i++) {
    temp = ss.top();
    ss.pop();
    heap.push(temp);
    if (isFace(temp)) {
      return false;
    }
  }
  return true;
}

void dealCards(stack<string>& heap, stack<string>& d_hand, stack<string>& nd_hand ) {  
    for (unsigned long i = 0; i < heap.size(); i++) {
      if (i%2 == 0) {
        nd_hand.push(heap.top());
      }
      else {
        d_hand.push(heap.top());
      }
      heap.pop();
    }
}


int main()
{
  string card;
  stack<string> player1, player2, heap;
  string input;
  while (cin >> input && input != "#") {
    heap.push(input);
    for (int i = 0; i < 51; i++) {
      cin >> card;
      printf("%s ", card.c_str());
      heap.push(card);
    }
  }
  cout << heap.size() << endl;
  dealCards(heap, player1, player2);
  cout << player1.size() << endl;
  return 0;
}
