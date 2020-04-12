cmake_minimum_required(VERSION 3.10)

project(TestLib)

add_subdirectory(TestLib)
add_subdirectory(ConsoleApplication1)

if (MSVC)
    add_subdirectory(TestLibNet)
    add_subdirectory(ConsoleApp1)
endif()