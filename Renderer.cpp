#include "Renderer.h"
#include <ostream>

Renderer::Renderer(const RenderConfig &config) : config(config) {
  map = new char *[config.height + 1];

  for (int row = 0; row <= config.height; row++)
    map[row] = new char[config.width + 1];

  for (int row = 0; row <= config.height; row++) {
    for (int col = 0; col <= config.width; col++) {
      if (row == 0 || row == config.height)
        map[row][col] = config.horizontalBorder;
      else if (col == 0 || col == config.width)
        map[row][col] = config.verticalBorder;
      else
        map[row][col] = config.emptySpace;
    }
  }

  map[0][0] = config.topLeftCorner;
  map[0][config.width] = config.topRightCorner;
  map[config.height][0] = config.bottomLeftCorner;
  map[config.height][config.width] = config.bottomRightCorner;

  std::cout << Terminal::CLEAR_SCREEN << Terminal::HIDE_CURSOR << std::flush;
}

Renderer::~Renderer() {
  for (int row = 0; row <= config.height; row++)
    delete[] map[row];

  delete map;

  std::cout << Terminal::SHOW_CURSOR << Terminal::COLOR_RESET << std::flush;
}

void Renderer::clearMap() {
  for (int row = 1; row < config.height; row++)
    memset(&map[row][1], config.emptySpace, config.width - 1);
}

void Renderer::renderSnake(const Snake &snake) {
  snake.forEach([&](Coordinates c) { map[c.y][c.x] = config.bodySkin; });
  Coordinates head = snake.getHeadCoords();
  map[head.y][head.x] = config.headSkin;
}

void Renderer::renderFruit(const Coordinates &fruit) {
  map[fruit.y][fruit.x] = config.fruitSkin;
}

void Renderer::render(const Snake &snake, const Coordinates &fruit) {
  clearMap();
  renderFruit(fruit);
  renderSnake(snake);

  std::stringstream ss;
  ss << Terminal::CURSOR_HOME;

  for (int row = 0; row <= config.height; row++) {
    ss.write(map[row], config.width + 1);
    ss << '\n';
  }

  std::cout << ss.str();
}
