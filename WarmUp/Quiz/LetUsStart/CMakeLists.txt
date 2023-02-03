cmake_minimum_required(VERSION 3.22)

project(WarmUp-Quiz-LetUsStart)

set(CMAKE_CXX_STANDARD 14)

set(SRC
        src/main.cpp)

add_executable(${PROJECT_NAME}-run ${SRC})