#pragma once

#include <GLFW/glfw3.h>

// TODO:
// > bind a Input class to GLFW
// > action system, input->register(ActionDescription , [](const Action &) -> void {})

namespace Engine {
class Input {
  friend class Window;

public:

private:
  Input(GLFWwindow *window);
  void update();

private:
  GLFWwindow *mWindow;
};

} // namespace Engine