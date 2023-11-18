cmake_minimum_required(VERSION 3.0)
project(harmonymix)
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs")  

file(GLOB SRC_FILES src/*.cpp)

add_subdirectory(tests)
add_subdirectory(src/jsoncpp)


add_executable(harmonymix ${SRC_FILES})

get_target_property(JSON_INC_PATH jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)
include_directories(${JSON_INC_PATH})

target_include_directories(harmonymix PRIVATE headers)
target_compile_features(harmonymix PRIVATE cxx_std_17)
target_link_libraries(harmonymix PRIVATE stdc++fs jsoncpp_lib)