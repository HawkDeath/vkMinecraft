#pragma once

#include "Common/Utils.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace Engine {

class InternLog {
public:
  InternLog() {
    try {
      std::vector<spdlog::sink_ptr> outputs(2);

      auto console_sink =
          std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
      auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
          "log_" + Intern::current_time_and_date() + ".txt", true);
      outputs[0] = std::move(console_sink);
      outputs[1] = std::move(file_sink);
      logger = std::make_shared<spdlog::logger>("InternLogger", outputs.begin(),
                                                outputs.end());
    } catch (spdlog::spdlog_ex &e) {
      std::printf(e.what());
    }
  }
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
  std::shared_ptr<spdlog::logger> logger;
};

} // namespace Engine

static Engine::InternLog mainLogger() {
  static Engine::InternLog log;
  return log;
};

#define LOG(...)                                                               \
  do {                                                                         \
    mainLogger().info(__VA_ARGS__);                                            \
  } while (0);

#define WLOG(...)                                                              \
  do {                                                                         \
    mainLogger().warn(__VA_ARGS__);                                            \
  } while (0);

#define ELOG(...)                                                              \
  do {                                                                         \
    mainLogger().error(__VA_ARGS__);                                           \
  } while (0);

