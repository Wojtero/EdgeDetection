cmake_minimum_required(VERSION 3.21)
project(EdgeDetection)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/external/CImg-3.0.0"
        )

add_executable(EdgeDetection
        app/App.cpp
        source/EdgeDetection/Utility.cpp include/EdgeDetection/Utility.hpp
        include/EdgeDetection/EdgeDetectionTypes.hpp
        include/EdgeDetection.hpp)

target_include_directories(EdgeDetection PUBLIC ${INCLUDE_DIRS})
