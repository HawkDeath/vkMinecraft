cmake_minimum_required(VERSION 3.10)
project(vkMinecraft)

set(CMAKE_CXX_STANDARD_REQUIRED 20)

if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")
else() # GCC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
endif()

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output")
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin")
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output/lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/lib")

add_subdirectory(3part)
add_subdirectory(Engine)
add_subdirectory(Game)

add_dependencies(vkMinecraft-Game vkMinecraft-Engine)

if(MSVC)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Game)
endif()