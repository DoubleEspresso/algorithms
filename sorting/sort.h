#ifndef SORT_H
#define SORT_H

namespace Sort {
  template<typename T> void insertion(std::vector<T> &v);
  template<typename T> void merge(std::vector<T> &v, int l, int r);
}

#include "insertion.hpp"
#include "merge.hpp"

#endif
