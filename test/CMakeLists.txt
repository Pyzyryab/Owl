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

# find_library(Owl "../build/Debug")

add_executable(${This} ${Sources})
target_compile_features(${This} PRIVATE cxx_std_17)

# add_executable(prueba "src/test.cpp")

target_link_libraries(
    ${This} 
    PRIVATE Owl
)

# Run tests after build
# add_custom_command(
#     OUTPUT test_cmake.exe
#     COMMENT "Running tests for the Owl Framework Project"
#     COMMAND ${This} 
# )