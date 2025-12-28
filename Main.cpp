#include "Game.h"

RenderConfig theme = {40, 20, "█", "║", "█", "║", "═", "╔", "╗", "╚", "╝", " "};

int main() {
  Game game = Game(theme);
  game.play();
}
