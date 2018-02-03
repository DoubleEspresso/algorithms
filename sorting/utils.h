#ifndef UTILS_H
#define UTILS_H


// swap two elements in an array
inline void swap(std::vector<int>& arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

// merge two sorted arrays into one sorted array
// subroutine of merge-sort
inline void merge_arrs(std::vector<int>& arr, int l, int m, int r) {
  for (int j = m; j<r; ++j) {
    int v = arr[j];    
    for (int i=j-1, k=j; i >= 0 && v < arr[i]; --i,--k) {
      swap(arr,k,i); 
    }
  }
}



#endif
