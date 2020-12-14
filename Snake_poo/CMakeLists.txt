cmake_minimum_required(VERSION 3.0.0)
project(snake VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(include)

set(SOURCES src/board.cpp src/display.cpp src/food.cpp src/game.cpp src/internals.cpp src/snake.cpp include/Board.h include/config.h include/display.h include/food.h include/game.h include/internals.h include/Snake.h)

add_executable(snake main.cpp ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
