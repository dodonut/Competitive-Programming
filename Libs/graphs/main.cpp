#include "adjlist.h"
#include "adjmat.h"
#include <iostream>
#include <numeric>

void print(jjj)

    int main() {

  {
    using namespace Graph;
    AdjList l = AdjList(4);
    l.add_edge(0, 10);

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cout << " " << graph.is_connected(i, j);
      }
      cout << '\n';
    }
  }

  return 0;
}
