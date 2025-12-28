#include "Input.h"

Input::Input(const std::unordered_map<char, Action> &customMap)
    : keyMap(customMap) {
  tcgetattr(STDIN_FILENO, &oldSettings);
  newSettings = oldSettings;

  newSettings.c_lflag &= ~(ICANON | ECHO);
  newSettings.c_cc[VMIN] = 0;
  newSettings.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

Input::~Input() { tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings); }

void Input::setInput(const Snake &snake) {
  char key;

  while (read(STDIN_FILENO, &key, 1) > 0) {
    char lowerKey = std::tolower(key);

    if (keyMap.find(lowerKey) == keyMap.end())
      continue;

    Action newAction = keyMap[lowerKey];

    if (newAction == Action::EXIT || newAction == Action::PRESS) {
      actionQueue.push_front(newAction);
      continue;
    }

    Action lastAction;

    if (!actionQueue.empty()) {
      lastAction = actionQueue.back();
    } else {
      lastAction = static_cast<Action>(snake.getDirection());
    }

    if (newAction != lastAction) {
      actionQueue.push_back(newAction);
    }
  }
}

Action Input::getNextAction() {
  if (actionQueue.empty())
    return Action::NOTHING;

  Action next = actionQueue.front();
  actionQueue.pop_front();
  return next;
}
