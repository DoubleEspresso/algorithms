#ifndef UTILS_H
#define UTILS_H

#include <vector>

// swap two elements in an array
template<typename T>
inline void swap(std::vector<T>& arr, int i, int j) {
    T t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

// merge two sorted arrays into one sorted array
// subroutine of merge-sort
template<typename T>
inline void merge_arrs(std::vector<T>& arr, int l, int m, int r) {
  for (int j = m; j<r; ++j) {
    T v = arr[j];    
    for (int i=j-1, k=j; i >= 0 && v < arr[i]; --i,--k) {
      swap(arr,k,i); 
    }
  }
}



#endif
