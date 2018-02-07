#include <string>
#include <cstring>
#include <vector>

#include "threads.h"
#include "rand.h"
#include "clock.h"
#include "list.h"

void test_linked_list();

int main(int argc, char ** argv) {
  List<int> * list = new SingleLink<int>();
  for (int j=0; j<5; ++j) list->insert(j,j);
  list->print();
  return 0;
}

void test_linked_list() { 

}
