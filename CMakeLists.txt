cmake_minimum_required(VERSION 3.0)
project (crawlpp)

set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_SOURCE_DIR}/cmake
    )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${PROJECT_BINARY_DIR}/bin)

set(CRAWLPP_LIBRARY libcrawlpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/third_party)
link_directories(${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(tools)