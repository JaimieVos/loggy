cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(loggy LANGUAGES CXX)

file(GLOB_RECURSE sources
    "src/*.h"
    "src/*.cpp"
    "example.cpp"
)

add_executable(loggy ${sources})

target_include_directories(loggy PUBLIC 
    ${PROJECT_SOURCE_DIR}/src
    example.cpp
)

foreach(source IN LISTS sources)
    get_filename_component(source_path "${source}" PATH ABSOLUTE)

    file(RELATIVE_PATH
        item_path_rel
        ${PROJECT_SOURCE_DIR}
        ${source_path})

    source_group("${item_path_rel}" FILES "${source}")
endforeach()