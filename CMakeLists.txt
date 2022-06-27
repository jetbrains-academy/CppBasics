# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

cmake_minimum_required(VERSION 3.22)

project(csc_cpp)

set(TEST_DIR test-framework)

# Add GoogleTest to the project
include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_SOURCE_DIR}/${TEST_DIR}
)

# Add tasks subprojects
include(cmake/utils.cmake)
add_subprojects(${CMAKE_SOURCE_DIR} ${TEST_DIR})