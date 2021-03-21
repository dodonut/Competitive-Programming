#include "adj_list.h"
#include "adj_mat.h"
#include <iostream>
#include <numeric>
#include <optional>
using namespace Graph;

void printf_graph(const AdjList &l) {

  for (size_t i = 0; i < l.size(); ++i) {
    std::printf("node -> %ld\n\t", i);
    for (auto node : l.get(i)) {
      std::printf("-> %ld ", node);
    }
    printf("\n");
  }
}

int main() {

  {
    using namespace std;
    AdjList l = AdjList(4);

    l.add_edge(0, 2);
    l.add_edge(0, 1);
    l.add_edge(2, 2);
    l.add_edge(2, 0);
    l.add_edge(1, 2);

    printf("inserted nodes\n");
    printf_graph(l);

    l.remove_edge(2, 3);
    l.remove_edge(2, 2);
    printf("removed edges\n\n");
    printf_graph(l);
    printf("removed node\n\n");
    l.remove_node(0);
    printf_graph(l);
  }

  return 0;
}
