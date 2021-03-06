
#ifndef ADJLIST_H
#define ADJLIST_H

#include <vector>

namespace Graph {

class AdjList {
private:
  std::vector<std::vector<int>> _set;

public:
  void add_node();
  void add_edge(size_t i, size_t j);
  void remove_node(size_t node);
  void remove_edge(size_t node_start, size_t node_value);
  void clear();
  AdjList(size_t nodes);
  AdjList();
  virtual ~AdjList();
};
} // namespace Graph

#endif /* ADJLIST_H */
