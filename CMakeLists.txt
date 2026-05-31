cmake_minimum_required(VERSION 3.10.0)
project(Prouter VERSION 0.1.0 LANGUAGES C CXX)

### Project Info
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

### Environment Info
set(CMAKE_CXX_STANDARD 20)

### Project Structure
add_library(Prouter
    src/core/pint.cpp
    src/core/prouter.cpp
    src/core/tracers/loopTracer.cpp
    src/core/tracers/arrayTracer.cpp
    src/core/controllers/pstepper.cpp
    src/utils/textBuilder.cpp
    src/utils/tableSetter.cpp
    src/utils/consoleUtils.cpp
    src/algorithms/alg_lcs.cpp
)

add_subdirectory(${PROJECT_SOURCE_DIR}/include)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ### Libraries
    ${PROJECT_SOURCE_DIR}/lib/tabulate/include
)

### CTest
enable_testing()
add_subdirectory(tests)

### CPack
include(CPack)
