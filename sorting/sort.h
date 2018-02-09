#ifndef SORT_H
#define SORT_H

#include <list>
#include <stack>

namespace Sort {
  template<typename T> void insertion(std::vector<T> &v);
  template<typename T> void merge(std::vector<T> &v, int l, int r);
  template<typename T> void topological(std::list<T>* adj, std::stack<T>& res);
}

#include "insertion.hpp"
#include "merge.hpp"
#include "topological.hpp"

#endif
