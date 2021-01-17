cmake_minimum_required(VERSION 3.10)

project(Tutorial)

# Tests
enable_testing()

add_executable(appendTest Tests/appendTest.cpp)
add_executable(deleteTest Tests/deleteTest.cpp)
add_executable(prependTest Tests/prependTest.cpp)
add_executable(insertTest Tests/insertTest.cpp)

# Libraries 
add_subdirectory(Linked-List)
target_include_directories(appendTest PUBLIC Linked-List)
target_link_libraries(appendTest linked-list)
target_include_directories(deleteTest PUBLIC Linked-List)
target_link_libraries(deleteTest linked-list)
target_include_directories(prependTest PUBLIC Linked-List)
target_link_libraries(prependTest linked-list)
target_include_directories(insertTest PUBLIC Linked-List)
target_link_libraries(insertTest linked-list)

# Add tests
add_test(AppendTester appendTest)
add_test(DeleteTester deleteTest)
add_test(PrependTester prependTest)
add_test(InsertTester insertTest)
