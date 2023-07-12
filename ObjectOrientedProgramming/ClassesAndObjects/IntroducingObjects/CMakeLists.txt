cmake_minimum_required(VERSION 3.25)

project(ObjectOrientedProgramming-ClassesAndObjects-IntroducingObjects)

set(TASK
        src/gobject.cpp)

set(SRC
        ${TASK} src/operators.cpp src/point.cpp)

set(TEST
        test/test.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include/)

configure_test_target(${PROJECT_NAME}-test ${SRC} ${TEST})