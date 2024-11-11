cmake_minimum_required(VERSION 3.10)

include(GoogleTest)

include(CTest)

enable_testing()

add_executable(main main.cpp)
target_link_libraries(main gtest gtest_main)
add_test(NAME main COMMAND main)
