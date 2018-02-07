#include "list.h"

template<typename T> void List<T>::print() {
  Node<T> * curr; curr = head;
  for(int j=0; j<count; ++j) {
    printf("%d ", curr->data); curr = curr->next;
  }
  printf("\n");
}

template<typename T> void SingleLink<T>::add(T data) {
  Node<T> * n = new Node<T>(data);
  tail->next = n;
  tail = n;
  ++count;
}

template<typename T> void SingleLink<T>::insert(T data, int idx) {
  Node<T> * prev;
  Node<T> * curr;
  curr = prev = head;
  for (int j=0; j<idx && curr != NULL; ++j) {
    prev = curr;
    curr = curr->next;
  }
  Node<T> * n = new Node<T>(data);
  prev->next = n;
  n->next = curr;
  ++count;
}

template<typename T> void SingleLink<T>::erase(int idx) {
  if (this->empty()) return;
  Node<T> * curr;
  Node<T> * prev;
  Node<T> * n = new Node<T>();
  curr = prev = head;

  if (idx == 0) { // first element
    n = head;
    head = head->next;
  } else {  

    for (int j=0; j<idx && curr != NULL; ++j) { 
      prev = curr; curr = curr->next;
    }

    if (idx == count - 1) { // last element
      n = curr;
      prev->next = tail;      
    } else { // general index
      n = curr; 
      curr = curr->next;
      prev->next = curr->next;
    }
  }
  --count;
  delete n;
}
