cmake_minimum_required(VERSION 3.5)

file (GLOB UTILS_SRC
    "*.h"
    "*.cpp"
)

add_library(utilities ${UTILS_SRC})

target_include_directories(utilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

