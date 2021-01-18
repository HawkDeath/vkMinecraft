#pragma once

#include "../Common/ExporterSymbol.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace Engine {

class VOXEL_EXPORT InternLog {
public:
  template <typename... Args> void info(Args &&... args) {
    logger->info(std::forward<Args>(args)...);
  }

  template <typename... Args> void warn(Args &&... args) {
    logger->warn(std::forward<Args>(args)...);
  }

  template <typename... Args> void error(Args &&... args) {
    logger->error(std::forward<Args>(args)...);
  }

private:
  std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("console");
};

static InternLog mainLogger() {
  static InternLog log;
  return log;
};
} // namespace Engine

#ifdef MINECRAFT_LOGGER_ENABLE
#define LOG(...)                                                               \
  do {                                                                         \
    Engine::mainLogger().info(__VA_ARGS__);                                    \
  } while (0);

#define WLOG(...)                                                              \
  do {                                                                         \
    Engine::mainLogger().warn(__VA_ARGS__);                                    \
  } while (0);

#define ELOG(...)                                                              \
  do {                                                                         \
    Engine::mainLogger().error(__VA_ARGS__);                                   \
  } while (0);

#else
#define LOG()
#define WLOG()
#define ELOG()
#endif // MINECRAFT_LOGGER_ENABLE
