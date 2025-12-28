#include "Snake.h"

Snake::Snake(const Coordinates &startCoords)
    : direction(Direction::LEFT), lastDirection(Direction::LEFT) {
  body.insert(startCoords);
}

Snake::Snake(const LinkedList &list, Direction direction)
    : body(list), direction(direction), lastDirection(direction) {}

void Snake::setDirection(Direction direction) {
  if (static_cast<int>(this->lastDirection) + static_cast<int>(direction) != 0)
    this->direction = direction;
}

bool Snake::move(const Coordinates &fruit, int height, int width) {
  Coordinates newHead = body.getHeadCoords();

  switch (direction) {
  case Direction::UP:
    newHead.y--;
    break;
  case Direction::DOWN:
    newHead.y++;
    break;
  case Direction::LEFT:
    newHead.x--;
    break;
  case Direction::RIGHT:
    newHead.x++;
    break;
  }

  if (newHead.x >= width)
    newHead.x = 1;
  else if (newHead.x <= 0)
    newHead.x = width - 1;
  else if (newHead.y >= height)
    newHead.y = 1;
  else if (newHead.y <= 0)
    newHead.y = height - 1;

  return performStep(newHead, fruit);
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

int Snake::getScore() const { return body.getLength(); }

Direction Snake::getDirection() const { return direction; }

Coordinates Snake::getHeadCoords() const { return body.getHeadCoords(); }

bool Snake::performStep(const Coordinates &head, const Coordinates &fruit) {
  bool isEating = false;

  if (head == fruit) {
    body.insert(head);
    isEating = true;
  } else
    body.update(head);

  lastDirection = direction;

  return isEating;
}

void Snake::forEach(const std::function<void(Coordinates)> &action) const {
  body.forEach(action);
}
