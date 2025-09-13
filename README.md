# Native macOS C++ Project

A simple C++ project with CMake build system for native macOS development using clang/clang++.

## 项目概述 / Project Overview

This project demonstrates native macOS C++ compilation using CMake with Apple's clang compiler.

## 文件结构 / File Structure

```
mingw64-mac/
├── main.cpp                    # C++ 源代码 / C++ source code
├── CMakeLists.txt              # CMake 配置 / CMake configuration
├── README.md                   # 项目文档 / Project documentation
└── build/                      # 构建目录 / Build directory
    └── bin/
        └── MinGW64Project      # 可执行文件 / Executable
```

## 快速开始 / Quick Start

### 1. 环境准备 / Environment Setup

#### 安装 Xcode Command Line Tools / Install Xcode Command Line Tools
```bash
# 安装 Xcode Command Line Tools / Install Xcode Command Line Tools
xcode-select --install

# 验证安装 / Verify installation
xcode-select -p
clang --version
clang++ --version
```

#### 安装 CMake / Install CMake
```bash
# 使用 Homebrew 安装 CMake / Install CMake using Homebrew
brew install cmake

# 验证 CMake 版本 / Verify CMake version
cmake --version
```

### 2. 构建项目 / Build Project

```bash
# 创建构建目录 / Create build directory
mkdir build && cd build

# 配置和构建 / Configure and build
cmake ..
make

# 运行程序 / Run program
./bin/MinGW64Project
```

## clang/clang++ 安装指南 / clang/clang++ Installation Guide

### 什么是 clang/clang++？/ What is clang/clang++?

clang 是 LLVM 项目的一部分，是一个 C、C++、Objective-C 和 Objective-C++ 编程语言的编译器前端。它是 Apple 的默认编译器，也是 macOS 上推荐的 C++ 编译器。

clang is part of the LLVM project, a compiler front-end for C, C++, Objective-C, and Objective-C++ programming languages. It's Apple's default compiler and the recommended C++ compiler on macOS.

### 安装方法 / Installation Methods

#### 方法 1: Xcode Command Line Tools (推荐) / Method 1: Xcode Command Line Tools (Recommended)

```bash
# 安装 Xcode Command Line Tools / Install Xcode Command Line Tools
xcode-select --install

# 验证安装 / Verify installation
clang --version
clang++ --version
which clang
which clang++
```

#### 方法 2: 完整 Xcode (可选) / Method 2: Full Xcode (Optional)

```bash
# 从 App Store 安装 Xcode / Install Xcode from App Store
# 或者从 Apple Developer 下载 / Or download from Apple Developer

# 验证安装 / Verify installation
xcodebuild -version
clang --version
```

#### 方法 3: Homebrew 安装 LLVM / Method 3: Install LLVM via Homebrew

```bash
# 安装 LLVM (包含 clang) / Install LLVM (includes clang)
brew install llvm

# 添加到 PATH / Add to PATH
echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc

# 验证安装 / Verify installation
clang --version
clang++ --version
```

#### 方法 4: 手动安装 LLVM / Method 4: Manual LLVM Installation

```bash
# 下载 LLVM 预编译版本 / Download LLVM pre-built binaries
cd ~/Downloads
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-17.0.6/clang+llvm-17.0.6-x86_64-apple-darwin.tar.xz

# 解压到 /usr/local / Extract to /usr/local
sudo tar -xf clang+llvm-17.0.6-x86_64-apple-darwin.tar.xz -C /usr/local/

# 添加到 PATH / Add to PATH
echo 'export PATH="/usr/local/clang+llvm-17.0.6-x86_64-apple-darwin/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
```

### 验证 clang 安装 / Verify clang Installation

