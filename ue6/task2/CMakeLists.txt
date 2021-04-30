cmake_minimum_required(VERSION 3.17)
project(task2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task2
        flock.cpp
        flock.h
        fur.cpp
        fur.h
        main.cpp
        scientist.cpp
        scientist.h
        sheep.cpp
        sheep.h)
