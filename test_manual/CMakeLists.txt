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

target_link_libraries(
    ${This}
    Owl
)

# TODO Make an execute_process() function to automatically run "tests" when the project is compiled