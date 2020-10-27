cmake_minimum_required(VERSION 2.6)
project(jsonParser)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests jsonparserTest.cpp ../jsonParser.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
