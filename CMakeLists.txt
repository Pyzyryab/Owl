        ################ Owl ################
#   --   A web reflective framework for C++   --   #
        #####################################

cmake_minimum_required (VERSION 3.8)

set(This Owl) # Creates a variable to reference the project's name
project( # Sets the properties of the project
    ${This}
    VERSION 0.1.3
    LANGUAGES CXX
) 
list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

SET(CMAKE_CXX_STANDARD 17) # This project will be build using the C++ 17 standard
SET(CMAKE_CXX_EXTENSIONS OFF) # Let's ensure -std=c++xx instead of -std=g++xx
SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")
# Directories for headers and source code
file(
    GLOB_RECURSE
        Headers
            ./include/Owl/**.hpp
        Sources
            src/**.cpp
)

# Add source to this project's executable.
add_library (${This} STATIC ${Headers} ${Sources})
target_include_directories(${This} PUBLIC "include")

# Target properties
SET_TARGET_PROPERTIES(${This} PROPERTIES CMAKE_BUILD_TYPE Debug)

# Compiler options to enable the inclusion of reflection capabilities into C++
# thanks to the .NET System library of the Microsoft's COMMON LANGUAGE RUNTIME SUPPORT
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES COMMON_LANGUAGE_RUNTIME "")
STRING(REPLACE "/EHsc" "/EHa" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
STRING(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /c")


# TODO: Add tests and install targets if needed.
# enable_testing()
# add_subdirectory(test) # Disabled until a solution for the incompatibility with the CPP unit test frameworks
add_subdirectory(test) 

# Run tests after build
add_custom_command(
    OUTPUT test_cmake.exe
    COMMENT "Running tests for the Owl Framework Project"
    COMMAND ${This} 
)