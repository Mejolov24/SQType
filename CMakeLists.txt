cmake_minimum_required(VERSION 3.10)

project(SQType VERSION 0.1.0 LANGUAGES C CXX)

add_library(SQType INTERFACE)

target_include_directories(SQType INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(simple_example examples/simple_example.cpp)

target_link_libraries(simple_example PRIVATE SQType)