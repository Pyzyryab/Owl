cmake_minimum_required(
    VERSION 3.8
)

set(This OwlTests)
project(${This} CXX)

file(
    GLOB_RECURSE
        Sources
            src/**.cpp
)

add_executable(${This} ${Sources})
target_compile_features(${This} PRIVATE cxx_std_17)

# The locations of the MS CppUnitTestFramework
include_directories("C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Auxiliary/VS/UnitTest/include")
link_directories("C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Auxiliary/VS/UnitTest/lib/x86/Microsoft.VisualStudio.TestTools.CppUnitTestFramework.lib")

target_link_libraries(
    ${This} 
    PRIVATE 
    Owl
)