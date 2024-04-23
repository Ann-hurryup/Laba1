cmake_minimum_required(VERSION 3.26)
project(1)

set(CMAKE_CXX_STANDARD 17)

# Добавление в проект lib, bin
add_subdirectory(lib)
add_subdirectory(bin)
add_subdirectory(services)


enable_testing()
add_subdirectory(tests)
