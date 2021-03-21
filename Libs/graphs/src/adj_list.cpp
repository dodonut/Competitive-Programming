#include "adj_list.h"
#include <algorithm>
#include <assert.h>
#include <iostream>

void Graph::AdjList::add_node() {
    _set.push_back(std::vector<int>());
}
void Graph::AdjList::add_edge(size_t start, size_t end) {
  assert(end < _set.size());
  _set.at(start).push_back(end);
}
void Graph::AdjList::remove_node(size_t node) {
  _set.erase(_set.begin() + node);
}
void Graph::AdjList::remove_edge(size_t node_start, size_t node_value) {
  auto ref = _set.at(node_start);

  auto exists = std::binary_search(ref.begin(), ref.end(), node_value);
  if (exists)
    ref.erase(ref.begin() + node_value);
}
void Graph::AdjList::clear() { _set.resize(0); }

Graph::AdjList::AdjList(size_t nodes) {
  _set.resize(nodes);
  for (size_t i = 0; i < nodes; ++i) {
    _set.at(i) = std::vector<size_t>();
  }
}
Graph::AdjList::AdjList() {}
Graph::AdjList::~AdjList() {}
