#pragma once
#include "Coordinates.h"
#include "Snake.h"
#include "cstring"
#include <iostream>
#include <sstream>

struct RenderConfig {
  int width;
  int height;
  char headSkin;
  char bodySkin;
  char fruitSkin;
  char verticalBorder;
  char horizontalBorder;
  char topLeftCorner;
  char topRightCorner;
  char bottomLeftCorner;
  char bottomRightCorner;
  char emptySpace;
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

class Renderer {
  const RenderConfig config;
  char **map;

  void clearMap();

  void renderSnake(const Snake &snake);

  void renderFruit(const Coordinates &fruit);

public:
  Renderer(const RenderConfig &config);

  ~Renderer();

  void render(const Snake &snake, const Coordinates &fruit);
};
