# copyright (c) Zhicheng Wei 
cmake_minimum_required(VERSION 2.8)
project (mc)

set (mc_VERSION_MAJOR 0)
set (mc_VERSION_MINOR 1)
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)
add_subdirectory (src bin)

