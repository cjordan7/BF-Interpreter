cmake_minimum_required(VERSION 2.8.9)

project(BFInterpreter)

set(SOURCES src/main.cpp src/bf.cpp)


# include_directories(include)
add_executable(bfInterpreter ${SOURCES})
