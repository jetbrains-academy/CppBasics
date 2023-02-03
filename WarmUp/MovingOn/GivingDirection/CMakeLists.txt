cmake_minimum_required(VERSION 3.22)

project(WarmUp-MovingOn-GivingDirection)

set(TASK
        src/direction.cpp)

set(SRC
        ${TASK} src/main.cpp
        src/move.cpp src/point.cpp)

set(TEST
        test/test.cpp)

add_executable(${PROJECT_NAME}-run ${SRC})

configure_test_target(${PROJECT_NAME}-test ${TASK} ${TEST})

prepare_sfml_framework_lesson_task(
        "${CMAKE_CURRENT_SOURCE_DIR}/.."
        ${PROJECT_NAME}-run
        ${PROJECT_NAME}-test
)