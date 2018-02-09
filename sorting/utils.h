#ifndef UTILS_H
#define UTILS_H

#include <vector>


// merge two sorted arrays into one sorted array
// subroutine of merge-sort
template<typename T>
inline void merge_arrs(std::vector<T>& arr, int l, int m, int r) {
  for (int j = m; j<r; ++j) {
    T v = arr[j];    
    for (int i=j-1, k=j; i >= 0 && v < arr[i]; --i,--k) {
      std::swap(arr[k],arr[i]);
    }
  }
}

template<typename T>
inline void topsort(const std::list<T> * adj, std::vector<bool>& visited, std::stack<T>& s, const int& idx) {
  visited[idx] = true;
  
  std::list<int>::const_iterator i;  
  for (i = adj[idx].begin(); i != adj[idx].end(); ++i)
    if (!visited[*i]) topsort(adj, visited, s, *i);

  s.push(idx);
}


#endif
