cmake_minimum_required(VERSION 3.10)
project(vkMinecraft-Engine)

include_directories(${CMAKE_SOURCE_DIR}/3part)
include_directories(${CMAKE_SOURCE_DIR})

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(LOG_SOURCES 
    "Log/Log.h")
set(COMMON_SOURCES
    "Common/Utils.h"
    "Common/Utils.cpp")

set(WINDOW_SOURCES
    "Window/Window.h"
    "Window/Window.cpp")

set(ENGINE_SORUCES 
    "Engine/Engine.h"
    "Engine/Engine.cpp")
set(ENGINE_LIB_SOURCES ${LOG_SOURCES} ${COMMON_SOURCES} ${WINDOW_SOURCES} ${ENGINE_SORUCES})

add_library(${PROJECT_NAME} STATIC ${ENGINE_LIB_SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw vulkan volk_headers glm spdlog EnTT)