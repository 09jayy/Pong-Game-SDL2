# Pong-Game-SDL2

# Configure and Build with CMake

Prerequisites:

- Git
- CMake
- C++ compiler

First, clone the repository

```sh
git clone https://github.com/09jayy/Pong-Game-SDL2
cd Pong-Game-SDL2
```

Note: The CMakeLists.txt will first use `find_package(SDL2 QUIET)` to locate SDL2 dependencies before attempting to download the SDL2 repository

## Open in Visual Studio as CMake Project

1. In Visual Studio: File > Open > CMake.. > "Pong-Game-SDL2/CMakeLists.txt"
1. Select configuration (e.g. x64-Debug, x64-Release)
1. Run CMake Configuration (this will run using CMakePresets.json)
1. Build Project (Ctrl+Shift+B / Cmd+Shift+B)
1. Run Pong-Game-SDL.exe (Shift+F5)

## Ninja Generator

### Debug

```sh
mkdir build
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Debug
ninja
```

### Release

```sh
mkdir build
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja
```

## Visual Studio 17 Generator

### Debug

```sh
mkdir build
cmake .. -G "Visual Studio 17" -DCMAKE_BUILD_TYPE=Debug
msbuild Pong-Game-SDL2.sln
```

### Release

```sh
mkdir build
cmake .. -G "Visual Studio 17" -DCMAKE_BUILD_TYPE=Release
msbuild Pong-Game-SDL2.sln
```
