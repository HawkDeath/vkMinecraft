#pragma once

#include "../Window/Window.h"

#include <memory>

namespace Engine {
class Engine {
public:
  explicit Engine();
  ~Engine();
  
  void init();

  void run();

  GLFWwindow *getWin() const { return mWindow->getWin();
  }

private:
  std::unique_ptr<Window> mWindow;
};

}