cmake_minimum_required(VERSION 3.10)

project(TestLib VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

add_library(${PROJECT_NAME} ${source_files})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# target_include_directories(${PROJECT_NAME}
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
# )

