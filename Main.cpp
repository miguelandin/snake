#include "Coordinates.h"
#include "Renderer.h"
#include "Snake.h"

RenderConfig theme = {60, 20, "●", "o", "★", "║", "═", "╔", "╗", "╚", "╝", " "};

int main() {
  Snake snake = Snake(Coordinates(theme.width / 2, theme.height / 2));
  Renderer renderer = Renderer(theme);
  renderer.render(snake, Coordinates(10, 10));
}
