#include "Snake.h"
#include <cctype>
#include <deque>
#include <termios.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>

enum class Action {
  NOTHING = 0,
  UP = 1,
  DOWN = -1,
  LEFT = 2,
  RIGHT = -2,
  PRESS = 3,
  EXIT = -3
};

class Input {
  std::unordered_map<char, Action> keyMap;
  std::deque<Action> actionQueue;
  struct termios oldSettings, newSettings;

public:
  Input(const std::unordered_map<char, Action> &customMap);

  ~Input();

  void setInput(const Snake &snake);

  Action getNextAction();
};
