cmake_minimum_required(VERSION 3.13.4)
project(exercise)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CMAKE_CXX_STANDARD 17
	CMAKE_CXX_STANDARD_REQUIRED True
)
