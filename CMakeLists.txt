# CMakeList.txt : CMake project for Owl Framework Project
cmake_minimum_required (VERSION 3.8)

set(This Owl) # Creates a variable to reference the project's name
project(
    ${This} CXX
    VERSION 0.1.0
    LANGUAGES CXX
) # Sets the properties of the project

set(CMAKE_CXX_STANDARD 17) # This project will be build using the C++ 17 standard
set(CMAKE_CXX_EXTENSIONS OFF) # Let's ensure -std=c++xx instead of -std=g++xx

# Directories for headers and source code
file(
    GLOB_RECURSE
        Headers
            ./include/Owl/**.hpp
        Sources
            src/**.cpp
)

# Add source to this project's executable.
add_library (${This} ${Headers} ${Sources})
target_include_directories(${This} PUBLIC "include")

# Compiler options to enable the inclusion of reflection capabilities into C++
# thanks to the .NET System library of the Microsoft's COMMON LANGUAGE RUNTIME SUPPORT
SET_TARGET_PROPERTIES(Owl PROPERTIES COMPILE_FLAGS "/clr")
STRING(REPLACE "/EHsc" "/EHa" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
STRING(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")  
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /c")


# TODO: Add tests and install targets if needed.
enable_testing()
#add_subdirectory(test)