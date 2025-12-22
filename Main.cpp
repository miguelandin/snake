#include "Coordinates.h"
#include "LinkedList.h"
#include <iostream>

void printStuff(Coordinates c) { std::cout << c.x << ", " << c.y << std::endl; }

int main() {
  LinkedList *list = new LinkedList();
  list->insert(Coordinates(1, 1));
  list->printContent();
  list->update(Coordinates(4, 2));
  list->insert(Coordinates(9, 9));
  list->insert(Coordinates(9, 9));
  list->insert(Coordinates(9, 9));
  list->insert(Coordinates(9, 9));
  list->insert(Coordinates(9, 9));
  list->insert(Coordinates(9, 9));
  list->forEach(printStuff);
}
