#include "Game.h"

#include <Log/Log.h>

namespace vkMinecraft {

Game::Game() : mIsGameRunning(false), mEngine(nullptr) {}
Game::~Game() {}

void Game::run() {
  initialize();
  mIsGameRunning = true;
  mEngine = std::make_unique<Engine::Engine>();
  if (!mEngine->initialize()) {
    ELOG("[Engine] Failed to initialize engine")
    return;
  }

  initialize();

  while (mIsGameRunning) {
    mEngine->run();
   
  }
  shutdown();
}
void Game::initialize() { LOG("[Game] Initialize") } // namespace vkMinecraft
void Game::shutdown() { LOG("[Game] Shutdown") }
} // namespace vkMinecraft