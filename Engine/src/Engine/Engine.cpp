#include "Engine.h"
#include "Log/Log.h"
namespace Engine {

Engine::Engine() : mWindow(nullptr) {}

Engine::~Engine() {}
bool Engine::initialize() {
  bool result = true;
  mWindow = std::make_unique<Window>();

  if (!mWindow)
    result = false;

  return result;
}
void Engine::run() { mWindow->update(); }
} // namespace Engine