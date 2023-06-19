cmake_minimum_required(VERSION 3.16)
project(ListTest)

set(CMAKE_CXX_STANDARD 14)

# Add your source files
set(SOURCE_FILES 
    src/ListNode.h
    src/ListItr.h
    src/List.h
    test/tests.cpp)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})