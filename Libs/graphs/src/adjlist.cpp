#include "adjlist.h"
#include <iostream>

void Graph::AdjList::add_node() { _set.push_back(std::vector<int>()); }
void Graph::AdjList::add_edge(size_t node, size_t value) {
  _set.at(node).push_back(value);
}
void Graph::AdjList::remove_node(size_t node) {
  _set.erase(_set.begin() + node);
}
void Graph::AdjList::remove_edge(size_t node_start, size_t node_value) {
  auto ref = _set.at(node_start);
  auto begin = ref.begin();
  ref.erase(begin + node_value);
}
void Graph::AdjList::clear() { _set.resize(0); }

Graph::AdjList::AdjList(size_t nodes) {
  _set.reserve(nodes);
  for (size_t i = 0; i < nodes; ++i) {
    _set.at(i) = std::vector<int>();
  }
}
Graph::AdjList::AdjList() {}
Graph::AdjList::~AdjList() {}
