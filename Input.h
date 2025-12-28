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
  struct termios oldSettings, newSettings;
  std::deque<Action> actionQueue;
  std::unordered_map<char, Action> keyMap;

public:
  Input(char up, char down, char left, char right, char press, char exit);

  ~Input();

  void setInput(const Snake &snake);

  Action getNextAction();
};
