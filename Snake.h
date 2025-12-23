#pragma once
#include "Coordinates.h"
#include "LinkedList.h"

enum Direction { UP = 1, DOWN = -1, LEFT = 2, RIGHT = -2 };

class Snake {
  Direction direction;
  Direction lastDirection;
  LinkedList body;

  void performStep(const Coordinates &head, const Coordinates &fruit);

public:
  Snake();

  void setDirection(Direction direction);

  bool havesColision();

  void move(const Coordinates &fruit);

  void warp(const Coordinates &newLocation, const Coordinates &fruit);

  int getScore();

  Coordinates getHeadCoords();
};
