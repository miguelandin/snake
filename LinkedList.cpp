#pragma once
#include "LinkedList.h"

LinkedList::LinkedList() {
  list = nullptr;
  length = 0;
}

int LinkedList::getLength() { return this->length; }

Coordinates LinkedList::getFirstCoords() { return list->coords; }

Coordinates LinkedList::getCoords(int index) {
  Node *temp = list;
  for (int i = 0; i < index && i < length - 1; i++)
    temp = temp->next;

  return temp->coords;
}

void LinkedList::update(const Coordinates &c) {
  Node *temp = list->prev;

  while (temp != list) {
    temp->coords = temp->prev->coords;
    temp = temp->prev;
  }

  temp->coords = c;
}

void LinkedList::insert(const Coordinates &c) {
  if (list == nullptr) {
    list = new Node(c);
    list->next = list;
    list->prev = list;
  } else {
    Node *tail = list->prev;
    Node *newNode = new Node(c, list, tail);
    list->prev = newNode;
    tail->next = newNode;
    list = newNode;
  }
  length++;
}

void LinkedList::printContent() {
  Node *temp = list;

  do {
    std::cout << "[" << temp->coords.x << ", " << temp->coords.y << "]";
    temp = temp->next;
  } while (temp != list);
  std::cout << std::endl;
}

void LinkedList::forEach(std::function<void(Coordinates)> action) {
  if (list == nullptr)
    return;

  Node *temp = list;
  do {
    action(temp->coords);
    temp = temp->next;
  } while (temp != list);
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
  length = 0;
}
