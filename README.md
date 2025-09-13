# MinGW64 Cross-Compilation

Simple C++ project for creating Windows executables on macOS using MinGW64.

## 文件结构 / File Structure

```
mingw64_mac/
├── main.cpp                    # C++ 源代码
├── CMakeLists.txt             # CMake 配置 (22行)
├── README.md                  # 项目文档
├── mingw64-toolchain.cmake    # 工具链文件 (可选)
└── build/                     # 构建目录
    ├── CMakeCache.txt
    ├── CMakeFiles/
    ├── Makefile
    └── bin/
        └── MinGW64Project.exe # Windows 可执行文件
```

## 安装 / Install

```bash
brew install mingw-w64
```

## 构建 / Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## 运行 / Run

```bash
# On Windows
MinGW64Project.exe

# On macOS with Wine
brew install --cask wine-stable
wine ./bin/MinGW64Project.exe
```

## 文件 / Files

- `main.cpp` - C++ source code
- `CMakeLists.txt` - CMake config (22 lines)
- `build/bin/MinGW64Project.exe` - Windows executable

## 技术 / Tech

- **Target**: Windows PE32+ x86-64
- **Compiler**: MinGW64 GCC
- **Standard**: C++17
- **Size**: ~145 KB
