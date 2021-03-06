#include "adjmat.h"

Graph::AdjMat::AdjMat(size_t s) : _nodes(s) { _set.reserve(s * s); }

Graph::AdjMat::~AdjMat() {}

size_t Graph::AdjMat::index(size_t i, size_t j) { return _nodes * i + j; }

void Graph::AdjMat::add(size_t i, size_t j) {
  auto ind = this->index(i, j);
  if (_set.at(ind) != 1) {
    _connections++;
    _set.at(ind) = 1;
  }
}

void Graph::AdjMat::remove(size_t i, size_t j) {
  auto ind = this->index(i, j);
  if (_set.at(ind) != 0) {
    _set.at(ind) = 0;
    _connections--;
  }
}

void Graph::AdjMat::clear() { std::fill(_set.begin(), _set.end(), 0); }

bool Graph::AdjMat::is_connected(size_t i, size_t j) {
  return _set.at(index(i, j));
}

double Graph::AdjMat::ratio() { return _connections / (_nodes * _nodes); }
