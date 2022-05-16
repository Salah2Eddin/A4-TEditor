cmake_minimum_required(VERSION 3.22)
project(A4_TEditor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A4_TEditor
        editor.cpp
        editor.h
        files.cpp
        files.h
        main.cpp)
