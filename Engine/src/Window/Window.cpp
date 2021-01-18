#include "Window/Window.h"

#include "Log/Log.h"

namespace Engine {

Window::Window() : mGlfwWindow(nullptr) { glfwInit(); }

Window::~Window() {
  glfwDestroyWindow(mGlfwWindow);
  glfwTerminate();
}

void Window::init() {
  LOG("GLFW version: {}.{}.{}", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR,
      GLFW_VERSION_REVISION)
  mGlfwWindow = glfwCreateWindow(800, 600, "test", nullptr, nullptr);
}
} // namespace Engine