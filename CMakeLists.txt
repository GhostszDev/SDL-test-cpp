cmake_minimum_required(VERSION 3.14)
project(test)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_PATH "/Users/stevenrivera/Downloads/SDL2-2.0.10/i686-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIR} )

add_executable(test main.cpp Classes/Window/Window.cpp Classes/Window/Window.h)

target_link_libraries(test ${SDL2_LIBRARY})