cmake_minimum_required(VERSION 3.0.0)
project(myapp VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


add_executable(myapp main.cpp source/ArcGraph.cpp source/ListGraph.cpp source/MatrixGraph.cpp source/SetGraph.cpp)
target_include_directories(myapp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
