cmake_minimum_required(VERSION 3.22)

project(sfml-download NONE)

include(ExternalProject)

ExternalProject_Add(
        sfml
        SOURCE_DIR "@SFML_DOWNLOAD_ROOT@/sfml-src"
        BINARY_DIR "@SFML_DOWNLOAD_ROOT@/sfml-build"
        GIT_REPOSITORY
            https://github.com/SFML/SFML.git
        GIT_TAG
            2.5.1
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
)