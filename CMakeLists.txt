# CMakeList.txt : CMake project for oop-lab-01, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (LabWork)

file (GLOB_RECURSE Lab_SRC
    "src/*.cpp"
    "src/*.h"
)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(config)

add_subdirectory(src/lib) # Main library
add_subdirectory(apps)    # Custom executables
add_subdirectory(tests)   # Unit tests
