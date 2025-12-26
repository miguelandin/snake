#pragma once
#include "Coordinates.h"
#include "Input.h"
#include "Renderer.h"
#include "Snake.h"
#include <random>

class Game {
  Input input;
  RenderConfig config;
  Snake snake;
  Renderer renderer;
  bool isPaused;
  std::mt19937 rng;
  constexpr static int sleepTime = 100000;

  Coordinates spawnFruit();

public:
  Game(const RenderConfig &config);

  void play();
};
