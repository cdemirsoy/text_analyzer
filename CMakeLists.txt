# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)
project(TextAnalyzer)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -std=c++17")

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories(src)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
include_directories(${PROJECT_SOURCE_DIR})
add_executable(cmake_hello src/main.cpp src/SortedList.cpp src/TextAnalyzer.cpp)