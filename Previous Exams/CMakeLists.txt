cmake_minimum_required(VERSION 3.17)
project(Previous_Exams)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(2019-Task-1 2019\ -\ December/Task\ 1.cpp)
add_executable(2019-Task-2 2019\ -\ December/Task\ 2.cpp)
add_executable(2019-Task-3 2019\ -\ December/Task\ 3.cpp)
add_executable(2019-Task-4 2019\ -\ December/Task\ 4.cpp)
add_executable(2019-Task-5 2019\ -\ December/Task\ 5.cpp)

add_executable(2020-Task-1 2020\ -\ May/Task\ 1.cpp)
add_executable(2020-Task-2 2020\ -\ May/Task\ 2.cpp)
add_executable(2020-Task-3 2020\ -\ May/Task\ 3.cpp)
add_executable(2020-Task-4 2020\ -\ May/Task\ 4.cpp)
add_executable(2020-Task-5 2020\ -\ May/Task\ 5.cpp)