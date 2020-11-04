cmake_minimum_required(VERSION 2.6)
project(jsonParser)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests projectTest.cpp ../JSON.cpp ../Hero.cpp ../Monster.cpp) 
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
