#include "LinkedList.h"

LinkedList::LinkedList() { list = nullptr; };

Node *LinkedList::getNextNode(Node *node) { return node->next; }

Coordinates LinkedList::getCoordinates(Node *node) { return node->coords; }

void LinkedList::update(const Coordinates &c) {
  Node *last = list->prev;
  Node *temp = last;

  while (temp != list) {
    temp->coords = temp->prev->coords;
    temp = temp->prev;
  }

  temp->coords = c;
}

void LinkedList::insert(const Coordinates &c) {
  Node *newNode = new Node(c, list, list->prev);
  list->prev = newNode;
  list = newNode;
}

LinkedList::~LinkedList() {
  if (list == nullptr)
    return;

  list->prev->next = nullptr; // break cicle

  Node *temp = list;
  Node *nodeDelete;

  while (temp != nullptr) {
    nodeDelete = temp;
    temp = temp->next;
    delete nodeDelete;
  }

  list = nullptr;
}
