
#include "utils.h"

namespace Sort {

  void insertion(std::vector<int> &v) {
    for (unsigned int i=1; i<v.size(); ++i) {
      int s = v[i];
      for (int j=i-1; j >= 0 && v[j] > s; --j) {
        int t = v[j];
        v[j] = s;
        v[j+1] = t;
        s = v[j];
      }
    }
  }

}
