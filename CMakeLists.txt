cmake_minimum_required(VERSION 3.10)
project(Employee)

set(CMAKE_CXX_STANDARD 17)

# Google Test
add_subdirectory(googletest)
enable_testing()
include_directories(googletest/googletest/include googletest/googlemock/include)

# The bad part
add_library(Stack Stack/Stack.cpp Stack/Stack.h)

add_executable(StackMain Stack/Main.cpp)
target_link_libraries(StackMain Stack)

# Tests for the bad part
add_executable(StackTest Stack/StackTest.cpp)
target_link_libraries(StackTest Stack gtest gtest_main)
add_test(StackTest StackTest)
