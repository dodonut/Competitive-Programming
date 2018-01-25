#include <iostream>
#include <stack>
#include <vector>

using namespace std;
//display deck
void display_deck(stack<string> deck, int player) {
  cout << player << endl;
  while (!deck.empty()) {
    std::cout << deck.top() << ' ';
    deck.pop();
  }
  printf("\n\n");
}
//return true if is a face, false otherwise
bool isFace(const string& card) {
  if (card[1] == 'A' || card[1] == 'J' || card[1] == 'Q' || card[1] == 'K') {
    return true;
  }
  return false;
}
//faceMeans : return an integer that means how many cards of cover that face mean by the rules
int faceMeans(string face) {
  char f = face[1];
  switch (f) {
    case 'J':
      return 1;
    case 'Q':
      return 2;
    case 'K':
      return 3;
    default:
      return 4;
  }
}
//COVER : return an integer that means which player should take the heap
int cover(stack<string>& heap, stack<string>& player1, stack<string>& player2, int whoPlayedTheCard) {
  int n = faceMeans(heap.top());
  for (int i = 0; i < n; i++) {
    if (whoPlayedTheCard == 0 && !player2.empty()) {
      heap.push(player2.top());
      player2.pop();
      if (isFace(heap.top())) {
        n = faceMeans(heap.top());
        //to start at 0 again because its going to increment at the end of statment
        i = -1;
        whoPlayedTheCard = (whoPlayedTheCard + 1) % 2;
      }
    }
    else if(whoPlayedTheCard == 1 && !player1.empty()){
      heap.push(player1.top());
      player1.pop();
      if (isFace(heap.top())) {
        n = faceMeans(heap.top());
        i = -1;
        whoPlayedTheCard = (whoPlayedTheCard + 1) % 2;
      }
    }
  }
  return whoPlayedTheCard;
}
//invert deck : returns a inverted stack
stack<string> invert(const stack<string>& heap) {
  stack<string> temp;
  stack<string> tempheap = heap;
  while (!tempheap.empty()) {
    temp.push(tempheap.top());
    tempheap.pop();
  }
  return temp;
}
//add the heap to the winnerOfTheHeap top deck without changing the heap order
void takeTheHeap(stack<string>& heap, stack<string>& winnerOfTheHeap) {
  //inverting the deck of the winner to a temp deck
  stack<string> temp = invert(winnerOfTheHeap);
  while(!winnerOfTheHeap.empty()) winnerOfTheHeap.pop();

  while(!heap.empty()){
    winnerOfTheHeap.push(heap.top());
    heap.pop();
  }
  while(!temp.empty()){
    winnerOfTheHeap.push(temp.top());
    temp.pop();
  }
}
//flow of the game
void Game() {
  string card1, card2;
  string input;
  stack<string> player1, player2, heap;
  //player2 will always be the non-dealer
  //read a complete deck and distribute to the players by the rules
  while (cin >> input && input != "#") {
    player2.push(input);
    for (int i = 0; i < 25; i++) {
      cin >> card1;
      cin >> card2;
      player1.push(card1);
      player2.push(card2);
    }
    cin >> card1;
    player1.push(card1);

    // display_deck(player1);
    // display_deck(player2);

    //player2 starts at first time
    int playerturn = 1;
    //games on until one of players loses by emptying their hands
    int i = 0;
    while(!player1.empty() && !player2.empty()){
      if (playerturn == 0) {
        heap.push(player1.top());
        player1.pop();
      } else {
        heap.push(player2.top());
        player2.pop();
      }
      i++;
      if(player1.empty() || player2.empty()) break;
      if (isFace(heap.top())) {
        playerturn = cover(heap, player1, player2, playerturn);
        if (playerturn == 0) {
          if (!player2.empty()) {
            takeTheHeap(heap, player1);
            display_deck(player1, 1);
            display_deck(player2, 2);
          }
        }
        else {
          if (!player1.empty()) {
            takeTheHeap(heap, player2);
            display_deck(player1, 1);
            display_deck(player2, 2);
          }
        }
        //change turn to go back again on lines below to avoid use a continue statemant
        playerturn = (playerturn + 1) % 2;
      }
      playerturn = (playerturn + 1) % 2;

    }
    if (!player1.empty()) {
      printf("%d %d\n", 1, player1.size());
    }
    else {
      printf("%d %d\n", 2, player2.size());
    }
    while(!player1.empty()) player1.pop();
    while(!player2.empty()) player2.pop();
    while(!heap.empty()) heap.pop();
  }
}

int main()
{
  Game();
  return 0;
}
