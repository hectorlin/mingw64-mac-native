# CMake 关键词指南 / CMake Keywords Guide

CMake 核心关键词和命令速查 / CMake core keywords and commands quick reference.

## 核心关键词 / Core Keywords

### CMake 定义 / CMake Definition
**CMake** = 跨平台构建系统生成器 / Cross-platform build system generator
- 生成 Makefile、Visual Studio 项目等 / Generates Makefiles, Visual Studio projects, etc.
- 一次配置，多平台构建 / Configure once, build everywhere

### 关键优势 / Key Advantages
- **跨平台 / Cross-platform**: Windows, macOS, Linux
- **标准化 / Standardized**: 行业标准 / Industry standard
- **自动化 / Automated**: 自动依赖管理 / Automatic dependency management

## 关键词速查 / Keywords Quick Reference

### 核心命令 / Core Commands
| 关键词 / Keyword | 功能 / Function | 示例 / Example |
|------------------|-----------------|----------------|
| `cmake_minimum_required` | 版本要求 / Version requirement | `cmake_minimum_required(VERSION 3.16)` |
| `project` | 项目定义 / Project definition | `project(MyProject)` |
| `add_executable` | 创建可执行文件 / Create executable | `add_executable(app main.cpp)` |
| `add_library` | 创建库 / Create library | `add_library(lib STATIC src.cpp)` |
| `target_link_libraries` | 链接库 / Link libraries | `target_link_libraries(app lib)` |

### 系统设置 / System Settings
| 关键词 / Keyword | 功能 / Function | 示例 / Example |
|------------------|-----------------|----------------|
| `CMAKE_SYSTEM_NAME` | 目标系统 / Target system | `set(CMAKE_SYSTEM_NAME Windows)` |
| `CMAKE_C_COMPILER` | C 编译器 / C compiler | `set(CMAKE_C_COMPILER gcc)` |
| `CMAKE_CXX_COMPILER` | C++ 编译器 / C++ compiler | `set(CMAKE_CXX_COMPILER g++)` |
| `CMAKE_CXX_STANDARD` | C++ 标准 / C++ standard | `set(CMAKE_CXX_STANDARD 17)` |

### 编译选项 / Compilation Options
| 关键词 / Keyword | 功能 / Function | 示例 / Example |
|------------------|-----------------|----------------|
| `target_compile_options` | 编译选项 / Compile options | `target_compile_options(app PRIVATE -Wall)` |
| `target_include_directories` | 头文件路径 / Include directories | `target_include_directories(app PRIVATE include)` |
| `target_compile_definitions` | 编译定义 / Compile definitions | `target_compile_definitions(app PRIVATE DEBUG)` |

## 命令速查 / Commands Quick Reference

### 配置命令 / Configuration Commands
```bash
cmake .                           # 基本配置 / Basic config
cmake -DCMAKE_BUILD_TYPE=Release . # 发布版本 / Release build
cmake -DCMAKE_INSTALL_PREFIX=/usr . # 安装路径 / Install path
```

### 构建命令 / Build Commands
```bash
cmake --build .                   # 构建所有 / Build all
cmake --build . --target app      # 构建特定目标 / Build specific target
cmake --build . -j 4              # 并行构建 / Parallel build
```

### 安装命令 / Install Commands
```bash
cmake --install .                 # 安装 / Install
cmake --install . --prefix /usr   # 指定路径 / Custom path
```

### 清理命令 / Clean Commands
```bash
cmake --build . --target clean    # 清理 / Clean
rm -rf build/                     # 删除构建目录 / Remove build dir
```

## 快速开始 / Quick Start

### 环境准备 / Environment Setup
```bash
brew install mingw-w64              # 安装 MinGW64 / Install MinGW64
which x86_64-w64-mingw32-gcc        # 验证安装 / Verify installation
```

### 项目构建 / Project Build
```bash
mkdir build && cd build              # 创建构建目录 / Create build dir
cmake ..                            # 配置 / Configure
cmake --build .                     # 构建 / Build
ls -la bin/                         # 查看输出 / Check output
```

### 程序运行 / Program Run
```bash
MinGW64Project.exe                  # Windows 运行 / Run on Windows
wine ./bin/MinGW64Project.exe       # macOS 运行 / Run on macOS
```

## 问题解决 / Troubleshooting

### 关键词问题 / Keyword Issues
| 问题 / Problem | 关键词 / Keyword | 解决方案 / Solution |
|----------------|------------------|---------------------|
| 编译器未找到 / Compiler not found | `CMAKE_C_COMPILER` | 检查路径 / Check path: `which gcc` |
| 构建失败 / Build failed | `cmake --build` | 清理重建 / Clean rebuild: `rm -rf build/` |
| 权限问题 / Permission denied | `chmod` | 添加执行权限 / Add execute: `chmod +x app` |

### 调试关键词 / Debug Keywords
```bash
cmake --build . --verbose          # 详细输出 / Verbose output
cmake -DCMAKE_BUILD_TYPE=Debug ..  # 调试模式 / Debug mode
cmake -DCMAKE_CXX_FLAGS="-Wall" .. # 自定义标志 / Custom flags
```

## 关键词总结 / Keywords Summary

### 必记关键词 / Must-Know Keywords
- **`cmake_minimum_required`** - 版本要求 / Version requirement
- **`project`** - 项目定义 / Project definition  
- **`add_executable`** - 创建可执行文件 / Create executable
- **`target_compile_options`** - 编译选项 / Compile options
- **`CMAKE_CXX_STANDARD`** - C++ 标准 / C++ standard

### 常用命令 / Common Commands
- **`cmake .`** - 配置 / Configure
- **`cmake --build .`** - 构建 / Build
- **`cmake --install .`** - 安装 / Install

---

**快速提示 / Quick Tip**: 修改 CMakeLists.txt 后清理构建目录 / Clean build directory after modifying CMakeLists.txt
