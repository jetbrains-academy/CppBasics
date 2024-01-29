macro(add_subprojects _base_dir _ignore_dirs)
    # Find all CMakeLists.txt paths
    file(GLOB_RECURSE _cmake_files RELATIVE "${_base_dir}" CMakeLists.txt)
    # Collect all subdirectories containing CMakeLists.txt
    set(_dirs)
    foreach (file_path ${_cmake_files})
        get_filename_component(_dir_path ${file_path} PATH)
        list(APPEND _dirs ${_dir_path})
    endforeach ()

    unset(_cmake_files)
    unset(_dir_path)

    # Add all found directories
    foreach (dir ${_dirs})
        set(_should_add TRUE)
        foreach (ignore_dir ${_ignore_dirs})
            string(FIND "${dir}" ${ignore_dir} _out)
            if (NOT "${_out}" EQUAL -1)
                set(_should_add FALSE)
                break ()
            endif ()
        endforeach ()
        if (${_should_add})
            add_subdirectory(${dir})
        endif ()
        unset(_should_add)
    endforeach ()
endmacro()

function(create_test_target_lib_name TARGET_NAME OUTPUT_NAME)
    set(${OUTPUT_NAME} "${TARGET_NAME}-src-part" PARENT_SCOPE)
endfunction()

macro(configure_test_target _target_name _src_files _test_files)
    create_test_target_lib_name(${_target_name} _src_part_lib)

    # Create utility library to separate src files from test files
    add_library(${_src_part_lib} STATIC ${_src_files})

    # Rename learners main function to prevent overloading or name conflicts
    # It will rename symbols only in files from `_src_files` set
    string(SHA1 _hash _target_name)
    target_compile_definitions(${_src_part_lib} PRIVATE main=main${_hash})
    unset(_hash)

    # Create test executable target
    add_executable(${_target_name} ${_test_files})

    # Add files from `_src_files` set to target
    target_link_libraries(${_target_name} ${_src_part_lib})

    # Add Google Test libraries to target
    target_link_libraries(${_target_name} gtest gtest_main)

    unset(_test_source)
endmacro()

# Adds SFML headers and links its libs
macro(target_link_sfml _target_name)
    target_link_libraries(${_target_name} sfml-system sfml-window sfml-graphics sfml-audio)
endmacro()

# Copies resource files to the build directory
macro(target_copy_resources _target_name)
    add_custom_command(TARGET ${_target_name} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:${_target_name}>/resources/)
endmacro()

macro(prepare_sfml_framework_lesson_task _lesson_path _target_name _test_name)
    include_directories(${SFML_INCLUDE_DIR})
    # on MacOS clang by default does not search for header files in /usr/local/include directory,
    # where homebrew is likely to put the SFML headers;
    # as a dirty quickfix we simply add this directory manually
    if (${APPLE})
        include_directories(/usr/local/include)
        include_directories(/opt/homebrew/include)
    endif()
    include_directories(${CMAKE_SOURCE_DIR}/include/)
    target_copy_resources(${_target_name})
    target_link_sfml(${_target_name})
    if (NOT "${_test_name}" STREQUAL "")
        target_copy_resources(${_test_name})
        create_test_target_lib_name(${_test_name} _src_part_lib)
        target_link_sfml(${_src_part_lib})
        target_link_sfml(${_test_name})
    endif()
endmacro()