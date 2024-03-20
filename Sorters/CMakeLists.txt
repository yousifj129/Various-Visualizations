cmake_minimum_required(VERSION 3.5)

file(GLOB SORTERS_SRC
     "*.h"
     "*.cpp"
)
add_library(sorters ${SORTERS_SRC})

target_include_directories(sorters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(sorters PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
