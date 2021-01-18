cmake_minimum_required(VERSION 3.10)
project(vkMinecraft-Game)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Engine)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(${PROJECT_NAME} main.cpp "Game.h" "Game.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE vkMinecraft-Engine)