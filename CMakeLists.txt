cmake_minimum_required(VERSION 3.15)
project(libopvault)

message("Building with CMake version: ${CMAKE_VERSION}")

include_directories(include)
link_directories()
add_subdirectory(src)
enable_testing()
add_subdirectory(test)
