#pragma once

#include <Engine.h>

#include <memory>

namespace vkMinecraft {
class Game {
public:
  explicit Game();
  ~Game();

  void run();

private:
  void initialize();
  void shutdown();

private:
  bool mIsGameRunning;
  std::unique_ptr<Engine::Engine> mEngine;
};

} // namespace vkMinecraft