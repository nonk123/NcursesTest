cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(NcursesTest)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

add_executable(NcursesTest "")
target_link_libraries(NcursesTest PRIVATE ${CURSES_LIBRARIES})
target_include_directories(NcursesTest PRIVATE include/ ${CURSES_INCLUDE_DIRS}) 
target_sources(NcursesTest
    PRIVATE
        src/main.cpp
        src/Game.cpp)
