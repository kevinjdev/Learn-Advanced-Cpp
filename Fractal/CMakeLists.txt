cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#add_definitions(-std=c++11)
set (CMAKE_CXX_STANDARD 11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(fractal)

add_executable(fractal src/main.cpp src/Bitmap.cpp src/FractalCreator.cpp src/Mandelbrot.cpp src/RGB.cpp src/ZoomList.cpp)