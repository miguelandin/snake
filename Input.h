#include "Snake.h"
#include <termios.h>
#include <unistd.h>

enum class Action { NOTHING, MOVE, PRESS, EXIT };
class Input {
  struct termios oldSettings, newSettings;

public:
  Input();

  ~Input();

  Action setInput(Snake &snake);
};
