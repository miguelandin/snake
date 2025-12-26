#include "Input.h"
#include "Snake.h"
#include <termios.h>
#include <unistd.h>

Input::Input() {
  tcgetattr(STDIN_FILENO, &oldSettings);
  newSettings = oldSettings;

  newSettings.c_lflag &= ~(ICANON | ECHO);
  newSettings.c_cc[VMIN] = 0;
  newSettings.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

Input::~Input() { tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings); }

Action Input::setInput(Snake &snake) {
  char key;
  if (read(STDIN_FILENO, &key, 1) <= 0)
    return Action::NOTHING;

  switch (std::tolower(key)) {
  case 'w':
    snake.setDirection(Direction::UP);
    return Action::MOVE;
  case 's':
    snake.setDirection(Direction::DOWN);
    return Action::MOVE;
  case 'a':
    snake.setDirection(Direction::LEFT);
    return Action::MOVE;
  case 'd':
    snake.setDirection(Direction::RIGHT);
    return Action::MOVE;
  case 'q':
    return Action::EXIT;
  case ' ':
    return Action::PRESS;
  default:
    return Action::NOTHING;
  }
}
