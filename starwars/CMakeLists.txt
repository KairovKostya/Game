cmake_minimum_required(VERSION 3.17)
project(starwars)

set(CMAKE_CXX_STANDARD 17)


include_directories(${starwars_SOURCE_DIR}/objects)
include_directories(${starwars_SOURCE_DIR}/controller)
include_directories(${starwars_SOURCE_DIR}/output)
include_directories(${starwars_SOURCE_DIR}/input)
add_executable(starwars main.cpp)
