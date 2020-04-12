cmake_minimum_required(VERSION 3.10)

project(ConsoleApplication1 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/Main.cpp)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../TestLib/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# target_include_directories(${PROJECT_NAME}
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
# )

if (EMSCRIPTEN) # https://stackoverflow.com/questions/37747205/cmake-project-for-emscripten
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s DEMANGLE_SUPPORT=1 --bind")
endif()

target_link_libraries(${PROJECT_NAME} TestLib)