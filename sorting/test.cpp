#include <string>
#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void isort(std::vector<int> &v) {
  for (int i=1; i<v.size(); ++i) {
    int s = v[i];
    for (int j=i-1; j >= 0 && v[j] > s; --j) {
      int t = v[j];
      v[j] = s;
      v[j+1] = t;
      s = v[j];
    }
  }
}

inline bool OK(std::vector<int> &v, int i) { return i < v.size() && i >= 0; }

int find_nearest(std::vector<int>&v, int i) {
  // binary search to return nearest idx less than i
  // in sorted v
  int l = 0; int r = v.size(); int m = v.size()/2;
  int count = 0;
  
  if (v[0] == i) return 0;

  while ( l <= r ) {
    
    m = l + (r - l) / 2;

    int d = v[m];

    if (d == i) break; 

    if (d < i) { 
      if (OK(v, m + 1) && v[m + 1] >= i ) break;
      l = m + 1;
    }
    
    if (d > i) {
      if (OK(v, m - 1) && v[m - 1] < i ) break;
      r = m - 1;
    }
    ++count;
  }
  while (v[m] >= i) m -= 1;

  return (m < 0 ? 0 : m);
}

int find(std::vector<int> &v, int i) {
  // binary search to return index of i
  // in sorted v
  // note : repeated values .. will not necessarily 
  // return the smallest index..
  int l = 0; int r = v.size(); int m = v.size()/2;
  int count = 0;

  while (l <= r) {    
    m = l + (r - l)/2;

    int d = v[m];

    if (d == i) break;

    if (d < i) l = m + 1;
    else if (d > i) r = m - 1;

    ++count;
  }

  // get the smallest index here..if repeated elements exist
  while (v[m] == i) m -= 1;
  m += 1;

  if (l > r) printf("..not found!\n");
  else printf("..idx of v[%d] = %d (%d-tries)\n", m, v[m], count);
}

inline void swap(std::vector<int>& arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

// merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(std::vector<int>& arr, int l, int m, int r) {
  for (int j = m; j<r; ++j) {
    int v = arr[j];    
    for (int i=j-1, k=j; i >= 0 && v < arr[i]; --i,--k) {
      swap(arr,k,i); 
    }
  }
}


void mergeSort(std::vector<int>& arr, int l, int r) {
  if (l < r) {
    int m = l + (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr, l, m, r);
  }
}


int main() {
  srand(time(NULL));

  int N = rand()%1000+1;
  printf("..size=%d\n", N);
  
  std::vector<int> unsorted;
  for (int i=0; i<N; ++i) {
    unsorted.push_back(rand() % N + 1);
  }
  //for(int i=0; i<unsorted.size(); ++i) printf("%d ", unsorted[i]);
  //printf("\n");

  mergeSort(unsorted, 0, unsorted.size());

  for(int i=0; i<unsorted.size(); ++i) printf("%d ", unsorted[i]);
  printf("\n");


  

  /*
  isort(unsorted);
  int i = unsorted[rand()%unsorted.size()];
  printf("..binary search: find %d\n", i);
  find(unsorted, i);

  int count = 0;
  for (int j=0; j<unsorted.size(); ++j) {
    if (unsorted[j]!=i) ++count;
    else break;
  }

  printf("..brute force v[%d] = %d (%3.3f)\n", count, unsorted[count], log2(count));
  
  int ii = rand()%unsorted.size();
  printf("find largest idx smaller than %d\n", ii);
  int j = find_nearest(unsorted, ii);
  printf ("v[%d]=%d, v[%d]=%d, i=%d\n", j, unsorted[j], j+1, unsorted[j+1], ii);
  */

  /*
  //merge sort piece
  N = 20;
  std::vector<int> arr1;
  std::vector<int> arr2;

  for (int i=0; i<N; ++i) {
    arr1.push_back(rand() % (10*N));
    arr2.push_back((rand() % (10*N)));
  }

  isort(arr1);
  isort(arr2);  



  for(int i=0; i<arr1.size(); ++i) printf("%d ", arr1[i]);
  printf("\n");
  for(int i=0; i<arr2.size(); ++i) printf("%d ", arr2[i]);
  printf("\n");

  for (int j=0; j<arr2.size(); ++j) arr1.push_back(arr2[j]);

  for(int i=0; i<arr1.size(); ++i) printf("%d ", arr1[i]);
  printf("\n");

  merge(arr1, 0, N, arr1.size());



  for(int i=0; i<arr1.size(); ++i) printf("%d ", arr1[i]);
  printf("\n");
  */
}
