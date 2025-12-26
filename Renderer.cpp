#include "Renderer.h"

Renderer::Renderer(const RenderConfig &config) : config(config) {
  for (int i = 0; i < CACHE_SIZE; i++)
    rendererCache[i] = config.emptySpace;

  rendererCache[MapId::EMPTY] = config.emptySpace;
  rendererCache[MapId::WALL_H] = config.horizontalBorder;
  rendererCache[MapId::WALL_V] = config.verticalBorder;
  rendererCache[MapId::BODY] = config.bodySkin;
  rendererCache[MapId::HEAD] = config.headSkin;
  rendererCache[MapId::CORNER_TL] = config.topLeftCorner;
  rendererCache[MapId::CORNER_TR] = config.topRightCorner;
  rendererCache[MapId::CORNER_BL] = config.bottomLeftCorner;
  rendererCache[MapId::CORNER_BR] = config.bottomRightCorner;
  rendererCache[MapId::FRUIT] = config.fruitSkin;

  map = new char *[config.height + 1];
  for (int row = 0; row <= config.height; row++) {
    map[row] = new char[config.width + 1];
    for (int col = 0; col <= config.width; col++) {
      if (row == 0 || row == config.height)
        map[row][col] = MapId::WALL_H;
      else if (col == 0 || col == config.width)
        map[row][col] = MapId::WALL_V;
      else
        map[row][col] = MapId::EMPTY;
    }
  }

  map[0][0] = MapId::CORNER_TL;
  map[0][config.width] = MapId::CORNER_TR;
  map[config.height][0] = MapId::CORNER_BL;
  map[config.height][config.width] = MapId::CORNER_BR;

  std::cout << Terminal::CLEAR_SCREEN << Terminal::HIDE_CURSOR << std::flush;
}

Renderer::~Renderer() {
  for (int row = 0; row <= config.height; row++)
    delete[] map[row];

  delete[] map;

  std::cout << Terminal::SHOW_CURSOR << Terminal::COLOR_RESET << std::flush;
}

void Renderer::clearMap() {
  for (int row = 1; row < config.height; row++)
    memset(&map[row][1], MapId::EMPTY, config.width - 1);
}

void Renderer::renderSnake(const Snake &snake) {
  snake.forEach([&](Coordinates c) { map[c.y][c.x] = MapId::BODY; });
  Coordinates head = snake.getHeadCoords();
  map[head.y][head.x] = MapId::HEAD;
}

void Renderer::renderFruit(const Coordinates &fruit) {
  map[fruit.y][fruit.x] = MapId::FRUIT;
}

void Renderer::render(const Snake &snake, const Coordinates &fruit) {
  clearMap();
  renderFruit(fruit);
  renderSnake(snake);

  std::stringstream ss;
  ss << Terminal::CURSOR_HOME;

  for (int row = 0; row <= config.height; row++) {
    for (int col = 0; col <= config.width; col++) {
      unsigned char id = (unsigned char)map[row][col];
      ss << rendererCache[id] << rendererCache[id];
    }
    ss << '\n';
  }
  std::cout << ss.str();
}
