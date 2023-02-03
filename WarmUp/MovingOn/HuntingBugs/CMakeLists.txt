cmake_minimum_required(VERSION 3.22)

project(WarmUp-MovingOn-HuntingBugs)

set(TASK
        src/approaching.cpp)

set(SRC
        ${TASK} src/main.cpp
        src/move.cpp src/point.cpp src/direction.cpp src/borders.cpp src/collision.cpp src/generate.cpp src/loop.cpp)

add_executable(${PROJECT_NAME}-run ${SRC})

prepare_sfml_framework_lesson_task(
        "${CMAKE_CURRENT_SOURCE_DIR}/.."
        ${PROJECT_NAME}-run
        ""
)