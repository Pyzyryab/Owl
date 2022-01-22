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

add_library(${This} ${Sources})
target_compile_features(${This} PRIVATE cxx_std_17)

find_package(MSUnitTestFramework REQUIRED)
find_program(
    VSTest_EXECUTABLE 
    NAMES vstest.console.exe 
    PATHS "C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/TestWindow"
    REQUIRED
)


target_link_libraries(
    ${This}
    PRIVATE MSUnitTestFramework::MSUnitTestFramework 
    Owl
)
add_test(NAME ${This} COMMAND "${VSTest_EXECUTABLE}" "$<TARGET_FILE:${This}>" /EnableCodeCoverage)

