cmake_minimum_required(VERSION 3.31)

project(cpp-patterns CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_CONFIGURATIONS_TYPE "Debug;Release")

add_subdirectory(src/abstract_factory)