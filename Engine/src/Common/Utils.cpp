#include "Common/Utils.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace Engine::Intern {
std::string current_time_and_date() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  std::stringstream ss;
  ss << std::put_time(std::localtime(&in_time_t), "%Y_%m_%d_%H_%M_%S");
  return ss.str();
}
} // namespace Engine::Intern