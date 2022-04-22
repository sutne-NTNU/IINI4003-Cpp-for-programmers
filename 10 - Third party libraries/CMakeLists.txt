cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs/cmake")

project(10\ -\ Third\ party\ libraries)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include \"${PROJECT_SOURCE_DIR}/libs/imgui-sfml/imconfig-SFML.h\" -std=c++1y -Wall -Wextra -Wno-reorder -Wno-ignored-qualifiers")

if(APPLE)
  add_definitions(-DGL_SILENCE_DEPRECATION)
endif()

find_package(SFML 2.1 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIR})

find_package(Bullet REQUIRED)
include_directories(${BULLET_INCLUDE_DIRS})

find_package(Threads REQUIRED)

include_directories(libs/imgui libs/imgui-sfml)

add_executable(Assignment10 main.cpp libs/glut_shapes.c libs/imgui/imgui.cpp libs/imgui/imgui_widgets.cpp libs/imgui/imgui_draw.cpp libs/imgui-sfml/imgui-SFML.cpp)

target_link_libraries(Assignment10 ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Assignment10 ${SFML_LIBRARIES})
target_link_libraries(Assignment10 ${OPENGL_LIBRARIES})
target_link_libraries(Assignment10 ${BULLET_LIBRARIES})
