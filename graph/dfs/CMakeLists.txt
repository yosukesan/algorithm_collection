
cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(dfs)
#message("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
add_library(dfs dfs.cpp)
install(TARGETS dfs DESTINATION ${CMAKE_INSTALL_PREFIX})

project(dfs_test)
enable_testing()
add_executable(dfs_test "${PROJECT_SOURCE_DIR}/test/main.cpp" dfs)
add_test(NAME "dfs_ci_test" COMMAND dfs_test)
