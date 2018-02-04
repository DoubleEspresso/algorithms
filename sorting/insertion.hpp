
#include "utils.h"

namespace Sort {

  template<typename T>
  void insertion(std::vector<T> &v) {
    for (unsigned int i=1; i<v.size(); ++i) {
      T s = v[i];
      for (int j=i-1; j >= 0 && v[j] > s; --j) {
        T t = v[j];
        v[j] = s;
        v[j+1] = t;
        s = v[j];
      }
    }
  }

}
