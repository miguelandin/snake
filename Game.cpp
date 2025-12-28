#include "Game.h"
#include <unordered_map>

Game::Game(const RenderConfig &config,
           const std::unordered_map<char, Action> &controls)
    : input(controls), config(config),
      snake(Coordinates(config.width / 2, config.height / 2)), renderer(config),
      isPaused(false), rng(std::random_device{}()) {}

Coordinates Game::spawnFruit() {
  std::uniform_int_distribution<int> randX(1, config.width - 1);
  std::uniform_int_distribution<int> randY(1, config.height - 1);

  return Coordinates(randX(rng), randY(rng));
}

void Game::play() {
  Coordinates fruit = spawnFruit();
  bool paused = false;

  while (!snake.hasColision()) {
    renderer.render(snake, fruit);
    input.setInput(snake);

    if (!paused) {
      Action nextAction = input.getNextAction();
      switch (nextAction) {
      case Action::UP:
        snake.setDirection(Direction::UP);
        break;
      case Action::DOWN:
        snake.setDirection(Direction::DOWN);
        break;
      case Action::LEFT:
        snake.setDirection(Direction::LEFT);
        break;
      case Action::RIGHT:
        snake.setDirection(Direction::RIGHT);
        break;
      case Action::PRESS:
        paused = !paused;
        break;
      case Action::NOTHING:
        break;
      case Action::EXIT:
        return;
      }

      if (snake.move(fruit, config.height, config.width))
        fruit = spawnFruit();
    } else {
      Action nextAction = input.getNextAction();
      switch (nextAction) {
      case Action::PRESS:
        paused = !paused;
        break;
      case Action::EXIT:
        return;
      default:
        break;
      }
    }

    usleep(sleepTime);
  }
}
