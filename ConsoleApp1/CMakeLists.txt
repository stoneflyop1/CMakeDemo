cmake_minimum_required(VERSION 3.10)

project(ConsoleApp1 
    VERSION 1.0
    LANGUAGES CSharp)

file(GLOB source_files 
    "${CMAKE_CURRENT_SOURCE_DIR}/Properties/*.cs"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cs")

# Set the output folder where your program will be created
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${source_files})

# https://github.com/Aschratt/DotNetWithCMake
# Create assembly info with current version.
#CONFIGURE_FILE("Properties/AssemblyInfo.cs.template" "Properties/AssemblyInfo.cs")
add_dependencies(${PROJECT_NAME} TestLibNet)

############################## C#/CLR  ###################################
# https://stackoverflow.com/questions/2050863/cmake-and-c-cli-c-sharp/55421261#55421261
## Include CMake utilities for CSharp, for WinForm and WPF application support.
# include(CSharpUtilities)
# Set the .NET Framework version for the executable.
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.5.2")
SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES
    "Microsoft.CSharp"
    "System"
    "System.Core"
    "System.Data"
    "System.Drawing"
)
# https://stackoverflow.com/questions/50614863/cmake-building-c-sharp-without-prefer-32-bit-flag
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_GLOBAL_Prefer32Bit "false")
# Set the C# language version (defaults to 3.0).
set(CMAKE_CSharp_FLAGS "/langversion:latest")