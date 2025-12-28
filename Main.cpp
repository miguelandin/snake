#include "Game.h"
#include <unordered_map>

int main() {
  RenderConfig theme = {40,  20,  "█", "║", "█", "║",
                        "═", "╔", "╗", "╚", "╝", " "};
  std::unordered_map<char, Action> controls;
  controls['w'] = Action::UP;
  controls['s'] = Action::DOWN;
  controls['a'] = Action::LEFT;
  controls['d'] = Action::RIGHT;
  controls[' '] = Action::PRESS;
  controls['q'] = Action::EXIT;

  Game game = Game(theme, controls);
  game.play();
}
