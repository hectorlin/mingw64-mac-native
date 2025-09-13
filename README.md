# MinGW64 Cross-Compilation

Simple C++ project for creating Windows executables on macOS using MinGW64.

## 文件结构 / File Structure

```
mingw64_mac/
├── main.cpp           # C++ 源代码
├── CMakeLists.txt     # CMake 配置 (22行)
├── README.md          # 项目文档
├── CMAKE_USAGE.md     # CMake 使用指南
└── .gitignore         # Git 忽略文件
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
- `README.md` - Project documentation
- `CMAKE_USAGE.md` - CMake usage guide
- `.gitignore` - Git ignore file

## 技术 / Tech

- **Target**: Windows PE32+ x86-64
- **Compiler**: MinGW64 GCC
- **Standard**: C++17
- **Size**: ~145 KB
