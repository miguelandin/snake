#pragma once
#include "Coordinates.h"
#include "Nodo.h"
#include <functional>
#include <iostream>

class LinkedList {
  int length;
  Node *list;

public:
  LinkedList();

  void insert(const Coordinates &c);

  void update(const Coordinates &c);

  void printContent();

  int getLength();

  Coordinates getHeadCoords() const;

  Coordinates getCoords(int index);

  void forEach(const std::function<void(Coordinates)> &action) const;

  ~LinkedList();
};
