#include "Test.h"
#include <spdlog/spdlog.h>

int main() {
  spdlog::info("sum = {}", Test::sum(654, 15));
  std::getchar();
  return 0;
}