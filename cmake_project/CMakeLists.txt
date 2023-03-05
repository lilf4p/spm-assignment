cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17) 
project(cmake_project VERSION 0.1.0)

include_directories(include)
add_executable(cmake_project main.cpp ./include/utils.cpp)

