# CMake Requirements and Setup

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
message(STATUS "CMake version: ${CMAKE_VERSION}")

project(RayTracer)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -O3)
add_executable(a.out main.cpp)