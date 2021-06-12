cmake_minimum_required(VERSION 3.15)
project(MUZOWNIK)


set(CMAKE_CXX_STANDARD 14)

find_library(SDL2 REQUIRED SDL2)
include_directories(${SDL2_INCLUDE_DIRS})


link_libraries(${CMAKE_SOURCE_DIR}/SDL2.dll)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lm")

FILE(GLOB_RECURSE SOURCE_FILES src/*)
add_executable(MUZOWNIK ${SOURCE_FILES})

target_link_libraries(MUZOWNIK -lm SDL2)
