# Copyright (c) 2019 verthais

cmake_minimum_required(VERSION 3.13.4)
project(exercise CXX)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)

include(${CMAKE_SOURCE_DIR}/src/files.cmake)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CMAKE_CXX_STANDARD 17
        CMAKE_CXX_STANDARD_REQUIRED True
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include
        ${CMAKE_SOURCE_DIR}/lib/googletest/googlemock/include
)

add_subdirectory(lib/googletest)

target_link_libraries(
    ${PROJECT_NAME}
        gtest
        gmock
)
