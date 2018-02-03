#include "utils.h"


namespace Sort {

  void Merge(std::vector<int>& arr, int l, int r) {
    if (l < r) {
      int m = l + (r-l)/2;
      Merge(arr,l,m);
      Merge(arr,m+1,r);
      merge_arrs(arr, l, m, r);
    }
  }
  
}
