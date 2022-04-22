cmake_minimum_required(VERSION 2.8)

project(01\ -\ Basic\ C++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(taskA exercise_A.cpp)
add_executable(taskB exercise_B.cpp)
