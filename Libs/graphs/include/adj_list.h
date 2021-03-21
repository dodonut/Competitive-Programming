
#ifndef ADJLIST_H
#define ADJLIST_H

#include <vector>

namespace Graph {

class AdjList {
private:
  std::vector<std::vector<size_t>> _set;

public:
  inline std::vector<size_t> get(size_t node) const { return _set.at(node); }
  inline size_t size() const { return _set.size(); }
  void add_node();
  void add_edge(size_t start, size_t end);
  void remove_node(size_t node);
  void remove_edge(size_t node_start, size_t node_value);
  void clear();
  AdjList(size_t nodes);
  AdjList();
  virtual ~AdjList();
};
} // namespace Graph

#endif /* ADJLIST_H */
