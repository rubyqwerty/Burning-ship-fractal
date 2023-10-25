cmake_minimum_required(VERSION 3.0)
project(Drawing)		
include_directories(${SFML_INCLUDE_DIR})		
add_library(Drawing STATIC drawing.cpp)#
