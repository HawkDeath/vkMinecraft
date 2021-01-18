#pragma once
#if ((WIN32_ || WIN32) && (_MSC_VER > 1200))
#pragma warning(disable : 4996)
#endif

#include <string>

namespace Engine::Intern {
std::string current_time_and_date();
}