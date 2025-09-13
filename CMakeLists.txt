cmake_minimum_required(VERSION 3.16)

# MinGW64 for macOS
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-g++)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

project(MinGW64Project)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Create executable
add_executable(${PROJECT_NAME} main.cpp)

# Output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -O2)

# Build info
message(STATUS "MinGW64 on macOS -> Windows executable")