#pragma once
#include "Coordinates.h"

struct Node {

  Coordinates coords;

  Node *next;

  Node *prev;

  Node(const Coordinates &coords, Node *next, Node *prev) {
    this->coords = coords;
    this->next = next;
    this->prev = prev;
  }

  Node(const Coordinates &coords) : Node(coords, nullptr, nullptr) {}

  Node() : Node(Coordinates(), nullptr, nullptr) {}
};
