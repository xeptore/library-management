cmake_minimum_required (VERSION 3.10)

# debugging build configuration
set (CMAKE_BUILD_TYPE Debug)

project (main)
add_executable (main main.cpp)

# change output executable file to bin/main.o
set (EXECUTABLE_OUTPUT_PATH bin)
set_target_properties (main PROPERTIES OUTPUT_NAME main.o)

# add libraries and link them to main
add_library (Book book.h book.cpp)
target_link_libraries (main Book)
