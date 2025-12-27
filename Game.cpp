#include "Game.h"
#include "Coordinates.h"
#include <unistd.h>

Game::Game(const RenderConfig &config)
    : input(), config(config),
      snake(Coordinates(config.width / 2, config.height / 2)), renderer(config),
      isPaused(false), rng(std::random_device{}()) {}

Coordinates Game::spawnFruit() {
  std::uniform_int_distribution<int> randX(1, config.width - 1);
  std::uniform_int_distribution<int> randY(1, config.height - 1);

  return Coordinates(randX(rng), randY(rng));
}

void Game::play() {
  Coordinates fruit = spawnFruit();
  Coordinates warp;
  while (!snake.hasColision()) {
    renderer.render(snake, fruit);
    input.setInput(snake);
    if (snake.move(fruit, config.height, config.width))
      fruit = spawnFruit();
    usleep(sleepTime);
  }
}
