# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

cmake_minimum_required(VERSION 3.22)

project(cppbasics)

set(CMAKE_CXX_STANDARD 14)

set(TEST_DIR test-framework)
set(SFML_CUSTOM_DIR sfml)

# Add GoogleTest to the project
include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_SOURCE_DIR}/${TEST_DIR}
)

# Variable defining whether it is required to build SFML from sources
set(BUILD_SFML_SRC FALSE)
# On Windows always build SFML from sources
if (${WIN32})
    set(BUILD_SFML_SRC TRUE)
endif()

# If required, download and build SFML sources
if (${BUILD_SFML_SRC})
    include(cmake/sfml.cmake)
    fetch_sfml(
            ${PROJECT_SOURCE_DIR}/cmake
            ${PROJECT_SOURCE_DIR}/${SFML_CUSTOM_DIR}
    )
# Otherwise, assume SFML is installed on user machine and try to find it
else()
    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
endif()

include(cmake/utils.cmake)

# Add tasks subprojects
set(SUBPROJECTS_IGNORE_DIRS ${TEST_DIR} ${SFML_CUSTOM_DIR})
add_subprojects(${CMAKE_SOURCE_DIR} "${SUBPROJECTS_IGNORE_DIRS}")
unset(SUBPROJECTS_IGNORE_DIRS)

# Common configuration

# Disable variable length arrays (for pedagogical reasons)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Werror=vla")