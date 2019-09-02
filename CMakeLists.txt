# CMakeList.txt : CMake project for oop-lab-01, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (OOP-Lab01)

file (GLOB_RECURSE Lab_SRC
    "src/*.cpp"
    "src/*.h"
)

if (WIN32)
    if (MSVC)
        add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    endif ()
endif()

add_executable (lab ${Lab_SRC})
