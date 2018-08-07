#include "list.h"

template<typename T> void List<T>::print() {
  Node<T> * curr; curr = head;
  for(int j=0; j<count; ++j) {
    curr = curr->next;
    printf("%d ", curr->data); 
  }
  printf("\n");
}

//------------------------------------------------------------------
// singly-linked list
//------------------------------------------------------------------
template<typename T> void SingleLink<T>::push_back(T data) {
  Node<T> * n = new Node<T>(data);
  Node<T> * curr;  
  curr = head;
  for (int j=0; j<count; ++j ) { curr = curr->next; }
  curr->next = n;
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
      prev->next = curr;
    }
  }
  --count;
  delete n;
}


//------------------------------------------------------------------
// doubly-linked list
//------------------------------------------------------------------
template<typename T> void DoubleLink<T>::push_back(T data) {
  Node<T> * n = new Node<T>(data);
  Node<T> * curr;  
  curr = head;
  for (int j=0; j<count; ++j ) { curr = curr->next; }
  curr->next = n;
  tail = n;
  ++count;
}

template<typename T> void DoubleLink<T>::insert(T data, int idx) {
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

template<typename T> void DoubleLink<T>::erase(int idx) {
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
      prev->next = curr;
    }
  }
  --count;
  delete n;
}
