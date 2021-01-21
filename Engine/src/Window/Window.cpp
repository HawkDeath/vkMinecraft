#include "Window/Window.h"

#include "Log/Log.h"

namespace Engine {

Window::Window() : mGlfwWindow(nullptr), mInput(nullptr) {
  glfwSetErrorCallback([](int errorCode, const char *description) -> void {
    ELOG("[GLFW Error] Code {0}, description: {1}", errorCode, description)
  });

  if (glfwInit() != GLFW_TRUE) {
    exit(0); // TODO: make better solution
  }
  LOG("GLFW version: {0}.{1}.{2}", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR,
      GLFW_VERSION_REVISION)

  // only for Vulkan
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  // TODO: Graphic API should decide, what do:
  // For OpenGL
  //     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  //     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  mGlfwWindow = glfwCreateWindow(1280, 720, "vkMinecraft", nullptr, nullptr);
  if (!mGlfwWindow) {
    glfwTerminate();
    exit(0); // TODO: same as below
  }
  mInput = std::make_unique<Input>(mGlfwWindow);
  glfwSetWindowUserPointer(mGlfwWindow, this);
  glfwSetKeyCallback(mGlfwWindow, &handleKeyCallback);
}

Window::~Window() {
  if (mGlfwWindow) {
    glfwDestroyWindow(mGlfwWindow);
  }
  glfwTerminate();
}

void Window::update() const {
  // update input
  glfwPollEvents();
  // foreach all registered intput events

  mInput->update();

  int key = glfwGetKey(mGlfwWindow, GLFW_KEY_ESCAPE);
  if (key == GLFW_PRESS) {
    exit(0);
  }
}

void Window::handleKeyCallback(GLFWwindow *window, int key, int scancode,
                             int action,
                       int mods) {
  auto *window_ = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
  auto *input = window_->mInput.get();
  // input->keyCallback();
}

} // namespace Engine