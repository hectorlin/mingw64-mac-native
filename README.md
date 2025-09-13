# Native macOS C++ Project

A simple C++ project with CMake build system for native macOS development.

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

```bash
# 安装 Xcode Command Line Tools / Install Xcode Command Line Tools
xcode-select --install

# 安装 CMake / Install CMake
brew install cmake

# 验证安装 / Verify installation
clang --version
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
- **编译器 / Compiler**: AppleClang
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

2. **CMake 未安装 / CMake not installed**
   ```bash
   brew install cmake
   ```

3. **构建失败 / Build failed**
   ```bash
   make clean-all
   cmake ..
   make
   ```

4. **MinGW64 未找到 / MinGW64 not found**
   ```bash
   brew install mingw-w64
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