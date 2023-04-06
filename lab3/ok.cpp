#include <iostream>

struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int key = 0;
};

struct List
{
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};
List* create_empty_list() {
    List* list = new List();
    list->NIL = new Node();
    list->NIL->prev = list->NIL;
    list->NIL->next = list->NIL;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    return list;
}

int main() {
  List* list = create_empty_list();
  
  return 0;
}