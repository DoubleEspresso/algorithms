#include "utils.h"

namespace Sort {
  
  template<typename T>
  void topological(std::list<T> * adj, std::stack<T>& res, size_t N) {
    std::vector<bool> visited;

    for (unsigned int j = 0; j < N; ++j) {
      visited.emplace_back(false);
    }
    
    for (unsigned int j = 0; j < N; ++j) {
      if (!visited[j]) top_sort(adj, visited, res, j);
    }      
  }  
}
