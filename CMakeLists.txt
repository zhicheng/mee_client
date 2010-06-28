# copyright (c) Zhicheng Wei 
cmake_minimum_required(VERSION 2.8)
project (mc)

set (mc_VERSION_MAJOR 0)
set (mc_VERSION_MINOR 1)

set (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY
)

add_custom_target (uninstall
    "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

# set uninstall
add_subdirectory (src bin)

