# Pong-Game-SDL2

# Configure and Build with CMake

## Visual Studio

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
