cmake_minimum_required(VERSION 3.22)

project(WarmUp-Quiz-MaxInt)

set(CMAKE_CXX_STANDARD 14)

set(SRC
        src/task.cpp)

set(TEST
        test/test.cpp)

add_executable(${PROJECT_NAME}-run ${SRC})

configure_test_target(${PROJECT_NAME}-test ${SRC} ${TEST})