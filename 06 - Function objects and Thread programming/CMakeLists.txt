cmake_minimum_required(VERSION 3.17)
project(06\ -\ Function\ objects\ and\ Thread\ programming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

add_executable(Exercise1 Exercise1.cpp)

# Adding Boost.Asio to exercise2
find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
add_executable(Exercise2 Exercise2.cpp)
target_link_libraries(Exercise2 ${Boost_LIBRARIES})