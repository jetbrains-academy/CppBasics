macro(fetch_sfml _download_module_path _download_root)
    set(SFML_DOWNLOAD_ROOT ${_download_root})
    configure_file(
            ${_download_module_path}/sfml-download.cmake
            ${_download_root}/CMakeLists.txt
            @ONLY
    )
    unset(SFML_DOWNLOAD_ROOT)

    # build static SFML libs in order to get self-contained executables
    # (i.e. no need to change PATH on Windows to point to built .dll)
    set(BUILD_SHARED_LIBS FALSE)

    execute_process(
            COMMAND
            "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
            WORKING_DIRECTORY
            ${_download_root}
    )
    execute_process(
            COMMAND
            "${CMAKE_COMMAND}" --build .
            WORKING_DIRECTORY
            ${_download_root}
    )

    # adds the sfml targets
    add_subdirectory(
            ${_download_root}/sfml-src
            ${_download_root}/sfml-build
    )

    set(SFML_INCLUDE_DIR ${_download_root}/sfml-src/include)
endmacro()