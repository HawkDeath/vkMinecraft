#pragma once

#include "Window/Window.h"

#include <memory>

namespace Engine {
class Engine {
public:
  explicit Engine();
  ~Engine();
  
  bool initialize();

  void run();

private:
  std::unique_ptr<Window> mWindow;
};

}