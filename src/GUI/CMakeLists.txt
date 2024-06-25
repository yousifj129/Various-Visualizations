cmake_minimum_required(VERSION 3.5)

file(GLOB GUI_SRC
     "*.h"
     "*.cpp"
     "*.ui"
)

add_library(gui ${GUI_SRC})

add_dependencies(gui sorters)
target_include_directories(gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(gui PUBLIC
                     Qt${QT_VERSION_MAJOR}::Widgets
                     sorters
                     utilities
)


