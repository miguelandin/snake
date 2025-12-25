#include "Coordinates.h"
#include "Renderer.h"
#include "Snake.h"

int main() {
  RenderConfig defaultTheme = {40,  20,  'O', 'o', '@', '|',
                               '-', '#', '#', '#', '#', ' '};
  Snake snake = Snake();
  Renderer renderer = Renderer(defaultTheme);
  renderer.render(snake, Coordinates(10, 20));
}
