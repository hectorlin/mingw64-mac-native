# MinGW64 Cross-Compilation Project

A complete C++ project demonstrating cross-compilation from macOS to Windows using MinGW64 with advanced CMake targets.

## 项目概述 / Project Overview

This project showcases how to use MinGW64 on macOS to create Windows executables through cross-compilation, featuring a comprehensive CMake build system with custom targets similar to Make.

## 文件结构 / File Structure

```
mingw64_mac/
├── main.cpp           # C++ 源代码 (18行)
├── CMakeLists.txt     # CMake 配置 (79行，含自定义目标)
├── README.md          # 项目文档
├── CMAKE_USAGE.md     # CMake 关键词指南
└── .gitignore         # Git 忽略文件
```

## CMake 工作流程 / CMake Workflow

### 1. 环境准备 / Environment Setup
```bash
# 安装 MinGW64 / Install MinGW64
brew install mingw-w64

# 验证安装 / Verify installation
which x86_64-w64-mingw32-gcc
```

### 2. 项目配置 / Project Configuration
```bash
# 创建构建目录 / Create build directory
mkdir build && cd build

# 配置 CMake / Configure CMake
cmake ..

# 查看可用目标 / View available targets
cmake --build . --target info
```

### 3. 构建流程 / Build Process
```bash
# 基本构建 / Basic build
cmake --build .

# 调试版本 / Debug build
cmake --build . --target debug

# 发布版本 / Release build
cmake --build . --target release

# 重新构建 / Rebuild
cmake --build . --target rebuild
```

### 4. 运行和测试 / Run and Test
```bash
# 查看项目信息 / View project info
cmake --build . --target info

# 运行程序 (需要 Wine) / Run program (requires Wine)
cmake --build . --target run

# 清理项目 / Clean project
cmake --build . --target clean-all
```

## 可用目标 / Available Targets

| 目标 / Target | 命令 / Command | 功能 / Function |
|---------------|----------------|-----------------|
| **`info`** | `cmake --build . --target info` | 显示项目信息 / Show project info |
| **`debug`** | `cmake --build . --target debug` | 构建调试版本 / Build debug version |
| **`release`** | `cmake --build . --target release` | 构建发布版本 / Build release version |
| **`rebuild`** | `cmake --build . --target rebuild` | 重新构建 / Rebuild project |
| **`run`** | `cmake --build . --target run` | 运行程序 / Run program |
| **`clean-all`** | `cmake --build . --target clean-all` | 完全清理 / Complete cleanup |

## 快速开始 / Quick Start

### 完整流程 / Complete Workflow
```bash
# 1. 克隆项目 / Clone project
git clone https://github.com/hectorlin/mingw64-mac.git
cd mingw64-mac

# 2. 安装依赖 / Install dependencies
brew install mingw-w64

# 3. 构建项目 / Build project
mkdir build && cd build
cmake ..
cmake --build . --target info

# 4. 运行程序 / Run program
cmake --build . --target run
```

### 开发流程 / Development Workflow
```bash
# 调试开发 / Debug development
cmake --build . --target debug
cmake --build . --target info

# 发布构建 / Release build
cmake --build . --target release

# 清理重建 / Clean rebuild
cmake --build . --target clean-all
cmake ..
cmake --build .
```

## 技术规格 / Technical Specifications

- **目标平台 / Target Platform**: Windows PE32+ x86-64
- **编译器 / Compiler**: MinGW64 GCC 15.2.0
- **C++ 标准 / C++ Standard**: C++17
- **构建系统 / Build System**: CMake 3.16+
- **文件大小 / File Size**: ~145 KB (Release)
- **交叉编译 / Cross-compilation**: macOS → Windows

## 项目文件 / Project Files

- **`main.cpp`** - C++ 源代码，简单的控制台程序 / C++ source code, simple console program
- **`CMakeLists.txt`** - CMake 配置文件，包含 6 个自定义目标 / CMake configuration with 6 custom targets
- **`README.md`** - 项目文档和使用指南 / Project documentation and usage guide
- **`CMAKE_USAGE.md`** - CMake 关键词速查指南 / CMake keywords quick reference guide
- **`.gitignore`** - Git 忽略文件配置 / Git ignore file configuration

## 故障排除 / Troubleshooting

### 常见问题 / Common Issues

1. **MinGW64 未找到 / MinGW64 not found**
   ```bash
   brew install mingw-w64
   which x86_64-w64-mingw32-gcc
   ```

2. **构建失败 / Build failed**
   ```bash
   cmake --build . --target clean-all
   cmake ..
   cmake --build .
   ```

3. **Wine 运行失败 / Wine run failed**
   ```bash
   brew install --cask wine-stable
   cmake --build . --target run
   ```

## 贡献 / Contributing

欢迎提交 Issue 和 Pull Request！/ Welcome to submit issues and pull requests!

## 许可证 / License

MIT License - 开源项目 / Open source project

---

**GitHub 仓库 / GitHub Repository**: https://github.com/hectorlin/mingw64-mac
