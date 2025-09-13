cmake_minimum_required(VERSION 3.16)

# Detect platform and set appropriate toolchain
if(APPLE)
    # MinGW64 for macOS
    message(STATUS "Detected macOS - Using MinGW64 cross-compilation")
    set(CMAKE_SYSTEM_NAME Windows)
    set(CMAKE_C_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-g++)
    set(CMAKE_C_COMPILER_WORKS 1)
    set(CMAKE_CXX_COMPILER_WORKS 1)
    set(PLATFORM_TYPE "macOS->Windows")
    set(EXECUTABLE_SUFFIX ".exe")
elseif(UNIX AND NOT APPLE)
    # Native GCC for Linux/Fedora
    message(STATUS "Detected Linux/Fedora - Using native GCC")
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_CXX_COMPILER g++)
    set(PLATFORM_TYPE "Linux/Fedora")
    set(EXECUTABLE_SUFFIX "")
else()
    # Default to native compiler
    message(STATUS "Using default compiler for platform")
    set(PLATFORM_TYPE "Native")
    set(EXECUTABLE_SUFFIX "")
endif()

project(MinGW64Project)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Build types
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Create executable
add_executable(${PROJECT_NAME} main.cpp)

# Output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Set executable name based on platform
if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.exe")
else()
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")
endif()

# Compiler flags based on build type and platform
if(APPLE)
    # MinGW64 specific flags
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        $<$<CONFIG:Debug>:-g -O0>
        $<$<CONFIG:Release>:-O2 -DNDEBUG>
    )
elseif(UNIX AND NOT APPLE)
    # Linux/Fedora specific flags
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -Wpedantic
        $<$<CONFIG:Debug>:-g -O0 -DDEBUG>
        $<$<CONFIG:Release>:-O2 -DNDEBUG -march=native>
    )
    # Link with pthread for Linux
    target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
else()
    # Default flags
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        $<$<CONFIG:Debug>:-g -O0>
        $<$<CONFIG:Release>:-O2 -DNDEBUG>
    )
endif()

# Make-like targets
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/cmake_install.cmake
    COMMENT "Cleaning build files"
)

add_custom_target(debug
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ..
    COMMAND ${CMAKE_COMMAND} --build .
    COMMENT "Building debug version"
)

# Build info
message(STATUS "Platform: ${PLATFORM_TYPE}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Output: ${PROJECT_NAME}${EXECUTABLE_SUFFIX}")
message(STATUS "Available targets: make, make clean-all, make debug")