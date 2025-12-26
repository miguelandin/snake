#pragma once
#include "Coordinates.h"
#include "Snake.h"
#include "cstring"
#include <iostream>
#include <sstream>

struct RenderConfig {
  int width;
  int height;
  const char *headSkin;
  const char *bodySkin;
  const char *fruitSkin;
  const char *verticalBorder;
  const char *horizontalBorder;
  const char *topLeftCorner;
  const char *topRightCorner;
  const char *bottomLeftCorner;
  const char *bottomRightCorner;
  const char *emptySpace;
};

namespace Terminal {
constexpr const char *CLEAR_SCREEN = "\x1b[2J";
constexpr const char *CURSOR_HOME = "\x1b[H";
constexpr const char *HIDE_CURSOR = "\x1b[?25l";
constexpr const char *SHOW_CURSOR = "\x1b[?25h";
constexpr const char *COLOR_RESET = "\x1b[0m";
constexpr const char *COLOR_GREEN = "\x1b[32m";
constexpr const char *COLOR_RED = "\x1b[31m";
} // namespace Terminal

namespace MapId {
const char EMPTY = 0;
const char HEAD = 1;
const char BODY = 2;
const char FRUIT = 3;
const char WALL_V = 4;
const char WALL_H = 5;
const char CORNER_TL = 6;
const char CORNER_TR = 7;
const char CORNER_BL = 8;
const char CORNER_BR = 9;
} // namespace MapId

class Renderer {
  const RenderConfig config;
  char **map;
  static constexpr int CACHE_SIZE = 256;
  const char *rendererCache[CACHE_SIZE];

  void clearMap();

  void renderSnake(const Snake &snake);

  void renderFruit(const Coordinates &fruit);

public:
  Renderer(const RenderConfig &config);

  ~Renderer();

  void render(const Snake &snake, const Coordinates &fruit);
};
