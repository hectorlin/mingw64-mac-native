# CMake 使用指南 / CMake Usage Guide

简单易懂的 CMake 命令和用法说明 / Simple and easy-to-understand CMake commands and usage guide.

## 基本概念 / Basic Concepts

### 什么是 CMake？/ What is CMake?
CMake 是一个跨平台的构建系统生成器，可以生成各种构建文件（如 Makefile、Visual Studio 项目等）。
CMake is a cross-platform build system generator that can generate various build files (like Makefiles, Visual Studio projects, etc.).

### 为什么使用 CMake？/ Why use CMake?
- **跨平台 / Cross-platform**: 一次配置，多平台构建
- **简单易用 / Simple**: 语法清晰，易于理解
- **功能强大 / Powerful**: 支持复杂的项目结构
- **标准化 / Standardized**: 广泛使用的行业标准

## 项目中的 CMakeLists.txt / CMakeLists.txt in This Project

### 文件内容 / File Content
```cmake
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
```

### 逐行解释 / Line by Line Explanation

1. **`cmake_minimum_required(VERSION 3.16)`**
   - 设置最低 CMake 版本要求
   - Sets minimum CMake version requirement

2. **`set(CMAKE_SYSTEM_NAME Windows)`**
   - 设置目标系统为 Windows
   - Sets target system to Windows

3. **`set(CMAKE_C_COMPILER ...)`**
   - 设置 C 编译器路径
   - Sets C compiler path

4. **`set(CMAKE_CXX_COMPILER ...)`**
   - 设置 C++ 编译器路径
   - Sets C++ compiler path

5. **`project(MinGW64Project)`**
   - 定义项目名称
   - Defines project name

6. **`set(CMAKE_CXX_STANDARD 17)`**
   - 设置 C++ 标准版本
   - Sets C++ standard version

7. **`add_executable(...)`**
   - 创建可执行文件
   - Creates executable

8. **`target_compile_options(...)`**
   - 设置编译选项
   - Sets compilation options

## 常用 CMake 命令 / Common CMake Commands

### 1. 配置项目 / Configure Project
```bash
# 基本配置 / Basic configuration
cmake .

# 指定构建类型 / Specify build type
cmake -DCMAKE_BUILD_TYPE=Release .

# 指定安装路径 / Specify install path
cmake -DCMAKE_INSTALL_PREFIX=/usr/local .
```

### 2. 构建项目 / Build Project
```bash
# 构建所有目标 / Build all targets
cmake --build .

# 构建特定目标 / Build specific target
cmake --build . --target MinGW64Project

# 并行构建 / Parallel build
cmake --build . -j 4
```

### 3. 安装项目 / Install Project
```bash
# 安装到系统 / Install to system
cmake --install .

# 安装到指定路径 / Install to specific path
cmake --install . --prefix /custom/path
```

### 4. 清理项目 / Clean Project
```bash
# 清理构建文件 / Clean build files
cmake --build . --target clean

# 删除构建目录 / Remove build directory
rm -rf build/
```

## 本项目使用步骤 / Usage Steps for This Project

### 1. 准备环境 / Prepare Environment
```bash
# 安装 MinGW64 / Install MinGW64
brew install mingw-w64

# 验证安装 / Verify installation
which x86_64-w64-mingw32-gcc
```

### 2. 配置项目 / Configure Project
```bash
# 创建构建目录 / Create build directory
mkdir build && cd build

# 配置 CMake / Configure CMake
cmake ..
```

### 3. 构建项目 / Build Project
```bash
# 构建项目 / Build project
cmake --build .

# 查看输出 / Check output
ls -la bin/
```

### 4. 运行程序 / Run Program
```bash
# 在 Windows 上运行 / Run on Windows
MinGW64Project.exe

# 在 macOS 上用 Wine 运行 / Run with Wine on macOS
wine ./bin/MinGW64Project.exe
```

## 常见问题 / Common Issues

### 1. 编译器未找到 / Compiler Not Found
```bash
# 错误信息 / Error message
CMake Error: Could not find compiler

# 解决方案 / Solution
# 检查编译器路径 / Check compiler path
which x86_64-w64-mingw32-gcc
# 更新 CMakeLists.txt 中的路径 / Update path in CMakeLists.txt
```

### 2. 构建失败 / Build Failed
```bash
# 错误信息 / Error message
make: *** [target] Error 1

# 解决方案 / Solution
# 清理并重新构建 / Clean and rebuild
rm -rf build/
mkdir build && cd build
cmake ..
cmake --build .
```

### 3. 权限问题 / Permission Issues
```bash
# 错误信息 / Error message
Permission denied

# 解决方案 / Solution
# 检查文件权限 / Check file permissions
chmod +x bin/MinGW64Project.exe
```

## 高级用法 / Advanced Usage

### 1. 调试构建 / Debug Build
```bash
# 启用详细输出 / Enable verbose output
cmake --build . --verbose

# 调试模式构建 / Debug build
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

### 2. 自定义选项 / Custom Options
```bash
# 自定义编译器标志 / Custom compiler flags
cmake -DCMAKE_CXX_FLAGS="-Wall -Wextra" ..

# 自定义安装路径 / Custom install path
cmake -DCMAKE_INSTALL_PREFIX=/custom/path ..
```

### 3. 多配置构建 / Multi-Config Build
```bash
# 创建多个构建目录 / Create multiple build directories
mkdir build-release build-debug
cd build-release && cmake -DCMAKE_BUILD_TYPE=Release ..
cd ../build-debug && cmake -DCMAKE_BUILD_TYPE=Debug ..
```

## 总结 / Summary

CMake 是一个强大的构建工具，通过简单的配置文件可以管理复杂的项目构建过程。本项目展示了如何使用 CMake 进行跨平台编译，特别是从 macOS 编译 Windows 可执行文件。

CMake is a powerful build tool that can manage complex project build processes through simple configuration files. This project demonstrates how to use CMake for cross-platform compilation, especially compiling Windows executables from macOS.

---

**提示 / Tip**: 建议在修改 CMakeLists.txt 后先清理构建目录再重新构建，以确保更改生效。
**Suggestion**: It's recommended to clean the build directory before rebuilding after modifying CMakeLists.txt to ensure changes take effect.
