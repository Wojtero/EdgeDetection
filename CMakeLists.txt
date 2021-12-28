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
        include/EdgeDetection.hpp
        source/EdgeDetection/PixelMatrix.cpp include/EdgeDetection/PixelMatrix.hpp
        source/EdgeDetection/Filter.cpp include/EdgeDetection/Filter.hpp
        source/EdgeDetection/NoiseReductionFilter.cpp include/EdgeDetection/NoiseReductionFilter.hpp
        source/EdgeDetection/GradientSuppression.cpp include/EdgeDetection/GradientSuppression.hpp
        source/EdgeDetection/Vector2Int.cpp include/EdgeDetection/Vector2Int.hpp
        source/EdgeDetection/InputParser.cpp include/EdgeDetection/InputParser.hpp source/EdgeDetection/HorizontalSobelFilter.cpp include/EdgeDetection/HorizontalSobelFilter.hpp source/EdgeDetection/VerticalSobelFilter.cpp include/EdgeDetection/VerticalSobelFilter.hpp)

target_include_directories(EdgeDetection PUBLIC ${INCLUDE_DIRS})
