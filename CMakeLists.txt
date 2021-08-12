cmake_minimum_required(VERSION 3.10)

# set the project name
project(practice VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# configure a header file to pass the version number only
configure_file(practiceConfig.h.in practiceConfig.h)

# add the Algo module library
add_subdirectory(algo_module)

# add the executable
add_executable(practice main.cpp)

target_link_libraries(practice PUBLIC algo)
# add the binary tree to the search path for include files
# so that we will find VersionConfig.h
target_include_directories(practice PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          )

install(TARGETS practice DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/practiceConfig.h"
  DESTINATION include
  )