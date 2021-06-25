//
//  Collection.hpp
//  lab3
//
//  Created by Donny Jones on 2/12/21.
//

#ifndef Collection_H
#define Collection_H
#include <iostream>
#include "list.hpp"


template <typename T>
class Collection;


template <typename T>
bool equal(const Collection<T>&, const Collection<T>&);

template <typename T>
class Collection {
 public:
  Collection();
  void addItem(const T& item);
  void removeItem(const T&);
  T lastItem();
  void printCollection();
  //friend bool a();
  friend bool equal<T>(const Collection<T>&, const Collection<T>&);
 private:
  node<T> *head;
};

template <typename T>
Collection<T>::Collection() {
  head = nullptr;
}

template <typename T>
void Collection<T>::addItem(const T& item) {
  // add to the front of the list
  node<T> *temp = new node<T>;
  temp->setData(item);
  temp->setNext(head);
  head = temp;
}

template<typename T>
void Collection<T>::removeItem(const T& item){
  node<T> *previous = nullptr;
  node<T> *current = head;
  node<T> *next;
  while (current != nullptr) {
    next = current->getNext();
    if (current->getData() == item) {
      if (previous != nullptr)
    previous->setNext(current->getNext());
      delete current;
    }
    // if deleted don't change
    if (current != nullptr)
      previous = current;
    current = next;
  }
}

template <typename T>
T Collection<T>::lastItem() {
  return head->getData();
}

template<typename T>
void Collection<T>::printCollection(){
  node<T> *current = head;
  while (current != nullptr) {
    std::cout << current->getData() << " ";
    current = current->getNext();
  }
  std::cout << std::endl;
}

template<typename T>
bool equal(const Collection<T>& lhs, const Collection<T>& rhs) {
  node<T> *left = lhs.head;
  node<T> *right = rhs.head;
    
  if (left == nullptr && right == nullptr)
      return true;
  else if (left == nullptr && right != nullptr)
      return false;
  else if (left != nullptr && right == nullptr)
      return false;
  else {
    while (left != nullptr && right != nullptr) {
      if (left->getData() != right->getData())
          return false;
      left = left->getNext();
      right = right->getNext();
    }
    // if only one is null
    if (left == nullptr && right != nullptr)
        return false;
    else if (left != nullptr && right == nullptr)
        return false;
  }
  // if all are true
  return true;
}
#endif
