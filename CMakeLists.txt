cmake_minimum_required(VERSION 3.6)
project(scaling-disco)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libstdc++ -static-libgcc")

set(SOURCE_FILES
        main.cpp)

add_executable(scaling-disco ${SOURCE_FILES})