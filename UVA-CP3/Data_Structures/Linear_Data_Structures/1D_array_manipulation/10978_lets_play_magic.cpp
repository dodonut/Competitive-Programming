#include <iostream>
#include <string>
using namespace std;

int get_new_pos(const string *order, int size,int curr, int advance) {
  int forward = 0;
  while (forward != advance) {
    if (order[curr] == "") forward++;
    curr = (curr + 1) % size;
  }
  return curr;
}

int main() {
  int N, curr_pos;
  string c, s, order[52];
  while (cin >> N,N) {
  fill(order, order + 52, "");
    curr_pos = 0;
    for (int i = 0; i < N; i++) {
      cin >> c >> s;
      curr_pos = get_new_pos(order, N, curr_pos, s.length()) % N;
      order[(curr_pos -1 + N) % N] = c;
    }

    cout << order[0];
    for (int i = 1; i < N; i++) {
      cout << " " << order[i];
    }
    cout << endl;
  }
}
