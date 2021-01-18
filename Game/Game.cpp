#include "Game.h"

#include <Log/Log.h>

namespace vkMinecraft {

Game::Game() : mIsGameRunning(false) {}
Game::~Game() {}

void Game::run() {
  initialize();
  mIsGameRunning = true;
  std::unique_ptr<Engine::Engine> mEngine = std::make_unique<Engine::Engine>();
  mEngine->init();
  WLOG("Warning test")
  ELOG("Error test")
  while (mIsGameRunning) {
    mEngine->run();
    int key = glfwGetKey(mEngine->getWin(), GLFW_KEY_ESCAPE);
    if (key == GLFW_PRESS) {
      mIsGameRunning = false;
      LOG("Exit...")
    }
  }
  shutdown();
}
void Game::initialize() { LOG("Initialize") } // namespace vkMinecraft
void Game::shutdown() { LOG("Shutdown") }
} // namespace vkMinecraft