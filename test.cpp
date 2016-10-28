#include "list.h"
#include <string>
#include <iostream>

int main(){
  List<std::string> list;
  std::string temp;
  while (true){
    std::cout << "Enter a value to add to the front of the list or enter nothing to pop:";
    std::cin >> temp;
    if (temp != ""){
      list.push_front(temp);
    } else {
      list.pop_front();
    }
    std::cout << "Current state of list. Head: " << list.head() << " Tail: " << list.tail() << std::endl;

    std::cout << "Enter a value to add to the back of the list or enter nothing to pop:";
    std::cin >> temp;
    if (temp != ""){
      list.push_back(temp);
    } else {
      list.pop_back();
    }
    std::cout << "Current state of list. Head: " << list.head() << " Tail: " << list.tail() << std::endl;
  }
}
