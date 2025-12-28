#pragma once
#include "Coordinates.h"
#include "Input.h"
#include "Renderer.h"
#include "Snake.h"
#include <random>
#include <unordered_map>

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
  Game(const RenderConfig &config,
       const std::unordered_map<char, Action> &controls);

  void play();
};
