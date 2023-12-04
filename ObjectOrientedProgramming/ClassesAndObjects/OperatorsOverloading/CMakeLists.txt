cmake_minimum_required(VERSION 3.25)

project(ObjectOrientedProgramming-ClassesAndObjects-OperatorsOverloading)

set(SRC
        src/main.cpp
        src/engine.cpp src/scenes.cpp src/textures.cpp
        src/scene.cpp src/statscene.cpp src/dynscene.cpp
        src/gobject.cpp src/gobjectlist.cpp src/cgobject.cpp
        src/player.cpp src/consumable.cpp src/enemy.cpp
        src/collision.cpp src/direction.cpp
        src/rectangle.cpp src/point.cpp
        src/operators.cpp src/utils.cpp
)

set(TASK
        src/operators.cpp)

set(TEST
        test/test.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include/)

configure_test_target(${PROJECT_NAME}-test "${SRC}" ${TEST})