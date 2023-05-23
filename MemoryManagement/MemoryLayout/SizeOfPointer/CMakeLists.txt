cmake_minimum_required(VERSION 3.22)

project(MemoryManagement-MemoryLayout-SizeOfPointer)

set(CMAKE_CXX_STANDARD 14)

set(OUTPUT_CPP_TASK MemoryManagement-MemoryLayout-SizeOfPointers-output-cpp)
set(OUTPUT_TXT_TASK MemoryManagement-MemoryLayout-SizeOfPointers-output-txt)

# custom command to produce output.txt file, because its content
# is platform-specific and need to be generated on student's machine
add_executable(${OUTPUT_CPP_TASK} test/output.cpp)
add_custom_target(${OUTPUT_TXT_TASK}
        COMMAND ${OUTPUT_CPP_TASK} ${CMAKE_CURRENT_SOURCE_DIR}/test/output.txt
        DEPENDS ${OUTPUT_CPP_TASK}
)

# Files from `./src` directory
set(SRC
        src/main.cpp)


# Running learner side code
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
add_executable(${PROJECT_NAME}-run ${SRC})
add_dependencies(${PROJECT_NAME}-run ${OUTPUT_TXT_TASK})