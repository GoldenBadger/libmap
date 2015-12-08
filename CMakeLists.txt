cmake_minimum_required(VERSION 3.4)
project(map)

set_property(GLOBAL PROPERTY CXX_STANDARD 11)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++11 -Wall -Werror -Wextra -W)

include_directories(
    ${CMAKE_SOURCE_DIR}/include/
    ${CMAKE_SOURCE_DIR}/lib/catch/single_include/
)
set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/treemap.cc
)
set(HEADERS
    ${CMAKE_SOURCE_DIR}/include/treemap.h
)
MESSAGE(STATUS ${HEADERS})

add_library(libmap SHARED ${SOURCES} ${HEADERS})
enable_testing(true)
