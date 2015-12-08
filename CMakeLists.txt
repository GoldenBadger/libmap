cmake_minimum_required(VERSION 3.4)
project(libmap)

include_directories(include, lib/catch/single_include)
file(GLOB SOURCES src/*.cpp)

add_library(libmap SHARED ${SOURCES})
enable_testing(true)
