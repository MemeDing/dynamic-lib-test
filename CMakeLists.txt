cmake_minimum_required(VERSION 4.3)

project(module_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULE_TEST_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(MODULE_TEST_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

add_subdirectory(src)