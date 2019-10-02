cmake_minimum_required(VERSION 3.14)
project(test)

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

add_executable(
        test
        main.cpp
        Classes/Window/Window.cpp
        Classes/Window/Window.h
        Classes/Checks/checks.cpp
        Classes/Checks/checks.h
        Classes/Controls/controls.cpp
        Classes/Controls/controls.h
)

target_link_libraries(
        test
        ${SDL2_LIBRARY}
        -lmingw32
        -lSDL2main
        -lSDL2
)