```bash
# 检查编译器版本 / Check compiler versions
clang --version
clang++ --version

# 检查编译器路径 / Check compiler paths
which clang
which clang++

# 检查编译器功能 / Check compiler capabilities
clang -print-search-dirs
clang++ -print-search-dirs

# 测试编译 / Test compilation
echo '#include <iostream>
int main() { std::cout << "Hello from clang!" << std::endl; return 0; }' > test.cpp
clang++ -o test test.cpp
./test
rm test.cpp test
```

### clang 配置 / clang Configuration

#### 设置环境变量 / Set Environment Variables

```bash
# 添加到 ~/.zshrc 或 ~/.bash_profile / Add to ~/.zshrc or ~/.bash_profile
export CC=clang
export CXX=clang++

# 设置 clang 路径 / Set clang paths
export CLANG_PATH="/usr/bin/clang"
export CLANGXX_PATH="/usr/bin/clang++"
```

#### 创建 clang 别名 / Create clang Aliases

```bash
# 添加到 ~/.zshrc / Add to ~/.zshrc
alias gcc="clang"
alias g++="clang++"
alias cc="clang"
alias cxx="clang++"
```

### 使用 clang 编译 / Compilation with clang

```bash
# 编译 C 程序 / Compile C program
clang -o hello hello.c

# 编译 C++ 程序 / Compile C++ program
clang++ -o hello hello.cpp

# 调试版本 / Debug version
clang++ -g -o hello hello.cpp

# 发布版本 / Release version
clang++ -O2 -o hello hello.cpp

# 使用 C++17 标准 / Using C++17 standard
clang++ -std=c++17 -o hello hello.cpp

# 静态链接 / Static linking
clang++ -static -o hello hello.cpp
```

## 可用命令 / Available Commands

| 命令 / Command | 功能 / Function |
|----------------|-----------------|
| `make` | 构建项目 / Build project |
| `make debug` | 构建调试版本 / Build debug version |
| `make release` | 构建发布版本 / Build release version |
| `make run` | 构建并运行 / Build and run |
| `make clean-all` | 清理构建文件 / Clean build files |

## 技术规格 / Technical Specifications

- **平台 / Platform**: macOS (Native)
- **编译器 / Compiler**: AppleClang (clang/clang++)
- **C++ 标准 / C++ Standard**: C++17
- **构建系统 / Build System**: CMake 3.16+
- **文件大小 / File Size**: ~53 KB

## MinGW64 安装 (可选) / MinGW64 Installation (Optional)

如果你想进行 Windows 交叉编译：/ If you want Windows cross-compilation:

```bash
# 安装 MinGW64 / Install MinGW64
brew install mingw-w64

# 验证安装 / Verify installation
x86_64-w64-mingw32-gcc --version
```

### 使用 MinGW64 交叉编译 / Cross-compilation with MinGW64

```bash
# 编译 Windows 可执行文件 / Compile Windows executable
x86_64-w64-mingw32-g++ -static -o hello.exe hello.cpp
```

## 故障排除 / Troubleshooting

### 常见问题 / Common Issues

1. **Xcode Command Line Tools 未安装 / Xcode Command Line Tools not installed**
   ```bash
   xcode-select --install
   ```

2. **clang 未找到 / clang not found**
   ```bash
   # 检查安装 / Check installation
   which clang
   xcode-select -p
   
   # 重新安装 / Reinstall
   sudo xcode-select --reset
   xcode-select --install
   ```

3. **CMake 未安装 / CMake not installed**
   ```bash
   brew install cmake
   ```

4. **构建失败 / Build failed**
   ```bash
   make clean-all
   cmake ..
   make
   ```

5. **权限问题 / Permission issues**
   ```bash
   chmod +x bin/MinGW64Project
   ```

## 开发工作流 / Development Workflow

```bash
# 修改代码 / Modify code
vim main.cpp

# 构建 / Build
make

# 运行 / Run
make run

# 调试版本 / Debug version
make debug
```

## 许可证 / License

MIT License

---

**项目状态 / Project Status**: ✅ 完全功能 / Fully functional