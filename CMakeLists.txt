cmake_minimum_required(VERSION 3.10.0)
project(Prouter VERSION 0.1.0 LANGUAGES C CXX)

### Project Info
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

### Environment Info
set(CMAKE_CXX_STANDARD 20)

### Project Structure
add_library(Prouter Prouter.cpp)

add_subdirectory(${PROJECT_SOURCE_DIR}/include)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ### Libraries
    ${PROJECT_SOURCE_DIR}/lib/tabulate/include
)

### CTest
add_subdirectory(tests)

include(CTest)
enable_testing()
add_test(NAME mytest COMMAND tests)

### CPack
include(CPack)
