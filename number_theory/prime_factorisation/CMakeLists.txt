
cmake_minimum_required(VERSION 3.11)

project (prime_number)
add_library(prime_number prime_factorisation.cpp)

project (test_prime_number)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(test_prime_number ${PROJECT_SOURCE_DIR}/test/main.cpp prime_factorisation)

install (TARGETS prime_number DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install (TARGETS test_prime_number DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

enable_testing()
#add_test()

