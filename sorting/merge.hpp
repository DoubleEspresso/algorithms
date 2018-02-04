#include "utils.h"


namespace Sort {

  template<typename T>
  void merge(std::vector<T>& arr, int l, int r) {
    if (l < r) {
      int m = l + (r-l)/2;
      merge(arr,l,m);
      merge(arr,m+1,r);
      merge_arrs(arr, l, m, r);
    }
  }
  
}
