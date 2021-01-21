#pragma once

#include <Input/Input.h>

#include <GLFW/glfw3.h>
#include <memory>

namespace Engine {
class Window {
  friend class Engine;

public:
  Window();
  ~Window();

  bool shouldClose() { return glfwWindowShouldClose(mGlfwWindow); }

private:
  void update() const;

  // Input system
  static void handleKeyCallback(GLFWwindow *window, int key, int scancode,
                                int action, int mods);

private:
  GLFWwindow *mGlfwWindow;
  std::unique_ptr<Input> mInput;
};

} // namespace Engine