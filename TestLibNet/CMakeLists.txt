cmake_minimum_required(VERSION 3.10)

project(TestLibNet VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB source_files
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

add_library(${PROJECT_NAME} SHARED ${source_files})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../TestLib/inc
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(${PROJECT_NAME} TestLib)
add_dependencies(${PROJECT_NAME} TestLib)

###########################  C++/CLI   #################################
# target_compile_options(${PROJECT_NAME} PRIVATE /clr)
# target_compile_options(${PROJECT_NAME} PRIVATE /fp:precise)
# https://stackoverflow.com/questions/40126734/set-clr-support-to-true-with-cmake
set_target_properties(${PROJECT_NAME} PROPERTIES VS_GLOBAL_CLRSupport  "true")
# Define the assembly to be mixed-mode (managed + unmanaged).
SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY COMMON_LANGUAGE_RUNTIME "")
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.5.2")
SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES
	"System"
    "System.Core"
)
# # https://github.com/hepcatjk/CsharpCLICplusplusDLLExample/blob/master/CLI_DLL_Bridge/CMakeLists.txt
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHa")
# #Ugly - is there a better fix to this ....
# if(CMAKE_CXX_FLAGS_DEBUG MATCHES "/RTC1")
#    string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
#    string(REPLACE "/RTC1" " " CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
# endif()

