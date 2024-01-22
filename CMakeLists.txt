cmake_minimum_required(VERSION 3.26)
project(Prouter)

set(CMAKE_CXX_STANDARD 20)
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -O2")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -O2")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")

add_subdirectory(include)
#add_subdirectory(src)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Libraries
include_directories(${PROJECT_SOURCE_DIR}/lib/tabulate/include)

add_executable(testDaemon tests/testDaemon.cpp)

enable_testing()
