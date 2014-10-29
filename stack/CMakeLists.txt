cmake_minimum_required(VERSION 2.8.4)
project(stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES My_stack.h My_stack.cpp My_calk.h My_calk.cpp My_scan_calk.h My_scan_calk.cpp main.cpp book.txt)
add_executable(stack ${SOURCE_FILES})