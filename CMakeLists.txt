cmake_minimum_required(VERSION 3.10)
project(my_game C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
link_directories(lib)

add_executable(my_game main.c)

target_link_libraries(my_game raylib opengl32 gdi32 winmm)
