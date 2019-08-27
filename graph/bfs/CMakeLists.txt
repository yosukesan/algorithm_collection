
cmake_minimum_required(VERSION 3.0)

project(bfs)
include_directories("${PROJECT_SOURCE_DIR}")
add_library(bfs bfs.cpp)
install(TARGETS bfs DESTINATION ${CMAKE_INSTALL_PREFIX})

project(bfs_test)
enable_testing()
add_executable(bfs_test "${PROJECT_SOURCE_DIR}/test/main.cpp" bfs)
add_test(NAME "bfs_ci_test" COMMAND bfs_test)
