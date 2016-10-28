#include "list.h"
#include <stdexcept>

template <class Item>
List<Item>::List(){
  list_head = NULL;
  list_tail = NULL;
}

template <class Item>
void List<Item>::deep_copy_from(List<Item>& copyme){
  list_head = NULL;
  list_tail = NULL;
  for (Node<Item>* curr=copyme.list_head; curr != NULL; curr=curr->next){
    push_back(curr->data);
  }
}

template <class Item>
void List<Item>::clean_up(){
  while (list_tail != NULL){
    pop_front();
  }
}

template <class Item>
List<Item>::~List(){
  clean_up();
}

template <class Item>
List<Item> List<Item>::operator=(List<Item>& rside){
  clean_up();
  deep_copy_from(rside);
  return *this;
}

template <class Item>
List<Item>::List(List<Item>& orig){
  deep_copy_from(orig);
}

template <class Item>
Item List<Item>::head() const{
  return list_head->data;
}

template <class Item>
Item List<Item>::tail() const{
  return list_tail->data;
}

template <class Item>
void List<Item>::push_back(Item i){
  Node<Item>* newNode = new Node<Item>;
  newNode->data = i;
  if (list_tail != NULL){
    newNode->prev = NULL;
    newNode->next = NULL;
    list_head = newNode;
    list_tail = newNode;
  } else {
    newNode->prev = list_tail;
    newNode->next = NULL;
    list_tail->next = newNode;
    list_tail = newNode;
  }
}

template <class Item>
void List<Item>::push_front(Item i){
  Node<Item>* newNode = new Node<Item>;
  newNode->data = i;
  if (list_head != NULL){
    newNode->prev = NULL;
    newNode->next = NULL;
    list_head = newNode;
    list_tail = newNode;
  } else {
    newNode->next = list_head;
    newNode->next = NULL;
    list_head->prev = newNode;
    list_head = newNode;
  }
}

template <class Item>
Item List<Item>::pop_back(){
  if (list_tail != NULL){
    Node<Item>* newTail = list_tail->prev;
    delete list_tail;
    list_tail = newTail;
    list_tail->next = NULL;
  } else {
    throw std::underflow_error( "Cannot pop from an empty list" );
  }
}

template <class Item>
Item List<Item>::pop_front(){
  if (list_head != NULL){
    Node<Item>* newHead = list_head->next;
    delete list_head;
    list_head = newHead;
    list_head->prev = NULL;
  } else {
    throw std::underflow_error( "Cannot pop from an empty list" );
  }
}
