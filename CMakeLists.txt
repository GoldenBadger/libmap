cmake_minimum_required(VERSION 3.4)
project(libmap)
set(map_VERSION_MAJOR 0)
set(map_VERSION_MINOR 1)
set(map_VERSION_PATCH 0)

configure_file(
    ${CMAKE_SOURCE_DIR}/include/config.h
    ${CMAKE_BINARY_DIR}/include/config.h
)

set_property(GLOBAL PROPERTY CXX_STANDARD 11)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++11 -Wall -Werror -Wextra -W)

include_directories(
    ${CMAKE_SOURCE_DIR}/include/
    ${CMAKE_SOURCE_DIR}/lib/catch/single_include/
)
set(SOURCES
)
set(HEADERS
    ${CMAKE_SOURCE_DIR}/include/rb_node.h
    ${CMAKE_SOURCE_DIR}/include/config.h
)
set(TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/test/test_main.cc
)

add_library(map SHARED ${SOURCES} ${HEADERS})
SET_TARGET_PROPERTIES(map PROPERTIES LINKER_LANGUAGE CXX)

add_executable(maptest ${TEST_SOURCES} ${HEADERS})
SET_TARGET_PROPERTIES(maptest PROPERTIES LINKER_LANGUAGE CXX)
TARGET_LINK_LIBRARIES(maptest map)
enable_testing(true)
add_test(maptest_all maptest)
