cmake_minimum_required(VERSION 3.22)

project(WarmUp-HelloWorld-FirstWords)

set(SRC
        src/main.cpp)

add_executable(${PROJECT_NAME}-run ${SRC})