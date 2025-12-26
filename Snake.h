#pragma once
#include "Coordinates.h"
#include "LinkedList.h"

enum class Direction { UP = 1, DOWN = -1, LEFT = 2, RIGHT = -2 };

class Snake {
  Direction direction;
  Direction lastDirection;
  LinkedList body;

  bool performStep(const Coordinates &head, const Coordinates &fruit);

public:
  Snake(const Coordinates &startCoords);

  Snake(const LinkedList &list, Direction direction);

  void setDirection(Direction direction);

  bool hasColision();

  bool move(const Coordinates &fruit);

  bool warp(const Coordinates &newLocation, const Coordinates &fruit);

  int getScore();

  Coordinates getHeadCoords() const;

  void forEach(const std::function<void(Coordinates)> &action) const;
};
