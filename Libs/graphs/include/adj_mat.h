#ifndef ADJMAT_H
#define ADJMAT_H

#include <vector>

namespace Graph {

class AdjMat {
private:
  std::vector<bool> _set;
  size_t _nodes;
  size_t _connections;
  size_t index(size_t i, size_t j);

public:
  void add(size_t i, size_t j);
  void remove(size_t i, size_t j);
  void clear();
  bool is_connected(size_t i, size_t j);
  //// connected / all;
  double ratio();
  AdjMat(size_t nodes);
  virtual ~AdjMat();
};
} // namespace Graph

#endif /*GRAPH_H */
