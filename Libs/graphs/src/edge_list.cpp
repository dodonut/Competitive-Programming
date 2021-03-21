#include "edge_list.h"
#include <algorithm>
void EdgeList::insert_in_order(pair<int, int> value) {
  _set.insert(std::upper_bound(_set.begin(), _set.end(), value), value);
}

void EdgeList::add_edge(size_t start, size_t end) {
  insert_in_order(make_pair(start, end));
}
void EdgeList::remove_edge(size_t node_start, size_t node_value) {
  auto pair = make_pair(node_start, node_value);
  auto exists = std::binary_search(_set.begin(), _set.end(), pair);
  if (exists)
    _set.erase(std::lower_bound(_set.begin(), _set.end(), pair));
}
void EdgeList::clear() {}
EdgeList::EdgeList() {}
