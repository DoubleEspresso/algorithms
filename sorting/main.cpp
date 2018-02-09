#include <string>
#include <cstring>
#include <vector>

#include "threads.h"
#include "rand.h"
#include "clock.h"
#include "sort.h"

void test_insertion();
void test_merge();
void test_topological();

int main(int argc, char ** argv) {
  test_insertion();
  test_merge();
  test_topological();  
  return 0;
}

void test_topological() {
  size_t N = 6;
  std::list<int> * verts = new std::list<int>[N];
  std::stack<int> s;
  verts[5].push_back(2);
  verts[5].push_back(0);
  verts[4].push_back(0);
  verts[4].push_back(1);
  verts[2].push_back(3);
  verts[3].push_back(1);

  Sort::topological(verts, s, 6);

  while(!s.empty()) {    
    printf("%d ", s.top());
    s.pop();
  }
  printf("\n");
}

void test_insertion() { 
  size_t N = 10000;
  MT19937<double> rand(0, N);
  std::vector<double> v;

  for (unsigned int i=0; i<N; ++i) v.push_back(rand.next());

  Clock c("insertion sort");
  Sort::insertion(v);
  c.finished();

  int errs = 0;
  for (unsigned int i=1; i<v.size(); ++i) {
    if (v[i] < v[i-1]) ++errs;
  }
  printf("..insertion arr has %d-errors\n", errs);

}

void test_merge() {
#ifdef _WIN32
  LARGE_INTEGER frequency;        // ticks per second
  LARGE_INTEGER t1, t2;           // ticks
  double elapsedTime;
  QueryPerformanceFrequency(&frequency);  // get ticks per second
  QueryPerformanceCounter(&t1);	// start timer
#endif

  size_t N = 10000;
  MT19937<double> rand(0, N);
  std::vector<double> v;

  for (unsigned int i=0; i<N; ++i) v.push_back(rand.next());

  Clock c("merge sort");
  Sort::merge(v, 0, v.size());
  c.finished();

  // check result
  int errs = 0;
  for (unsigned int i=1; i<v.size(); ++i) {
    if (v[i] < v[i-1]) ++errs;
  }
  printf("..merge arr has %d-errors\n", errs);

#ifdef _WIN32
  QueryPerformanceCounter(&t2);
  elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
  printf("..test_merge(%3.1fms)\n", (float)elapsedTime);
#endif
}
