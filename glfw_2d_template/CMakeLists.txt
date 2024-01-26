set(NAME "glfw_program")

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

cmake_minimum_required(VERSION 3.10)
project(${NAME})

add_executable(${NAME} main.c)

target_link_libraries(${NAME} glfw)
target_link_libraries(${NAME} GL)
