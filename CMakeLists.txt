cmake_minimum_required(VERSION 3.15)
project(Nutownik)


set(CMAKE_CXX_STANDARD 14)

find_library(SDL2 REQUIRED SDL2)
include_directories(${SDL2_INCLUDE_DIRS})


link_libraries(${CMAKE_SOURCE_DIR}/out/SDL2.dll)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lm -lSDL2")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)


FILE(GLOB_RECURSE SOURCE_FILES src/*)
add_executable(Nutownik ${SOURCE_FILES})

target_link_libraries(Nutownik -lm SDL2)
