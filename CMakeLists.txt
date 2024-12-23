cmake_minimum_required(VERSION 3.10)

# Project name and language
project(cite LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(cite src/main.cpp)