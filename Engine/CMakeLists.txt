cmake_minimum_required(VERSION 3.10)
project(vkMinecraft-Engine)

include_directories(${CMAKE_SOURCE_DIR}/3part)

include_directories(${CMAKE_SOURCE_DIR})

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_library(${PROJECT_NAME} STATIC Test.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC vulkan volk_headers glm glfw spdlog_header_only EnTT)