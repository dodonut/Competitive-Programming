#ifndef EDGE_LIST_H
#define EDGE_LIST_H

#include <vector>
using namespace std;
class EdgeList {
private:
  vector<pair<int, int>> _set;
  void insert_in_order(pair<int, int> value);

public:
  inline pair<int, int> get(size_t node) const { return _set.at(node); }
  inline size_t size() const { return _set.size(); }
  void add_edge(size_t start, size_t end);
  void remove_edge(size_t node_start, size_t node_value);
  void clear();
  EdgeList();
};

#endif /* EDGE_LIST_H */
