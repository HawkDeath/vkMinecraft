#include "Engine.h"
#include "../Log/Log.h"
namespace Engine {

Engine::Engine() { mWindow = std::make_unique<Window>(); }

Engine::~Engine() {}
void Engine::init() {
  LOG("Engine init")
  mWindow->init();
}
void Engine::run() { glfwPollEvents(); }
} // namespace Engine