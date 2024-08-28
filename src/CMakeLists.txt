cmake_minimum_required(VERSION 3.28)
project(OASystem)

set(CMAKE_CXX_STANDARD 11)

add_executable(OASystem
        OAUtils.cpp
        ../inc/OASystemUI.h
        ../inc/OAUtils.h
        OASystemUI.cpp
        main.cpp)
