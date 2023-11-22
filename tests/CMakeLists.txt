CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(TestHarmonyMix)
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs")  

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runAllTests
    user_test.cpp
    ../src/user.cpp
    userInterface_test.cpp
)

TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)
target_link_libraries(runAllTests gmock gtest gtest_main)
target_include_directories(runAllTests  PRIVATE ../headers)
