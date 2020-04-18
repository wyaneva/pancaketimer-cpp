cmake_minimum_required(VERSION 3.10)

# Set the project name
project(pancaketimer)

# Specify the C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Add the source files
add_subdirectory(src)

