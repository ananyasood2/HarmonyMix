CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(TestHarmonyMix)
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs")  

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runAllTests
    main.cpp
    user_test.cpp
    ../src/user.cpp
    userInterface_test.cpp
    playlist_test.cpp 
    ../src/playlist.cpp
    song_test.cpp
    ../src/song.cpp
    library_test.cpp 
    ../src/library.cpp
    ../src/jsoncpp.cpp
    ../src/db.cpp
)
target_include_directories(runAllTests PRIVATE ../headers/json)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)
target_link_libraries(runAllTests gmock gtest gtest_main stdc++fs)
target_include_directories(runAllTests  PRIVATE ../headers)
