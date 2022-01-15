# CMakeList.txt : CMake project for Owl Framework Project
cmake_minimum_required (VERSION 3.8)

set(This Owl) # Creates a variable to reference the project's name
project(${This} CXX) # Sets the name of the project and the languages used in

set(CMAKE_CXX_STANDARD 17) # This project will be build using the C++ 17 standard

# Directories for headers and source code
file(
    GLOB_RECURSE
        Headers
            ./include/Owl/**.hpp
        Sources
            src/**.cpp
)

add_library(
    ${This} SHARED ${Headers} ${Sources}
)


# Compuiler options to enable the inclusion of reflections capabilities into the C++ standard
# thanks to the .NET System library of the Microsoft's COMMON LANGUAGE RUNTIME SUPPORT
SET_TARGET_PROPERTIES(${This} PROPERTIES COMPILE_FLAGS "/clr")
STRING(REPLACE "/EHsc" "/EHa" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
STRING(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")  
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /c") 

# TODO: Add tests and install targets if needed.