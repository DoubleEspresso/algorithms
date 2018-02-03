#include <string>
#include <cstring>
#include <vector>

#include "threads.h"
#include "rand.h"
#include "clock.h"

void test_insertion();
void test_merge();

int main(int argc, char ** argv) {

  printf("..todo\n");
  return 0;
}


void test_insertion() { 

}

void test_merge() {
#ifdef _WIN32
  LARGE_INTEGER frequency;        // ticks per second
  LARGE_INTEGER t1, t2;           // ticks
  double elapsedTime;
  QueryPerformanceFrequency(&frequency);  // get ticks per second
  QueryPerformanceCounter(&t1);	// start timer
#endif

#ifdef _WIN32
  QueryPerformanceCounter(&t2);
  elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
  printf("..test_merge(%3.1fms)\n", (float)elapsedTime);
#endif
}
