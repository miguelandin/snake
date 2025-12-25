#include "Snake.h"

Snake::Snake() : Snake(LinkedList(), LEFT) { body.insert(Coordinates()); }

Snake::Snake(const LinkedList &list, Direction direction)
    : body(list), direction(direction), lastDirection(direction) {}

void Snake::setDirection(Direction direction) {
  if (this->lastDirection + direction != 0)
    this->direction = direction;
}

void Snake::move(const Coordinates &fruit) {
  Coordinates newHead = body.getHeadCoords();

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

bool Snake::hasColision() {
  Coordinates head = body.getHeadCoords();
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

Coordinates Snake::getHeadCoords() const { return body.getHeadCoords(); }

void Snake::performStep(const Coordinates &head, const Coordinates &fruit) {
  if (head == fruit)
    body.insert(head);
  else
    body.update(head);

  lastDirection = direction;
}

void Snake::forEach(const std::function<void(Coordinates)> &action) const {
  body.forEach(action);
}
