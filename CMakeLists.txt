cmake_minimum_required(VERSION 3.0)
project(harmonymix)
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs")  

file(GLOB SRC_FILES src/*.cpp)

add_subdirectory(tests)
set(CMAKE_BUILD_TYPE Debug)

add_executable(harmonymix ${SRC_FILES})


target_include_directories(harmonymix PRIVATE headers headers/json)
target_compile_features(harmonymix PRIVATE cxx_std_17)
target_link_libraries(harmonymix PRIVATE stdc++fs)

target_compile_options(harmonymix PRIVATE -Wall -Wextra -pedantic -O0 --std=c++17 -lstdc++fs)
