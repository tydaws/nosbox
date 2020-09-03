cmake_minimum_required(VERSION 3.17)
project(nosbox C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(src/shell)
add_subdirectory(src/commands)
add_subdirectory(src/disk)
add_subdirectory(src/filesystem)