#pragma once
#include "Nodo.h"

class LinkedList {
  Node *list;

  Node *getNextNode(Node *node);

public:
  LinkedList();

  Coordinates getCoordinates(Node *node);

  void insert(const Coordinates &c);

  void update(const Coordinates &c);

  ~LinkedList();
};
