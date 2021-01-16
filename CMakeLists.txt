cmake_minimum_required(VERSION 3.10)

project(Tutorial)

# Test
enable_testing()

add_executable(tester Tests/test.cpp)

add_subdirectory(Linked-List)
target_include_directories(tester PUBLIC Linked-List)
target_link_directories(tester PRIVATE Linked-List)
target_link_libraries(tester linked-list)

add_test(Tester tester)
