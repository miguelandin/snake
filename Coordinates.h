#pragma once

struct Coordinates {
  int x;
  int y;

  Coordinates(int x, int y) {
    this->x = x;
    this->y = y;
  }

  Coordinates() : Coordinates(0, 0) {}
};
