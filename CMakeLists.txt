cmake_minimum_required(VERSION 3.10)

#Set project name
project(RayTracing CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cc)