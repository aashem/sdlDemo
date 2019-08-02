cmake_minimum_required (VERSION 2.6)
project (Testing)
include_directories(${PROJECT_SOURCE_DIR})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(app main.cpp)
target_link_libraries(app ${SDL2_LIBRARIES})