#include <iostream>
#include <stack>
#include <vector>

using namespace std;
//display deck
void display_deck(stack<string> deck) {
  std::cout << "disp deck" << std::endl;
  std::cout << deck.size() << std::endl;
  std::cout << deck.empty() << std::endl;
  while (!deck.empty()) {
    std::cout << deck.top() << ' ';
    deck.pop();
  }
  std::cout << std::endl;
}
//return true if is a face, false otherwise
bool isFace(const string& card) {
  if (card[1] == 'A' || card[1] == 'J' || card[1] == 'Q' || card[1] == 'K') {
    return true;
  }
  return false;
}
//faceMeans : return an integer that means how many cards of cover that face mean by the rules
int faceMeans(char face) {
  switch (face) {
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
  int n = faceMeans(heap.top()[1]);
  for (int i = 0; i < n; i++) {
    if (whoPlayedTheCard == 0 && !player2.empty()) {
      heap.push(player2.top());
      player2.pop();
      if (isFace(heap.top())) {
        n = faceMeans(heap.top()[1]);
        i = 0;
        whoPlayedTheCard = (whoPlayedTheCard + 1) % 2;
      }
    }
    else if(whoPlayedTheCard == 1 && !player1.empty()){
      heap.push(player1.top());
      player1.pop();
      if (isFace(heap.top())) {
        n = faceMeans(heap.top()[1]);
        i = 0;
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
  winnerOfTheHeap = invert(winnerOfTheHeap);
  //placing the deck of the winner of the round on top of the heap
  while (!winnerOfTheHeap.empty()) {
    heap.push(winnerOfTheHeap.top());
    winnerOfTheHeap.pop();
  }
  //taking all cards to itself
  winnerOfTheHeap = heap;
}
//flow of the game
void Game() {;
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


    //player2 starts at first time
    int playerturn = 1;
    //games on until one of players loses by emptying their hands
    while(!player1.empty() || !player2.empty()){
      if (playerturn == 0) {
        heap.push(player1.top());
        player1.pop();
      } else {
        heap.push(player2.top());
        player2.pop();
      }
      if (isFace(heap.top())) {
        playerturn = cover(heap, player1, player2, playerturn);
        playerturn == 0 ? takeTheHeap(heap, player1) : takeTheHeap(heap, player2);
        //change turn to go back again on lines below to avoid use a continue statemant
        playerturn = (playerturn + 1) % 2;
      }
      playerturn = (playerturn + 1) % 2;
    }
    if (player1.empty()) {
      printf("%d %d", 2, player2.size());
    }
    else {
      printf("%d %d", 1, player1.size());
    }
  }
}

int main()
{
  Game();
  return 0;
}
