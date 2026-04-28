cmake_minimum_required(VERSION 4.2)
project(tictactoe C)

set(CMAKE_C_STANDARD 23)

add_executable(tictactoe main.c
        data.h
)


target_link_libraries(tictactoe raylib m)