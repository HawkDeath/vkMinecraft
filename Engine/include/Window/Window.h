#pragma once

#include <GLFW/glfw3.h>

namespace Engine {
class Window {
public:
  explicit Window();
  ~Window();
  void init();

  GLFWwindow *getWin() const { return mGlfwWindow; }

private:
  GLFWwindow *mGlfwWindow;
};

} // namespace Engine