cmake_minimum_required(VERSION 3.22)

project(WarmUp-MovingOn-StartTheGame)

set(SRC
        src/main.cpp src/empty.cpp)

add_executable(${PROJECT_NAME}-run ${SRC})

prepare_sfml_framework_lesson_task(
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
    ${PROJECT_NAME}-run
    ""
)