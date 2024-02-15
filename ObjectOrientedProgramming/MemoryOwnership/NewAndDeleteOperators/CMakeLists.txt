cmake_minimum_required(VERSION 3.26)

project(ObjectOrientedProgramming-MemoryOwnership-new_and_delete_operators)

set(CMAKE_CXX_STANDARD 14)

# Files from `./src` directory
set(SRC src/task.cpp src/book.cpp)

# Files from `./test` directory
set(TEST test/test.cpp)

# Running tests
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
configure_test_target(${PROJECT_NAME}-test "${SRC}" ${TEST})