cmake_minimum_required(VERSION 3.25)

project(ObjectOrientedProgramming-ClassesAndObjects-Introduction)

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

add_executable(${PROJECT_NAME}-run ${SRC})

prepare_sfml_framework_lesson_task(
        "${CMAKE_CURRENT_SOURCE_DIR}/.."
        ${PROJECT_NAME}-run
        ""
)
