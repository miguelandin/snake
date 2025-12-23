#pragma once

struct Coordinates {
  int x;
  int y;

  Coordinates(int x, int y) {
    this->x = x;
    this->y = y;
  }

  Coordinates() : Coordinates(0, 0) {}

  bool operator==(const Coordinates &other) const {
    return (x == other.x && y == other.y);
  }

  bool operator!=(const Coordinates &other) const { return !(*this == other); }
};
