cmake_minimum_required(VERSION 3.22)

project(MemoryManagement-MemoryLayout-SizeOfPointer)

set(CMAKE_CXX_STANDARD 14)

# custom command to produce output.txt file, because its content
# is platform-specific and need to be generated on student's machine
add_executable(${PROJECT_NAME}-output test/output.cpp)
add_custom_target(${PROJECT_NAME}-output-gen
        COMMAND ${PROJECT_NAME}-output ${CMAKE_CURRENT_SOURCE_DIR}/test/output.txt
        DEPENDS ${PROJECT_NAME}-output
)

# Files from `./src` directory
set(SRC
        src/main.cpp)


# Running learner side code
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
add_executable(${PROJECT_NAME}-run ${SRC})
add_dependencies(${PROJECT_NAME}-run ${PROJECT_NAME}-output-gen)