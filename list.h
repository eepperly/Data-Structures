#ifndef _LIST_H
#define _LIST_H

template <class Item>
class List{
 public:
  List();

  void deep_copy_from(List& copyme);
  void clean_up();
  
  ~List();
  List operator=(List& rside);
  List(List& orig);
  
  Item head() const;
  Item tail() const;
  void push_back(Item i);
  void push_front(Item i);
  Item pop_back();
  Item pop_front();
 private:
  Node* head;
  Node* tail;
};

template <class Item>
struct Node{
  Item data;
  Node* next;
  Node* prev;
}

#endif
