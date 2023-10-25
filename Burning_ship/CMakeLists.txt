cmake_minimum_required(VERSION 3.0)
project(Burning_ship)
set(SOURCE main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})


add_subdirectory(Drawing)
include_directories(Drawing)
target_link_libraries(Burning_ship Drawing)


find_package(SFML COMPONENTS graphics REQUIRED)
target_link_libraries(Burning_ship sfml-graphics)
include_directories(${SFML_INCLUDE_DIR})

