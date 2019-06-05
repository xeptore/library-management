cmake_minimum_required (VERSION 3.14.5)

# debugging build configuration
set (CMAKE_BUILD_TYPE Debug)

project (main)
add_executable (main src/main.cpp)


# changes the final output executable file to buil/bin/lib
set (EXECUTABLE_OUTPUT_PATH bin)
set_target_properties (main PROPERTIES OUTPUT_NAME lib)


# includes directories to help compiler find out imported .h files from
include_directories (include)


# adds libraries
add_library (Member include/member.h src/member.cpp)
target_link_libraries (main Member)

add_library (Book include/book.h src/book.cpp)
target_link_libraries (main Book)

add_library (Store include/store.h src/store.cpp)
target_link_libraries (main Store)

add_library (Util include/util.h src/util.cpp)
target_link_libraries (main Util)
