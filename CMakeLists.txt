cmake_minimum_required(VERSION 3.6)
project(scaling-disco)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libstdc++")
set(CMAKE_BUILD_TYPE Release)
set(SFML_ROOT "C:\\Program Files (x86)\\SFML")

set(SOURCE_FILES
        main.cpp)

add_executable(scaling-disco ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${SFML_ROOT}\\cmake\\Modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(scaling-disco ${SFML_LIBRARIES})
endif()