#include "Snake.h"
#include "Coordinates.h"
#include "LinkedList.h"

Snake::Snake() {
  direction = LEFT;
  lastDirection = LEFT;
  body = LinkedList();
  body.insert(Coordinates(0, 0));
}

void Snake::setDirection(Direction direction) {
  if (this->lastDirection + direction != 0)
    this->direction = direction;
}

void Snake::move(const Coordinates &fruit) {
  Coordinates newHead = body.getFirstCoords();

  switch (direction) {
  case UP:
    newHead.y--;
    break;
  case DOWN:
    newHead.y++;
    break;
  case LEFT:
    newHead.x--;
    break;
  case RIGHT:
    newHead.x++;
    break;
  }

  performStep(newHead, fruit);
}

bool Snake::havesColision() {
  Coordinates head = body.getFirstCoords();
  bool colision = false;
  int i = 0;
  body.forEach([&](Coordinates c) {
    if (i > 0 && head == c)
      colision = true;
    i++;
  });

  return colision;
}

void Snake::warp(const Coordinates &newLocation, const Coordinates &fruit) {
  performStep(newLocation, fruit);
}

int Snake::getScore() { return body.getLength(); }

Coordinates Snake::getHeadCoords() { return body.getFirstCoords(); }

void Snake::performStep(const Coordinates &head, const Coordinates &fruit) {
  if (head == fruit)
    body.insert(head);
  else
    body.update(head);

  lastDirection = direction;
}
