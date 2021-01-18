cmake_minimum_required(VERSION 3.10)
project(vkMinecraft-Engine)

include_directories(${CMAKE_SOURCE_DIR}/3part)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})


set(COMMON_SOURCES
    "src/Common/Utils.cpp")

set(WINDOW_SOURCES
    "src/Window/Window.cpp")

set(ENGINE_SORUCES 
    "src/Engine/Engine.cpp")

set(ENGINE_LIB_SOURCES ${COMMON_SOURCES} ${WINDOW_SOURCES} ${ENGINE_SORUCES})

add_library(${PROJECT_NAME} STATIC ${ENGINE_LIB_SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw vulkan volk_headers glm spdlog EnTT)