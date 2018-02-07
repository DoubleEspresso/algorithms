#ifndef LIST_H
#define LIST_H

template<typename T> 
struct Node {
  Node(T d) : next(0), data(d) {}
  Node() : next(0), data(0) {}
  Node * next;
  T data;
};

template<typename T>
class List {
 protected:
  Node<T> * head;
  Node<T> * tail;
  size_t count;

 public:
 List() : head(0), tail(0), count(0) { head = new Node<T>(); tail = new Node<T>(); }
  virtual ~List() {
    if (head) { delete head; head = 0; }
    if (tail) { delete tail; tail = 0; }
  }
  inline bool empty() { return head == NULL; }
  inline size_t size() { return count; }
  void print();
  virtual void add(T data) = 0;
  virtual void insert(T data, int idx) = 0;
  virtual void erase(int idx) = 0;
};

template<typename T>
class SingleLink : public List<T> {
  using List<T>::head;
  using List<T>::tail;
  using List<T>::count;
 public:
  SingleLink() {}
  ~SingleLink() {}
  void add(T data);
  void insert(T data, int idx);
  void erase(int idx);
}; 

#include "list.hpp"

#endif
